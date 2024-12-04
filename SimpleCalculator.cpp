#include<iostream>
using namespace std;
void displayMenu(){
    cout<<"Calculator Menu:\n";
    cout<<"1. Addition\n";
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Division \n";
    cout<<"5. Exit\n";
    cout<<"Choose an option:"; 
}
int main(){
    double num1, num2;
    int choice;
    bool active=true;

    while(active){
        displayMenu();
        cin>> choice;
    
    if(choice >=1 && choice<=4){
        cout<<"Enter first number: ";
        cin>>num1;
        cout<<"Enter second number: ";
        cin>>num2;
    }

switch (choice){
    case 1:
    cout<<"Result:"<< num1 + num2 <<endl;
    break;
    case 2:
    cout<<"Result:"<< num1-num2 <<endl;
    break;
    case 3:
    cout<<"Result:"<< num1*num2<<endl;
    break;
    case 4:
      if(num2!=0)
       {
        cout<<"Result:"<< num1/num2 <<endl;
        }
        else{
            cout<<"Error: Division by zero is not allowed."<<endl;
        }
        break;
    case 5:
    cout<<"Exiting..."<<endl;
    active=false;
    break;
    default:
    cout<<"Invalid choice. Please try again."<<endl;
    break;
  } 
  }
return 0;

}


