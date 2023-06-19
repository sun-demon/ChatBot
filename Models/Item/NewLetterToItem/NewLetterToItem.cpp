//
// Created by Daniil on 13.06.2023.
//

#include "NewLetterToItem.h"

#include "DatabaseManager.h"

using namespace std;

namespace DDP {
    NewLetterToItem::NewLetterToItem(int from, int to) : Item ("New letter"), from_(from), to_(to) {
        User user = DatabaseManager::getInstance().getUserByID(to);
        this->name = user.getSurname() + " " + user.getName();
    }

    void NewLetterToItem::accept(DDP::Menu &) {
        string message;
        cin >> message;
        Letter letter = Letter(from_, to_, message);
        DatabaseManager::getInstance().insertLetter(letter);
    }

    int NewLetterToItem::getFrom() const { return from_; }
    int NewLetterToItem::getTo() const { return to_; }

    void NewLetterToItem::setFrom(int from) { from_ = from; }
    void NewLetterToItem::setTo(int to) { to_ = to; }


}