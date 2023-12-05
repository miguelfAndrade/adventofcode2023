#include <iostream>
#include <fstream>
#include <string>

int processLine(std::string line, int lineNumber);

int main() {
    int sum = 0;

    int lineNumber = 1;

    std::string line;
    std::ifstream myfile ("input.txt");
    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        {
            sum += processLine(line, lineNumber);
            lineNumber++;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl; 

    std::cout << "SUM RESULT: " << sum << std::endl; 
    
    return 0;
}

int processLine(std::string line, int lineNumber) {
    int number = 0;
    int i = 0;
    int j = line.length()-1;
    std::string n = "";
    while(i < line.length()) {
        if (std::isdigit(line[i]))
        {
            n = line[i];
            break;
        }   
        i++;     
    }
    while(j >= 0) {
        if (std::isdigit(line[j]))
        {
            n += line[j];
            break;
        }   
        j--;     
    }

    std::cout << "The digit of the line " << lineNumber << " is: " << n << std::endl; 

    number = std::stoi(n);
    
    return number;
}