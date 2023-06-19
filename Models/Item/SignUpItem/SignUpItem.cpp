//
// Created by Daniil on 11.06.2023.
//

#include "SignUpItem.h"

#include "SignUpMenu.h"

using namespace std;

namespace DDP {
    SignUpItem::SignUpItem() : Item("Sign up") {}

    void SignUpItem::accept(Menu&) {
        SignUpMenu().run();
    }
}