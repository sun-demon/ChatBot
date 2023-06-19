//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_NEW_LETTER_MENU_H
#define CHATBOT_NEW_LETTER_MENU_H


#include "MainMenu.h"
#include "User.h"
#include "Vector.h"

namespace DDP {
    class NewLetterMenu : public MainMenu {
    public:
        NewLetterMenu(int);

        const Vector<User> & getUsers() const;
        void setUsers(const Vector<User> & users);

    private:
        Vector<User> users_;
    };
}

#endif //CHATBOT_NEW_LETTER_MENU_H
