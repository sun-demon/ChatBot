//
// Created by Daniil on 11.06.2023.
//

#include "PasswordItem.h"

#include <conio.h>
#include <windows.h>
#include "Color.h"
#include "Client.h"
#include "ClientException.h"
#include "Key.h"
#include "AuthorizationMenu/AuthorizationMenu.h"

using namespace std;

namespace DDP {
    PasswordItem::PasswordItem() : Item("Password") {}

    void PasswordItem::accept(Menu& menu) {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {0, 0};
        string password;
        string exceptionMessage;
        do {
            system("cls");
            pair<Color, Color> colors;
            if (!Client::isValidPassword(password)) {
                colors = {Color::RED, Color::REVERSE_RED};
                exceptionMessage = PasswordException().what();
            } else {
                colors = {Color::DEFAULT, Color::REVERSE};
                exceptionMessage = "";
            }

            cout << colors.first << password << "\r\n\r\n" << colors.second << exceptionMessage << colors.first << flush;

            SetConsoleCursorPosition(handle, position);

            int key = getch();
            switch (key) {
                case Key::ENTER :
                    try {
                        reinterpret_cast<AuthorizationMenu *>(&menu)->setExceptionMessage("");
                        reinterpret_cast<AuthorizationMenu *>(&menu)->setPassword(password);
                    } catch (LoginException & exc) {}
                    return;
                case Key::ESCAPE :
                    return;
                case Key::BACKSPACE :
                    if (position.X != 0) {
                        --position.X;
                        password.erase(position.X, 1);
                    }
                    break;
                default :
                    if (isprint(key))
                        password.insert(position.X++, 1, (char)key);
                    else if (key > 127) {
                        switch(getch()) {
                            case Key::LEFT :
                                position.X = (short) max(0, position.X - 1);
                                break;
                            case Key::RIGHT :
                                if (position.X != password.size())
                                    ++position.X;
                                break;
                        }
                    }
            }
        } while (true);
    }
}