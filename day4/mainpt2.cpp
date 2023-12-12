#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int getPoints(std::string st);
int getDigit(std::string st, int pos, int& newPos);
int getScratchNumber(std::string st, std::vector<int>& cards, int nLine);

int main() {
    int sum = 0;
    std::vector<int> cards(201, 0);
    int countLines = 0;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            countLines++;
            std::cout << line << std::endl; 
            getScratchNumber(line, cards, countLines);
        }
        
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl; 

    for(std::vector<int>::iterator it = cards.begin(); it != cards.end(); ++it) {
        sum += *it;
    }
    
    std::cout << "SUM RESULT: " << sum << std::endl; 
    
    return 0;
}

int getScratchNumber(std::string st, std::vector<int>& cards, int nLine) {
    // std::cout << "LINE: " << st << std::endl; 
    int n = getPoints(st);
    int length = nLine + n;
    for(int i=nLine; i<=length; ++i) {
        cards[i]++;
    }

    return 0;
}

int getPoints(std::string st) {
    st.erase(0, st.find(":")+1);
    
    int n = 0;

    std::size_t found = st.find_first_of("  ");
    while (found!=std::string::npos)
    {
        if(st[found+1] == ' ') {
            st[found+1] = '0';
            found=st.find_first_of(" ",found+2);
        }
        else found=st.find_first_of(" ",found+1);
    }

    std::string nWinning = st.substr(1, st.find("|")-2);
    std::string nHave = st.substr(st.find("|")+2, st.length());

    for(int i=0; i<nWinning.length(); ++i) {
        int nI = getDigit(nWinning, i, i);
        for(int j=0; j<nHave.length(); ++j) {
            int nJ = getDigit(nHave, j, j);
            if(nI == nJ) {
                if(n == 0) {
                    n++;
                }
                else if(n > 0) {
                    n = n*2;
                }
            }
        }  
    }

    // std::cout << "-" << nWinning << "-" << nHave << "-" << std::endl;
    // std::cout << nHave << std::endl;

    return n;
}

int getDigit(std::string st, int pos, int& newPos) {
    std::string l = st.substr(pos, 2);
    newPos = pos+2;
    // std::cout << l << std::endl;
    return std::stoi(l);
}
