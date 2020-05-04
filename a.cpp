#include"react.h"

int main() {
  init();
  print_at(3, "S'oled");
  print_at(10, "username");
  print_at(19, "password");
  print_at(28, "login");
  print_at(40, "post");
  print_at(50, "order history");
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


  

  char state = get_char_at(2);
  if (just_starting()) {
    state = '0';
    put_char_at(2, state);
  } else if (received_event()) {
    if (event_id_is("mainpage")) {
      state = '1';
      put_char_at(2, state);
  } 
    else if (event_id_is("postpage")) {
      state = '2';
      put_char_at(2, state);
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

  quit();
}
