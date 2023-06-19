//
// Created by Daniil on 11.06.2023.
//

#include "SurnameItem.h"

#include <conio.h>
#include <windows.h>
#include "Color.h"
#include "Client.h"
#include "ClientException.h"
#include "Key.h"
#include "SignUpMenu.h"

using namespace std;

namespace DDP {
    SurnameItem::SurnameItem() : Item("Surname") {}

    void SurnameItem::accept(Menu& menu) {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {0, 0};
        string surname;
        string exceptionMessage;
        do {
            system("cls");
            pair<Color, Color> colors;
            if (!Client::isValidSurname(surname)) {
                colors = {Color::RED, Color::REVERSE_RED};
                exceptionMessage = SurnameException().what();
            } else {
                colors = {Color::DEFAULT, Color::REVERSE};
                exceptionMessage = "";
            }

            cout << colors.first << surname << "\r\n\r\n" << colors.second << exceptionMessage << colors.first << flush;

            SetConsoleCursorPosition(handle, position);

            int key = getch();
            switch (key) {
                case Key::ENTER :
                    try {
                        reinterpret_cast<AuthorizationMenu *>(&menu)->setExceptionMessage("");
                        reinterpret_cast<SignUpMenu *>(&menu)->setSurname(surname);
                    } catch (LoginException & exc) {}
                    return;
                case Key::ESCAPE :
                    return;
                case Key::BACKSPACE :
                    if (position.X != 0) {
                        --position.X;
                        surname.erase(position.X, 1);
                    }
                    break;
                default :
                    if (isprint(key))
                        surname.insert(position.X++, 1, (char)key);
                    else if (key > 127) {
                        switch(getch()) {
                            case Key::LEFT :
                                position.X = (short) max(0, position.X - 1);
                                break;
                            case Key::RIGHT :
                                if (position.X != surname.size())
                                    ++position.X;
                                break;
                        }
                    }
            }
        } while (true);
    }
}