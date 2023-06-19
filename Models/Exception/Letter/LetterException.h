//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_LETTER_EXCEPTION_H
#define CHATBOT_LETTER_EXCEPTION_H

#include <stdexcept>

namespace DDP {
    struct LetterException : std::invalid_argument {
        explicit LetterException(const std::string& message = "Letter's message size can't be more than 2047 characters");
    };
}


#endif //CHATBOT_LETTER_EXCEPTION_H
