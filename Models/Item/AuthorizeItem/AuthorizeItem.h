//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_AUTHORIZE_ITEM_H
#define CHATBOT_AUTHORIZE_ITEM_H


#include "Item.h"

namespace DDP {
    struct AuthorizeItem : Item {
        AuthorizeItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_AUTHORIZE_ITEM_H
