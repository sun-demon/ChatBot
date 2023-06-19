//
// Created by Daniil on 11.06.2023.
//

#include "NewLetterItem.h"

#include "MainMenu.h"
#include "DatabaseManager.h"
#include "NewLetterMenu.h"

using namespace std;

namespace DDP {
    NewLetterItem::NewLetterItem() : Item("New letter") {}

    void NewLetterItem::accept(Menu & menu) {
        if (DatabaseManager::getInstance().getAllUsers().size() < 2)
            return;
        MainMenu * mainMenu = reinterpret_cast<MainMenu*>(& menu);
        NewLetterMenu(mainMenu->getUserID()).run();
    }
}