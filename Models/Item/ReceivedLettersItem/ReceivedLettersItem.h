//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_RECEIVED_LETTERS_ITEM_H
#define CHATBOT_RECEIVED_LETTERS_ITEM_H


#include "Item.h"

namespace DDP {
    struct ReceivedLettersItem : Item {
        ReceivedLettersItem();

        void accept(Menu &) override;
    };
}


#endif //CHATBOT_RECEIVED_LETTERS_ITEM_H
