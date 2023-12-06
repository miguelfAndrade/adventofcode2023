#include <iostream>
#include <fstream>
#include <string>

int processLine(std::string line, int lineNumber);
std::string convertStringToNumber(std::string nS);

int biggestNumberWord = 5;

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

std::string convertStringToNumber(std::string nS) {
    std::string n = "";
    // std::cout << nS << std::endl;
    if(nS.find("one")  != std::string::npos)
    {
        n = "1";
    }
    else if(nS.find("two")  != std::string::npos)
    {
        n = "2";
    }
    else if(nS.find("three")  != std::string::npos)
    {
        n = "3";
    }
    else if(nS.find("four")  != std::string::npos)
    {
        n = "4";
    }
    else if(nS.find("five")  != std::string::npos)
    {
        n = "5";
    }
    else if(nS.find("six")  != std::string::npos)
    {
        n = "6";
    }
    else if(nS.find("seven")  != std::string::npos)
    {
        n = "7";
    }
    else if(nS.find("eight")  != std::string::npos)
    {
        n = "8";
    }
    else if(nS.find("nine")  != std::string::npos)
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
    int upperLimit = i + biggestNumberWord;
    int lowerLimit = j - biggestNumberWord;
    while(i < line.length()) {
        upperLimit = biggestNumberWord;   
        if(i+biggestNumberWord >= line.length()-1) {
            upperLimit = line.length()-1;
        }
        if (std::isdigit(line[i])) {
            n = line[i];
            break;
        }   
        if (convertStringToNumber(line.substr(i,upperLimit)) != "") {
            n = convertStringToNumber(line.substr(i,upperLimit));
            break;
        }
        i++;    
    }

    while(j >= 0) {
        lowerLimit = j-biggestNumberWord+1;
        if(lowerLimit <= 0) {
            lowerLimit = 0;
        }
        if (std::isdigit(line[j])) {
            n += line[j];
            break;
        }
        if (convertStringToNumber(line.substr(lowerLimit, biggestNumberWord)) != "") {
            n += convertStringToNumber(line.substr(lowerLimit, biggestNumberWord));
            break;
        }
        j--; 
    }

    std::cout << "The digit of the line " << lineNumber << " is: " << n << std::endl; 

    number = std::stoi(n);
    
    return number;
}