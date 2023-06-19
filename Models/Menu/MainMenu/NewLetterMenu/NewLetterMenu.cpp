//
// Created by Daniil on 12.06.2023.
//

#include "NewLetterMenu.h"

#include "MainMenu.h"
#include "DatabaseManager.h"
#include <algorithm>
#include "Item.h"
#include "ApplicationManager.h"

using namespace std;

namespace DDP {
    NewLetterMenu::NewLetterMenu(int userID) : MainMenu(userID, "New to", {}) {
        Vector<User> users = DatabaseManager::getInstance().getAllUsers();
        for (auto iter = users.begin(); iter != users.end(); ++iter) {
            if (iter->getID() == userID) {
                users.erase(iter);
                return;
            }
        }

        users_ = users;

        Vector<Item *> items;
        for (auto & user : users_) {
            auto item = ApplicationManager::getInstance().newNewLetterToItem();
            item->setFrom(userID);
            item->setTo(user.getID());
            item->setName(user.getSurname() + " " + user.getName());
            items.push_back(item);
        }
        this->items = items;
    }

    const Vector<User> & NewLetterMenu::getUsers() const { return users_; }
    void NewLetterMenu::setUsers(const Vector<User> & users) { users_ = users; }
}