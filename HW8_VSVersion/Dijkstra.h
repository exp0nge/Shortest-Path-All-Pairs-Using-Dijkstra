//
// Created by MD on 5/18/2015.
//

#ifndef HW8_DIJKSTRA_DIJKSTRA_H
#define HW8_DIJKSTRA_DIJKSTRA_H
#include <iostream>
#include <vector>
#include "Vertex.h"

namespace md_islam{
    class Dijkstra{
    public:
        const static unsigned int INF = 429496723;
        Dijkstra(std::vector<Vertex *> *listOfVertices, Vertex* start, Vertex* end){
            this->listOfVertices = listOfVertices;
			this->listOfVisitedVertices = new std::vector < Vertex* > ;
            findShortestPath(start, end);

        }
        void findShortestPath(Vertex * start, Vertex * end){
            //set  vertices weight = INF
            for(std::vector<Vertex *>::iterator it = this->listOfVertices->begin();
                    it != this->listOfVertices->end(); ++it){
                (*it)->setValue(INF);
            }
			//set start weight = 0, visited = true
			start->setValue(0);
			start->setVisited(true);
			start->setParentVertex(start);

            //recursively go through graph
            calculateShortestWeight(start, end);

            //print trace
            printTree(end, start);


        }
        void calculateShortestWeight(Vertex * vertex, Vertex * end){
            if(vertex == end)
                return;
			else{
				std::vector<Vertex *> * neighbors = vertex->getNeighborVector();
				int newCost;
				//visit , set new values/parents
				for (std::vector<Vertex *>::iterator it = neighbors->begin(); it != neighbors->end(); ++it){
					if ((*it)->getExpandedStatus())
					{
						
					}
					else
					{
						newCost = (vertex->getValue() + vertex->getValueOfEdge(*it));
						if ((*it)->getValue() > newCost){
							//neighbor has greater value, so set parent, visited and new value
							(*it)->setParentVertex(vertex);
							(*it)->setValue(newCost);
							(*it)->setVisited(true);
							this->listOfVisitedVertices->push_back(*it);
						}
					}
				}

				vertex->setExpanded(true);
				//visit lowest cost neighbor
				int lowestValue = INF;
				Vertex * minCostVertex_ptr = neighbors->front();
				for (std::vector<Vertex *>::iterator it = listOfVisitedVertices->begin(); it != listOfVisitedVertices->end(); ++it){
					if ((*it)->getValue() < lowestValue && (*it)->getExpandedStatus() == false)
					{
						lowestValue = (*it)->getValue();
						minCostVertex_ptr = (*it);
					}
				}
				calculateShortestWeight(minCostVertex_ptr, end);
			}
        }
        void printTree(Vertex * end, Vertex * start){
            
            if(end == start){
				std::cout << start->getVertexLabel() << std::endl;
                return;
            }
            else{
				std::cout << end->getVertexLabel() << ", ";
                printTree(end->getParentVertex(), start);
            }
        }

    private:
        std::vector<Vertex *> *listOfVertices;
		std::vector<Vertex *> *listOfVisitedVertices;
    };
}

#endif //HW8_DIJKSTRA_DIJKSTRA_H
