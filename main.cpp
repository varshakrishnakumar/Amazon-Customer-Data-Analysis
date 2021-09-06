#include "Graph.h"

int main() {

    Graph graphtemp;//graph object to read data.csv file
    std::vector<std::pair<int, int> > Grr = graphtemp.readcsvresult("/home/NETID/aiushem2-lisamp2-rgyanm2-varshak3/data.csv");

    //obtaining max number of nodes in the data
    int nodes = graphtemp.readcsvtemp("/home/NETID/aiushem2-lisamp2-rgyanm2-varshak3/data.csv");


    Graph g = Graph(nodes);//graph object for SCC 
    Graph g2 = Graph(nodes);//graph object for Coloring

    //adding an edge between related nodes 
    for (unsigned int i = 0; i < Grr.size(); i++) {

        g.addEdge(Grr[i].first, Grr[i].second);
        g2.addEdgeColoring(Grr[i].first, Grr[i].second);
    }  
   
    //storing output of SCC in result vector
    std::vector<int> result = g.printstronglyConnect();
    
    //storing output of Graph Coloring in colorresult int-pair vector
    std::vector<std::pair<int, int> > colorresult = g2.greedyColoring();
    
/*Writing to stronglyconnected.csv*/
    // Create an output filestream object for SCC
    std::ofstream myFile("stronglyconnected.csv");

    // Send data to the stream
    for(unsigned i = 0; i < result.size(); ++i)
    {
        myFile << result.at(i) << ",\n";
    }
    // Close the file
    myFile.close();

/*Writing to graphcolor.csv*/
    // Create an output filestream object for Coloring
     std::ofstream myColorFile("graphcolor.csv");
    int count=0;
    // Send data to the stream
    for(unsigned i = 0; i < colorresult.size(); ++i)
    {
        myColorFile << "Vertex "<< colorresult[i].first<< " ---> Color " << colorresult[i].second << "\n";
    }
    //finding max number of colors used
    for(unsigned j = 0; j < colorresult.size(); ++j)
    {
        if(colorresult[j].second > count){
            count = colorresult[j].second;
        }
    }
    //Writing max number of colors to end of .csv file
    myColorFile << "Max Colors used: " << count;
    // Close the file
    myColorFile.close();

    return (0);
}