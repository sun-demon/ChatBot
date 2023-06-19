//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_SURNAME_ITEM_H
#define CHATBOT_SURNAME_ITEM_H


#include "Item.h"

namespace DDP {
    struct SurnameItem : Item {
        SurnameItem();

        void accept(Menu &) override;
    };
}

#endif //CHATBOT_SURNAME_ITEM_H
