//
// Created by Daniil on 11.06.2023.
//

#include "LetterException.h"

namespace DDP {
    LetterException::LetterException(const std::string &message) : std::invalid_argument(message) {}
}