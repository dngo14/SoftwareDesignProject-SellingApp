#include"react.h"
#include <fstream>
using namespace std;

class Post {
    char *name, *description, *email;

public:
    Post() {
        name = new char [20];
        description = new char [180];
        email = new char[20];
    for (int i = 0; i < 20; i++) {
            name[i] = '0';
    }
    for (int i = 0; i < 180; i++) {
            description[i] = '0';
    }
    for (int i = 0; i < 20; i++) {
            email[i] = '0';
    }
    }

    ~Post() {
        delete [] name;
        delete [] description;
        delete [] email;
    }

    void store() {
        for (int i = 0; i < 20; i++) {
            char v = get_char_at(i);
            if (v!='~') {
                name[i] = v;
            }
        }
        for (int i = 100; i < 280; i++) {
            char v = get_char_at(i);
            if (v!='~') {
                description[i] = v;
            }
        }
        for (int i = 300; i < 320; i++) {
            char v = get_char_at(i);
            if (v!='~') {
                email[i] = v;
            }
        }

        for (int i = 0; i < 320; i++) {
            char v = get_char_at(i);
            if(v!='~') {
                put_char_at(i, '~');
            }
    }

    string s = ""; 
    int i=0;
    while (name[i]!='0') { 
        s = s + name[i]; 
        i++;
    } 
    string d = ""; 
    int j=0;
    while (description[j]!='0') { 
        d = d + description[j]; 
        i++;
    } 
    string e = ""; 
    int k=0;
    while (email[k]!='0') { 
        e = e + email[k]; 
        i++;
    }
    string x = "";
    x = s+".txt";
        ofstream fout(x);
        fout << s << "\n" << d << "\n" << e << "\n";
        fout.close();
    }
 };


int main() {
  init();
  print_at(500, "Success!!");
  if (just_starting()) {
      print_at(0, "");
      print_at(100, "");
      print_at(300, "");
  }
  else if (received_event()) {
      Post p1{};
      p1.store();
      add_yaml("success.yaml");
  }
  add_yaml("input.yaml");

  quit();
}
