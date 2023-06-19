//
// Created by Daniil on 12.06.2023.
//

#include "SentLettersMenu.h"

#include "MainMenu.h"
#include "DatabaseManager.h"
#include <algorithm>
#include "Item.h"
#include "ApplicationManager.h"

using namespace std;

namespace DDP {
    SentLettersMenu::SentLettersMenu(int userID) : MainMenu(userID, "Sent from", {}) {
        Vector<Letter> letters = DatabaseManager::getInstance().getAllLetters();
        int count = 0;
        for (auto iter = letters.begin(); iter != letters.end(); ++iter)
            if (iter->getFrom() == userID)
                count++;
        Vector<Letter> sentLetters = Vector<Letter>(count);
        copy_if(letters.begin(), letters.end(), sentLetters.begin(), [userID](Letter & letter)->bool{ return letter.getFrom() == userID;});
        if (sentLetters.size() == 0)
            return;
        else {
            cout << sentLetters.size() << flush;
            getchar();
        }
        setLetters(sentLetters);
        Vector<Item *> items;
        for (auto & letter : letters_) {
            auto item = ApplicationManager::getInstance().newSentLetterToItem();
            item->setLetter(letter);
            items.push_back(item);
        }
        this->items = items;
    }


    const Vector<Letter> & SentLettersMenu::getLetters() const { return letters_; }
    void SentLettersMenu::setLetters(const Vector<DDP::Letter> & letters) { letters_ = letters; }
}