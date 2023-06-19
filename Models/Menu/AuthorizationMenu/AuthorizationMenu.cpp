//
// Created by Daniil on 11.06.2023.
//

#include <conio.h>
#include "AuthorizationMenu.h"

#include "Key.h"
#include "Color.h"
#include "ApplicationManager.h"

using namespace std;

namespace DDP {


    AuthorizationMenu::AuthorizationMenu() : Menu(
            "Authorization",
            {
                ApplicationManager::getInstance().newSignInItem(),
                ApplicationManager::getInstance().newSignUpItem()
            }
    ) {}



    AuthorizationMenu::AuthorizationMenu(const std::string & name, std::initializer_list<Item *> items) : Menu(name, items) {}

    const std::string &AuthorizationMenu::getLogin() const { return login_; }
    const std::string &AuthorizationMenu::getPassword() const { return password_; }

    void AuthorizationMenu::setLogin(const std::string & login) { login_ = login; }
    void AuthorizationMenu::setPassword(const std::string & password) { password_ = password; }
}