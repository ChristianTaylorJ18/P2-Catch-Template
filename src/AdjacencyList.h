#pragma once

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class AdjacencyList {
    int numberOfPowerIterations = 0;
    int numberOfCommands = 0;
    unordered_map <string,vector<string>> incoming_edges;
    unordered_map <string,vector<string>> outgoing_edges;
    unordered_map<string, int> uniqueNamesAndRanks;
    void initializeMatrix();
public:
    bool insert(string fromWebURL, string toWebURL);
    string PageRank(int n);
    //Debugging
    int getNumberOfPowerIterations();
    int getNumberOfCommands();
    int getNumberOfIncomingEdges();
};

// This class and method are optional.
