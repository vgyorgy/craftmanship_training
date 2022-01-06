#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

#include "car.h"
#include "persistent.h"
#include "business_rule.h"

// Test cars:
Car VW_Passat_B4("Volkswagen", "Passat", "B4", 1993, 1997);
Car VW_Polo_I("Volkswagen", "Polo", "I", 1975, 1981);
Car VW_Polo_II("Volkswagen", "Polo", "II", 1981, 1994);
Car VW_Polo_III("Volkswagen", "Polo", "III", 1994, 2001);
Car VW_Polo_IV("Volkswagen", "Polo", "IV", 2001, 2009);
Car VW_Polo_V("Volkswagen", "Polo", "V", 2009, 2017);
Car VW_Polo_VI("Volkswagen", "Polo", "VI", 2017, 2022);
Car Opel_Astra_F("Opel", "Astra", "F", 1996, 2008);

int main(void)
{
    add_car(VW_Passat_B4);
    add_car(VW_Polo_I);
    add_car(VW_Polo_II);
    add_car(VW_Polo_III);
    add_car(VW_Polo_IV);
    add_car(VW_Polo_V);
    add_car(VW_Polo_VI);
    add_car(Opel_Astra_F);
    
    // printf("VW Passat B4 stored: %s\n", is_car_stored(VW_Passat_B4) == true ? "Yes" : "No");
    print_cars_from_manufacturer("Volkswagen");
    remove_car(VW_Passat_B4);
    // printf("VW Passat B4 stored: %s\n", is_car_stored(VW_Passat_B4) == true ? "Yes" : "No");
    sleep(2);
    return(0);
}
