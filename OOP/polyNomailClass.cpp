#include <vector>
#include <climits>
#include <iostream>
using namespace std;
#include "Solution.h"



class Polynomial {

    public:
    int *degCoeff ;      // Name of your array (Don't change this)
    int capcity;
    // Complete the class
    
    Polynomial(){
        degCoeff = new int[100000];
        capcity = 100000;
    }
    
    Polynomial(int *degCoeff, int capcity){
        this->degCoeff = degCoeff;
        this->capcity = capcity;
    }
    
    Polynomial(Polynomial const &poly){

        this -> degCoeff = new int[poly.capcity];
        for(int i = 0; i < poly.capcity; i++){
            this -> degCoeff[i] = poly.degCoeff[i];
        }
        this -> capcity = poly.capcity;
    }

    void operator=(Polynomial const &poly){
        this -> degCoeff = new int[poly.capcity];
        for(int i = 0; i < poly.capcity; i++){
            this -> degCoeff[i] = poly.degCoeff[i];
        }
        this -> capcity = poly.capcity;
    }

    void setCoefficient(int i, int ele){
        if(i > capcity){
            int *newArray = new int[2 * capcity];
            for(int i = 0; i < capcity; i++){
                *(newArray + i) = *(degCoeff + i);
            }
            delete[] degCoeff;
            degCoeff = newArray;
            capcity *= 2;
        }
        degCoeff[i] = ele;
    }
    
    Polynomial operator+(Polynomial const &poly2){
        this->capcity = poly2.capcity;
        
        int *sumPoly = new int[this->capcity];
        int i = 0;
        while(i < this->capcity){
            int sum = degCoeff[i] + poly2.degCoeff[i];
            *(sumPoly + i) = sum;
            i++;
        }

        Polynomial pSum(sumPoly, i);
        return pSum;
    }
    
     Polynomial operator-(Polynomial const &poly2){
        this->capcity = poly2.capcity;
        
        int *subPoly = new int[this->capcity];
        int i = 0;
        while(i < this->capcity){
            int sum = degCoeff[i] - poly2.degCoeff[i];
            *(subPoly + i) = sum;
            i++;
        }

        Polynomial pSub(subPoly, i);
        return pSub;
    }
    
     Polynomial operator*(Polynomial const &poly2){
        this->capcity = poly2.capcity;
        
        int *mutltiPloy = new int[this->capcity * 2];
        int i = 0;
        int totalCoeff = 0;
        while(i < this->capcity){
            int j = 0;
            if(degCoeff[i] != 0 ){
                while(j < poly2.capcity){
                    if(poly2.degCoeff[j] != 0){
                        int multiCoeff = degCoeff[i] * poly2.degCoeff[j];
                        int multiIndex = i + j;
                        if(mutltiPloy[multiIndex] == 0){
                            mutltiPloy[multiIndex] = multiCoeff;
                            totalCoeff++;
                        }
                        else{
                            mutltiPloy[multiIndex] = mutltiPloy[multiIndex] + multiCoeff;
                        }
                    }
                    j++;
                }
            }
            i++;
        }
        int multiCoffSize = totalCoeff * 2;
        Polynomial pMul(mutltiPloy, multiCoffSize);
        return pMul;
    }
    
    void print(){
        for(int i = 0; i < capcity; i++){
            if(*(degCoeff + i) != 0){
                cout<<*(degCoeff + i)<<"x"<<i<<" ";
            }
        }
        cout<<" ";
    }

};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
