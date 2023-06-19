//
// Created by Daniil on 11.06.2023.
//

#include "AuthorizeItem.h"

#include "Client.h"
#include "User.h"
#include "ClientException.h"
#include "SignInMenu.h"
#include "DatabaseManager.h"
#include <algorithm>
#include "MainMenu.h"

using namespace std;

namespace DDP {
    AuthorizeItem::AuthorizeItem() : Item("Authorize") {}

    void AuthorizeItem::accept(Menu& menu) {
        try {
            SignInMenu * signInMenu = reinterpret_cast<SignInMenu*>(&menu);
            const string & login = signInMenu->getLogin();
            const string & password = signInMenu->getPassword();
            Client::checkLogin(login);
            Client::checkPassword(password);
            Vector<User> & users = DatabaseManager::getInstance().getAllUsers();
            auto iter = find_if(users.begin(), users.end(),
                                [login, password](const User & user) -> bool {
                return (user.getLogin() == login) && (user.getPassword() == password);
            });
            if (iter == users.end()) {
                signInMenu->setExceptionMessage("Wrong login or password!");
                return;
            } else {
                MainMenu(iter->getID()).run();
                return;
            }
        } catch (ClientException exc) {
            AuthorizationMenu * signInMenu = reinterpret_cast<AuthorizationMenu*>(&menu);
            signInMenu->setExceptionMessage(exc.what());
            return;
        }
    }
}