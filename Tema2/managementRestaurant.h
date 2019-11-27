#ifndef MANAGEMENT_RESTAURANT
#define MANAGEMENT_RESTAURANT

#include "restaurant.h"

class ManagementRestaurant{
private:
    int size;
    std::vector<Restaurant> vectorRestaurant;
    ManagementRestaurant(){}
    static ManagementRestaurant * Instance;
public:
    static ManagementRestaurant * get_Instance(){
        if(Instance == nullptr){
            Instance = new ManagementRestaurant();
        }
        return Instance;
    }
    friend std::istream & operator>>(std::istream &, ManagementRestaurant &);
    friend std::ostream & operator<<(std::ostream &, ManagementRestaurant &);
    ~ManagementRestaurant(){}
};

// ManagementRestaurant * ManagementRestaurant::Instance = nullptr;
#endif