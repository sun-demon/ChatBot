//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_AUTHORIZATION_MENU_H
#define CHATBOT_AUTHORIZATION_MENU_H


#include "Menu.h"

namespace DDP {
    class AuthorizationMenu : public Menu {
    public:
        AuthorizationMenu();
        AuthorizationMenu(const std::string &, std::initializer_list<Item*>);

        const std::string & getLogin() const;
        const std::string & getPassword() const;

        void setLogin(const std::string &);
        void setPassword(const std::string &);

    protected:
        std::string login_;
        std::string password_;
    };
}


#endif //CHATBOT_AUTHORIZATION_MENU_H
