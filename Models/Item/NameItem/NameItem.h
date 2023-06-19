//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_NAME_ITEM_H
#define CHATBOT_NAME_ITEM_H


#include "Item.h"

namespace DDP {
    struct NameItem : Item {
        NameItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_NAME_ITEM_H
