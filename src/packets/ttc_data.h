/*
 * ttc_data.h
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
 * \brief TTC data packet definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.4.2
 * 
 * \date 11/04/2019
 * 
 * \defgroup ttc_data TTC Data
 * \ingroup ttc_data
 * \{
 */

#ifndef TTC_DATA_H_
#define TTC_DATA_H_

#include "beacon_data.h"

namespace grs
{

    /**
     * \brief TTC data packet.
     */
    class TTCData: public grs::BeaconData
    {
        public:

            /**
             * \brief Constructor with initialization (overloaded).
             *
             * \param[in] pl is the payload to decode.
             *
             * \return None.
             */
            TTCData(Payload pl);

            /**
             * \brief Decodes the TTC data from a beacon packet payload.
             *
             * \param[in] pl is the payload to decode.
             *
             * \return None.
             */
            void decode(Payload pl);
    };
}

#endif // TTC_DATA_H_

//! \} End of ttc_data group
