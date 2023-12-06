#include <iostream>
#include <fstream>
#include <string>

const int nRed = 12;
const int nGreen = 13;
const int nBlue = 14;

int getGameId(std::string line);
int possibleIdGame(std::string line);
int numberOfSets(std::string line);


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

int possibleIdGame(std::string line) {
    int id = 0;
    std::string workLine = line.substr(line.find(":")+2, line.length()-1);

    // int semiColonPos = -1;

    // for(int i=0; i<line.length(); i++)
    // {
    //     std::string firstSet = line.substr(line.find_first_of(";"));
    // }

    id = getGameId(line);
    // id = numberOfSets(workLine);
    // std::cout << "Game ID: " << id << std::endl; 
    std::cout << "Game " << id << ": " << numberOfSets(workLine) << std::endl; 
    return id;
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