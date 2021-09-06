#pragma once

#include<string>
#include <fstream>
#include <istream>
#include <iostream>

#include "Graph.h"

using namespace std;

enum Extension {
  txt,
  csv  
};

class FileLoader {
    public:
        FileLoader(Graph* graph, const string& filename, double loadfactor=1.0);
        ~FileLoader();

    private:
        Graph* graph;
        string filename;
        ifstream file_;
        size_t totalByte_;
        size_t getByte();

        Extension findExtension(const string& extension) const;
        void build();
        void load(double loadfactor);
        bool hasNext();
        void buildCSV();
        bool checkCSV(const string& lhs, const string& rhs);
};