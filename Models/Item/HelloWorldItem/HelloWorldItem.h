//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_HELLO_WORLD_ITEM_H
#define TEST_HELLO_WORLD_ITEM_H


#include "Item.h"

namespace DDP {
    struct HelloWorldItem : Item {
        HelloWorldItem();

        void accept(Menu &) override;
    };
}


#endif //TEST_HELLO_WORLD_ITEM_H
