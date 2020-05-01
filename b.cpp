#include"react.h"


int main() {
  init();
  if (just_starting()) {
    print_at(0, "");
  }
  else if (received_event()) {

  }
  add_yaml("input.yaml");
  quit();
}
