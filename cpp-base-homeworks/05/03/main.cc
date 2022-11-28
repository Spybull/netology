#include <iostream>

class Figure {
    public:
        Figure() : Figure(0, "Figure") {}

        int getSidesCount() {
            return sides_count;
        }

        virtual void printInfo() {
            
            std::cout << std::endl << name << ":" << std::endl;

            if (check())
                std::cout << "Correct" << std::endl;
            else
                std::cout << "Incorrect" << std::endl;

            std::cout << "Side count: " << sides_count << std::endl;
        }

    protected:
        int sides_count;
        std::string name;

        Figure(int s, std::string _name)
        : sides_count(s)
        , name(_name)
        {}

        virtual bool check() {
            return sides_count == 0 ? true : false;
        }
};

class Triangle : public Figure {

    public:
        Triangle(int a, int b, int c, int A, int B, int C)
        : Figure(3, "Triangle")
        , sides {a, b, c}
        , angles{A, B, C}
        {}

        void printInfo() override {
            Figure::printInfo();

            std::cout << "Sides:\t";
            getSides();

            std::cout << "\nAngles:\t";
            getAngles();

            std::cout << std::endl;
        }

        void getSides() {
            int i = 0;
            for(char c='a'; c <= 'c'; ++c && ++i)
                std::cout << c << "=" << sides[i] << " ";
        }

        void getAngles() {
            int i = 0;
            for(char c='A'; c <= 'C'; ++c && ++i)
                std::cout << c << "=" << angles[i] << " ";
        }

    protected:
        int sides[3];
        int angles[3];

        virtual bool check() override {
            int angles_sum = 0;

            for (int i = 0; i < sides_count; ++i)
                angles_sum += angles[i];

            return sides_count==3 && angles_sum==180 ? true : false;
        }
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

    protected:
        virtual bool check() {
            return true;
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

            std::cout << "\n";
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

        virtual bool check() override {
            int angles_sum = 0;
            for (int i = 0; i < sides_count; ++i)
                angles_sum += angles[i];

            return sides_count== 4 && angles_sum==360 ? true : false;
        }
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
    Figure fig;
    printInfo(&fig);

    /* Triangles */
    Triangle tri(10, 20, 30, 50, 60, 70);
    RightTriangle riTri1(10, 20, 30, 50, 60);
    RightTriangle riTri2(10, 20, 30, 50, 40);
    IsosTriangle isosTri(10, 20, 50, 60);
    EquilTriangle equTri(30);

    printInfo(&tri);
    printInfo(&riTri1);
    printInfo(&riTri2);
    printInfo(&isosTri);
    printInfo(&equTri);
    /* Triangles */

    /* Quadrilateral */
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
    /* Quadrilateral */

    return 0;
}