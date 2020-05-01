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
            if (get_char_at(i)!='0') {
                name[i] = get_char_at(i);
            }
        }
        for (int i = 100; i < 280; i++) {
            if (get_char_at(i)!='0') {
                description[i] = get_char_at(i);
            }
        }
        for (int i = 300; i < 320; i++) {
            if (get_char_at(i)!='0') {
                email[i] = get_char_at(i);
            }
        }

        for (int i = 0; i < 320; i++) {
            if(get_char_at(i)!='0') {
                put_char_at(i, '0');
            }
    }

    string s = ""; 
    int i=0;
    while (name[i]!='0') { 
        s = s + name[i]; 
        i++;
    } 
        ofstream fout(s+".txt");
        fout << name << "\n" << description << "\n" << email << "\n";
        fout.close();
    }
 };


int main() {
  init();
  if (just_starting()) {
    print_at(0, "");
    print_at(100, "");
    print_at(300, "");
  }
  else if (received_event()) {
      Post p1{};
      p1.store();
  }
  add_yaml("input.yaml");
  quit();
}
