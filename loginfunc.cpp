#include"react.h"
#include <fstream>
using namespace std;
bool enter;
void check_login() {
    bool enter = false;
    ifstream login;
    login.open("UandP.txt");
    string user ="";
    string pass ="";
    for (int i = 10; i < 19; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 user = user+v;
             }
         }
    for (int i = 10; i < 19; i++) {
        char v = get_char_at(i);
         if (v!='~') {
            pass = pass+v;
             }
         }
         string nuser = "";
         string npass = "";
    while (login >> nuser >> npass) {
        if (user == nuser && pass == npass) {
            enter = true;
        }
        else {
            enter = false;
        }
    }
}