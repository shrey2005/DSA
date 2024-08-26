#include<iostream>
#include <cmath>
# define M_PI 3.14159265358979323846 
using namespace std;
class Inputs{
    public:
        int length, breadth, height, radius;
    
    void func(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }

    void func(int radius){
        this->radius = radius;
    }

    void func(int length, int breadth, int height){
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
};

class Rectangle : public Inputs{
    public:
        int area(){
            return length * breadth;
        }
};

class Circle : public Inputs {
    public:
        int area() {
            int radiusSq = radius * radius;
            float result = M_PI * radiusSq;
            int intValue2 = static_cast<int>(round(result));
            return intValue2;
        }
};
class Volume : public Inputs{
    public:
        int area(){
            return length * breadth * height;
        }
};

int choice(){
    int ch;
    cin>>ch;
    return ch;
}
int main()
{
    int cho = choice();
    if(cho==1)
    {
        Rectangle obj;
        obj.func(10,20);
        int ans = obj.area();
        cout<<ans;
    }
    else if(cho ==2)
    {
        Circle obj;
        obj.func(7);
        int ans = obj.area();
        cout<<ans;
    }
    else if(cho ==3)
    {
        Volume obj;
        obj.func(10,20,30);
        int ans = obj.area();
        cout<<ans;
    }
}