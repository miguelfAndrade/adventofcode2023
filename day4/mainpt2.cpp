#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SIZE 201
// #define SIZE 6

int getPoints(std::string st);
int getDigit(std::string st, int pos, int& newPos);

int main() {
    int sum = 1;
    int cp = 0;
    int count = 0;
    std::vector<int> cards(SIZE, 1);
    int copies[SIZE];

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
            int n = 0;
            cp = getPoints(line);
            copies[count] = cp;
            count++;
            if(cp != 0)
            {
                int i = count;
                if(i > SIZE-1) i = SIZE - 1;
                n = i + cp;
                if(n > SIZE) n = SIZE;
                for(i; i<n; ++i) {
                    cards[i]++;
                }
                // std::cout << cards[i] << std::endl;

            }
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 

    for(int i=1; i<SIZE; ++i) {
        std::cout << cards[i] << std::endl;
        if(copies[i] != 0)
        {
            int j = i+1;
            int n = j+copies[i];
            if(j>SIZE) j=SIZE-1;
            if(n > SIZE) n = SIZE;
            for(j; j<n; ++j) {
                cards[j] += (cards[i]-1);
            }
        }
        // std::cout << cards[i] << std::endl;
        sum += cards[i];
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

