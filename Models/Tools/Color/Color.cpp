//
// Created by Daniil on 11.06.2023.
//

#include "Color.h"

using namespace std;

namespace DDP {
    ostream & operator<<(ostream & out, Color color) {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, color);
        return out;
    }
}