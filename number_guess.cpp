#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
    cout<<"========================================================"<<endl;
    cout<<"=========== welcome the number Guessing Game ========== "<<endl;
    cout<<"========================================================"<<endl;
 //seed the random number generator
 srand(time(0));
 int random_no,user_guess=0;
 cout<<"Enter 1 for easy mode, 2 for normal mode and 3 for hard mode and other key to quit...."<<endl;
 cin>>user_guess;   

 while(user_guess == 1 || user_guess == 2 || user_guess == 3){
    if(user_guess == 1){
        random_no=rand()%10 +1;
        cout<<"You are playing easy mode, numbers range between 1 to 10"<<endl;
    }
    else if(user_guess == 2){
        random_no=rand()%100 +1;
        cout<<"You are playing normal mode, numbers range between 1 to 100"<<endl;
    }
    else{
        random_no=rand()%1000+1;
        cout<<"You are playing hard mode, numbers range between 1 to 1000"<<endl;
    }
    int n;
    cout<<"Chooose a number"<<endl;
    cin>>n;
    while(n!=random_no){
        if(n>random_no){
            cout<<"Your guess is low"<<endl;
        }
        else{
            cout<<"Your guess is high"<<endl;
        }
        cout<<"Choose again "; cin>>n;
    }
    cout<<"Congratulations! You guessed the correct number: "<< random_no <<endl;
    cout<<"Enter 1 for easy mode, 2 for normal mode and 3 for hard mode and any other key to quit"<<endl;
    cin>>user_guess;
 }
 return 0;

}
