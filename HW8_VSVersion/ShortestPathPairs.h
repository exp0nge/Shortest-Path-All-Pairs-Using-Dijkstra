#ifndef HW8_DIJKSTRA_SHORTESTPATHPAIRS_H
#define HW8_DIJKSTRA_SHORTESTPATHPAIRS_H
#include "Dijkstra.h"
namespace md_islam
{
	class ShortestPathPairs
	{
	public:
		ShortestPathPairs(std::list<Vertex*> * list_of_all_vertices)
		{
			//select first vertex to iterate over
			for (std::list<Vertex *>::iterator it = list_of_all_vertices->begin();
				it != list_of_all_vertices->end(); ++it)
			{
				std::cout << "From vertex " << (*it)->getVertexLabel() << std::endl;
				for (std::list<Vertex *>::iterator it2 = list_of_all_vertices->begin();
					it2 != list_of_all_vertices->end(); ++it2)
				{
					Dijkstra dijkstra(list_of_all_vertices, *it, *it2);
				}
			}
			
		}
	
	};
}

#endif //HW8_DIJKSTRA_SHORTESTPATHPAIRS_H