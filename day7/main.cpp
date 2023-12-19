#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

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


