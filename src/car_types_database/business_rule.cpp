#include <string>
using namespace std;

#include "gui.h"
#include "car.h"
#include "persistent.h"

void hello_world(void)
{
    string text = "Hello World!\n";
    display_text(text);
}

void print_cars_from_manufacturer(string manufacturer)
{
    string matches = get_cars_from_manufacturer(manufacturer);
    display_text(matches);
}
