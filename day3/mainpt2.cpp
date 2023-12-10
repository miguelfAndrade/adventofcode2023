#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

int getSum(std::vector<std::string> data);
int getNumber(std::string line, int i, int& newI);
int verifyUpBelow(std::string line, int pos, int& sPos);
int verifyLR(std::string line, int pos, int& sPos);

int main() {
    int sum = 0;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");

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
        // std::cout << st << std::endl;
        std::string prevSt = *std::prev(it);
        std::string nextSt = "";
        if(it != std::prev(data.end())) nextSt = *std::next(it);

        for(int i = 0; i < st.length(); ++i)
        {
            int newI = i;
            int n1 = 0;
            int n2 = 0;
            int sPos = -1;
            if(st[i] != '.' && std::isdigit(st[i]))
            {
                if(verifyUpBelow(nextSt, i, sPos) || verifyUpBelow(prevSt, i, sPos) || verifyLR(st, i-1, sPos) || verifyLR(st, i+1, sPos))
                {
                    sum += getNumber(st, i, newI);
                }
            }
            i = newI;
        }

    }

    return sum;
}

int getNumber(std::string line, int i, int& newI) {
    int number = 0;
    int cursorL = i;
    int cursorR = i;
    int left = i;
    int right = i;

    int tries = 0;

    while(tries < (line.length()/2))
    {
        if(std::isdigit(line[cursorL]))
        {
            left = cursorL;
            --cursorL;
            if(cursorL <= 0) cursorL = 0;
        }
        if(std::isdigit(line[cursorR]))
        {
            right = cursorR+1;
            ++cursorR;
            if(cursorR >= line.length()) cursorR = line.length()-1;
        }
        if(!std::isdigit(line[cursorL]) && !std::isdigit(line[cursorR])) 
        {
            number = std::stoi(line.substr(left, right-left));
            newI = right;
            break;
        }
        ++tries;
    }

    number = std::stoi(line.substr(left, right-left));
    newI = right;

    std::cout << "NUMBER: " << number << " i=" << i << std::endl;


    return number;
}

int verifyLR(std::string line, int pos, int& sPos) {
    int i = pos;
    if(i < 0) i = 0;
    if(i >= line.length()) i = line.length()-1;
    if(line[i] == '*') {
        sPos = i;
        return 1;
    }

    return 0;
}

int verifyUpBelow(std::string line, int pos, int& sPos) {
    if(line == "") return 0;
    int i = pos-1;
    int length = pos+2;
    if(i < 0) i = 0;
    if(length > line.length()) length = line.length();
    while(i<length)
    {
        if(line[i] == '*')
        {
            sPos = i;
            return 1;
        }
        ++i;
    }
    return 0;
}

