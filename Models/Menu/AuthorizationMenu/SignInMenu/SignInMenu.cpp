//
// Created by Daniil on 11.06.2023.
//

#include "SignInMenu.h"
#include "ApplicationManager.h"

namespace DDP {
    SignInMenu::SignInMenu() : AuthorizationMenu(
            "Sign in",
            {
                    ApplicationManager::getInstance().newLoginItem(),
                    ApplicationManager::getInstance().newPasswordItem(),
                    ApplicationManager::getInstance().newAuthorizeItem()
            }
    ) {}
}