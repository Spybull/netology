#include <iostream>

class Figure
{
    public:
        Figure() : Figure(0, "Figure") {}

        int getSidesCount() {
            return sides_count;
        }

        std::string getName() {
            return name;
        }

        virtual void printInfo() {
            std::cout << name << std::endl;
        }

    protected:
        int sides_count;
        std::string name;

        Figure(int _sides_count, std::string _name)
        : sides_count(_sides_count)
        , name(_name)
        {}

};

class Triangle : public Figure
{
    public:
        Triangle(int a, int b, int c, int A, int B, int C)
        : Figure(3, "Triangle")
        , sides {a, b, c}
        , angles{A, B, C}
        {}

        void printInfo() override
        {
            Figure::printInfo();

            std::cout << "Sides:\t";
            getSides();

            std::cout << "\nAngles:\t";
            getAngles();

            std::cout << "\n\n";
        }

        void getSides()
        {
            int i = 0;
            for(char c='a'; c <= 'c'; ++c && ++i)
                std::cout << c << "=" << sides[i] << " ";
        }

        void getAngles()
        {
            int i = 0;
            for(char c='A'; c <= 'C'; ++c && ++i)
                std::cout << c << "=" << angles[i] << " ";
        }

    protected:
        int sides[3];
        int angles[3];
};

class RightTriangle : public Triangle {
    public:
        RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
            name = "RightTriangle";
        }
};

class IsosTriangle : public Triangle {
    public:
        IsosTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
            name = "Isosceles Triangle";
        }
};

class EquilTriangle : public Triangle {
    public:
        EquilTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
            name = "Equilateral Triangle";
        }
};

class Quadrilateral : public Figure {

    public:
        Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure(4, "Quadrilateral")
        , sides  {a, b, c, d}
        , angles {A, B, C, D}
        {}

        void printInfo() override {
            Figure::printInfo();

            std::cout << "Sides:\t";
            getSides();

            std::cout << "\nAngles:\t";
            getAngles();

            std::cout << "\n\n";
        }

        void getSides() {
            int i = 0;
            for(char c='a'; c <= 'd'; ++c && ++i)
                std::cout << c << "=" << sides[i] << " ";
        }

        void getAngles() {
            int i = 0;
            for(char c='A'; c <= 'D'; ++c && ++i)
                std::cout << c << "=" << angles[i] << " ";
        }

    protected:
        int sides[4];
        int angles[4];
};

class Rectangle : public Quadrilateral {
    public:
        Rectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
            name = "Rectangle";
        }
};

class Square : public Quadrilateral {
    public:
        Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {
            name = "Square";
        }
};

class Parallelogram : public Quadrilateral {
    public:
        Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {
            name = "Parallelogram";
        }
};

class Rhombus : public Quadrilateral {
    public:
        Rhombus(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B) {
            name = "Rhombus";
        }
};

void printInfo(Figure *base) { 
    base->printInfo();
}

int main()
{
    Triangle tri(10, 20, 30, 50, 60, 70);
    RightTriangle riTri(10, 20, 30, 50, 60);
    IsosTriangle  isosTri(10, 20, 50, 60);
    EquilTriangle equTri(30);

    printInfo(&tri);
    printInfo(&riTri);
    printInfo(&isosTri);
    printInfo(&equTri);

    Quadrilateral qua(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rec(10, 20);
    Square squ(20);
    Parallelogram par(20, 30, 30, 40);
    Rhombus rom(30, 30, 40);

    printInfo(&qua);
    printInfo(&rec);
    printInfo(&squ);
    printInfo(&par);
    printInfo(&rom);

    return 0;
}