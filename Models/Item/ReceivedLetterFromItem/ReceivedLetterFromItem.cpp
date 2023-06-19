//
// Created by Daniil on 13.06.2023.
//

#include "ReceivedLetterFromItem.h"

#include "DatabaseManager.h"
#include "iostream"
#include "conio.h"

using namespace std;

namespace DDP {
    ReceivedLetterFromItem::ReceivedLetterFromItem(DDP::Letter letter) : Item(""), letter_(letter) {
        User userFrom = DatabaseManager::getInstance().getUserByID(letter.getFrom());
        this->name = userFrom.getSurname() + " " + userFrom.getName();
    }


    void ReceivedLetterFromItem::accept(DDP::Menu &) {
        cout << getLetter().getMessage() << "\r\n\r\n" << getLetter().getDateTime() << flush;
        getch();
    }

    const Letter &ReceivedLetterFromItem::getLetter() const { return letter_; }
    void ReceivedLetterFromItem::setLetter(DDP::Letter letter) { letter_ = letter; }
}