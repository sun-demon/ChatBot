//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_COLOR_H
#define CHATBOT_COLOR_H


#include <windows.h>
#include <ostream>

namespace DDP {
    enum Color : WORD {
        DEFAULT = 0x0f,
        REVERSE = 0xf0,
        RED = 0x04,
        REVERSE_RED = 0x04f,
        GREEN = 0x02,
        REVERSE_GREEN = 0x2f
    };

    std::ostream & operator<<(std::ostream & out, Color color);
}


#endif //CHATBOT_COLOR_H
