//
// Created by Daniil on 13.06.2023.
//

#ifndef CHATBOT_SENT_LETTER_TO_ITEM_H
#define CHATBOT_SENT_LETTER_TO_ITEM_H


#include "Item.h"
#include "Letter.h"

namespace DDP {
    class SentLetterToItem : public Item {
    public:
        SentLetterToItem(Letter letter = Letter());

        void accept(DDP::Menu &) override;

        const Letter & getLetter() const;
        void setLetter(Letter);

    private:
        Letter letter_;
    };
}

#endif //CHATBOT_SENT_LETTER_TO_ITEM_H
