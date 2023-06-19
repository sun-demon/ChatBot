//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_LOGIN_ITEM_H
#define CHATBOT_LOGIN_ITEM_H


#include "Item.h"

namespace DDP {
    struct LoginItem : Item {
        LoginItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_LOGIN_ITEM_H
