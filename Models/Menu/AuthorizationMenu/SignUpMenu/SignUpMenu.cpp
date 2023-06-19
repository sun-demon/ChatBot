//
// Created by Daniil on 12.06.2023.
//

#include "SignUpMenu.h"
#include "LoginItem.h"
#include "PasswordItem.h"
#include "SurnameItem.h"
#include "NameItem.h"
#include "RegisterItem.h"
#include "AgeItem.h"
#include "ApplicationManager.h"

using namespace std;

namespace DDP {
    SignUpMenu::SignUpMenu() : AuthorizationMenu(
            "Sign up",
            {
                    ApplicationManager::getInstance().newLoginItem(),
                    ApplicationManager::getInstance().newPasswordItem(),
                    ApplicationManager::getInstance().newSurnameItem(),
                    ApplicationManager::getInstance().newNameItem(),
                    ApplicationManager::getInstance().newAgeItem(),
                    ApplicationManager::getInstance().newRegisterItem()
            }
    ) {}


    const string & SignUpMenu::getSurname() const { return surname_; }
    const string & SignUpMenu::getName() const { return name_; }
    int SignUpMenu::getAge() const { return age_; }

    void SignUpMenu::setSurname(const std::string & surname) { surname_ = surname; }
    void SignUpMenu::setName(const std::string & name) { name_ = name; }
    void SignUpMenu::setAge(int age) { age_ = age; }
}