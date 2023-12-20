#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

struct camelCards
{
    char hand[5];
    int handStrength;
    int bid;
    int rank;
};

void calculateRank(std::vector<camelCards>& data);
int getHandStrength(std::vector<char> vec);
int fiveOfKind(std::vector<char> hand, int n);
int fourOfKind(std::vector<char> hand, int n);
int fullHouse(std::vector<char> hand, int n);
int threeOfKind(std::vector<char> hand, int n);
int twoPair(std::vector<char> hand, int n);
int onePair(std::vector<char> hand, int n);

int main() {
    int res = 0;

    std::vector<camelCards> data;

    std::string line;
    std::ifstream myfile ("input.txt");
    // std::ifstream myfile ("i.txt");


    if (myfile.is_open())
    {
        while (std::getline(myfile, line) )
        {
            camelCards cards;
            cards.rank = 1;
            for(int i=0; i<5; ++i) {
                cards.hand[i] = line[i]; 
            }
            cards.bid = std::stoi(line.substr(6, line.length()-6));
            std::vector<char> vec (cards.hand, cards.hand + sizeof(cards.hand) / sizeof(char));
            cards.handStrength = getHandStrength(vec);
            data.push_back(cards);
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 

    for (size_t i = 0; i < data.size(); ++i)
    {
        res += data[i].bid * data[i].rank;
    }

    std::cout << "SUM RESULT: " << res << std::endl; 
    
    return 0;
}

void calculateRank(std::vector<camelCards>& data) {

}

int getHandStrength(std::vector<char> vec) {
    int equal = 1;
    int n = vec.size();

    std::sort (vec.begin(), vec.end()); 

    if(fiveOfKind(vec, n)) equal = 7;
    else if(fourOfKind(vec, n)) equal = 6;
    else if(fullHouse(vec, n)) equal = 5;
    else if(threeOfKind(vec, n)) equal = 4;
    else if(twoPair(vec, n)) equal = 3;
    else if(onePair(vec, n)) equal = 2;

    return equal;
}

int fiveOfKind(std::vector<char> hand, int n) {
    for (int i = 1; i < n; i++)      
    {         
        if (hand[i] != hand[0]) return 0;
    }
    return 1;
}

int fourOfKind(std::vector<char> hand, int n) {
    int c = 0;
    for (int i = 1; i < n; i++)      
    {         
        if (hand[i] != hand[0]) c++;
    }
    if(c == 4) return 1;
    else return 0;
}

int fullHouse(std::vector<char> hand, int n) {
    int c = 0;
    for (int i = 1; i < n; i++)      
    {         
        if (hand[i] != hand[0]) c++;
    }
    if(c == 6) return 1;
    else return 0;
}

int threeOfKind(std::vector<char> hand, int n){
    int c = 0;
    for (int i = 0; i < n; i++)      
    {         
        if (hand[i] != hand[0]) c++;
    }
    if(c == 6) return 1;
    else return 0;
}
int twoPair(std::vector<char> hand, int n){
    return 0;
}
int onePair(std::vector<char> hand, int n){
    return 0;
}
