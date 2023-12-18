#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

int getInfo(std::string st, std::vector<size_t>& timeDist);

int main() {
    long int res = 1;

    std::vector<size_t> timeDist;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        {
            getInfo(line, timeDist);
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 

    long int counter = 0;    
    for (size_t j = 1; j < timeDist[0]; j++)
    {
        long int msLeft = timeDist[0] - j;
        long int distance = msLeft * j;
        if(distance > timeDist[1]) counter++;
    }
    if(counter == 0) counter = 1;
    res = res*counter;
    
    
    std::cout << "SUM RESULT: " << res << std::endl; 
    
    return 0;
}

int getInfo(std::string st, std::vector<size_t>& timeDist) {
    std::string n = "";
    size_t number;
    for(int i=0; i<st.length(); ++i) { 
        if(std::isdigit(st[i])) {
            std::size_t p = st.find_first_of(" ", i);
            if(p == std::string::npos) p = st.length();
            int newI = st.find_first_of(" ", p);
            n += st.substr(i, p-i);
            if(newI == std::string::npos) newI = st.length();
            i = newI;
        }
    }
    std::stringstream nStr;

    nStr << n;
    nStr >> number;

    timeDist.push_back(number);
    return 0;
}
