#include <iostream>
#include <fstream>
#include <string>

int processLine(std::string line, int lineNumber);
std::string convertStringToNumber(std::string nS, int i, int rl);

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

std::string convertStringToNumber(std::string nS, int i, int rl) {
    std::string n = "";

    int i3 = i;
    int i4 = i;
    int i5 = i;
    int width3 = 3;
    int width4 = 4;
    int width5 = 5;
    
    if(rl) {
        i3 = (i-2);
        i4 = (i-3);
        i5 = (i-4);
        if (i3 < 0) i3 = 0;
        if (i4 < 0) i4 = 0;
        if (i5 < 0) i5 = 0;
    }
    
    if (i3 + width3 > nS.length()) width3 = nS.length() - i3;
    if (i4 + width4 > nS.length()) width4 = nS.length() - i4 - 1;
    if (i5 + width5 > nS.length()) width5 = nS.length() - i5 - 2;

    if(nS.substr(i3, width3) == "one")
    {
        n = "1";
    }
    else if(nS.substr(i3, width3) == "two")
    {
        n = "2";
    }
    else if(nS.substr(i5, width5) == "three")
    {
        n = "3";
    }
    else if(nS.substr(i4, width4) == "four")
    {
        n = "4";
    }
    else if(nS.substr(i4, width4) == "five")
    {
        n = "5";
    }
    else if(nS.substr(i3, width3) == "six")
    {
        n = "6";
    }
    else if(nS.substr(i5, width5) == "seven")
    {
        n = "7";
    }
    else if(nS.substr(i5, width5) == "eight")
    {
        n = "8";
    }
    else if(nS.substr(i4, width4) == "nine")
    {
        n = "9";
    }
    return n;
}

int processLine(std::string line, int lineNumber) {
    int number = 0;
    int i = 0;
    int j = line.length()-1;
    std::string n = "";
    while(i < line.length()) {
        if (std::isdigit(line[i])) {
            n = line[i];
            break;
        }   
        n = convertStringToNumber(line, i, 0);
        if (n != "") {
            break;
        }
        i++;    
    }

    while(j >= 0) {
        if (std::isdigit(line[j])) {
            n += line[j];
            break;
        }
        if (convertStringToNumber(line, j, 1) != "") {
            n += convertStringToNumber(line, j, 1);
            break;
        }
        j--; 
    }

    std::cout << "The digit of the line " << lineNumber << " is: " << n << std::endl; 

    number = std::stoi(n);
    
    return number;
}