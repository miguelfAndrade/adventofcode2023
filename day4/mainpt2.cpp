#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SIZE 6

int getPoints(std::string st);
int getDigit(std::string st, int pos, int& newPos);

int main() {
    int sum = 0;
    int p = 0;
    int c = 0;
    int n = 0;
    std::vector<int> cards(SIZE, 1);

    std::string line;
    // std::ifstream myfile ("input.txt");
    std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
            p = getPoints(line);
            c++;
            if(p != 0)
            {
                n = c + p;
                if(c > SIZE-1) c = SIZE-1;
                if(n > SIZE-1) n = SIZE;
                for(int i=c; i<n; ++i) {
                    int n2 = cards[c-1]+c;
                    if(n2 > SIZE-1) n2 = SIZE-1;
                    for(int j=c-1; j<n2; ++j) {
                        cards[j]++;
                    }
                    // if(cards[c-1] > 1) {
                    // }
                    // else {
                    //     if(i == n-1) i = n-1;
                    //     cards[i]++;
                    // }
                }
            }
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 

    for(std::vector<int>::iterator it = cards.begin(); it != cards.end(); ++it) {
        sum += *it;
        std::cout << *it << std::endl;
    }

    
    std::cout << "SUM RESULT: " << sum << std::endl; 
    
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
                n++;
                // continue;
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

