/******************************************************************************
 * 
 * Copyright (C) 2021 Dmitry Plastinin
 * Contact: uncellon@yandex.ru, uncellon@gmail.com, uncellon@mail.ru
 * 
 * This file is part of the Hlk Logger library.
 * 
 * Hlk Logger is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as pubblished by the
 * Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * Hlk Logger is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more
 * details
 * 
 * You should have received a copy of the GNU Lesset General Public License
 * along with Hlk Logger. If not, see <https://www.gnu.org/licenses/>.
 * 
 *****************************************************************************/

#ifndef HLK_BASIC_MESSAGE_LAYOUT_H
#define HLK_BASIC_MESSAGE_LAYOUT_H

#include <string>

namespace Hlk {

class BasicMessageLayout {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual std::string build(const std::string &prefix, const std::string &message) {
        std::string currentDate = formatCurrentDate(), currentTime = formatCurrentTime();
        return currentDate + " " + currentTime + " [" + prefix + "] - " + message;
    }

    static std::string formatCurrentTime();
    static std::string formatCurrentDate();
};

} // namespace Hlk

#endif // HLK_BASIC_MESSAGE_LAYOUT_H