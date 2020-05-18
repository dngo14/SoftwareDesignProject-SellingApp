#include"react.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Login { //login class to check login of the user
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

  void check_login() { //checks login by looking at what the user type in global mem through a loop
     for (int i = 700; i < 719; ++i) {
              char v;
              v = get_char_at(i);
              if (v!='~' && v!='\0') { //to check if it is a char
                 nuser+=v;
              }
              else {
                break; //breaks loop if there is a ~ or null byte
              }
          }
     for (int i = 719; i < 728; ++i) {
         char v;
         v = get_char_at(i);
          if (v!='~' && v!='\0') { //char check
             npass+=v;
              }
            else {
              break; //breaks loop when it hits a ~ or null byte
            }
          }

    for (int i = 700; i < 728; ++i) { //clears the global mem to be used again
      put_char_at(i, '~'); 
    }

    print_at(700, "");
    print_at(719, "");
    ifstream U(file.c_str()); //makes stream from username and password file
  while (getline(U, user, '\0')) { //compares the username and password to the ones in the UandP.txt by getting them through a while loop
     getline(U, pass, '\0'); 
     if (user == nuser && pass == npass) { //compares the strings
       add_yaml("main_page.yaml");
       break;
     }
  }
  add_yaml("login_failure.yaml");
}
void create_account() { //function to create an account
    ofstream fout("UandP.txt",ios::app); //creates stream to username and password txt
     for (int i = 730; i < 740; i++) {
             char v = get_char_at(i);
             if (v!='~') {
                 user = user+v; //string addition
             }
         }
      for (int i = 740; i < 750; i++) {
            char v = get_char_at(i);
            if (v!='~') {
                pass = pass+v;
            }
        }
      fout << user << pass; //adds what the user typed in the text input in global mem
      fout.close();

      for (int i = 730; i < 750; ++i) { //clears the global mem index where the user regesiters
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

    void display() { //displays the items by getting 4 differents strings
    string username = "Items.txt";
     ifstream dis(username.c_str()); //creates stream from file
     int i = 2000;
      while (getline(dis, item, '\0')) { //gets the lines seperated by null bytes
        getline(dis, price, '\0'); //puts the lines into strings
        getline(dis, description, '\0');
        getline(dis, email, '\0');
          print_at(i, item); //prints them into global mem to be displayed
          print_at(i+20, price);
          print_at(i+100, description);
          print_at(i+280, email);
        i += 300;
        if (getline(dis, end)=="/n") { //if there is a \n it would break the loop
          break;
        }
        for (int x = i; x < 8000; x+=300) { //puts "" at remaining indexes in the display scrollview so it won't display a bunch of ~
          print_at(x, "");
          print_at(x+20, "");
          print_at(x+100, "");
          print_at(x+280, "");
        }
}
}
void read_global() { //reads what the user typed in to make a post
    ofstream fout("Items.txt",ios::app); //makes a stream to the file that holds all of the items
             for (int i = 1000; i < 1020; i++) { //checks each specific index and puts it into a string
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') { //this is to get item name
                 item = item+v;
             }
         }
        for (int i = 1020; i < 1040; i++) {
             char v = get_char_at(i); //since user types at specific indexes, we can get the info at those indexes to store 
             if (v!='~' && v!= '\0') { //this is one is to get item price
                 price = price+v;
             }
         }
         for (int i = 1100; i < 1280; i++) {
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') { // get item description
                 description = description+v;
             }
         }
         for (int i = 1300; i < 1320; i++) {
             char v = get_char_at(i);
             if (v!='~' && v!= '\0') { //get email of the seller
                 email = email+v;
             }
         }
         for (int i = 1000; i < 1320; i++) {
             char v = get_char_at(i);
             if(v!='~') { //clears the global mem
                 put_char_at(i, '~');
             }
     }
    fout << item << '\0' << price << '\0' << description << '\0' << email << '\0' << "\n"; //puts the strings into the file and then a \n
    fout.close();
}

void display_nothing() { //needed to clear global mem from displaying ~
  for (int i = 2000; i < 8000; i+=300) {
    char v = get_char_at(i);
  if (v == '~') {
  print_at(i, "");
  print_at(i+20, ""); //"" are used to make it blank
  print_at(i+100, "");
  print_at(i+280, "");
  }
  }
}
void delete_orders(int x) { // function to delete an item in the txt file when a user press order on that item
    string file = "Items.txt"; 
    ofstream temp; //makes a temp file
    //ofstream bought("Bought.txt",ios::app);
    ifstream myfile(file.c_str()); //makes stream from file
    temp.open("temp.txt"); //opens the temporary file
    int i = 1;
    string titem;
    string tprice;
    string tdescription; //makes trash strings
    string temail;
    string tend;
    if (x > 1) {
    while (i<x && getline(myfile, item, '\0')) { //depending on what item is bought, the loop goes up to the item that is bought in the Item.txt file
       getline(myfile, price, '\0');
       getline(myfile, description, '\0'); 
       getline(myfile, email, '\0');
       getline(myfile, end);
       temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
       i+=1;
    } //loop ends at the item bought
      getline(myfile, titem, '\0'); //puts the item information in trash strings
      getline(myfile, tprice, '\0');
      getline(myfile, tdescription, '\0');
      getline(myfile, temail, '\0');
      getline(myfile, tend);
      //bought << titem << '\0' <<  tprice << '\0' << tdescription << '\0' <<  temail << '\0' << "\n";
    while(getline(myfile, item, '\0')) { //continues to put the other items into the temporary file
      getline(myfile, price, '\0');
      getline(myfile, description, '\0');
      getline(myfile, email, '\0');
      getline(myfile, end);
      temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
    }
    }
    else { //this is used if the first item is bought
      getline(myfile, titem, '\0'); //put item info into trash strings
      getline(myfile, tprice, '\0');
      getline(myfile, tdescription, '\0');
      getline(myfile, temail, '\0');
      getline(myfile, tend);
      //bought << titem << '\0' <<  tprice << '\0' << tdescription << '\0' <<  temail << '\0' << "\n";
    while(getline(myfile, item, '\0')) { //if there are remaining items not bought, puts it into temporary file
      getline(myfile, price, '\0');
      getline(myfile, description, '\0');
      getline(myfile, email, '\0');
      getline(myfile, end);
      temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
    }
    }
    myfile.close();
    temp.close();
    //bought.close();
    remove("Items.txt"); //deletes the Items.txt
    rename("temp.txt", "Items.txt"); //renames the temporary file to Items.txt
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

  void store_orders(int x) { //checks the specific indexes at where the items are displayed
    for (int i = x; i < x+20; i++) { //stores the info of the item bought into strings from global mem
          char v = get_char_at(i);
          if (v!='~' && v!= '""') { //gets item name
              item = item+v;
          }
         }
        for (int i = x+20; i < x+40; i++) {
             char v = get_char_at(i); //gets price
             if (v!='~'&& v!= '""') {
                 price = price+v;
             }
         }
         for (int i = x+100; i < x+280; i++) {
             char v = get_char_at(i); //gets description
             if (v!='~'&& v!= '""') {
                 description = description+v;
             }
         }
         for (int i = x+280; i < x+300; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') { //gets email of the user selling
                 email = email+v;
             }
         }
          ofstream fout("Bought.txt",ios::app); //makes stream to Bought.txt so that it appends
          fout << item << price << description << email << "\n"; //puts items into personal bought.txt
          fout.close();
  }

  void display_orders() { //function to display the orders that you have made
    string username = "Bought.txt"; //makes stream from txt file
     ifstream dis(username.c_str());
     int i = 8000;
      while (getline(dis, item, '\0')) { //reads the lines by seperating them by null bytes
        getline(dis, price, '\0');
        getline(dis, description, '\0');
        getline(dis, email, '\0');
          print_at(i, item);
          print_at(i+20, price);
          print_at(i+100, description); //prints them into global mem at specific indexes for the scrollview to display
          print_at(i+280, email);
        i += 300;
        if (getline(dis, end)=="/n") { //breaks the loop 
          break;
        }
}
}

void deletemem_orders() { //to clear the global mem after you leave you my orders page
  for (int i = 8000; i < 10000; i++) {
    char c = get_char_at(i);
    if (c != '~') {
    put_char_at(i, '~');
    }
  }
  for (int i = 8000; i < 10000; i+=300) { //puts "" so that ~ wont display on the main page
  char v = get_char_at(i);
  if (v == '~') {
  print_at(i, "");
  print_at(i+20, "");
  print_at(i+100, ""); //to make the display blank
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

  void store_likes(int x) { //stores likes by looking at the indexes on the main page
    for (int i = x; i < x+20; i++) {
          char v = get_char_at(i);
          if (v!='~' && v!= '""') { //gets item name
              item = item+v;
          }
         }
        for (int i = x+20; i < x+40; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') { //gets item price
                 price = price+v;
             }
         }
         for (int i = x+100; i < x+280; i++) { //puts them into strings
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') {
                 description = description+v; //gets description
             }
         }
         for (int i = x+280; i < x+300; i++) {
             char v = get_char_at(i);
             if (v!='~'&& v!= '""') { //gets email
                 email = email+v;
             }
         }
          ofstream fout("Likes.txt",ios::app); //stream to file so that it can append
          fout << item << price << description << email << "\n"; //puts the strings into personal Likes.txt followed by "\n"
          fout.close();
  }

  void display_likes() { //displays the likes by creating stream from likes.txt
    string username = "Likes.txt";
     ifstream dis(username.c_str());
     int i = 8000;
      while (getline(dis, item, '\0')) {
        getline(dis, price, '\0');
        getline(dis, description, '\0'); //gets the info by seperating the text by null byte
        getline(dis, email, '\0');
          print_at(i, item);
          print_at(i+20, price);
          print_at(i+100, description); //prints that item info into global to display
          print_at(i+280, email);
        i += 300;
        if (getline(dis, end)=="/n") {
          break;
        }
}
}

void deletemem_likes() { //clears global mem by replacing all chars that are not ~ with ~
  for (int i = 8000; i < 10000; i++) {
    char c = get_char_at(i);
    if (c != '~') {
    put_char_at(i, '~');
    }
  }
  for (int i = 8000; i < 10000; i+=300) { //puts "" at specific places so ~ wont display randomly
  char v = get_char_at(i);
  if (v == '~') {
  print_at(i, "");
  print_at(i+20, "");
  print_at(i+100, ""); //makes display blank and not ~
  print_at(i+280, "");
  }
  }
}

void delete_like(int x) { //deletes like by determining what line the like is on
    string file = "Likes.txt";
    ofstream temp; //creates temporary file
    ifstream myfile(file.c_str()); //makes stream from Likes.txt
    temp.open("temp.txt"); //temporary file
    int i = 1;
    string titem;
    string tprice;
    string tdescription; //makes trash strings
    string temail;
    string tend;
    if (x > 1) {
    while (i<x && getline(myfile, item, '\0')) { //puts favorite items before the removed item into the temporary file
       getline(myfile, price, '\0');
       getline(myfile, description, '\0');
       getline(myfile, email, '\0');
       getline(myfile, end);
       temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
       i+=1;
    }
      getline(myfile, titem, '\0'); //gets to item removed, puts the item info into trash strings
      getline(myfile, tprice, '\0');
      getline(myfile, tdescription, '\0');
      getline(myfile, temail, '\0');
      getline(myfile, tend);
    while(getline(myfile, item, '\0')) { //continues to put remaining liked items into temporary file
      getline(myfile, price, '\0');
      getline(myfile, description, '\0');
      getline(myfile, email, '\0');
      getline(myfile, end);
      temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
    }
    }
    else { //if the item removed is the first item
      getline(myfile, titem, '\0'); //puts item info into trash strings
      getline(myfile, tprice, '\0');
      getline(myfile, tdescription, '\0');
      getline(myfile, temail, '\0');
      getline(myfile, tend);
    while(getline(myfile, item, '\0')) { //continues to put favorite items into temporary file
      getline(myfile, price, '\0');
      getline(myfile, description, '\0');
      getline(myfile, email, '\0');
      getline(myfile, end);
      temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0' << "\n";
    }
    }
    myfile.close();
    temp.close();
    remove("Likes.txt"); //removes personal Likes.txt
    rename("temp.txt", "Likes.txt"); //renames temporary file to personal Likes.txt
    deletemem_likes();
}
};





class User:public Login, public Likes, public Orders { //created when a user logins
  bool bexists;
  bool lexists;
  public:
    User() { //Was in the process of making a function to check if the user has a personal bought and likes text file and if they don't create one
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


int main() {
  init();
  User Danny{}; //creates user object
  Post Post{}; //creates Post object
  print_at(3, "S'oled"); //prints at specific spots in global mem to displat
  print_at(10, "");
  print_at(19, "");
  print_at(28, "Login");
  print_at(40, "Post");
  print_at(50, "My Orders");
  print_at(70, "Likes");
  print_at(100, "Item");
  print_at(110, "Price");
  print_at(120, "Description");
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
  print_at(500, "Incorrect username or passord. Please try it again!");

  

  char state = get_char_at(2); //checks for when the user presses any buttons
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
    else if (event_id_is("myposts")) {
      state = '7';
      put_char_at(2, state);
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
      Post.display_nothing();
      Post.delete_orders(1);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("ordertwo")) {

      Post.delete_orders(2);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("orderthree")) {

      Post.delete_orders(3);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("orderfour")) {
      Post.delete_orders(4);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("orderfive")) {

      Post.delete_orders(5);
      state = '6';
      put_char_at(2, state);
    }else if (event_id_is("ordersix")) {
      Danny.store_orders(3500);
      Post.delete_orders(6);
      state = '6';
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
  
//changes page if the state is changed from the buttons
  if ('0' == state) add_yaml("login_page.yaml");
  if ('8' == state) add_yaml("login_page.yaml");
  else if('1' == state) add_yaml("main_page.yaml"), Post.display(), Danny.deletemem_likes(), Post.display_nothing();
  else if('2' == state) add_yaml("post_page.yaml");
  else if('3'== state) add_yaml("profile_page.yaml");  
  else if('4' == state) add_yaml("history_page.yaml"), Danny.display_orders();
  else if('5' == state) add_yaml("likes_pages.yaml"), Danny.display_likes();
  else if('6' == state) add_yaml("success.yaml");
  else if('7' == state) add_yaml("my_posts.yaml"), Post.display();

  quit();
}
