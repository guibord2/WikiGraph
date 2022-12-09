#include "Graph.h"
int main()
{
    // g++ -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc -g    to compile without make file
    // ./main                                                to run
    Graph g = Graph();
    g.readIn("/workspaces/CS_225/Final proj/WikiGraph/tests/data/Tarjans5.txt");
    //g.print();
    //Graph badreadin = Graph();
    //badreadin.readIn("gabran.txt");
    //badreadin.print();
    /*
    std::cout<<"---------------------------------\n\n";
    std::vector<Node> answer = g.Bfs("1", "5");
    for (Node node : answer) {
        std::cout << node.title_ << " -> ";
    }
    std::cout<<"\n---------------------------------\n";
    std::map<string, double> central = g.Brandes();
    if (answer.empty()) {std::cout << "empty\n";}
    else {
        for (Node node : answer) {
            std::cout << node.title_ << " -> "; 
        }
        std::cout << "\n";
        for (auto it : central) {
            std::cout << it.first << ": " << it.second << " ->";
        }
    }*/
    std::cout<<"\n---------------------------------\n";
    std::vector<std::set<Node>> connected = g.Tarjans();
    int count = 1;
    for (auto component : connected) {
        if (component.empty()) {std::cout << "Empty\n";}
        std::cout << "Component " << count << ":\n";
        count++;
        for (Node node : component) {
            std::cout << node.title_ << " - ";
        }
        std::cout << "\n";
    }
    
    return 0;
}