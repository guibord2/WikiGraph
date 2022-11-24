#include <iostream>
#include "../src/Node.h"
#include "../src/Graph.h"

using namespace std;

// g++ -g -o test tests.cpp src/Node.cpp src/Graph.cpp    to compile without make file
// ./test                                                to run
int main(){

    // '==' operator test1
    Graph g = Graph();
    g.readIn("data/OneNode2.txt");
    Graph g1 = Graph();
    g1.readIn("data/OneNode2.txt");
    bool flag;
    if(g == g1){flag = true;}
    else{flag = false;}
    if(flag == true){cout << "'==' operator test1 passed" << endl;}
    else{cout << "'==' operator test1 failed" << endl;}


    // '==' operator test2
    Graph g2 = Graph();
    g2.readIn("data/OneNode1.txt");
    Graph g3 = Graph();
    g3.readIn("data/OneNode2.txt");
    bool flag1;
    if(g2 == g3){flag1 = true;}
    else{flag1 = false;}
    if(flag1 == false){cout << "'==' operator test2 passed" << endl;}
    else{cout << "'==' operator test2 failed" << endl;}

}