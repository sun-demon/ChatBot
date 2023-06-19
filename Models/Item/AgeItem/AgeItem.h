//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_AGE_ITEM_H
#define CHATBOT_AGE_ITEM_H


#include "Item.h"

namespace DDP {
    struct AgeItem : Item {
        AgeItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_AGE_ITEM_H
