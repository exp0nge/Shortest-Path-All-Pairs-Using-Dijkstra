//
// Created by MD on 5/23/2015.
//

#include "Vertex.h"

md_islam::Vertex::Vertex(char vertexLabel) {
    this->vertexLabel = vertexLabel;
    this->visited = false;
    this->expanded = false;
	this->neighbors = new std::list < Vertex* > ;
	this->edgeMap = new std::map < Vertex*, int > ;
}

void md_islam::Vertex::setParentVertex(md_islam::Vertex *parentNode) {
    this->parentNode = parentNode;
}

void md_islam::Vertex::addNeighbor(Vertex* neighbor_vertex)
{
	this->neighbors->push_back(neighbor_vertex);
}



md_islam::Vertex *md_islam::Vertex::getParentVertex() {
    return this->parentNode;
}

void md_islam::Vertex::makeEdge(md_islam::Vertex *neighborEdge, int weight) {
	(*this->edgeMap)[neighborEdge] =  weight;
}


void md_islam::Vertex::setVisited(bool state) {
    this->visited = state;
}

void md_islam::Vertex::setExpanded(bool state) {
    this->expanded = state;
}

std::list<md_islam::Vertex *> *md_islam::Vertex::getNeighborVector() {
    return this->neighbors;
}



bool md_islam::Vertex::getVisitedStatus() {
    return this->visited;

}

std::map<md_islam::Vertex *, int>* md_islam::Vertex::getEdges() {
    return this->edgeMap;
}

void md_islam::Vertex::setValue(int value) {
    this->value = value;
}

bool md_islam::Vertex::getExpandedStatus() {
    return this->expanded;
}

int md_islam::Vertex::getValue() {
    return this->value;
}

int md_islam::Vertex::getValueOfEdge(md_islam::Vertex *neighborEdge) {
    return this->edgeMap->at(neighborEdge);
}

char md_islam::Vertex::getVertexLabel() {
    return this->vertexLabel;
}
