//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_SIGN_UP_ITEM_H
#define CHATBOT_SIGN_UP_ITEM_H


#include "Item.h"

namespace DDP {
    struct SignUpItem : Item {
        SignUpItem();

        void accept(Menu &) override;
    };
}


#endif //CHATBOT_SIGN_UP_ITEM_H
