//
// Created by Daniil on 12.06.2023.
//

#ifndef CHATBOT_MAIN_MENU_H
#define CHATBOT_MAIN_MENU_H


#include "Menu.h"

namespace DDP {
    class MainMenu : public Menu {
    public:
        MainMenu(int);
        MainMenu(int, const std::string &, std::initializer_list<Item *>);

        int getUserID() const;
        void setUserID(int);

    protected:
        int userID_;

    };
}


#endif //CHATBOT_MAIN_MENU_H
