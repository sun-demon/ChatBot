//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_ITEM_H
#define TEST_ITEM_H


#include <iostream>

#include "IConsumer.h"
#include "Menu.h"

namespace DDP {
    class Menu;

    class Item : public IConsumer<Menu&> {
    public:
        Item(std::string);
        virtual ~Item();

        void accept(Menu &) override;

        const std::string & getName() const;
        void setName(std::string);

    protected:
        std::string name;
    };
}

#endif //TEST_ITEM_H
