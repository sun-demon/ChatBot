//
// Created by Daniil on 10.06.2023.
//

#include "Menu.h"

#include <conio.h>
#include <iostream>
#include <utility>

#include "Key.h"
#include "Color.h"
#include "Item.h"

using namespace std;

namespace DDP {
    Menu::Menu(string name, initializer_list<Item *> items) : name(std::move(name)), items(items) {}

    void Menu::run() {
        if (items.size() == 0)
            return;
        startRun:
        system("cls");
        cout << Color::DEFAULT << name << "\r\n\r\n";
        for (int i = 0; i < items.size(); ++i) {
            if (i == currentPosition)
                cout << Color::REVERSE << items[i]->getName() << Color::DEFAULT << "\r\n";
            else
                cout << items[i]->getName() << "\r\n";
        }
        cout << "\r\n\r\n" << Color::REVERSE_RED << exceptionMessage_ << Color::DEFAULT;

        cout << "\e[?25l" << flush;
        do {
            int key = getch();
            switch(key) {
                case Key::ESCAPE :
                    return;
                case Key::ENTER :
                    continueTo:
                    system("cls");
                    cout << "\e[?25h" << flush;
                    items[currentPosition]->accept(*this);
                    goto startRun;
                default :
                    if (key > 127)
                        switch (getch()) {
                            case Key::TOP :
                                if (currentPosition != 0) {
                                    --currentPosition;
                                    goto startRun;
                                }
                                break;
                            case Key::DOWN :
                                if ((currentPosition != items.size()) && ((currentPosition + 1) != items.size())) {
                                    ++currentPosition;
                                    goto startRun;
                                }
                                break;
                            case Key::RIGHT :
                                goto continueTo;
                        }
            }
        } while (true);
    }


    const std::string &Menu::getExceptionMessage() const { return exceptionMessage_; }
    void Menu::setExceptionMessage(const std::string & message) { exceptionMessage_ = message; }

}
