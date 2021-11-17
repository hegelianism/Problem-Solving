/*
 * Problem : www.codewars.com/kata/585894545a8a07255e0002f1
 *
 * The algorithm identifies the next possible steps given the current dot and the visited dots in the pattern
 * Then, using a given starting point, we run a standard recursion for len = len - 1, till the length of the pattern is 1.  
 */  

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

set<char> Dots{'A', 'B', 'C', 'D', 'E', 'F', 'G' ,'H', 'I'};

std::vector<char> visitedDots;
set<char> AvailableDots(Dots);


set<char> CalculateConnectivity(char CurrentDot, set<char> AvailableDots) {

    set<char> Connections(AvailableDots);

    switch (CurrentDot) {

    case 'A':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('I');
        if (AvailableDots.find('D') != AvailableDots.end())
            Connections.erase('G');
        if (AvailableDots.find('B') != AvailableDots.end())
            Connections.erase('C');
        break;

    case 'B':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('H');
        break;

    case 'C':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('G');
        if (AvailableDots.find('B') != AvailableDots.end())
            Connections.erase('A');
        if (AvailableDots.find('F') != AvailableDots.end())
            Connections.erase('I');
        break;

    case 'D':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('F');
        break;

    case 'E':
        break;

    case 'F':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('D');
        break;

    case 'G':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('C');
        if (AvailableDots.find('D') != AvailableDots.end())
            Connections.erase('A');
        if (AvailableDots.find('H') != AvailableDots.end())
            Connections.erase('I');
        break;

    case 'H':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('B');
        break;

    case 'I':
        if (AvailableDots.find('E') != AvailableDots.end())
            Connections.erase('A');
        if (AvailableDots.find('H') != AvailableDots.end())
            Connections.erase('G');
        if (AvailableDots.find('F') != AvailableDots.end())
            Connections.erase('C');
        break;
    }

    return(Connections);
}

unsigned int countPatternsFrom(char currentDot, unsigned short length) {

    int patterns = 0;

    if (length <=0 || length >= 10) 
        return 0;
    else if (length == 1) 
        return 1;
    

    AvailableDots.erase(currentDot);

    set<char> connections = CalculateConnectivity(currentDot, AvailableDots);

    for (auto nextDot : connections) {
        if (length > 1) 
            patterns += countPatternsFrom(nextDot, length - 1);
        AvailableDots.insert(nextDot);
    }

    AvailableDots.insert(currentDot);
    return patterns;
}



int main()
{
    cout << countPatternsFrom('A', 0) << endl;
    cout << countPatternsFrom('A', 10)<< endl;
    cout << countPatternsFrom('B', 1) << endl;
    cout << countPatternsFrom('C', 2) << endl;
    cout << countPatternsFrom('D', 3) << endl;
    cout << countPatternsFrom('E', 4) << endl;
}