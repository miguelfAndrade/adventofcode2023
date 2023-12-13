#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

// int converter(std::string st, int seed);
int getSeeds(std::string st, std::vector<long int>& seeds);
long int getDigit(std::string st, int pos, int& newPos);

int main() {
    long int n = 0;
    std::vector<long int> seeds;
    std::vector<std::string> seedToSoil;
    std::vector<std::string> soilToFert;
    std::vector<std::string> fertToWater;
    std::vector<std::string> waterToLight;
    std::vector<std::string> ligthToTemp;
    std::vector<std::string> tempToHum;
    std::vector<std::string> humToLocation;

    int counter = 0;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
            getSeeds(line, seeds);
            if(std::isdigit(line[0]))
            {
                switch (counter)
                {
                case 1:
                    seedToSoil.push_back(line);
                    break;
                case 2:
                    soilToFert.push_back(line);
                    break;
                case 3:
                    fertToWater.push_back(line);
                    break;
                case 4:
                    waterToLight.push_back(line);
                    break;
                case 5:
                    ligthToTemp.push_back(line);
                    break;
                case 6:
                    tempToHum.push_back(line);
                    break;
                case 7:
                    humToLocation.push_back(line);
                    break;
                default:
                    break;
                }
            }
            else if(line[0] != 0 && (line.find("seeds:") == std::string::npos))
            {
                counter++;
            }
             
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 
    
    std::cout << "SUM RESULT: " << counter << std::endl; 
    
    return 0;
}

int getSeeds(std::string st, std::vector<long int>& seeds) {
    if(st.find("seeds:") == 0) {
        std::string nStr = st.substr(7, st.length()-7);
        std::cout << "-" << nStr << "-" << std::endl;
        for(int i=0; i<nStr.length(); ++i)
        {
            // std::cout << getDigit(nStr, i, i) << std::endl;
            seeds.push_back(getDigit(nStr, i, i));
        }
    }
    return 0;
}

long int getDigit(std::string st, int pos, int& newPos) {
    long int n = 0;
    std::stringstream nStr;
    std::size_t p = st.find_first_of(" ", pos);
    if(p == std::string::npos) p = st.length();
    newPos = st.find_first_of(" ", p);
    nStr << st.substr(pos, p-pos);
    if(newPos == std::string::npos) newPos = st.length();
    nStr >> n;
    return n;
}
