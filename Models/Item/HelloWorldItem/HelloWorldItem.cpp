//
// Created by Daniil on 10.06.2023.
//

#include "HelloWorldItem.h"

#include <conio.h>

using namespace std;

namespace DDP {
    HelloWorldItem::HelloWorldItem() : Item("Hello world") {}

    void HelloWorldItem::accept(Menu&) {
        cout << "Hello, world!" << flush;
        getch();
    }
}