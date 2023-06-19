//
// Created by Daniil on 10.06.2023.
//

#include "HelloWorldMenu.h"
#include "HelloWorldItem.h"

namespace DDP {
    HelloWorldMenu::HelloWorldMenu() : Menu(
            "Hello world menu",
            {
                new HelloWorldItem(),
                new HelloWorldItem(),
                new HelloWorldItem()
            }
    ) {}
}