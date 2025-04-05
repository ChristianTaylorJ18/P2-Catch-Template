#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "AdjacencyList.h"

using namespace std;
// Christian Taylor 58540310
TEST_CASE("Test for website insertion", "[tag]") {
  set<string> expectedSet = {"google.com", "wiki.com"};
  AdjacencyList myGraph;
  myGraph.insert("google.com", "wiki.com");
  myGraph.insert("wiki.com", "google.com");
  set<string> actualSet = myGraph.getUniqueWebsite();
  REQUIRE(equal(actualSet.begin(), actualSet.end(), expectedSet.begin(), expectedSet.end())); // fix me!
}

TEST_CASE("Test for power and number of iterations input validation", "[tag]") {
  AdjacencyList myGraph;
  string input = "5 2";
  myGraph.parseInput(input);

  SECTION("Correct power iterations") {
    REQUIRE(myGraph.getNumberOfPowerIterations() == 2);
  }

  SECTION("Correct # of iterations") {
    REQUIRE(myGraph.getNumberOfCommands() == 5);
  }
}

TEST_CASE("Ensure incomingEdgesAmount", "[flag]") {
  string input = R"(5 2
google1.com maps.com
google2.com maps.com
google3.com maps.com
google4.com maps.com
google5.com maps.com
)";

  int expectedNumberOfIncomingEdges = 5;
  AdjacencyList g;
  g.parseInput(input);
  int actualNumberOfIncomingEdges = g.getNumberOfIncomingEdges();

  REQUIRE(actualNumberOfIncomingEdges == expectedNumberOfIncomingEdges);
}

TEST_CASE("Small PageRank Output Test", "[flag]") {
  string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

  string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

  string actualOutput;
  AdjacencyList g;
  g.parseInput(input);
  actualOutput = g.PageRank(g.getNumberOfPowerIterations());

  REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Duplicates PageRank Output Test", "[flag]") {
  string input = R"(7 2
google.com google.com
google.com google.com
google.com google.com
google.com google.com
google.com google.com
google.com google.com
google.com google.com
)";

  string expectedOutput = R"(google 1.0
)";

  string actualOutput;
  AdjacencyList g;
  g.parseInput(input);
  actualOutput = g.PageRank(g.getNumberOfPowerIterations());

  REQUIRE(actualOutput == expectedOutput);
}

