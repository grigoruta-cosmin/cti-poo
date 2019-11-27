#include "managementRestaurant.h"

std::istream & operator>>(std::istream &in, ManagementRestaurant &prod){
    in >> prod.size;
    prod.vectorRestaurant.resize(prod.size);
    for(auto &i : prod.vectorRestaurant)
        in >> i;
    return in;
}

std::ostream & operator<<(std::ostream &out, ManagementRestaurant &prod){
    for(auto i : prod.vectorRestaurant)
        out << i;
    return out;
}