//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_REGISTER_ITEM_H
#define CHATBOT_REGISTER_ITEM_H


#include "Item.h"

namespace DDP {
    struct RegisterItem : Item {
        RegisterItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_REGISTER_ITEM_H
