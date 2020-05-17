#include"react.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Login {
  string nuser;
  string npass;
  string user;
  string pass;
  string file;

public:
  Login () {
  nuser = "";
  npass = "";
  user ="";
  pass ="";
  file = "UandP.txt";
  }

  void check_login() {
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
    ifstream U(file.c_str());
  while (getline(U, user, '\0')) {
     getline(U, pass, '\0'); 
     if (user == nuser && pass == npass) {
       add_yaml("main_page.yaml");
       break;
     }
     }
}
void create_account() {
    ofstream fout("UandP.txt",ios::app);
     for (int i = 730; i < 740; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 user = user+v;
             }
         }
      for (int i = 740; i < 750; i++) {
            char v = get_char_at(i);
            if (v!='~') {
                pass = pass+v;
            }
        }
      fout << user << pass;
      fout.close();

      for (int i = 730; i < 750; ++i) {
      put_char_at(i, '~');
    }
}


};

class Post {
  string item;
  string price;
  string description;
  string email;
  string end;

  public:
    Post() {
     item ="";
     price ="";
     description ="";
     email="";
     end="";
    }

    void display() {
    string username = "Items.txt";
     ifstream dis(username.c_str());
     int i = 2000;
      while (getline(dis, item, '\0')) {
        getline(dis, price, '\0');
        getline(dis, description, '\0');
        getline(dis, email, '\0');
          print_at(i, item);
          print_at(i+20, price);
          print_at(i+100, description);
          print_at(i+280, email);
        i += 300;
        if (getline(dis, end)=="/n") {
          break;
        }
        for (int x = i; x < 8000; x+=300) {
          print_at(x, "");
          print_at(x+20, "");
          print_at(x+100, "");
          print_at(x+280, "");
        }
}
}
void read_global() {
    ofstream fout("Items.txt",ios::app);
             for (int i = 1000; i < 1020; i++) {
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') {
                 item = item+v;
             }
         }
        for (int i = 1020; i < 1040; i++) {
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') {
                 price = price+v;
             }
         }
         for (int i = 1100; i < 1280; i++) {
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') {
                 description = description+v;
             }
         }
         for (int i = 1300; i < 1320; i++) {
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') {
                 email = email+v;
             }
         }
         for (int i = 1000; i < 1320; i++) {
             char v = get_char_at(i);
             if(v!='~') {
                 put_char_at(i, '~');
             }
     }
    fout << item << '\0' << price << '\0' << description << '\0' << email << '\0' << "\n";
    fout.close();
}

void display_nothing() {
  for (int i = 2000; i < 8000; i++) {
    char v = get_char_at(i);
  if (v == '~') {
  print_at(i, "");
  }
  }
}



static int num;

int numberoflines() {
    std::ifstream f("Items.txt");
    std::string line;
    for (num = 0; std::getline(f, line); ++num)
    ;
    return num;

}
void delete_orders(int button_num) {
        string item = "";
        string price = "";
        string description = "";
        string email = "";
        string end = "";

        string file = "Items.txt";
        ofstream temp;
        ifstream myfile(file.c_str());
        temp.open("temp.txt");

        if (button_num==1) {
                item = "";
                price = "";
                description = "";
                email = "";
                temp << item <<  price << description <<  email ;
        }
        for (int i = 0; i < button_num-1; i++) {  //pass two line  

                getline(myfile, item, '\0');
                getline(myfile, price, '\0');
                getline(myfile, description, '\0');
                getline(myfile, email, '\0');
                temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
                 }
                getline(myfile, item, '\0');
                getline(myfile, price, '\0');
                getline(myfile, description, '\0');
                getline(myfile, email, '\0');
        for (int j= button_num; j< numberoflines(); j++) {
                getline(myfile, item, '\0');
                getline(myfile, price, '\0');
                getline(myfile, description, '\0');
                getline(myfile, email, '\0');
                temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";

        }
  
       // cout << "The record with the name " << item << " has been deleted if it exsisted" << endl;
        myfile.close();
        temp.close();
        remove("Items.txt");
       rename("temp.txt", "Items.txt");

}

};

class Orders {
  string item;
  string price;
  string description;
  string email;
  string end;

public:
  Orders() {
    item ="";
    price ="";
    description ="";
    email="";
    end="";
  }

  void store_orders(int x) {
    for (int i = x; i < x+20; i++) {
          char v = get_char_at(i);
          if (v!='~' && v!= '""') {
              item = item+v;
          }
         }
        for (int i = x+20; i < x+40; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 price = price+v;
             }
         }
         for (int i = x+100; i < x+280; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 description = description+v;
             }
         }
         for (int i = x+280; i < x+300; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 email = email+v;
             }
         }
          ofstream fout("Bought.txt",ios::app);
          fout << item << price << description << email << "\n";
          fout.close();
  }

  void display_orders() {
    string username = "Bought.txt";
     ifstream dis(username.c_str());
     int i = 8000;
      while (getline(dis, item, '\0')) {
        getline(dis, price, '\0');
        getline(dis, description, '\0');
        getline(dis, email, '\0');
          print_at(i, item);
          print_at(i+20, price);
          print_at(i+100, description);
          print_at(i+280, email);
        i += 300;
        if (getline(dis, end)=="/n") {
          break;
        }
}
}

void deletemem_orders() {
  for (int i = 8000; i < 10000; i++) {
    char c = get_char_at(i);
    if (c != '~') {
    put_char_at(i, '~');
    }
  }
  for (int i = 8000; i < 10000; i+=300) {
  char v = get_char_at(i);
  if (v == '~') {
  print_at(i, "");
  print_at(i+20, "");
  print_at(i+100, "");
  print_at(i+280, "");
  }
  }
}
};

class Likes {
  string item;
  string price;
  string description;
  string email;
  string end;
  int num;

public:
  Likes() {
    item ="";
    price ="";
    description ="";
    email="";
    end="";
    num = 0;
  }

  void store_likes(int x) {
    for (int i = x; i < x+20; i++) {
          char v = get_char_at(i);
          if (v!='~' && v!= '""') {
              item = item+v;
          }
         }
        for (int i = x+20; i < x+40; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 price = price+v;
             }
         }
         for (int i = x+100; i < x+280; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 description = description+v;
             }
         }
         for (int i = x+280; i < x+300; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 email = email+v;
             }
         }
          ofstream fout("Likes.txt",ios::app);
          fout << item << price << description << email << "\n";
          fout.close();
  }

  void display_likes() {
    string username = "Likes.txt";
     ifstream dis(username.c_str());
     int i = 8000;
      while (getline(dis, item, '\0')) {
        getline(dis, price, '\0');
        getline(dis, description, '\0');
        getline(dis, email, '\0');
          print_at(i, item);
          print_at(i+20, price);
          print_at(i+100, description);
          print_at(i+280, email);
        i += 300;
        if (getline(dis, end)=="/n") {
          break;
        }
}
}

void deletemem_likes() {
  for (int i = 8000; i < 10000; i++) {
    char c = get_char_at(i);
    if (c != '~') {
    put_char_at(i, '~');
    }
  }
  for (int i = 8000; i < 10000; i+=300) {
  char v = get_char_at(i);
  if (v == '~') {
  print_at(i, "");
  print_at(i+20, "");
  print_at(i+100, "");
  print_at(i+280, "");
  }
  }
}
int numberoflines() {
    std::ifstream f("Likes.txt");
    std::string line;
    for (num = 0; std::getline(f, line); ++num)
    ;
    return num;

}

// void delete_like(int botton_num) {
//         string file = "Likes.txt";
//         ofstream temp;
//         ifstream myfile(file.c_str());
//         temp.open("temp.txt");

//         if (botton_num==1) {
//                 item = "";
//                 price = "";
//                 description = "";
//                 email = "";
//                 temp << item <<  price << description <<  email ;
//         }
//         for (int i = 0; i < botton_num-1; i++) {  //pass two line  

//                 getline(myfile, item, '\0');
//                 getline(myfile, price, '\0');
//                 getline(myfile, description, '\0');
//                 getline(myfile, email, '\0');
//                 temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
//                  }
//                 getline(myfile, item, '\0');
//                 getline(myfile, price, '\0');
//                 getline(myfile, description, '\0');
//                 getline(myfile, email, '\0');
//         for (int j= botton_num; j< numberoflines(); j++) {
//                 getline(myfile, item, '\0');
//                 getline(myfile, price, '\0');
//                 getline(myfile, description, '\0');
//                 getline(myfile, email, '\0');
//                 temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
//         }
  
//        // cout << "The record with the name " << item << " has been deleted if it exsisted" << endl;
//         myfile.close();
//         temp.close();
//         remove("Likes.txt");
//        rename("temp.txt", "Likes.txt");
// }
void delete_like(int x) {
    string file = "Likes.txt";
    ofstream temp;
    ifstream myfile(file.c_str());
    temp.open("temp.txt");
    int i = 1;
    string titem;
    string tprice;
    string tdescription;
    string temail;
    string tend;
    if (x > 1) {
    while (i<x && getline(myfile, item, '\0')) {
       getline(myfile, price, '\0');
       getline(myfile, description, '\0');
       getline(myfile, email, '\0');
       getline(myfile, end);
       temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
       i+=1;
    }
      getline(myfile, titem, '\0');
      getline(myfile, tprice, '\0');
      getline(myfile, tdescription, '\0');
      getline(myfile, temail, '\0');
      getline(myfile, tend);
    while(getline(myfile, item, '\0')) {
      getline(myfile, price, '\0');
      getline(myfile, description, '\0');
      getline(myfile, email, '\0');
      getline(myfile, end);
      temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
    }
    }
    else {
      getline(myfile, titem, '\0');
      getline(myfile, tprice, '\0');
      getline(myfile, tdescription, '\0');
      getline(myfile, temail, '\0');
      getline(myfile, tend);
    while(getline(myfile, item, '\0')) {
      getline(myfile, price, '\0');
      getline(myfile, description, '\0');
      getline(myfile, email, '\0');
      getline(myfile, end);
      temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
    }
    }
    myfile.close();
    temp.close();
    remove("Likes.txt");
    rename("temp.txt", "Likes.txt");
    deletemem_likes();
}
};





class User:public Login, public Likes, public Orders {
  bool bexists;
  bool lexists;
  public:
    User() {
      //Bexists();
      //Lexists();
      //if (bexists != false && lexists != false) {
       // std::ofstream bfile ("Bought.txt");
        //std::ofstream lfile ("Likes.txt");
      //}
      //else {

      //}
    }

//   bool Bexists() {
//   ifstream bexists("Bought.txt");
//   return bexists;
// }
//   bool Lexists() {
//   ifstream lexists("Likes.txt");
//   return lexists;
// }


};

int Post::num = 0;

int main() {
  init();
  User Danny{};
  Post Post{};
  print_at(3, "S'oled");
  print_at(10, "");
  print_at(19, "");
  print_at(28, "login");
  print_at(40, "post");
  print_at(50, "order");
  print_at(70, "Likes");
  print_at(100, "Item                   Price                  Seller");
  print_at(170, "Post"); 
  print_at(200, "history");
  print_at(210, "logout");
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
  print_at(445, "username");
  print_at(455, "password");
  print_at(465, "Create");
  print_at(473, "Like");
  print_at(480, "Order");
  print_at(487, "Remove");

  

  char state = get_char_at(2);
  if (just_starting()) {
  print_at(700, "");
  print_at(719, "");
  print_at(730, "");
  print_at(740, "");
  state = '0';
  put_char_at(2, state);
  } else if (received_event()) {
    if (event_id_is("mainpage one")) {
      Danny.check_login();
      Post.display();

    }
    else if (event_id_is("create")) {
      Danny.create_account();
    }
    else if (event_id_is("mainpage")) {
      state = '1';
    put_char_at(2, state);
  }
    else if (event_id_is("postpage")) {
      state = '2';
      put_char_at(2, state);
      print_at(1000, "");
      print_at(1020, "");
      print_at(1100, "");
      print_at(1300, "");

    }
    else if (event_id_is("post")) {
      Post.read_global();
      state = '6';
      put_char_at(6, state);

    }
    else if (event_id_is("profilepage")) {
      state = '3';
      put_char_at(2, state);
      Danny.display_likes();
    }
    else if (event_id_is("order_history_page")) {
      Danny.display_orders();
      state = '4';
      put_char_at(2, state);
    }
    else if (event_id_is("likespage")) {
      state = '5';
      put_char_at(2, state);
    }
    else if (event_id_is("loginpage")) {
      state = '8';
      put_char_at(2, state);
    }
    else if (event_id_is("mainpage")) {
      state = '1';
      put_char_at(2, state);
      Danny.deletemem_likes();

  }
  
    else if (event_id_is("one")) {
      Danny.store_likes(2000);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("two")) {
      Danny.store_likes(2300);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("three")) {
      Danny.store_likes(2600);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("four")) {
      Danny.store_likes(2900);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("five")) {
      Danny.store_likes(3200);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("six")) {
      Danny.store_likes(3500);
      state = '6';
      put_char_at(2, state);
    }
      else if (event_id_is("orderone")) {
      Danny.store_orders(2000);
      Post.delete_orders(1);
      state = '4';
      put_char_at(2, state);
    }else if (event_id_is("ordertwo")) {
      Danny.store_orders(2300);
      Post.delete_orders(2);
      state = '4';
      put_char_at(2, state);
    }else if (event_id_is("orderthree")) {
      Danny.store_orders(2600);
      Post.delete_orders(3);
      state = '4';
      put_char_at(2, state);
    }else if (event_id_is("orderfour")) {
      Danny.store_orders(2900);
      Post.delete_orders(4);
      state = '4';
      put_char_at(2, state);
    }else if (event_id_is("orderfive")) {
      Danny.store_orders(3200);
      Post.delete_orders(5);
      state = '4';
      put_char_at(2, state);
    }else if (event_id_is("ordersix")) {
      Danny.store_orders(3500);
      Post.delete_orders(6);
      state = '4';
      put_char_at(2, state);
    }
    else if (event_id_is("delete_one")) {
      Danny.delete_like(1);
      state = '6';
      put_char_at(2, state);
  }else if (event_id_is("delete_two")) {
      Danny.delete_like(2);
      state = '6';
      put_char_at(2, state);
  }else if (event_id_is("delete_three")) {
      Danny.delete_like(3);
      state = '6';
      put_char_at(2, state);
  }else if (event_id_is("delete_four")) {
      Danny.delete_like(4);
      state = '6';
      put_char_at(2, state);
  }else if (event_id_is("delete_five")) {
      Danny.delete_like(5);
      state = '6';
      put_char_at(2, state);
  }else if (event_id_is("delete_six")) {
      Danny.delete_like(6);
      state = '6';
      put_char_at(2, state);
  }
  }
  

  if ('0' == state) add_yaml("login_page.yaml");
  if ('8' == state) add_yaml("login_page.yaml");
  else if('1' == state) add_yaml("main_page.yaml"), Post.display(), Danny.deletemem_likes();
  else if('2' == state) add_yaml("post_page.yaml");
  else if('3'== state) add_yaml("profile_page.yaml");  
  else if('4' == state) add_yaml("history_page.yaml"), Danny.display_orders();
  else if('5' == state) add_yaml("likes_pages.yaml"), Danny.display_likes();
  else if('6' == state) add_yaml("success.yaml");

  quit();
}
