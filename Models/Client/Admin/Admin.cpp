//
// Created by Daniil on 10.06.2023.
//

#include "Admin.h"

#include <fstream>

using namespace std;

namespace DDP {
    ostream & Admin::serialize(ostream & out) const {
        string prefix = "Admin";
        size_t prefixSize = prefix.size();

        out.write(prefix.c_str(), (long long)prefixSize + 1);
        Client::serialize(out);
        return out;
    }
    istream & Admin::deserialize(istream & in) {
        string prefix = "Admin";
        size_t prefixSize = prefix.size();
        char buffer[prefixSize + 1];

        in.read(buffer, (long long)prefixSize + 1);
        Client::deserialize(in);
        return in;
    }
}