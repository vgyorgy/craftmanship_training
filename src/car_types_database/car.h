#ifndef CAR_H
#define CAR_H

typedef int date;

class Car
{
    public:
        string manufacturer;
        string type;
        string subtype;
        date production_start;
        date production_stop;
        string stringify(void);
        Car(void);
        Car(string line);
        Car(string manufacturer, string type, string subtype, int production_start, int production_stop);
};

#endif
