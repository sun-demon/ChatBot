//
// Created by Daniil on 13.06.2023.
//

#ifndef CHATBOT_NEW_LETTER_TO_ITEM_H
#define CHATBOT_NEW_LETTER_TO_ITEM_H


#include "Item.h"

namespace DDP {
    class NewLetterToItem : public Item {
    public:
        NewLetterToItem(int = 0, int = 0);

        void accept(DDP::Menu &) override;

        int getFrom() const;
        int getTo() const;

        void setFrom(int);
        void setTo(int);

    private:
        int from_;
        int to_;
    };
}

#endif //CHATBOT_NEW_LETTER_TO_ITEM_H
