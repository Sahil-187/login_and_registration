#include <iostream>
#include <map>
#include <fstream>
#include <string>


using namespace std;
#include "records.cpp"


int main() {
    records a;
    int choice;
    cout<<"Welcome to login and registraion \n";
    while(true){
    cout<<"Enter 1 to Register , 2 to login, 0 to exit\n";
    cout<<"Enter your choice : ";
    cin >> choice ;
    switch (choice)
    {
    case 1:
        a.registration();
        break;
    case 2 :
        a.login();
      break ;
    default:
        a.exit();
        return 0;
    }
    }
    return 0;
}