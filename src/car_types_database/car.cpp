#include <string>
#include <sstream>      // use string as stream for getline()
using namespace std;

#include "car.h"

// Entity
string Car::stringify(void)
{
    return(this->manufacturer
           + '|'
           + this->type
           + '|'
           + this->subtype
           + '|'
           + to_string(this->production_start) + '|'
           + to_string(this->production_stop));
}

Car::Car(void)
{
    
}

Car::Car(string line)
{
    string production_start_str;
    string production_stop_str;
    
    istringstream line_stream(line);
    getline(line_stream, this->manufacturer, '|');
    getline(line_stream, this->type, '|');
    getline(line_stream, this->subtype, '|');
    getline(line_stream, production_start_str, '|');
    getline(line_stream, production_stop_str, '|');
    this->production_start = stoi(production_start_str);
    this->production_stop  = stoi(production_stop_str);
}

Car::Car(string manufacturer, string type, string subtype, int production_start, int production_stop)
{
    this->manufacturer     = manufacturer;
    this->type             = type;
    this->subtype          = subtype;
    this->production_start = production_start;
    this->production_stop  = production_stop;
}
