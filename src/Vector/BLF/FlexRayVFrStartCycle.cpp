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

#include "FlexRayVFrStartCycle.h"

#include <cstring>

namespace Vector {
namespace BLF {

FlexRayVFrStartCycle::FlexRayVFrStartCycle() :
    ObjectHeader(),
    channel(),
    version(),
    channelMask(),
    dir(),
    cycle(),
    clientIndex(),
    clusterNo(),
    nmSize(),
    dataBytes(),
    reserved1(),
    tag(),
    data(),
    reserved2()
{
    objectType = ObjectType::FR_STARTCYCLE;
}

char * FlexRayVFrStartCycle::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::read(buffer);

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // version
    size = sizeof(version);
    memcpy((void *) &version, buffer, size);
    buffer += size;

    // channelMask
    size = sizeof(channelMask);
    memcpy((void *) &channelMask, buffer, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy((void *) &dir, buffer, size);
    buffer += size;

    // cycle
    size = sizeof(cycle);
    memcpy((void *) &cycle, buffer, size);
    buffer += size;

    // clientIndex
    size = sizeof(clientIndex);
    memcpy((void *) &clientIndex, buffer, size);
    buffer += size;

    // clusterNo
    size = sizeof(clusterNo);
    memcpy((void *) &clusterNo, buffer, size);
    buffer += size;

    // nmSize
    size = sizeof(nmSize);
    memcpy((void *) &nmSize, buffer, size);
    buffer += size;

    // dataBytes
    size = dataBytes.size();
    memcpy(dataBytes.data(), buffer, size);
    buffer += size;

    // reserved1
    size = reserved1.size();
    memcpy(reserved1.data(), buffer, size);
    buffer += size;

    // tag
    size = sizeof(tag);
    memcpy((void *) &tag, buffer, size);
    buffer += size;

    // data
    size = data.size() * sizeof(DWORD);
    memcpy(data.data(), buffer, size);
    buffer += size;

    // reserved2
    size = reserved2.size();
    memcpy(reserved2.data(), buffer, size);
    buffer += size;

    return buffer;
}

char * FlexRayVFrStartCycle::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::write(buffer);

    // channel
    size = sizeof(channel);
    memcpy(buffer, (void *) &channel, size);
    buffer += size;

    // version
    size = sizeof(version);
    memcpy(buffer, (void *) &version, size);
    buffer += size;

    // channelMask
    size = sizeof(channelMask);
    memcpy(buffer, (void *) &channelMask, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy(buffer, (void *) &dir, size);
    buffer += size;

    // cycle
    size = sizeof(cycle);
    memcpy(buffer, (void *) &cycle, size);
    buffer += size;

    // clientIndex
    size = sizeof(clientIndex);
    memcpy(buffer, (void *) &clientIndex, size);
    buffer += size;

    // clusterNo
    size = sizeof(clusterNo);
    memcpy(buffer, (void *) &clusterNo, size);
    buffer += size;

    // nmSize
    size = sizeof(nmSize);
    memcpy(buffer, (void *) &nmSize, size);
    buffer += size;

    // dataBytes
    size = dataBytes.size();
    memcpy(buffer, dataBytes.data(), size);
    buffer += size;

    // reserved1
    size = reserved1.size();
    memcpy(buffer, reserved1.data(), size);
    buffer += size;

    // tag
    size = sizeof(tag);
    memcpy(buffer, (void *) &tag, size);
    buffer += size;

    // data
    size = data.size() * sizeof(DWORD);
    memcpy(buffer, data.data(), size);
    buffer += size;

    // reserved2
    size = reserved2.size();
    memcpy(buffer, reserved2.data(), size);
    buffer += size;

    return buffer;
}

size_t FlexRayVFrStartCycle::calculateObjectSize()
{
    size_t size =
        ObjectHeader::calculateObjectSize() +
        sizeof(channel) +
        sizeof(version) +
        sizeof(channelMask) +
        sizeof(dir) +
        sizeof(cycle) +
        sizeof(clientIndex) +
        sizeof(clusterNo) +
        sizeof(nmSize) +
        dataBytes.size() +
        reserved1.size() +
        sizeof(tag) +
        data.size() * sizeof(DWORD) +
        reserved2.size();

    return size;
}

}
}
