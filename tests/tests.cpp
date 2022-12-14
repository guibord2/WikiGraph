
#include "../src/Node.h"
#include "../src/Graph.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

//g++ -g -o test tests.cpp ../src/Node.cpp ../src/Graph.cpp          to compile
//./test                                                             to run

TEST_CASE("'==' operator test1", "[weight=5]") {
    Graph g = Graph();
    g.readIn("data/OneNode2.txt");
    Graph g1 = Graph();
    g1.readIn("data/OneNode2.txt");

    //Check Each Node
    std::map<std::string, Node> g1_map = g1.get_map();
    std::map<std::string, Node> g_map = g.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}

TEST_CASE("Empty Graph Test", "[weight=5]"){
    //Empty Graph Test
    Graph emptyreadin = Graph();
    emptyreadin.readIn("data/EmptyGraph.txt");
    Graph emptymanual = Graph();
    std::map<std::string, Node> g1_map = emptyreadin.get_map();
    std::map<std::string, Node> g_map = emptymanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}


TEST_CASE("Graph with 1 Node Test", "[weight=5]"){
    //Graph with 1 Node
    Graph onenodereadin = Graph();
    onenodereadin.readIn("data/OneNode1.txt");
    Graph onenodemanual = Graph();
    //add node and edge to the artificial graph
    onenodemanual.addNode("Baseball", "Ruben");
    std::map<std::string, Node> g1_map = onenodereadin.get_map();
    std::map<std::string, Node> g_map = onenodemanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}


TEST_CASE("Graph with 2 Node Test", "[weight=5]"){
    //Graph with 2 Nodes
    Graph twonodereadin = Graph();
    twonodereadin.readIn("data/OneNode2.txt");
    Graph twonodemanual = Graph();
    twonodemanual.addNode("Baseball", "Matt");
    twonodemanual.addNode("Baseball", "Ruben");
    std::map<std::string, Node> g1_map = twonodereadin.get_map();
    std::map<std::string, Node> g_map = twonodemanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}


TEST_CASE("BFS Small Test", "[weight=5]"){
    Graph g = Graph();
    g.readIn("data/bfs_small.txt");
    std::vector<Node> bfs_vect = g.Bfs("Desi", "Ruben");
    std::map<std::string, Node> g_map = g.get_map();
    std::vector<Node> manual_vect = {g_map["Matt"], g_map["Ruben"]};

    //Loop through both vectors to see if they match
    std::vector<Node>::iterator bfs_it = bfs_vect.begin();
    std::vector<Node>::iterator man_it = manual_vect.begin();

    REQUIRE(bfs_vect.empty() == manual_vect.empty());
    
    while(bfs_it != bfs_vect.end() && man_it != manual_vect.end()){
        //Check Edges
        Node g_node = *bfs_it;
        Node g1_node = *man_it;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());
        bfs_it++;
        man_it++;
    }
    REQUIRE(bfs_it == bfs_vect.end());
    REQUIRE(man_it == manual_vect.end());

}



TEST_CASE("BFS Large Test", "[weight=5]"){
    Graph g = Graph();
    g.readIn("data/bfs_large.txt");
    std::vector<Node> bfs_vect = g.Bfs("a", "w");
    std::map<std::string, Node> g_map = g.get_map();
    std::vector<Node> manual_vect = {g_map["b"], g_map["c"],g_map["d"],g_map["e"],g_map["f"],
                                    g_map["g"],g_map["h"],g_map["i"],g_map["j"],g_map["k"],
                                    g_map["l"],g_map["m"],g_map["n"],g_map["o"],g_map["p"],
                                    g_map["q"],g_map["r"],g_map["s"],g_map["t"],g_map["u"],
                                    g_map["v"],g_map["w"]};

    //Loop through both vectors to see if they match
    std::vector<Node>::iterator bfs_it = bfs_vect.begin();
    std::vector<Node>::iterator man_it = manual_vect.begin();

    REQUIRE(bfs_vect.empty() == manual_vect.empty());
    
    while(bfs_it != bfs_vect.end() && man_it != manual_vect.end()){
        //Check Edges
        Node g_node = *bfs_it;
        Node g1_node = *man_it;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());
        bfs_it++;
        man_it++;
    }
    REQUIRE(bfs_it == bfs_vect.end());
    REQUIRE(man_it == manual_vect.end());

}


TEST_CASE("BFS No connection", "[weight=5]"){
    Graph g = Graph();
    g.readIn("data/bfs_large.txt");
    std::vector<Node> bfs_vect = g.Bfs("x", "z");
    std::map<std::string, Node> g_map = g.get_map();
    std::vector<Node> manual_vect = {};

    //Loop through both vectors to see if they match
    std::vector<Node>::iterator bfs_it = bfs_vect.begin();
    std::vector<Node>::iterator man_it = manual_vect.begin();

    REQUIRE(bfs_vect.empty() == manual_vect.empty());
    
    while(bfs_it != bfs_vect.end() && man_it != manual_vect.end()){
        //Check Edges
        Node g_node = *bfs_it;
        Node g1_node = *man_it;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());
        bfs_it++;
        man_it++;
    }
    REQUIRE(bfs_it == bfs_vect.end());
    REQUIRE(man_it == manual_vect.end());

}


TEST_CASE("Tarjans no connections", "[weight=5]"){
    Graph g = Graph();
    g.readIn("Final proj/WikiGraph/tests/data/Tarjans1.txt");
    std::vector<std::set<Node>> answer = g.Tarjans();
    REQUIRE(answer.size() == 0);
}

TEST_CASE("Tarjan's algorithm", "[weight=5]") { 
    //Since Articles with no links cant be used as a path they are not made into Nodes
    // which is why they arent included in connectivity since they dont provide any use to finding paths between articles
    SECTION("Single connected component") {
        Graph a = Graph();
        a.readIn("data/Tarjans2.txt");
        vector<set<Node>> connected_components = a.Tarjans();
        
        REQUIRE(connected_components.size() == 1);
        REQUIRE(connected_components[0].size() == 5);
        std::vector<Node> nodes = {Node("1"),Node("2"),Node("3"),Node("4"),Node("5")};
        //set<Node> answer(nodes, nodes + 5);
        std::vector<Node> to_check;
        for (auto node : connected_components[0]) {
            to_check.push_back(node);
        }
        REQUIRE(std::is_permutation(to_check.begin(), to_check.end(),nodes.begin(), nodes.end()));
        //REQUIRE(connected_components[0] == set<Node>(nodes, nodes + 5));
    }

    // Test a case with multiple connected components
    SECTION("Multiple connected components") { //Simple multiple connections
        Graph b = Graph();
        b.readIn("data/tarjansmulti.txt");
        vector<set<Node>> connected_components = b.Tarjans();

        REQUIRE(connected_components.size() == 2);
        Node nodes[] = {Node("1"),Node("2"),Node("3"),Node("4"),Node("5")};
        REQUIRE(connected_components[0].size() == 3);
        REQUIRE(connected_components[1].size() == 1);
        REQUIRE(connected_components[1].begin()->title_ == "5");
    }

    // Test a case with no connected components
    SECTION("No connected components") {
        Graph c = Graph();

        vector<set<Node>> connected_components = c.Tarjans();

        REQUIRE(connected_components.size() == 0);
    }

    // Test a case with a disconnected graph
    SECTION("Disconnected graph") {
        Graph d = Graph();
        d.readIn("data/Tarjans4.txt");

        vector<set<Node>> connected_components = d.Tarjans();
        REQUIRE(connected_components.size() == 3);
        REQUIRE(connected_components[0] == set<Node>({Node("1")}));
        REQUIRE(connected_components[1] == set<Node>({Node("3")}));
        REQUIRE(connected_components[2] == set<Node>({Node("5")}));
    }

    // Test a case with a graph that contains a cycle
    SECTION("Graph with a cycle") {
        
        Graph e = Graph();
        e.readIn("data/Tarjans5.txt");

        vector<set<Node>> connected_components = e.Tarjans();
        std::vector<Node> nodes = {Node("1"),Node("2"),Node("3"),Node("4"),Node("5")};
        std::vector<Node> to_check;
        for (auto node : connected_components[0]) {
            to_check.push_back(node);
        }
        REQUIRE(connected_components.size() == 1);
        REQUIRE(connected_components[0].size() == 5);
        REQUIRE(std::is_permutation(to_check.begin(), to_check.end(),nodes.begin(), nodes.end()));

    }
}


TEST_CASE("Brandes Algorithm", "[weight=5]"){
    SECTION("No connections") {
        Graph a = Graph();
        map<string, double> central = a.Brandes();
        REQUIRE(central.empty());
    }
    SECTION("Correct centrality") {
        Graph b = Graph();
        b.readIn("data/bfs_small.txt");
        map<string, double> central = b.Brandes();
        REQUIRE(central["Baseball"] == (1.0/12));
        REQUIRE(central["Desi"] == (2.0/12));
        REQUIRE(central["Matt"] == (2.0/12));
        REQUIRE(central["Ruben"] == (2.0/12));
    }
    SECTION("Correct centrality_2") {
        Graph b = Graph();
        b.readIn("data/tarjansmulti_2.txt");
        map<string, double> central = b.Brandes();
        REQUIRE(central["1"] == (1.0/20));
        REQUIRE(central["2"] == (1.0/20));
        REQUIRE(central["5"] == (1.0/20));
        REQUIRE(central["7"] == (1.0/20));
    }
}
