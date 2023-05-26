#ifndef PERTURB_NETWORK_HPP
#define PERTURB_NETWORK_HPP

#include "ADJ/select_elements.hpp"
#include "ADJ/add_multiple_edge.hpp"
#include "ADJ/del_multiple_edge.hpp"
using namespace std;

//Perturb Network Edges Based on Cross Linking
//Select two edges (a--b) and (c--d) ; (a-/-d) ; (b-/-c)
//Cross them such that (a--d); (c--b); (a-/-b) and (c-/-d)

void perturb_edges_cross(A_Network *X, int num)
{
	vector<Edge> edges; //Each set of 4 vertice constitute a,b,c,d in order;
	Edge newedge1, newedge2;
	
	int it=0;
	while (it<num)
	{ 
		pick_random_2edges(*X, &edges);
		newedge1=create(edges[0].node1, edges[1].node2, edges[0].edge_wt);
		newedge2=create(edges[1].node1, edges[0].node2, edges[1].edge_wt);

		del_edge(X, edges[0]);
		del_edge(X, edges[1]);
		add_edge(X, newedge1);
		add_edge(X, newedge2);
		
		it++;
	}//end of while
	
return;}
/******* End of Function **************/

//Add Random Edges to the network

void perturb_edges_add (A_Network *X, int num)
{
	vector<Edge> edges; //Each set of 4 vertice constitute a,b,c,d in order;
	pick_random_edges(*X, &edges, num,0);
	add_edgeS(X, edges);
}
/******* End of Function **************/


//Delete Random Edges to the network

void perturb_edges_del(A_Network *X, int num)
{
	vector<Edge> edges; //Each set of 4 vertice constitute a,b,c,d in order;
	pick_random_edges(*X, &edges, num,1);
	del_edgeS(X, edges);
	
}
/******* End of Function **************/




/******* End of Function **************/






#endif
