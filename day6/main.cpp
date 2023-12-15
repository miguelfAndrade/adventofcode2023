#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int main() {
    int counter = 0;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
                         
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 
    
    std::cout << "SUM RESULT: " << counter << std::endl; 
    
    return 0;
}