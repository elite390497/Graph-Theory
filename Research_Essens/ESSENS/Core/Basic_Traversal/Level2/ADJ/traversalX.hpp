#ifndef TRAVERSAL_HPP
#define TRAVERSAL_HPP

#include "ADJ/network_traversal.hpp"



using namespace std;

/**Traversal based on these features ***/
// 1. Traverse Type: Node; Font; Pieces (0,1,2)
// 2. Increase Set: Node; Nodes; Subgraph (0,1,2);
// 3. Edges added as traversed (0); from top of heap (1);
//===Optional
// 4. Blacklist : Visited or Not X Node or Edge (00 (visited; node) (0); 01 (visited; edge)(1); 
/**************************/

void traversal(int node, A_Network X, const string &opt, A_Network *Y)
{
	//Find the matching options
	
	//BFS
	//multiple node travesal--1
	//increase by multiple nodes--1
	//Edges added as traversed--0
	if(opt=="bfs")
	{traversal_110(node,X,add_to_heap_bfs,Y);
	return; }
	
	//CHORDAL
	//single node travesal--0
	//increase by multiple nodes--1
	//Edges added as traversed--0
	if(opt=="chd")
	{traversal_010(node,X,add_to_heap_chd,Y);
		return;}
	
	//MAXST
	//single node travesal--0
	//increase by single node--0
	//create acyclic graph--0
	if(opt=="maxst")
	{traversal_000(node,X,add_to_heap_maxst,Y);
		return;}
	
	//DFS
	//single node travesal--0
	//increase by single node--0
	//create acyclic graph--0
	if(opt=="dfs")
	{traversal_000(node,X,add_to_heap_dfs,Y);
		return;}

	
	//RANDOM1
	//single node travesal--0
	//increase by single node--0
	//Edges added as traversed--0
	if(opt=="rnd")
	{traversal_000(node,X,add_to_heap_rnd,Y);
	return;}
	
	
}

/********/




/******* End of Functions **************/


#endif
