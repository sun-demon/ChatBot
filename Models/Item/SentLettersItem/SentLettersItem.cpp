//
// Created by Daniil on 11.06.2023.
//

#include "SentLettersItem.h"

#include "MainMenu.h"
#include "DatabaseManager.h"
#include "SentLettersMenu.h"

using namespace std;

namespace DDP {
    SentLettersItem::SentLettersItem() : Item("Sent letters") {}

    void SentLettersItem::accept(Menu & menu) {
        if (DatabaseManager::getInstance().getAllUsers().size() < 2)
            return;
        MainMenu * mainMenu = reinterpret_cast<MainMenu*>(& menu);
        SentLettersMenu(mainMenu->getUserID()).run();
    }
}