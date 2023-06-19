//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_LETTER_CONTROLLER_H
#define CHATBOT_LETTER_CONTROLLER_H

#include "Letter.h"
#include "Vector.h"

namespace DDP {
    struct LetterController {
        virtual void insertLetter(Letter &) = 0;
        virtual void deleteLetterByID(int) = 0;
        virtual const Vector<Letter> & getAllLetters() = 0;
        virtual const Letter & getLetterByID(int) = 0;
    };
}

#endif //CHATBOT_LETTER_CONTROLLER_H
