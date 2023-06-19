//
// Created by Daniil on 12.06.2023.
//

#include "ReceivedLettersMenu.h"

#include "MainMenu.h"
#include "DatabaseManager.h"
#include <algorithm>
#include "Item.h"
#include "ReceivedLetterFromItem.h"
#include "ApplicationManager.h"

using namespace std;

namespace DDP {
    ReceivedLettersMenu::ReceivedLettersMenu(int userID) : MainMenu(userID, "Received from", {}) {
        Vector<Letter> letters = DatabaseManager::getInstance().getAllLetters();
        int count = count_if(letters.begin(), letters.end(), [userID](Letter & letter)->bool{ return letter.getTo() == userID;});
        Vector<Letter> receivedLetters = Vector<Letter>(count);
        copy_if(letters.begin(), letters.end(), receivedLetters.begin(), [userID](Letter & letter)->bool{ return letter.getTo() == userID;});
        if (receivedLetters.size() == 0)
            return;

        letters_ = receivedLetters;
        Vector<Item *> items;
        for (auto & letter : letters_) {
            auto item = ApplicationManager::getInstance().newReceivedLetterFromItem();
            item->setLetter(letter);
            items.push_back(item);
        }
        this->items = items;
    }


    const Vector<Letter> & ReceivedLettersMenu::getLetters() const { return letters_; }
    void ReceivedLettersMenu::setLetters(const Vector<DDP::Letter> & letters) { letters_ = letters; }
}