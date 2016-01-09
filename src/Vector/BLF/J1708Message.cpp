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

#include "J1708Message.h"

#include <cstring>

namespace Vector {
namespace BLF {

J1708Message::J1708Message() :
    ObjectHeader(),
    channel(),
    dir(),
    reserved1(),
    error(),
    size(),
    data(),
    reserved2()
{
    /* can be one of:
     *   - objectType = ObjectType::J1708_MESSAGE;
     *   - objectType = ObjectType::J1708_VIRTUAL_MSG;
     */
}

char * J1708Message::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::read(buffer);

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy((void *) &dir, buffer, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy((void *) &reserved1, buffer, size);
    buffer += size;

    // error
    size = sizeof(error);
    memcpy((void *) &error, buffer, size);
    buffer += size;

    // size
    size = sizeof(size);
    memcpy((void *) &size, buffer, size);
    buffer += size;

    // data
    size = data.size();
    memcpy(data.data(), buffer, size);
    buffer += size;

    // reserved2
    size = reserved2.size();
    memcpy(reserved2.data(), buffer, size);
    buffer += size;

    return buffer;
}

char * J1708Message::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::write(buffer);

    // channel
    size = sizeof(channel);
    memcpy(buffer, (void *) &channel, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy(buffer, (void *) &dir, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy(buffer, (void *) &reserved1, size);
    buffer += size;

    // error
    size = sizeof(error);
    memcpy(buffer, (void *) &error, size);
    buffer += size;

    // size
    size = sizeof(size);
    memcpy(buffer, (void *) &size, size);
    buffer += size;

    // data
    size = data.size();
    memcpy(buffer, data.data(), size);
    buffer += size;

    // reserved2
    size = reserved2.size();
    memcpy(buffer, reserved2.data(), size);
    buffer += size;

    return buffer;
}

size_t J1708Message::calculateObjectSize()
{
    size_t size_ =
        ObjectHeader::calculateObjectSize() +
        sizeof(channel) +
        sizeof(dir) +
        sizeof(reserved1) +
        sizeof(error) +
        sizeof(size) +
        data.size() +
        reserved2.size();

    return size_;
}

}
}
