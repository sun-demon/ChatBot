//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_RECEIVED_LETTERS_MENU_H
#define CHATBOT_RECEIVED_LETTERS_MENU_H


#include "MainMenu.h"
#include "Letter.h"
#include "Vector.h"

namespace DDP {
    class ReceivedLettersMenu : public MainMenu {
    public:
        ReceivedLettersMenu(int);

        const Vector<Letter> & getLetters() const;
        void setLetters(const Vector<Letter> & letters);

    private:
        Vector<Letter> letters_ = Vector<Letter>();
    };
}

#endif //CHATBOT_RECEIVED_LETTERS_MENU_H
