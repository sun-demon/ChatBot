//
// Created by Daniil on 11.06.2023.
//

#include "AgeItem.h"

#include <conio.h>
#include <windows.h>
#include "Color.h"
#include "Client.h"
#include "ClientException.h"
#include "Key.h"
#include "SignUpMenu.h"

using namespace std;

namespace DDP {
    AgeItem::AgeItem() : Item("Age") {}

    void AgeItem::accept(Menu& menu) {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {0, 0};
        string age;
        string exceptionMessage;
        do {
            system("cls");
            pair<Color, Color> colors;
            if (!Client::isValidAge(atoi(age.c_str()))) {
                colors = {Color::RED, Color::REVERSE_RED};
                exceptionMessage = AgeException().what();
            } else {
                colors = {Color::DEFAULT, Color::REVERSE};
                exceptionMessage = "";
            }

            cout << colors.first << age << "\r\n\r\n" << colors.second << exceptionMessage << colors.first << flush;

            SetConsoleCursorPosition(handle, position);

            int key = getch();
            switch (key) {
                case Key::ENTER :
                    try {
                        reinterpret_cast<AuthorizationMenu *>(&menu)->setExceptionMessage("");
                        reinterpret_cast<SignUpMenu *>(&menu)->setAge(atoi(age.c_str()));
                    } catch (LoginException & exc) {}
                    return;
                case Key::ESCAPE :
                    return;
                case Key::BACKSPACE :
                    if (position.X != 0) {
                        --position.X;
                        age.erase(position.X, 1);
                    }
                    break;
                default :
                    if (isdigit(key) && age.size() < 3)
                        age.insert(position.X++, 1, (char)key);
                    else if (key > 127) {
                        switch(getch()) {
                            case Key::LEFT :
                                position.X = (short) max(0, position.X - 1);
                                break;
                            case Key::RIGHT :
                                if (position.X != age.size())
                                    ++position.X;
                                break;
                        }
                    }
            }
        } while (true);
    }
}