/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK bulkioInterfaces.
 *
 * REDHAWK bulkioInterfaces is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK bulkioInterfaces is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
#ifndef __bulkio_shmtransport_h
#define __bulkio_shmtransport_h

#include <ossie/PropertyMap.h>
#include <ossie/ProvidesPort.h>
#include <ossie/UsesPort.h>

#include <BulkioTransport.h>

namespace bulkio {

    template <typename PortType>
    class ShmOutputManager : public OutputManager<PortType>
    {
    public:
        ShmOutputManager(OutPort<PortType>* port);

        virtual std::string transportName();

        virtual OutputTransport<PortType>* createUsesTransport(ExtendedCF::NegotiableProvidesPort_ptr port,
                                                               const std::string& connectionId,
                                                               const CF::Properties& properties);
    };

}

#endif // __bulkio_shmtransport_h
