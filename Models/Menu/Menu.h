//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_MENU_H
#define TEST_MENU_H


#include "IRunnable.h"
#include "Item.h"
#include "Vector.h"

namespace DDP {
    class Item;

    class Menu : public IRunnable {
    public:
        Menu(std::string, std::initializer_list<Item *>);

        void run() override;

        const std::string & getExceptionMessage() const;
        void setExceptionMessage(const std::string &);

    protected:
        std::string name;
        Vector<Item *> items;
        int currentPosition = 0;
        std::string exceptionMessage_ = "";
    };
}


#endif //TEST_MENU_H
