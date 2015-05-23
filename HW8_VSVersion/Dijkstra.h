//
// Created by MD on 5/18/2015.
//

#ifndef HW8_DIJKSTRA_DIJKSTRA_H
#define HW8_DIJKSTRA_DIJKSTRA_H
#include <iostream>
#include "Vertex.h"

namespace md_islam{
    class Dijkstra{
    public:
        const static unsigned int INF = 429496723;
        Dijkstra(std::list<Vertex *> *&listOfVertices, Vertex* start, Vertex* end){
            this->listOfVertices = listOfVertices;
			this->listOfVisitedVertices = new std::list < Vertex* > ;
            findShortestPath(start, end);

        }
        void findShortestPath(Vertex * start, Vertex * end){
			if (start == end)
			{
				return;
			}
			
            //set  vertices weight = INF
            for(std::list<Vertex *>::iterator it = this->listOfVertices->begin();
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
			this->trace_vector = new std::list < char > ;
            printTree(end, start);


        }
		~Dijkstra()
        {
			delete this->trace_vector;
			delete this->listOfVisitedVertices;
        }
        void calculateShortestWeight(Vertex * vertex, Vertex * end){
            if(vertex == end)
                return;
			else{
				std::list<Vertex *> * neighbors = vertex->getNeighborVector();
				int newCost;
				//visit , set new values/parents
				for (std::list<Vertex *>::iterator it = neighbors->begin(); it != neighbors->end(); ++it){
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
				for (std::list<Vertex *>::iterator it = listOfVisitedVertices->begin(); it != listOfVisitedVertices->end(); ++it){
					if ((*it)->getValue() < lowestValue && (*it)->getExpandedStatus() == false)
					{
						lowestValue = (*it)->getValue();
						minCostVertex_ptr = (*it);
					}
				}
				calculateShortestWeight(minCostVertex_ptr, end);
			}
        }

		void printTreeHelper(Vertex* end, Vertex* start)
        {
			if (end == start){
				this->trace_vector->push_back(start->getVertexLabel());
				return;
			}
			else{
				this->trace_vector->push_back(end->getVertexLabel());
				printTreeHelper(end->getParentVertex(), start);
			}
        }

	    void printTree(Vertex * end, Vertex * start){
			printTreeHelper(end, start);
			for (std::list<char>::reverse_iterator it = this->trace_vector->rbegin(); it != this->trace_vector->rend(); ++it)
			{
				std::cout << (*it) << "->";
			}
			std::cout << " Goal reached" <<std::endl;
			//reset vertices properties
			for (auto &i : *this->listOfVertices)
			{
				i->setExpanded(false);
				i->setValue(false);

			}
        }

    private:
		std::list<char> * trace_vector;
        std::list<Vertex *> *listOfVertices;
		std::list<Vertex *> *listOfVisitedVertices;
    };
}

#endif //HW8_DIJKSTRA_DIJKSTRA_H
