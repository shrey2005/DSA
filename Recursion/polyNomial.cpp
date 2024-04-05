#include <iostream>
#include <vector>
#include <climits>


using namespace std;

class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    int capcity;
    // Complete the class
    
    public:
    Polynomial(){
        degCoeff = new int[10];
        capcity = 10;
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

    // void add(int ele){
    //     // cout<<"Add function called : "<<ele<<" Capcacity : "<<capcity<<" Index  : "<<nextIndex<<endl;
    //     if(nextIndex == capcity){
    //         int *newArray = new int[2 * capcity];
    //         for(int i = 0; i < capcity; i++){
    //             *(newArray + i) = *(degCoeff + i);
    //         }
    //         delete[] degCoeff;
    //         degCoeff = newArray;
    //         capcity *= 2;
    //     }
    //      degCoeff[nextIndex]= ele;
    //      nextIndex++;
    // }

    void setCoefficient(int i, int ele){
        // cout<<" Index : "<<i<<" Elements : "<<ele<<" Capacity : "<<capcity<<endl;
        if(i == capcity){
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
            cout<<"Sum : "<<sum <<endl;
            *(sumPoly + i) = sum;
            i++;
        }
        
        Polynomial pSum(sumPoly, i);
        return pSum;
    }
    
     Polynomial& operator-(Polynomial const &poly2){
        cout<<"This Capcaity : "<<this->capcity<<endl;
        cout<<"Poly 2 capacity : "<<poly2.capcity<<endl;
        this->capcity = poly2.capcity;
        
        int *sumPoly = new int[this->capcity];
        int i = 0;
        while(i < this->capcity){
            int sum = degCoeff[i] - poly2.degCoeff[i];
            cout<<"Sum : "<<sum <<endl;
            *(sumPoly + i) = sum;
            i++;
        }
        delete[] degCoeff;
        degCoeff = sumPoly;
        return *this;
    }
    
     Polynomial& operator*(Polynomial const &poly2){
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
        cout<<"Dynamically created multiplication  : "<<endl;
        int k = 0;
        while(k < totalCoeff){
            cout<<mutltiPloy[k]<<"x"<<k<<" ";
            degCoeff[k] = mutltiPloy[k];
            k++;
        }
        this -> capcity = k;
        
        // Polynomial result = mutltiPloy;
        // return result;
        return *this;
    }
    
    void print(){
        cout<<"Print Array :";
        for(int i = 0; i < capcity; i++){
            if(*(degCoeff + i) != 0){
                cout<<*(degCoeff + i)<<"x"<<i<<" ";
            }
        }
        cout<<" ";
    }

};

//Driver program to test above functions
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
    
    cout<<"First : "<<endl;
    first.print();
    cout<<endl;
    
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
    
    cout<<"Second : "<<endl;
    second.print();
    
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
        //     // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        // case 4 : // Copy constructor
        // {
        //     Polynomial third(first);
        //     if(third.degCoeff == first.degCoeff) {
        //         cout << "false" << endl;
        //     }
        //     else {
        //         cout << "true" << endl;
        //     }
        //     break;
        // }
            
        // case 5 : // Copy assignment operator
        // {
        //     Polynomial fourth(first);
        //     if(fourth.degCoeff == first.degCoeff) {
        //         cout << "false" << endl;
        //     }
        //     else {
        //         cout << "true" << endl;
        //     }
        //     break;
        // }
            
    }
    
    return 0;
}
