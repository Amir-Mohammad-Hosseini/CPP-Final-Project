#include <iostream>
#include "device.h"
using namespace std;

int main()
{
    // create shapes with sample numbers
    Shape cube(1, 2, 3);
    Shape sphere(4, 5, 6);
    Shape cylinder(7, 8, 9);

    // create simple devices
    Device fuelFilter;
    fuelFilter.AddShape(cube);

    Device airFilter;
    airFilter.AddShape(sphere);

    Device oilPump;
    oilPump.AddShape(cylinder);

    // create complex devices
    Device engine;
    engine.AddShape(sphere);
    engine.AddShape(cylinder);
    engine.AddShape(cylinder);
    engine.AddShape(cylinder);
    engine.AddShape(cylinder);

    Device transmission;
    transmission.AddShape(cube);
    transmission.AddShape(cube);
    transmission.AddShape(cube);
    transmission.AddShape(cube);
    transmission.AddShape(cylinder);
    transmission.AddShape(cylinder);
    transmission.AddShape(cylinder);
    transmission.AddShape(cylinder);

    // create a automobile with devices
    Device automobile;
    automobile.AddDevice(fuelFilter);
    automobile.AddDevice(airFilter);
    automobile.AddDevice(oilPump);
    automobile.AddDevice(engine);
    automobile.AddDevice(transmission);

    // add shapes to automobile
    // with sample numbers
    Shape seat(10, 11, 12);
    Shape dashboard(13, 14, 15);
    Shape wheel(16, 17, 18);
    Shape door(19, 20, 21);

    automobile.AddShape(seat);
    automobile.AddShape(seat);
    automobile.AddShape(seat);
    automobile.AddShape(seat);
    automobile.AddShape(dashboard);
    automobile.AddShape(wheel);
    automobile.AddShape(wheel);
    automobile.AddShape(wheel);
    automobile.AddShape(wheel);

    automobile.AddShape(door);
    automobile.AddShape(door);
    automobile.AddShape(door);
    automobile.AddShape(door);

    // find volume, surface area, and mass of automobile
    cout << "Volume of Automobile: " << automobile.EvalVolume() << endl;
    cout << "Surface Area of Automobile: " << automobile.EvalSurface() << endl;
    cout << "Mass of Automobile: " << automobile.EvalMass() << endl;

    return 0;
}
