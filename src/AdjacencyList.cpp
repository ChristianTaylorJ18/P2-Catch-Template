#include <iostream>
#include <utility>
#include "AdjacencyList.h"

using namespace std;

bool AdjacencyList::insert(string fromWebURL, string toWebURL) {
    if (fromWebURL == toWebURL) {
        return false;
    }
    incoming_edges[toWebURL].push_back(fromWebURL);
    outgoing_edges[fromWebURL].push_back(toWebURL);
    uniqueNamesAndRanks[toWebURL] = 1; // might just want to url name
    uniqueNamesAndRanks[fromWebURL] = 1; // might just want to url name
    return true;
}
void AdjacencyList::initializeMatrix() {
    for (auto pair : uniqueNamesAndRanks) {
        pair.second = 1/uniqueNamesAndRanks.size();
    }
}
int AdjacencyList::getNumberOfPowerIterations() {
    return this->numberOfPowerIterations;
}
int AdjacencyList::getNumberOfCommands() {
    return this->numberOfCommands;
}
int AdjacencyList::getNumberOfIncomingEdges() {
    return 0;
}
// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    this->initializeMatrix();
    string result;
    for (int i = 0; i < uniqueNamesAndRanks.size(); i++) {

    }
    cout << result;
    return result;
}
