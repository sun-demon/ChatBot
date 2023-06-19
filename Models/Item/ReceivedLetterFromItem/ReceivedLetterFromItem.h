//
// Created by Daniil on 13.06.2023.
//

#ifndef CHATBOT_RECEIVED_LETTER_FROM_ITEM_H
#define CHATBOT_RECEIVED_LETTER_FROM_ITEM_H


#include "Item.h"
#include "Letter.h"

namespace DDP {
    class ReceivedLetterFromItem : public Item {
    public:
        ReceivedLetterFromItem(Letter letter = Letter());

        void accept(DDP::Menu &) override;

        const Letter & getLetter() const;
        void setLetter(Letter);

    private:
        Letter letter_;
    };
}

#endif //CHATBOT_RECEIVED_LETTER_FROM_ITEM_H
