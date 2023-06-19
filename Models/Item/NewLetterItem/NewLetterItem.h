//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_NEW_LETTER_ITEM_H
#define CHATBOT_NEW_LETTER_ITEM_H


#include "Item.h"

namespace DDP {
    struct NewLetterItem : Item {
        NewLetterItem();

        void accept(Menu &) override;
    };
}


#endif //CHATBOT_NEW_LETTER_ITEM_H
