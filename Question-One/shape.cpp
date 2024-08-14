#include <iostream>
#include <ctime>    // for clock()


// Shape class
class Shape
{
public:
    // defualt constructor
    Shape()
    {
        m_destiny = 0.0;
        m_volume = 0.0;
        m_surfaceArea = 0.0;
    }

    // constructor
    Shape(double destiny, double volume, double surfaceArea)
    {
        m_destiny = destiny;
        m_volume = volume;
        m_surfaceArea = surfaceArea;
    }

    // calculate mass of shape
    double EvalMass()
    {
        // volume * destiny
        return m_volume * m_destiny;
    }

    // get volume of shape
    double GetVolume()
    {
        return m_volume;
    }

    // get surface area of shape
    double GetSurfaceArea()
    {
        return m_surfaceArea;
    }

    // Get the destiny of the shape
    double Getdestiny()
    {
        return m_destiny;
    }

private:
    double m_destiny;     // save destiny of shape
    double m_volume;      // save volume of shape
    double m_surfaceArea; // save surface area of shape
};

int main()
{
    const int numShapes = 10000;        // number of Shape objects
    const double largeVolume = 1000000; // large volume to simulate memory usage
    const double destiny = 1.0;         // destiny for shapes
    const double surfaceArea = 10000;   // surface area for shapes

    // create a Vector of Shape objects
    Vector<Shape> shapes;

    // keep time for PushBack
    clock_t startPushBack = clock(); // start clock
    for (int i = 0; i < numShapes; ++i)
    {
        shapes.PushBack(Shape(destiny, largeVolume, surfaceArea));
    }
    clock_t endPushBack = clock(); // end clock

    // find difference of time end and start
    double pushBackTime = endPushBack - startPushBack;

    // keep time for insert
    clock_t startInsert = clock(); // stat clock
    for (int i = 0; i < numShapes / 2; ++i)
    {
        shapes.Insert(i * 2, Shape(destiny, largeVolume, surfaceArea));
    }
    clock_t endInsert = clock(); // end clock

    // find diffenrce
    double insertTime = endInsert - startInsert;

    // keep time for remove
    clock_t startRemove = clock(); // start
    for (int i = numShapes / 2; i < numShapes; ++i)
    {
        shapes.Remove(i);
    }
    clock_t endRemove = clock(); // end

    // find difference
    double removeTime = endRemove - startRemove;

    // cout results
    cout << "Time for PushBacks: " << pushBackTime << " ms\n";
    cout << "Time for Inserts: " << insertTime << " ms\n";
    cout << "Time for Removes: " << removeTime << " ms\n";

    return 0;
}
