#include"react.h"
#include <fstream>
using namespace std;
bool enter;
char nstate;

void registerfunc() {
   string nuser = "";
   string npass = "";
     for (int i = 800; i < 819; ++i) {
              char v;
              v = get_char_at(i);
              if (v!='~' && v!='\0') {
                 nuser+=v;
              }
              else {
                break;
              }
          }
     for (int i = 819; i < 828; ++i) {
         char v;
         v = get_char_at(i);
          if (v!='~' && v!='\0') {
             npass+=v;
              }
            else {
              break;
            }
          }

    for (int i = 800; i < 828; ++i) {
      put_char_at(i, '~');
    }

    print_at(800, "");
    print_at(819, "");

     string username = "UandP.txt";
     ifstream U(username.c_str());
     string user ="";
     string pass ="";
  while (U >> user >> pass) { 
     if (user != "" && pass != "") {
       add_yaml("main_page.yaml");
     }
     else {
       cerr << "please choose a username and pass word";
     }
 }
}