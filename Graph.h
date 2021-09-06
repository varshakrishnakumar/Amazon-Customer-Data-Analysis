#pragma once
// #include "DFS.h"
#include <list>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

using namespace std;
class Graph {
    int nodes; //number of nodes
    list<int> *adj; //array of adjacent lists

    public:


        Graph(std::string file, bool header);

        // Constructor
        Graph(int nodes) ;
        Graph();

        //Deconstructor
        ~Graph();

        //Method to add edge
        void addEdge(int current, int next);

        //Method to add graphcoloring
        void addEdgeColoring(int current, int next);


        //returns if strongly connected
        vector<int> printstronglyConnect();


        //returns coloring of vertices
        std::vector<std::pair<int, int> > greedyColoring();

        //Function to copy and reverse graph
        Graph transpose();
        void DFS(int n, bool visited[]);
        void fillOrder(int nodes, bool visited[], stack<int> &Stack);

        int size();
        //Graph LoadStronglyConnect();

    std::vector<std::pair<int, int>> readcsvresult(std::string filename);
    int readcsvtemp(std::string filename);




    private:
    long stoi(const char *s);

};