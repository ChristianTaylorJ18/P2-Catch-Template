#include <iostream>

#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    AdjacencyList graph;
    cin >> no_of_lines;
    cin >> power_iterations;
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        graph.insert(from, to);
    }
    graph.PageRank(power_iterations);
}
