#include"react.h"
#include <fstream>
#include <typeinfo>
using namespace std;

class Post {
  string item;
  string price;
  string description;
  string email;
public:
  Post() {
     string item ="";
     string price ="";
     string description ="";
     string email="";  
  }
  Post(string i, string p, string d, string e) {
    item = i;
    price = p;
    description = d;
    email = e;
  }
};


int main() {
    display();
}

