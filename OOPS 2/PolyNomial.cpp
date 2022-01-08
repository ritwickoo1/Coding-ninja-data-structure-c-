/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;
class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    
    	// Default Constructor
    	Polynomial(){
            degCoeff = new int[5];
            capacity = 5;
            for(int i = 0; i < 5; i++){
                degCoeff[i] = 0;
            }
        }
    	// Copy Constructor
    	Polynomial(Polynomial const &p){
            capacity = p.capacity;
            degCoeff = new int[capacity];
            for(int i = 0; i < capacity; i++){
                degCoeff[i] = p.degCoeff[i];
            }
        }
    	// Assingnment operator
    	void operator= (Polynomial const &p){
            capacity = p.capacity;
            degCoeff = new int[capacity];
            for(int i = 0; i < capacity; i++){
                degCoeff[i] = p.degCoeff[i];
            }
        }
    	void setCoefficient(int degree,int coeff){
            while(degree >= capacity){
                int *newDegreeCoeff = new int[2*capacity];
                for(int i = 0; i < capacity;i++){
                    newDegreeCoeff[i] = degCoeff[i];
                }
                for(int i = capacity; i < 2*capacity; i++){
                    newDegreeCoeff[i] = 0;
                }
                delete [] degCoeff;
                degCoeff = newDegreeCoeff;
                capacity *=2;
            }
            degCoeff[degree] = coeff;
        }
    	Polynomial operator+(Polynomial &p){
            Polynomial p3;
            int max = capacity > p.capacity?capacity:p.capacity;
            if(max==capacity){
                for(int i = p.capacity; i < capacity; i++){
                    p.setCoefficient(i,0);
                }
            }
            if(max == p.capacity){
                for(int i = capacity;i < p.capacity; i++ ){
                    setCoefficient(i,0);
                }
            }
            for(int i = 0; i < max; i++){
                p3.setCoefficient(i,degCoeff[i]+p.degCoeff[i]);
            }
            return p3;
        }
    	Polynomial operator-(Polynomial &p){
            Polynomial p3;
            int max = capacity > p.capacity?capacity:p.capacity;
            if(max==capacity){
                for(int i = p.capacity; i < capacity; i++){
                    p.setCoefficient(i,0);
                }
            }
            if(max == p.capacity){
                for(int i = capacity;i < p.capacity; i++ ){
                    setCoefficient(i,0);
                }
            }
            for(int i = 0; i < max; i++){
                p3.setCoefficient(i,degCoeff[i]-p.degCoeff[i]);
            }
            return p3;
        }
    	Polynomial operator*(Polynomial const &p) const{
            Polynomial p3;
            int n = capacity + p.capacity-1;
            for(int i = 0 ; i < n; i++){
                p3.setCoefficient(i,0);
            }
            for(int i = 0; i < capacity; i++){
                for(int j = 0; j < p.capacity; j++){
                    int coeff = degCoeff[i]*p.degCoeff[j];
                    int degree = i+j;
                    p3.setCoefficient(degree,coeff+p3.degCoeff[degree]);
                }
            }
            return p3;
        }
    	void print() const{
            for(int i = 0; i < capacity; i++){
                if(degCoeff[i]){
                    cout<<degCoeff[i]<<"x"<<i<<" ";
                }
            }
            cout<<endl;
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
