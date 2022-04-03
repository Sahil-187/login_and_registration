#include "records.h"

records::records()
{
    data_file.open("login_data.txt");
    string username, password;
    while (data_file >> username >> password)
    {
        login_data[username] = password;
    }
}
void records::updateLoginData()
{
    for (auto &itr : login_data)
    {
        data_file << itr.first << itr.second << endl;
    }
}
void records::registration()
{
    string name, password;
    bool flag = true;
    while (flag)
    {
    enter_name:
        cout << "Enter Unique UserName : ";
        cin >> name;
        if (login_data.find(name) == login_data.end())
        {
            flag = false;
        }
        else
        {
            int choice;
            cout << "User name is already found \n";
        choice:
            cout << "press 1 to enter another username\npress 2 to exit\n";
            cout << "Enter your choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                goto enter_name;
                break;
            case 2:
                cout << "Leaving registration ... \n";
                return;
            default:
                cout << "Invalid choice , Enter again\n";
                goto choice;
                break;
            }
        }
    }
    cout << "Enter your password\n";
    cin >> password;
    login_data[name] = password;
}
void records::login()
{
    string name, password;
enter_name_login:
    cout << "Enter username : ";
    cin >> name;
    if (login_data.find(name) == login_data.end())
    {
        int choice;
        cout << "User name not found\n";
    choice_login:
        cout << "Enter 1 to try again or enter 2 to exit\n";
        cout << "Enter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            goto enter_name_login;
            break;
        case 2:
            cout << "Leaving login ... \n";
            return;
        default:
            cout << "Invalid choice , Enter again\n";
            goto choice_login;
            break;
        }
    }
    bool flag = false;
    int cnt = 5;
    while(cnt) {
    cout<<"Enter your password "<<5-cnt<<"/5 : ";
    cin >> password ;
    if(login_data[name]==password) {
        break;
    }
    cnt--;
    }
    if(cnt==0) {
        goto enter_name_login ;
    }
    cout<<"login successfull ... \n";
}