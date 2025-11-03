#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Abstract base class for concrete Shape classes
class Shape
{
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};


class CompositeShape
{
private:
        std::vector<Shape*> m_compositeShapes; 
public:
    virtual ~CompositeShape() = default;
    void addShape(Shape &compositeShape)
    {
        m_compositeShapes.push_back(&compositeShape);
    }
    void removeShape(Shape &CompositeShape)
    {
        for(int i = 0; i < m_compositeShapes.size(); ++i)
        {
            if(m_compositeShapes[i] == &CompositeShape)
            {
                m_compositeShapes.erase(m_compositeShapes.begin() + i);
            }
        }
    }
    virtual void draw() const
    {
        for(auto const &m_compositeShape : m_compositeShapes)
        {
            m_compositeShape->draw();
        }
    }
};

// Concrete Shape classes
class Circle : public Shape
{
public:
    explicit Circle(double radius) : m_Radius(radius) {}

    void draw() const override
    {
        cout << "Drawing a circle with radius " << m_Radius << endl;
    }

private:
    double m_Radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : m_Width(width), m_Height(height) {}

    void draw() const override
    {
        cout << "Drawing a rectangle with width " << m_Width << " and height " << m_Height << endl;
    }

private:
    double m_Width;
    double m_Height;
};

class Triangle : public Shape
{
public:
    Triangle(double side1, double side2, double side3) : m_Side1(side1), m_Side2(side2), m_Side3(side3) {}

    void draw() const override
    {
        cout << "Drawing a triangle with sides " << m_Side1 << ", " << m_Side2 << ", and " << m_Side3 << endl;
    }

private:
    double m_Side1;
    double m_Side2;
    double m_Side3;
};

int main()
{
    Circle c(5);
    Rectangle r(10, 20);
    Triangle t(3, 4, 5);

    // Create a composite shape
    CompositeShape cs;
    cs.addShape(c);
    cs.addShape(r);
    cs.addShape(t);

    // Draw the composite shape
    cs.draw();

    // Remove a shape from the composite shape
    cs.removeShape(r);

    // Draw the composite shape again
    cs.draw();

    return 0;
}
