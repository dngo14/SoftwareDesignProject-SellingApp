#include"react.h"
#include <iostream>
using namespace std;
void login() {
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "greg" && userPassword == "dunn")
        {
            cout << "Welcome Greg!\n";
            break;
        }
        else if (userName == "patrick" && userPassword == "dunn")
        {
            cout << "Welcome Patrick!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
}



     

int main() {
  init();
  print_at(3, "S'oled");
  print_at(10, "username");
  print_at(19, "password");
  print_at(28, "login");
char state = get_char_at(2);
  if (just_starting()) {
    state = '0';
    put_char_at(2, state);
  } 
  if ('0' == state) add_yaml("login_page.yaml");
     quit();
}