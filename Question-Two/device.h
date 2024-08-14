#include "Vector.h" //using Q1 vector
#include "shape.h"  // using Q1 shape

// Device class
class Device
{
public:
    // constructor
    Device();

    void AddShape(Shape &shape);
    void AddDevice(Device &device);

    double EvalVolume();  // find volumes of all shapes
    double EvalSurface(); // find surface areas of all shapes
    double EvalMass();    // find mass of all shapes

private:
    Vector<Shape> m_shapes;   // list of shapes
    Vector<Device> m_devices; // list of devices
};

Device::Device()
{
    m_shapes.Resize(0);
    m_devices.Resize(0);
}

void Device::AddShape(Shape &shape)
{
    m_shapes.PushBack(shape);
}

void Device::AddDevice(Device &device)
{
    m_devices.PushBack(device);
}

double Device::EvalVolume()
{
    double totalVolume = 0.0;

    // sum volume of all shapes
    for (int i = 0; i < m_shapes.GetSize(); ++i)
    {
        totalVolume += m_shapes[i].GetVolume();
    }

    // sum volume of all devices
    for (int i = 0; i < m_devices.GetSize(); ++i)
    {
        totalVolume += m_devices[i].EvalVolume();
    }

    return totalVolume;
}

double Device::EvalSurface()
{
    double totalSurface = 0.0;

    // sum surface area of all shapes
    for (int i = 0; i < m_shapes.GetSize(); ++i)
    {
        totalSurface += m_shapes[i].GetSurfaceArea();
    }

    // sum surface area of all devices
    for (int i = 0; i < m_devices.GetSize(); ++i)
    {
        totalSurface += m_devices[i].EvalSurface();
    }

    return totalSurface;
}

double Device::EvalMass()
{
    double totalMass = 0.0;

    // sum mass of all shapes
    for (int i = 0; i < m_shapes.GetSize(); ++i)
    {
        totalMass += m_shapes[i].EvalMass();
    }

    // sum mass of all devices
    for (int i = 0; i < m_devices.GetSize(); ++i)
    {
        totalMass += m_devices[i].EvalMass();
    }

    return totalMass;
}
