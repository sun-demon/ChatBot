//
// Created by Daniil on 11.06.2023.
//

#include "ReceivedLettersItem.h"

#include "MainMenu.h"
#include "DatabaseManager.h"
#include "ReceivedLettersMenu.h"

using namespace std;

namespace DDP {
    ReceivedLettersItem::ReceivedLettersItem() : Item("Received letters") {}

    void ReceivedLettersItem::accept(Menu & menu) {
        if (DatabaseManager::getInstance().getAllUsers().size() < 2)
            return;
        MainMenu * mainMenu = reinterpret_cast<MainMenu*>(& menu);
        ReceivedLettersMenu(mainMenu->getUserID()).run();
    }
}