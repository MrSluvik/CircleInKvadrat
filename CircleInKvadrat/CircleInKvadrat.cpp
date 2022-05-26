// Використовуючи поняття множинного успадкування, розробіть клас «Коло, вписане в квадрат».
#include <iostream>
#include <Windows.h>
using namespace std;

class Circle 
{protected:
   double radius;//радіус кола
public:
    Circle(double radius) {
        this->radius = radius;
    }
    double getR() 
    { 
        return this->radius; 
    }

    double sq()//площа кола
    {        
        return 3.14 * pow(radius, 2);
    }
    double dis()//довжина кола
    {        
        return 2 * 3.14 * radius;
    }

    double diamet()//diametr кола
    {
     return radius * 2;
    }

   ~Circle() {}
};

class Square
{
protected:
    double Side;//сторона квадрата
 public:
    Square(double Side)
    {
        this->Side = Side;
    }

    double getA()
    {
        return this->Side;    
    }
     
    double perimetr() //метод знаходження периметра квадрата 
    {       
        return Side * 4;
    }

    double square() //метод знаходження площі квадрата 
    {
      return pow(Side, 2);
    }

    double diagonal() //метод знаходження діагоналі квадрата 
    {     
        return Side * sqrt(2);
    }

	~Square(){}
};

class CircleInSquare:public Circle,public Square
{
protected:
    double diametr;//кола вписаного в квадрат
public:
    CircleInSquare(double diametr):Circle(radius*2),Square(Side)
    {
        this->diametr = diametr;
        radius = this->diametr / 2;
        Side = this->diametr;
    }

    ~CircleInSquare(){}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CircleInSquare a(4.1);
    cout << "Радіус кола = " << a.getR()<<endl;
    cout << "Діаметр кола = " << a.diamet() << endl;
    cout << "Площа кола " << a.sq() << endl;
    cout << "Довжина кола = " << a.dis()<<"\n" << endl;
    
    cout << "Довжина сторони квадрата = " << a.getA() << endl;
    cout << "Перимет квадрата = " << a.perimetr() << endl;
    cout << "Площа квадрата = " << a.square() << endl;
    cout << "Діагональ квадрата =" << a.diagonal() << endl;
}