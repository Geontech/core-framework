#!/usr/bin/env python2
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


import logging
from ossie.cf import CF, CF__POA
from ossie.resource import Resource, start_component
from ossie.properties import simple_property, simpleseq_property, struct_property, structseq_property


class TestPythonProps (CF__POA.Resource, Resource):
    """Python component for testing properties"""

    prop1 = simple_property(id_="DCE:b8f43ac8-26b5-40b3-9102-d127b84f9e4b",
                            name="string_prop",
                            type_="string",
                            action="external",
                            kinds=("configure",))

    prop2 = simpleseq_property(id_="DCE:10b3364d-f035-4639-8e7f-02ac4706f5c7[]",
                               name="stringseq_prop",
                               type_="string",
                               action="external",
                               kinds=("configure",),
                               defvalue=[])

    class SomeStruct(object):
        field1 = simple_property(id_="item1",
                                type_="string",
                                defvalue=None)
        field2 = simple_property(id_="item2",
                                type_="long",
                                defvalue=None)
        field3 = simple_property(id_="item3",
                                type_="double",
                                defvalue=None)

    struct = struct_property(id_="DCE:ffe634c9-096d-425b-86cc-df1cce50612f", 
                            name="struct_test", 
                            structdef=SomeStruct)

    class MulticastAddress(object):
        ip_address = simple_property(id_="ip_address", type_="string")
        port = simple_property(id_="port", type_="ushort")

        def __init__(self, ip_address="", port=0):
            self.ip_address = ip_address
            self.port = port


    multicasts = structseq_property(id_="DCE:897a5489-f680-46a8-a698-e36fd8bbae80[]",
                                    name="multicasts",
                                    structdef=MulticastAddress,
                                    defvalue=[])

    def __init__(self, identifier, execparams):
        Resource.__init__(self, identifier, execparams)


    def initialize(self):
        Resource.initialize(self)
        self.prop1 = "MyDefault1"
        self.prop2.append("1")
        self.prop2.append("2")
        self.prop2.append("3")

        self.struct.field1 = "StructDefault"
        self.struct.field2 = 100
        self.struct.field3 = 1.0

        self.multicasts.append(TestPythonProps.MulticastAddress("127.0.0.1", 123))
        self.multicasts.append(TestPythonProps.MulticastAddress("127.0.0.1", 456))
        

if __name__ == '__main__':
    logging.getLogger().setLevel(logging.DEBUG)
    start_component(TestPythonProps)
