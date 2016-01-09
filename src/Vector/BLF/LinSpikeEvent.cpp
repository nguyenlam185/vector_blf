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

#include "LinSpikeEvent.h"

#include <cstring>

namespace Vector {
namespace BLF {

LinSpikeEvent::LinSpikeEvent() :
    ObjectHeader(),
    channel(),
    width(),
    reserved()
{
    objectType = ObjectType::LIN_SPIKE_EVENT;
}

char * LinSpikeEvent::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::read(buffer);

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // width
    size = sizeof(width);
    memcpy((void *) &width, buffer, size);
    buffer += size;

    // reserved
    size = reserved.size();
    memcpy(reserved.data(), buffer, size);
    buffer += size;

    return buffer;
}

char * LinSpikeEvent::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::write(buffer);

    // channel
    size = sizeof(channel);
    memcpy(buffer, (void *) &channel, size);
    buffer += size;

    // width
    size = sizeof(width);
    memcpy(buffer, (void *) &width, size);
    buffer += size;

    // reserved
    size = reserved.size();
    memcpy(buffer, reserved.data(), size);
    buffer += size;

    return buffer;
}

size_t LinSpikeEvent::calculateObjectSize()
{
    size_t size =
        ObjectHeader::calculateObjectSize() +
        sizeof(channel) +
        sizeof(width) +
        reserved.size();

    return size;
}

}
}
