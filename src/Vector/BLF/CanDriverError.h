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
#include "ObjectHeader.h"

#include "vector_blf_export.h"

namespace Vector {
namespace BLF {

/**
 * @brief CAN_DRIVER_ERROR
 *
 * CAN driver error information for transceiver of a CAN channel.
 */
class VECTOR_BLF_EXPORT CanDriverError : public ObjectHeader
{
public:
    CanDriverError();

    /**
     * @brief application channel
     *
     * CAN channel the driver error information
     * belongs to.
     */
    WORD channel;

    /**
     * @brief # of TX errors
     *
     * Number of transmit errors that occurred in CAN
     * controller for that channel.
     */
    BYTE txErrors;

    /**
     * @brief # of RX errors
     *
     * Number of receive errors that occurred in CAN
     * controller for that channel.
     */
    BYTE rxErrors;

    /**
     * @brief CAN driver error code
     *
     * Error code
     */
    DWORD errorCode;
};

}
}
