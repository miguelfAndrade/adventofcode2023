#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

int getSum(std::vector<std::string> data);

int main() {
    int sum = 0;

    std::string line;
    std::ifstream myfile ("input.txt");

    std::vector<std::string> schem;

    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
            schem.push_back(line);
        }
        myfile.close();

        sum = getSum(schem);
    }
    else std::cout << "Unable to open file" << std::endl; 

    
    std::cout << "SUM RESULT: " << sum << std::endl; 
    
    return 0;
}

int getSum(std::vector<std::string> data) {
    int sum = 0;

    for (std::vector<std::string>::iterator it = data.begin() ; it != data.end(); ++it)
    {
        std::string st = *it;
        for(int i = 0; i != st.length(); ++i)
        {
            if(st[i] != '.' && !std::isdigit(st[i]))
            {

            }
        }

    }

    return sum;
}

int getNumber(std::string line, int i) {
    int number = 0;
    int left = i-3;
    int right = i+3;

    if(i=0)
    {
        return std::stoi(line.substr(i, right));
    }
    if(i=line.length()-1)
    {

        return std::stoi(line.substr(left, i));
    }

    // while()
    // {

    // }
}

int verifyUpBelow(std::string line, int pos) {
    int i = pos-1;
    int length = pos+1;
    if(i < 0) i = 0;
    if(length > line.length()) length = line.length();
    while(i<length)
    {
        if(std::isdigit(line[i]))
        {
            return getNumber(line.substr(), i);
        }
        ++i;
    }
}

