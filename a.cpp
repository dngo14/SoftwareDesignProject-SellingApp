#include"react.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

bool enter;
char nstate;

void check_login() {
   string nuser = "";
   string npass = "";
     for (int i = 700; i < 719; ++i) {
              char v;
              v = get_char_at(i);
              if (v!='~' && v!='\0') {
                 nuser+=v;
              }
              else {
                break;
              }
          }
     for (int i = 719; i < 728; ++i) {
         char v;
         v = get_char_at(i);
          if (v!='~' && v!='\0') {
             npass+=v;
              }
            else {
              break;
            }
          }

    for (int i = 700; i < 728; ++i) {
      put_char_at(i, '~');
    }

    print_at(700, "");
    print_at(719, "");

     string username = "UandP.txt";
     ifstream U(username.c_str());
     string user ="";
     string pass ="";
  while (U >> user >> pass) { 
     if (user == nuser && pass == npass) {
       add_yaml("main_page.yaml");
     }
     else {
       if (user != nuser && pass != npass) {
      cerr << "Invalid Input";
    }
     }
 }
}

void read_global() {
    string a = "";
    string b = "";
    string c = "";
    string d = "";
    ofstream fout("Test.txt",ios::app);
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
    fout << a << d << b << c << "\n";
    fout.close();
}


int main() {
  init();
  print_at(3, "S'oled");
  print_at(10, "");
  print_at(19, "");
  print_at(28, "login");
  print_at(40, "post");
  print_at(50, "order");
  print_at(70, "favorites");
  print_at(100, "Item                   Price                  Seller");
  print_at(170, "Post"); 
  print_at(200, "history");
  print_at(210, "likes");
  print_at(240, "Name");
  print_at(250, "Description");
  print_at(262, "Contact Info");
  print_at(275, "My Posts");
  print_at(290, "My Orders");
  print_at(300, "Profile");
  print_at(310, "<< ");
  print_at(314, "Item               Description");
  print_at(350, "profile picture");
  print_at(370, "Success!!");
  print_at(390, "Item");
  print_at(405, "Price");
  print_at(414, "Description");
  print_at(435, "Email");

  

  char state = get_char_at(2);
  if (just_starting()) {
    print_at(700, "");
  print_at(719, "");
    state = '0';
    put_char_at(2, state);
  } else if (received_event()) {
    if (event_id_is("mainpage")) {
      check_login();
  } 
    else if (event_id_is("postpage")) {
      print_at(1000, "");
      print_at(1020, "");
      print_at(1100, "");
      print_at(1300, "");
      state = '2';
      put_char_at(2, state);
    }
    else if (event_id_is("post")) {
      read_global();
      state = '6';
      put_char_at(6, state);

    }
    else if (event_id_is("profilepage")) {
      state = '3';
      put_char_at(2, state);
    }
    else if (event_id_is("order_history_page")) {
      state = '4';
      put_char_at(2, state);
    }
    else if (event_id_is("likespage")) {
      state = '5';
      put_char_at(2, state);
    }
  }

  if ('0' == state) add_yaml("login_page.yaml");
  else if('1' == state) add_yaml("main_page.yaml");
  else if('2' == state) add_yaml("post_page.yaml");
  else if('3'== state) add_yaml("profile_page.yaml");  
  else if('4' == state) add_yaml("history_page.yaml");
  else if('5' == state) add_yaml("likes_pages.yaml");
  else if('6' == state) add_yaml("success.yaml");

  quit();
}
