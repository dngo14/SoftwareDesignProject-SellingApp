#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


int numberoflines() {
    std::ifstream f("Items.txt");
    std::string line;
    int i;
    for (i = 0; std::getline(f, line); ++i)
    ;
    return i;
}



int main()
{
    cout << numberoflines();

    /*
        string item = "";
        string price = "";
        string description = "";
        string email = "";
        string end = "";

        string file = "a.txt";
        ofstream temp;
        ifstream myfile(file.c_str());
        temp.open("temp.txt");
        for (int i = 0; i < 1; i++) {  //pass two line  
                getline(myfile, item, '\0');
                getline(myfile, price, '\0');
                getline(myfile, description, '\0');
                getline(myfile, email, '\0');

        }
                for (int i = 7; i < 8; i++) {  // get the third line          
                getline(myfile, item, '\0');
                getline(myfile, price, '\0');
                getline(myfile, description, '\0');
                getline(myfile, email, '\0');
                temp << item << '\0' <<  price << '\0' << description << '\0' <<  email << '\0';
        }

        
       // cout << "The record with the name " << item << " has been deleted if it exsisted" << endl;
        myfile.close();
        temp.close();
        remove("a.txt");
       rename("temp.txt", "a.txt");
        */
}
