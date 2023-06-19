//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_SIGN_UP_MENU_H
#define CHATBOT_SIGN_UP_MENU_H


#include "AuthorizationMenu/AuthorizationMenu.h"

namespace DDP {
    struct SignUpMenu : AuthorizationMenu {
        SignUpMenu();

        const std::string & getSurname() const;
        const std::string & getName() const;
        int getAge() const;

        void setSurname(const std::string &);
        void setName(const std::string &);
        void setAge(int);

    private:
        std::string surname_;
        std::string name_;
        int age_;
    };
}

#endif //CHATBOT_SIGN_UP_MENU_H
