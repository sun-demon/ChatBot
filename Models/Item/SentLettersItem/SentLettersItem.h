//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_SENT_LETTERS_ITEM_H
#define CHATBOT_SENT_LETTERS_ITEM_H


#include "Item.h"

namespace DDP {
    struct SentLettersItem : Item {
        SentLettersItem();

        void accept(Menu &) override;
    };
}


#endif //CHATBOT_SENT_LETTERS_ITEM_H
