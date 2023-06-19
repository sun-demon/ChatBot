//
// Created by Daniil on 11.06.2023.
//

#include "SignInItem.h"

#include "SignInMenu.h"

using namespace std;

namespace DDP {
    SignInItem::SignInItem() : Item("Sign in") {}

    void SignInItem::accept(Menu&) {
        SignInMenu().run();
    }
}