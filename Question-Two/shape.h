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
