//
// Created by Daniil on 10.06.2023.
//

#include "Item.h"

#include <utility>

using namespace std;

namespace DDP {
    Item::Item(string name) : name(std::move(name)) {}
    Item::~Item() = default;

    void Item::accept(Menu &) {}

    const std::string & Item::getName() const {
        return name;
    }
    void Item::setName(std::string newName) { this->name = newName; }
}