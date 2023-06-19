//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_SENT_LETTERS_MENU_H
#define CHATBOT_SENT_LETTERS_MENU_H


#include "MainMenu.h"
#include "Letter.h"
#include "Vector.h"

namespace DDP {
    class SentLettersMenu : public MainMenu {
    public:
        SentLettersMenu(int);

        const Vector<Letter> & getLetters() const;
        void setLetters(const Vector<Letter> & letters);

    private:
        Vector<Letter> letters_ = Vector<Letter>();
    };
}

#endif //CHATBOT_SENT_LETTERS_MENU_H
