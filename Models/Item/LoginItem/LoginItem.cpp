//
// Created by Daniil on 11.06.2023.
//

#include "LoginItem.h"

#include <conio.h>
#include <windows.h>
#include "Color.h"
#include "Client.h"
#include "ClientException.h"
#include "Key.h"
#include "AuthorizationMenu.h"

using namespace std;

namespace DDP {
    LoginItem::LoginItem() : Item("Login") {}

    void LoginItem::accept(Menu& menu) {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {0, 0};
        string login;
        string exceptionMessage;
        do {
            system("cls");
            pair<Color, Color> colors;
            if (!Client::isValidLogin(login)) {
                colors = {Color::RED, Color::REVERSE_RED};
                exceptionMessage = LoginException().what();
            } else {
                colors = {Color::DEFAULT, Color::REVERSE};
                exceptionMessage = "";
            }

            cout << colors.first << login << "\r\n\r\n" << colors.second << exceptionMessage << colors.first << flush;

            SetConsoleCursorPosition(handle, position);

            int key = getch();
            switch (key) {
                case Key::ENTER :
                    try {
                        reinterpret_cast<AuthorizationMenu *>(&menu)->setExceptionMessage("");
                        reinterpret_cast<AuthorizationMenu *>(&menu)->setLogin(login);
                    } catch (LoginException & exc) {}
                    return;
                case Key::ESCAPE :
                    return;
                case Key::BACKSPACE :
                    if (position.X != 0) {
                        --position.X;
                        login.erase(position.X, 1);
                    }
                    break;
                default :
                    if (isprint(key))
                        login.insert(position.X++, 1, (char)key);
                    else if (key > 127) {
                        switch(getch()) {
                            case Key::LEFT :
                                position.X = (short) max(0, position.X - 1);
                                break;
                            case Key::RIGHT :
                                if (position.X != login.size())
                                    ++position.X;
                                break;
                        }
                    }
            }
        } while (true);
    }
}