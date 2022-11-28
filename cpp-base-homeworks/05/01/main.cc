#include <iostream>

class Figure
{
    public:
        Figure()
        : sides_count(0)
        , name("Figure")
        {}

        int getSidesCount() {
            return sides_count;
        }

        std::string getName() {
            return name;
        }

    protected:
        int sides_count;
        std::string name;

        Figure(int _sides_count, std::string _name)
        : sides_count(_sides_count)
        , name(_name)
        {}
};

class Triangle : public Figure {
    public:
        Triangle() :Figure(3, "Triangle") {}
};

class Quadrilateral : public Figure {
    public:
        Quadrilateral() : Figure(4, "Quadrilateral") {}
};

int main()
{
    Figure fig;
    Triangle tri;
    Quadrilateral qua;

    std::cout << fig.getName() << ": " << fig.getSidesCount() << std::endl;
    std::cout << tri.getName() << ": " << tri.getSidesCount() << std::endl;
    std::cout << qua.getName() << ": " << qua.getSidesCount() << std::endl;
    return 0;
}