//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_PASSWORD_ITEM_H
#define CHATBOT_PASSWORD_ITEM_H


#include "Item.h"

namespace DDP {
    struct PasswordItem : Item {
        PasswordItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_PASSWORD_ITEM_H
