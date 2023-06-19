//
// Created by Daniil on 11.06.2023.
//

#include "RegisterItem.h"

#include "Client.h"
#include "User.h"
#include "ClientException.h"
#include "AuthorizationMenu/SignUpMenu/SignUpMenu.h"
#include "DatabaseManager.h"
#include <algorithm>
#include "MainMenu.h"

using namespace std;

namespace DDP {
    RegisterItem::RegisterItem() : Item("Register") {}

    void RegisterItem::accept(Menu& menu) {
        try {
            auto * signUpMenu = reinterpret_cast<SignUpMenu*>(&menu);
            const string & login = signUpMenu->getLogin();
            const string & password = signUpMenu->getPassword();
            const string & surname = signUpMenu->getSurname();
            const string & name = signUpMenu->getName();
            int age = signUpMenu->getAge();
            Client::checkLogin(login);
            Client::checkPassword(password);
            Client::checkSurname(surname);
            Client::checkName(name);
            Client::checkAge(age);
            Vector<User> & users = DatabaseManager::getInstance().getAllUsers();
            auto iter = find_if(users.begin(), users.end(),
                                [login](const User & user) -> bool {
                return (user.getLogin() == login);
            });
            if (iter == users.end()) {
                User user(login, password, surname, name, age);
                DatabaseManager::getInstance().insertUser(user);
                MainMenu(user.getID()).run();
                return;
            } else {

                signUpMenu->setExceptionMessage("The login is reserved");
                return;
            }
        } catch (ClientException exc) {
            SignUpMenu * signUpMenu = reinterpret_cast<SignUpMenu*>(&menu);
            signUpMenu->setExceptionMessage(exc.what());
            return;
        }
    }
}