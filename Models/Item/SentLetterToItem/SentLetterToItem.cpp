//
// Created by Daniil on 13.06.2023.
//

#include "SentLetterToItem.h"

#include "DatabaseManager.h"
#include "iostream"
#include "conio.h"

using namespace std;

namespace DDP {
    SentLetterToItem::SentLetterToItem(DDP::Letter letter) : Item(""), letter_(letter) {
        User userTo = DatabaseManager::getInstance().getUserByID(letter.getTo());
        this->name = userTo.getSurname() + " " + userTo.getName();
    }


    void SentLetterToItem::accept(DDP::Menu &) {
        cout << getLetter().getMessage() << "\r\n\r\n" << getLetter().getDateTime() << flush;
        getch();
    }

    const Letter & SentLetterToItem::getLetter() const { return letter_; }
    void SentLetterToItem::setLetter(DDP::Letter letter) { letter_ = letter; }
}