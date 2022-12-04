#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <map>
class Graph {
    public:    
    
    //Check to see if two graphs are identical
    bool operator==(Graph g1);
    void addNode(string title, string destination);
    //read a tsv and load into
    void readIn(std::string tsv);
    void print();
    std::vector<Node> Bfs(std::string source, std::string target);
    std::map<std::string, Node> get_map() {return node_map;}
    std::vector<int> Brandes();
    std::vector<Node> Tarjans();
    private:
    std::map<std::string, Node> node_map;
};
//reaed in nodes, then bfs through each nodes adjacency list until we find target article, then 