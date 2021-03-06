/*
 * obdh_data.h
 * 
 * Copyright (C) 2019, Universidade Federal de Santa Catarina.
 * 
 * This file is part of FloripaSat-GRS.
 * 
 * FloripaSat-GRS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * FloripaSat-GRS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FloripaSat-GRS. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief OBDH data packet definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.4.2
 * 
 * \date 10/04/2019
 * 
 * \defgroup obdh_data OBDH Data
 * \ingroup beacon_data
 * \{
 */

#ifndef OBDH_DATA_H_
#define OBDH_DATA_H_

#include "eps_data.h"

namespace grs
{

    /**
     * \brief OBDH data packet.
     */
    class OBDHData: public grs::BeaconData
    {
        public:

            /**
             * \brief Constructor with initialization (overloaded).
             *
             * \param[in] pl is the payload to decode.
             *
             * \return None.
             */
            OBDHData(Payload pl);

            /**
             * \brief Decodes the OBDH data from a beacon packet payload.
             *
             * \param[in] pl is the payload to decode.
             *
             * \return None.
             */
            void decode(Payload pl);
    };
}

#endif // OBDH_DATA_H_

//! \} End of obdh_data group
