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

#ifndef HLK_TERMINAL_LOGGING_HANDLER
#define HLK_TERMINAL_LOGGING_HANDLER

#include "abstractlogginghandler.h"

#include <iostream>

namespace Hlk {

class TerminalLoggingHandler : public AbstractLoggingHandler {
    virtual void write(const std::string &message) override {
        std::cout << message << std::endl;
    }
};

} // namespace Hlk

#endif // HLK_TERMINAL_LOGGING_HANDLER