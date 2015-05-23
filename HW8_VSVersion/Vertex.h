//
// Created by MD on 5/23/2015.
//

#ifndef HW8_DIJKSTRA_VERTEX_H
#define HW8_DIJKSTRA_VERTEX_H

#include <vector>
#include <map>

namespace md_islam{
    class Vertex {
    public:
        Vertex(char vertexLabel);

        //make edge function
        void makeEdge(Vertex *neighborEdge, int weight);
        //setters
        void setVisited(bool state);
        void setExpanded(bool state);
        void setValue(int value);
        void setParentVertex(Vertex * parentNode);
		void addNeighbor(Vertex* neighbor_vertex);
        //getters
        bool getVisitedStatus();
        bool getExpandedStatus();
        int getValue();
        int getValueOfEdge(Vertex * neighborEdge);
        char getVertexLabel();
        Vertex* getParentVertex();
        std::map<Vertex *, int> *getEdges();
        std::vector<Vertex *> * getNeighborVector();
    private:
        Vertex * parentNode;
        char vertexLabel;
        std::vector<Vertex *> *neighbors;
        bool visited, expanded;
        int value;
        std::map<Vertex *, int> *edgeMap;
    };
}


#endif //HW8_DIJKSTRA_VERTEX_H
