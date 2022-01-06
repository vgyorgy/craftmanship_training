#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "car.h"
#include "persistent.h"

#define FILE_STORAGE   "db.txt"
#define DELIMITER      '|'

void add_car(Car car)
{
    if (is_car_stored(car) == false)    // prevent duplicates
    {
        ofstream MyFile;
        MyFile.open(FILE_STORAGE, ios_base::app);   // append
        MyFile << car.stringify() << '\n';
        MyFile.close();
    }
}

void remove_car(Car car)
{
    ifstream MyFile_read(FILE_STORAGE);
    string   line;
    string   new_content = "";
    string   car_str     = car.stringify();
    
    // Read file, copy content excluded the removing line:
    while (getline(MyFile_read, line))
    {
        if (line != car_str)
        {
            new_content += line + '\n';
        }
    }
    MyFile_read.close();
    
    // Write copied content to file:
    ofstream MyFile_write(FILE_STORAGE);
    MyFile_write << new_content;
    MyFile_write.close();
}

bool is_car_stored(Car car)
{
    ifstream MyFile(FILE_STORAGE);
    string   line;
    string   car_str = car.stringify();
    bool     stored  = false;
    
    while (getline(MyFile, line))
    {
        if (line == car_str)
        {
            stored = true;
            break;
        }
    }
    
    MyFile.close();
    return(stored);
}

string get_cars_from_manufacturer(string manufacturer)
{
    ifstream MyFile(FILE_STORAGE);
    string   line;
    string   matches = "";
    while (getline(MyFile, line))
    {
        Car car(line);
        if (car.manufacturer == manufacturer)
        {
            matches += car.stringify() + '\n';
        }
    }
    MyFile.close();
    return(matches);
}
