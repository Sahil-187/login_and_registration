#ifndef records_h
#define records_h

class records {
private :
map<string,string> login_data;
fstream data_file;
public :
records();
void updateLoginData ();
void registration();
void login();
};
#endif