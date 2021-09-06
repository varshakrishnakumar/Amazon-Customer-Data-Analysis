#include "Graph.h"

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

using namespace std;

void Graph::DFS(int n, bool visited[]) {
    visited[n] = true;
    //cout<<n<<endl;
    
    list<int>::iterator i;
    for (i = adj[n].begin(); i != adj[n].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i, visited);
        }
    }
}


Graph::Graph(int nodes) {
    this->nodes = nodes;
    adj = new list<int>[nodes+1];
}

Graph::Graph() {
    //empty constructor used for readcsv
}

Graph::~Graph() {
    delete [] adj;
}

void Graph::addEdge(int current, int next) {
    adj[current].push_back(next);
}

void Graph::addEdgeColoring(int current, int next) {
    adj[current].push_back(next);
    adj[next].push_back(current);
}


Graph Graph::transpose() {
    Graph g(nodes);
    for (int i = 0; i < nodes; i++) {
        list<int>::iterator iter;
        for (iter = adj[i].begin(); iter != adj[i].end(); ++iter) {
            g.adj[*iter].push_back(i);
        }
    }
    return g;
}

int Graph::size() {
    return nodes;
}

vector<int> Graph::printstronglyConnect() {
    stack<int> Stack;
    vector<int> res;
  
    bool *visited = new bool[nodes];
    for(int i = 0; i < nodes; i++)
        visited[i] = false;
  
    for(int i = 0; i < nodes; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
  
    Graph gr = transpose();
  
    for(int i = 0; i < nodes; i++)
        visited[i] = false;
  
    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();
  
        if (visited[v] == false)
        {   
            gr.DFS(v, visited);
            res.push_back(v);
        }
        
    }
    delete[] visited;
    visited = NULL;
    return res;
}
std::vector<std::pair<int, int>> Graph::greedyColoring()
{
    std::vector<std::pair<int, int>> color;
    int result[nodes];
 
    
    result[0]  = 0;
 
    
    for (int u = 1; u < nodes; u++)
        result[u] = -1;  
 
    
    bool available[nodes];
    for (int cr = 0; cr < nodes; cr++)
        available[cr] = false;
 
   
    for (int u = 1; u < nodes; u++)
    {
      
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
 
        
        int cr;
        for (cr = 0; cr < nodes; cr++)
            if (available[cr] == false)
                break;
 
        result[u] = cr; 
 
        
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
  
   
    for (int u = 0; u < nodes; u++){
        std::pair<int,int> pair(u,result[u]);
        color.push_back(pair);  
    }   
    return color;       
}


void Graph::fillOrder(int nodes, bool visited[], stack<int> &Stack)
{
    visited[nodes] = true;
  
    list<int>::iterator i;
    for(i = adj[nodes].begin(); i != adj[nodes].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
  
    Stack.push(nodes);
}

long Graph::stoi(const char *s) {
    long i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

std::vector<std::pair<int, int> > Graph::readcsvresult(std::string filename) {

        std::vector<std::pair<int, int> > result;

        std::ifstream myFile(filename.c_str(),std::ifstream::in);
        if(!myFile.is_open()) throw std::runtime_error("Could not open file2");

        std::string line, colname;
        
        while(std::getline(myFile, line)) {
            std::stringstream ss(line);

            std::string first_val;
            std::getline(ss, first_val, ',');

            std::string sec_val;
            std::getline(ss, sec_val, '\n');
            
            std::pair<int, int> int_p( stoi(first_val.c_str()),stoi(sec_val.c_str()) );
            result.push_back(int_p);
        }

        myFile.close();

        return result;
    }
int Graph::readcsvtemp(std::string filename) {

    
        std::ifstream myFile(filename.c_str(),std::ifstream::in);
        if(!myFile.is_open()) throw std::runtime_error("Could not open file3");

        std::string line, colname;

        int temp = 0;
        while(std::getline(myFile, line)) {
            std::stringstream ss(line);
        
            std::string first_val;
            std::getline(ss, first_val, ',');

            std::string sec_val;
            std::getline(ss, sec_val, '\n');
            
            int first = stoi(first_val.c_str());
            int second = stoi(sec_val.c_str());
            temp = std::max(first, temp);
            temp = std::max(second, temp);
           
        }

        myFile.close();

        return temp+1;
    }




