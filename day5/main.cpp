#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

long int converter(long int seed, std::vector<std::vector<long int>> list);
void getNumbers(std::string line, std::vector<long int>& numbers);
int getSeeds(std::string st, std::vector<long int>& seeds);
long int getDigit(std::string st, int pos, int& newPos);

int main() {
    long int n = 1000000000000;
    std::vector<long int> seeds;
    std::vector<std::vector<long int>> seedToSoil;
    std::vector<std::vector<long int>> soilToFert;
    std::vector<std::vector<long int>> fertToWater;
    std::vector<std::vector<long int>> waterToLight;
    std::vector<std::vector<long int>> ligthToTemp;
    std::vector<std::vector<long int>> tempToHum;
    std::vector<std::vector<long int>> humToLocation;

    int counter = 0;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
            std::vector<long int> tmp;
            getSeeds(line, seeds);
            if(std::isdigit(line[0]))
            {
                switch (counter)
                {
                case 1:
                    getNumbers(line, tmp);
                    seedToSoil.push_back(tmp);
                    break;
                case 2:
                    getNumbers(line, tmp);
                    soilToFert.push_back(tmp);
                    break;
                case 3:
                    getNumbers(line, tmp);
                    fertToWater.push_back(tmp);
                    break;
                case 4:
                    getNumbers(line, tmp);
                    waterToLight.push_back(tmp);
                    break;
                case 5:
                    getNumbers(line, tmp);
                    ligthToTemp.push_back(tmp);
                    break;
                case 6:
                    getNumbers(line, tmp);
                    tempToHum.push_back(tmp);
                    break;
                case 7:
                    getNumbers(line, tmp);
                    humToLocation.push_back(tmp);
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

    for(std::vector<long int>::iterator it = seeds.begin() ; it != seeds.end(); ++it) {
        long int seed = *it;
        long int soil = converter(seed, seedToSoil);
        long int fertilizer = converter(soil, soilToFert);
        long int water = converter(fertilizer, fertToWater);
        long int light = converter(water, waterToLight);
        long int temperature = converter(light, ligthToTemp);
        long int humidity = converter(temperature, tempToHum);
        long int location = converter(humidity, humToLocation);

        n = fmin(n, location);

    }
    
    std::cout << "SUM RESULT: " << n << std::endl; 
    
    return 0;
}

long int converter(long int seed, std::vector<std::vector<long int>> list) {
    long int convertedNumber = -1;

    for(std::vector<std::vector<long int>>::iterator n = list.begin() ; n != list.end(); ++n) {
        std::vector<long int> number = *n;
        if(number[1] <= seed && seed <= (number[1]+(number[2]-1))) {
            convertedNumber = number[0] + (seed - number[1]);
            break;
        }
    }
    if(convertedNumber == -1) convertedNumber = seed;
    
    return convertedNumber;
}

void getNumbers(std::string line, std::vector<long int>& numbers) {
    std::vector<long int> tmp;
    int posI = 0;
    tmp.push_back(getDigit(line, posI, posI));
    posI++;
    tmp.push_back(getDigit(line, posI, posI));
    posI++;
    tmp.push_back(getDigit(line, posI, posI));

    numbers = tmp;
}

int getSeeds(std::string st, std::vector<long int>& seeds) {
    if(st.find("seeds:") == 0) {
        std::string nStr = st.substr(7, st.length()-7);
        // std::cout << "-" << nStr << "-" << std::endl;
        for(int i=0; i<nStr.length(); ++i)
        {
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
