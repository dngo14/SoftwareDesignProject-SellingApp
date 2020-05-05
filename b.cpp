#include"react.h"
#include <fstream>
using namespace std;

// class Post {
//     char *name;
//     char *description;
//     char *email;

// public:
//     Post() {
//         name = new char [20];
//         description = new char [180];
//         email = new char[20];
//     for (int i = 0; i < 20; i++) {
//             name[i] = '\0';
//     }
//     for (int i = 0; i < 180; i++) {
//             description[i] = '\0';
//     }
//     for (int i = 0; i < 20; i++) {
//             email[i] = '\0';
//     }
//     }

//     ~Post() {
//         delete [] name;
//         delete [] description;
//         delete [] email;
//     }

//     void store() {
//         for (int i = 0; i < 20; i++) {
//             char v = get_char_at(i);
//             if (v!='~') {
//                 name[i] = v;
//             }
//         }
//         for (int i = 100; i < 280; i++) {
//             char v = get_char_at(i);
//             if (v!='~') {
//                 description[i] = v;
//             }
//         }
//         for (int i = 300; i < 320; i++) {
//             char v = get_char_at(i);
//             if (v!='~') {
//                 email[i] = v;
//             }
//         }

//         for (int i = 0; i < 320; i++) {
//             char v = get_char_at(i);
//             if(v!='~') {
//                 put_char_at(i, '~');
//             }
//     }

//      string s = ""; 
//      int i=0;
//      while (name[i]!='\0') { 
//          s = s + name[i]; 
//          i++;
//      } 
//      string d = ""; 
//      int j=0;
//      while (description[j]!='\0') { 
//          d = d + description[j]; 
//          j++;
//      } 
//      string e = ""; 
//      int k=0;
//      while (email[k]!='\0') { 
//          e = e + email[k]; 
//          k++;
//     }
//     // string x = "";
//     // x = s+".txt";
//     // string s(name);
//     // string d(description);
//     // string e(email);

//         ofstream fout("Test.txt");
//         fout << s << "\n" << d << "\n" << e << "\n";
//         fout.close();
//     }
// };

void read_global() {
    string a = "";
    string b = "";
    string c = "";
    string d = "";
    ofstream fout;
    ifstream fin;
    fin.open("Test.txt");
    fout.open("Test.txt",ios::app);
             for (int i = 1000; i < 1020; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 a = a+v;
             }
         }
        for (int i = 1020; i < 1040; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 d = d+v;
             }
         }
         for (int i = 1100; i < 1280; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 b = b+v;
             }
         }
         for (int i = 1300; i < 1320; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 c = c+v;
             }
         }
         for (int i = 1000; i < 1320; i++) {
             char v = get_char_at(i);
             if(v!='~') {
                 put_char_at(i, '~');
             }
     }
    if(fin.is_open()) {
        fout << a << d << b << c << "\n";
    }
    fin.close();
    fout.close();
}



int main() {
  init();
  print_at(500, "Success!!");
  if (just_starting()) {
      print_at(0, "");
      print_at(100, "");
      print_at(300, "");
  }
  else if (received_event()) {
      read_global();
      add_yaml("success.yaml");
  }
  add_yaml("input.yaml");
  quit();
}
