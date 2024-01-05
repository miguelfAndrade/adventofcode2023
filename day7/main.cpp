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
int cardStrength(char card);

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
            cards.rank = 1;
            data.push_back(cards);
        }
        myfile.close();

    }
    else std::cout << "Unable to open file" << std::endl; 

    for (size_t i = 0; i < data.size()-1; ++i)
    {
        for(size_t j = i+1; j < data.size(); ++j) {
            if(data[i].handStrength > data[j].handStrength) data[i].rank++;
            else if(data[i].handStrength < data[j].handStrength) data[j].rank++;
            else if(data[i].handStrength == data[j].handStrength) {
                for(int k=0; k < 5; ++k) {
                    if(data[i].hand[k] != data[j].hand[k]) {
                        int c1 = cardStrength(data[i].hand[k]);
                        int c2 = cardStrength(data[j].hand[k]);
                        if(c1 > c2) data[i].rank++;
                        else data[j].rank++;
                        break;
                    }
                }
            }
        }
    }

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

    std::sort(vec.begin(), vec.end()); 

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
    for (int i = 0; i < n-3; i++)      
    {        
        if (hand[i] == hand[i+1] && hand[i] == hand[i+2] && hand[i] == hand[i+3]) return 1;
    }
    return 0;
}

int fullHouse(std::vector<char> hand, int n) {
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)      
    {         
        if (hand[i] == hand[0]) c1++;
        if (hand[i] == hand[n-1]) c2++;
    }
    if(c1 == 3 && c2 == 2) return 1;
    else if(c1 == 2 && c2 == 3) return 1;
    else return 0;
}

int threeOfKind(std::vector<char> hand, int n) {
    for (int i = 0; i < n-2; i++)      
    {  
        if (hand[i] == hand[i+1] && hand[i] == hand[i+2]) return 1;
    }
    return 0;
}
int twoPair(std::vector<char> hand, int n) {
    int c = 0;
    for (int i = 0; i < n; i++)      
    {  
        if (i >= n-1) break;
        if (hand[i] == hand[i+1]) {
            c++;
            i = i+1;
        }
    }
    if(c == 2) return 1;
    else return 0;
}
int onePair(std::vector<char> hand, int n) {
    for (int i = 0; i < n; i++)      
    {  
        if (i >= n-1) break;
        if (hand[i] == hand[i+1]) return 1;
    }
    return 0;
}

int cardStrength(char card) {
    int strength = (int) card;
    switch (card)
    {
        case 'A':
            strength = 100 + strength;
            break;
        case 'K':
            strength = 90 + strength;
            break;
        case 'Q':
            strength = 80 + strength;
            break;
        case 'J':
            strength = 70 + strength;
            break;
        case 'T':
            strength = 60 + strength;
            break;
        default:
            break;
    }
    return strength;
}
