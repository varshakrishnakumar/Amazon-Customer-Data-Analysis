#include <string>
#include "../cs225/catch/catch.hpp"
#include <vector>

#include "../Graph.h"


TEST_CASE("strongly connected graph1", "[valgrind][weight=1]") {
    vector<int> testSCC{0,3,2,1};
    Graph g = Graph(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,5);
    g.addEdge(5,2);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    
    vector<int> SCC= g.printstronglyConnect();
    REQUIRE(testSCC == SCC);
}
TEST_CASE("graph coloring", "[valgrind][weight=1]") {
    vector<int> testColor1{0,1,2,3,4,5};
    vector<int> testColor2{0,1,1,1,2,3};
    Graph g = Graph(6);
    g.addEdgeColoring(0,1);
    g.addEdgeColoring(0,2);
    g.addEdgeColoring(0,3);
    g.addEdgeColoring(0,4);
    g.addEdgeColoring(0,5);
    g.addEdgeColoring(5,2);
    g.addEdgeColoring(2,4);
    g.addEdgeColoring(3,4);
    g.addEdgeColoring(4,5);
    
    vector<pair<int, int> > Color= g.greedyColoring();
    vector<int>colorresult1;
    vector<int>colorresult2;
    for (unsigned i = 0; i < Color.size(); i++) {
        colorresult1.push_back(Color[i].first);
        colorresult2.push_back(Color[i].second);
    }
    
    REQUIRE(colorresult1 == testColor1);
    REQUIRE(colorresult2 == testColor2);
}

TEST_CASE("dfs", "[valgrind][weight=1]") {
    Graph g = Graph(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,5);
    g.addEdge(5,2);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    bool visited[6];
    // vector<int> ans = ...... (store what the dfs SHOULD return)
    //vector<int> v ;
     g.DFS(0,visited);
    //vector<int> test{0,1,2,4,5,3};
    //REQUIRE(v == test);
}
// check if the vector results are the same