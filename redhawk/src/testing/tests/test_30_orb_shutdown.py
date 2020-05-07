#
# This file is protected by Copyright. Please refer to the COPYRIGHT file
# distributed with this source distribution.
#
# This file is part of REDHAWK core.
#
# REDHAWK core is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# REDHAWK core is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see http://www.gnu.org/licenses/.
#

import unittest
from _unitTestHelpers import scatest
import time
import contextlib
import cStringIO
import tempfile
import re
import resource
import sys as _sys
from omniORB import CORBA
from omniORB import any as _any
from xml.dom import minidom
import os as _os
import Queue
import StringIO
from ossie.cf import CF
from ossie.utils import redhawk
from ossie.utils import type_helpers
from ossie.utils import rhconnection
from ossie.utils import allocations
from ossie.utils import sb
from ossie.utils.model import NoMatchingPorts
from ossie.events import Subscriber, Publisher
from ossie.cf import CF
import traceback
import CosNaming


class OrbShutdownTest(scatest.CorbaTestCase):
    def setUp(self):
        pass

    def tearDown(self):
        # Do all application shutdown before calling the base class tearDown,
        # or failures will probably occur.
        scatest.CorbaTestCase.tearDown(self)

    def test_attach_shutdown(self):
        dom_name=scatest.getTestDomainName()

        self.launchDomainManager()
        dom=redhawk.base.attach(dom_name)
        self.assertNotEqual(dom, None)
        orb1 = dom.orb

        try:
            redhawk.base.attach(dom_name, 'bad_location')
            self.assertFalse(True)
        except:
            self.assertTrue(True)

        # Attach to the domain a second time, which will create a new Domain
        # object sharing the same ORB (the feature where it would return an
        # existing reference was dropped).
        dom3=redhawk.base.attach(dom_name)
        self.assertNotEqual(dom3,None)
        self.assertNotEqual(dom, dom3)
        self.assertEqual(dom.name, dom3.name)
        self.assertEquals(orb1, dom3.orb)

        orb1.shutdown(True)

        # Verify that we get the location=None domain, not dom4
        dom4=redhawk.base.attach(dom_name)
        self.assertNotEqual(dom, dom4)
        self.assertNotEquals(orb1, dom4.orb)
