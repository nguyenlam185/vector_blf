/*
 * Copyright (C) 2013 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#pragma once

#include "platform.h"

#include "VectorTypes.h"
#include "ObjectHeader2.h"

#include "vector_blf_export.h"

namespace Vector {
namespace BLF {

/**
 * @brief MOST_ETHERNET_PKT_FRAGMENT
 */
class VECTOR_BLF_EXPORT MostEthernetPktFragment : public ObjectHeader2
{
public:
    MostEthernetPktFragment();

    virtual void setObjectSize();

    WORD channel; /**< application channel */
    BYTE dummy1;
    BYTE ackNack; /**< acknowledge code */
    DWORD validMask; /**< bitfield indicating which members have valid data */
    ULONGLONG sourceMacAdr; /**< 48 bit source address */
    ULONGLONG destMacAdr; /**< 48 bit target address */
    BYTE pAck; /**< a preemptive acknowledge code */
    BYTE cAck; /**< CRC acknowledge from the packet receiver(s) to the packet transmitter */
    WORD dummy2;
    DWORD crc; /**< Cyclic Redundancy Check */
    DWORD dataLen; /**< number of transmitted user data bytes */
    DWORD dataLenAnnounced; /**< announced user data length at the start of the transmission */
    DWORD firstDataLen; /**< number of bytes in firstData */
    LPBYTE firstData; /**< variable data */
};

}
}
