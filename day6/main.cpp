#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int getInfo(std::string st, std::vector<int>& timeDist);

int main() {
    int res = 1;

    std::vector<std::vector<int>> timeDist;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        {
            std::vector<int> tmp;
            getInfo(line, tmp);
            timeDist.push_back(tmp);
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 

    for (size_t i = 0; i < timeDist[0].size(); i++)
    {
        int counter = 0;    
        for (size_t j = 1; j < timeDist[0][i]; j++)
        {
            int msLeft = timeDist[0][i] - j;
            int distance = msLeft * j;
            if(distance > timeDist[1][i]) counter++;
        }
        if(counter == 0) counter = 1;
        res = res*counter;
    }
    
    
    std::cout << "SUM RESULT: " << res << std::endl; 
    
    return 0;
}

int getInfo(std::string st, std::vector<int>& timeDist) {
    for(int i=0; i<st.length(); ++i) { 
        if(std::isdigit(st[i])) {
            std::string n = "";
            std::size_t p = st.find_first_of(" ", i);
            if(p == std::string::npos) p = st.length();
            int newI = st.find_first_of(" ", p);
            n =  st.substr(i, p-i);
            if(newI == std::string::npos) newI = st.length();
            i = newI;
            timeDist.push_back(std::stoi(n));
        }
    }
    return 0;
}
