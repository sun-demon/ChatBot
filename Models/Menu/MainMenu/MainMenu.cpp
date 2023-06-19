//
// Created by Daniil on 12.06.2023.
//

#include "MainMenu.h"
#include "SentLettersItem.h"
#include "ReceivedLettersItem.h"
#include "NewLetterItem.h"
#include "ApplicationManager.h"

namespace DDP {
    MainMenu::MainMenu(int userID) : Menu (
            "Main menu",
            {
                ApplicationManager::getInstance().newSentLettersItem(),
                ApplicationManager::getInstance().newReceivedLettersItem(),
                ApplicationManager::getInstance().newNewLetterItem()
            }
    ){ setUserID(userID); }

    MainMenu::MainMenu(int userID, const std::string & name, std::initializer_list<Item *> items) : Menu (name, items) {
        setUserID(userID);
    }

    int MainMenu::getUserID() const { return userID_; }
    void MainMenu::setUserID(int userID) { userID_ = userID; }
}