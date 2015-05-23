#include <iostream>
#include "Dijkstra.h"

using namespace md_islam;
using namespace std;
int main() {
    Vertex * vA = new Vertex('A');
    Vertex * vB = new Vertex('B');
    Vertex * vC = new Vertex('C');
    Vertex * vD = new Vertex('D');
    //add neighbors bidirectionally
	vA->addNeighbor(vB);
	vA->addNeighbor(vC);
	vB->addNeighbor(vA);
	vB->addNeighbor(vD);
	vC->addNeighbor(vA);
	vC->addNeighbor(vD);
	vD->addNeighbor(vB);
	vD->addNeighbor(vC);
    vA->makeEdge(vB, 2);
    vA->makeEdge(vC, 1);
    vB->makeEdge(vA, 2);
    vB->makeEdge(vD, 1);
    vC->makeEdge(vA, 1);
    vC->makeEdge(vD, 3);
    vD->makeEdge(vC, 3);
    vD->makeEdge(vB, 1);

    vector<Vertex*> * listOfVertices = new vector<Vertex*>;
    listOfVertices->push_back(vA);
    listOfVertices->push_back(vB);
    listOfVertices->push_back(vC);
    listOfVertices->push_back(vD);

    Dijkstra dijkstraAlgo(listOfVertices, vA, vD);


    return 0;
}