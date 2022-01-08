#include <iostream>
using namespace std;
class ComplexNumbers {
    // Complete this class
    private:
    	int real, imaginary;
    public:
    	ComplexNumbers(int real,int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }
    	void plus(ComplexNumbers const &c){
            real = real+ c.real;
            imaginary = imaginary + c.imaginary;
        }
    	void multiply(ComplexNumbers const &c){
            int temp = real;
            real = real* c.real+(-1*(imaginary * c.imaginary));
            imaginary = temp * c.imaginary+c.real*imaginary;
        } 
    	void print(){
            cout<<real<<" + i"<<imaginary<<endl;
        }
};
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}