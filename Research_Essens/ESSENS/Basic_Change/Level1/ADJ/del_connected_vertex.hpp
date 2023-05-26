#ifndef DEl_CONNECTED_VERTEX_HPP
#define DEL_CONNECTED_VERTEX_HPP

#include "extract_elements.hpp"
#include "unary_set_operations.hpp"
#include "ADJ/find_Xneighbors.hpp"
using namespace std;


//Node is left as singleton vertex
void del_vertex(A_Network *X, int node1)
{
	vector<int> neighs;
	get_all_neighbors(node1, *X, 1, &neighs);
	del_edgeS(X,node1,neighs);
	
return;}

//With option
//dir=0 bidirectional dir=1 unidirectional
void del_vertex(A_Network *X, int node1,bool dir)
{
	vector<int> neighs;
	get_all_neighbors(node1, *X, 1, &neighs);
	del_edgeS(X,node1,neighs,dir);
	
return;}


/******* End of Function **************/






#endif
