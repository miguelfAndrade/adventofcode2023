#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

int getSum(std::vector<std::string> data);
int getNumber(std::string& line, int i, int& newI);
int verifyUpBelow(std::string line, int pos, int& nPos);
int verifyLR(std::string line, int pos);

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
    
    int j = 0;

    for (std::vector<std::string>::iterator it = data.begin() ; it != data.end(); ++it)
    {
        std::string st = *it;
        std::string prevSt = *std::prev(it);
        std::string nextSt = "";
        if(it != std::prev(data.end())) nextSt = *std::next(it);

        for(int i = 0; i < st.length(); ++i)
        {
            int newI = i;
            int n1 = 0;
            int n2 = 0;
            int nPosUp = i;
            int nPosDw = i;
            if(st[i] == '*')
            {
                int ratio = (verifyUpBelow(nextSt, i, nPosUp)*1000) + (verifyUpBelow(prevSt, i, nPosDw)*100) + (verifyLR(st, i-1)*10) + verifyLR(st, i+1);
                int n1 = 0;
                int n2 = 0;
                
                switch (ratio)
                {
                case 11:
                    n1 = getNumber(st, i-1, newI);
                    n2 = getNumber(st, i+1, newI);
                    break;
                case 110:
                    n1 = getNumber(prevSt, nPosDw, newI);
                    n2 = getNumber(st, i-1, newI);
                    break;
                case 101:
                    n1 = getNumber(prevSt, nPosDw, newI);
                    n2 = getNumber(st, i+1, newI);
                    break;
                case 1100:
                    n1 = getNumber(nextSt, nPosUp, newI);
                    n2 = getNumber(prevSt, nPosDw, newI);
                    break;
                case 1010:
                    n1 = getNumber(nextSt, nPosUp, newI);
                    n2 = getNumber(st, i-1, newI);
                    break;
                case 1001:
                    n1 = getNumber(nextSt, nPosUp, newI);
                    n2 = getNumber(st, i+1, newI);
                    break;
                case 1000:
                    n1 = getNumber(nextSt, i-1, newI);
                    n2 = getNumber(nextSt, i+1, newI);
                    break;
                case 100:
                    n1 = getNumber(prevSt, i-1, newI);
                    n2 = getNumber(prevSt, i+1, newI);
                    break;
                default:
                    break;
                }
                sum += n1*n2;
            }
            i = newI;
        }

        int jN = j+1;
        if(jN > data.size()-1) jN = data.size()-1;

        data.at(j) = st;
        data.at(jN) = nextSt;
        j++;

        // std::cout << st << std::endl;
    }

    return sum;
}

int getNumber(std::string& line, int i, int& newI) {
    int number = 0;
    int cursorL = i;
    int cursorR = i;
    int left = i;
    int right = i;

    std::string tmp = line;

    int tries = 0;

    while(tries < 10)
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
            if(cursorL != cursorR)
            {
                number = std::stoi(line.substr(left, right-left));
                newI = right;
                break;
            }
            else number = 0;
        }
        ++tries;
    }

    if(cursorL != cursorR) {
        number = std::stoi(line.substr(left, right-left));

        // std::cout << right << std::endl;
        for(int j=left; j<right;++j) {
            tmp.replace(j, 1, "D");
            
        }
    }
    else number = 0;

    line = tmp;

    newI = right;

    // std::cout << std::endl << line << std::endl;
    // std::cout << "NUMBER: " << number << " i=" << i << std::endl;


    return number;
}

int verifyLR(std::string line, int pos) {
    int i = pos;
    if(i < 0) i = 0;
    if(i >= line.length()) i = line.length()-1;
    if(std::isdigit(line[i])) {
        return 1;
    }

    return 0;
}

int verifyUpBelow(std::string line, int pos, int& nPos) {
    if(line == "") return 0;
    int i = pos-1;
    int length = pos+2;
    if(i < 0) i = 0;
    if(length > line.length()) length = line.length();
    while(i<length)
    {
        if(std::isdigit(line[i]))
        {
            nPos = i;
            return 1;
        }
        ++i;
    }
    return 0;
}

