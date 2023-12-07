#include <iostream>
#include <fstream>
#include <string>

int getGameId(std::string line);
int possibleIdGame(std::string gameLine);
int numberOfSets(std::string line);
int getDigit(std::string set, std::size_t pos);

int main() {
    int sum = 0;

    std::string line;
    std::ifstream myfile ("input.txt");
    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        { 
            sum += possibleIdGame(line);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl; 

    std::cout << "SUM RESULT: " << sum << std::endl; 
    
    return 0;
}

int possibleIdGame(std::string gameLine) {
    std::string line = gameLine;

    int sets = 0;

    int minRed = 0;
    int minGreen = 0;
    int minBlue = 0;

    sets = numberOfSets(line);

    line = line.substr(line.find(":")+1, line.length()-1);

    for(int i=0; i<sets; i++)
    {
        std::size_t semiColonPos = line.find_first_of(";");
        std::string set = line.substr(0, semiColonPos);

        int red = minRed;
        int green = minGreen;
        int blue = minBlue;

        if(semiColonPos == std::string::npos) 
        {
            semiColonPos = line.length()-1;
            set = line;
        }
        
        std::size_t posRed = set.find(" red");
        std::size_t posGreen = set.find(" green");
        std::size_t posBlue = set.find(" blue");

        if(posRed != std::string::npos)
        {
            red = getDigit(set, posRed);
            if(red > minRed) minRed = red;
        }
        if(posGreen != std::string::npos)
        {
            green = getDigit(set, posGreen);
            if(green > minGreen) minGreen = green;
        }
        if(posBlue != std::string::npos)
        {
            blue = getDigit(set, posBlue);
            if(blue > minBlue) minBlue = blue;
        }

        line.erase(0, semiColonPos+1);

    }

    // std::cout << "MIN R: " << minRed << " | MIN G: " << minGreen << " | MIN B: " << minBlue << std::endl; 
    
    return minRed*minGreen*minBlue;
}

int getGameId(std::string line) {
    std::string l = line;
    l.erase(0, 5);
    int pos = l.find(":");
    std::string game = l.substr(0,pos);
    return std::stoi(game);
}

int numberOfSets(std::string line) {
    int sets = 0;

    std::string l = line;
    std::size_t pos = l.find_first_of(";");
    
    while(pos != std::string::npos) {
        l[pos]='*';
        pos = l.find_first_of(";");
        sets++;
    }
    
    return sets+1;
}

int getDigit(std::string set, std::size_t pos) {
    int i = pos - 2;
    if(i<0) i=0;

    return std::stoi(set.substr(i, pos-i));
}