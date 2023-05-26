#ifndef GET_NEXT_NODES_HPP
#define GET_NEXT_NODES_HPP
#include "unary_set_operations.hpp"
//#include "binary_set_operations.hpp"
#include "ADJ/add_edge.hpp"
using namespace std;

/***** Update the Priority Queue *****/
//Determine critical value of nodes
//Add node to heap
/***** Update the Priority Queue *****/

//Update Priority Q

//Single Element Selected ; Use marked value to check if new node
bool get_next_nodes(vector< pair<int_double, double> > *myheap, vector<double> marked, int *stnode)
{
	int_double tops;
	pair<int_double, double> top_elem;
	if(myheap->size()==0){ return false;}
	
	//Get top element that is not marked
	while(1)
	{
	if(myheap->size()==0){ return false;}	
	top_elem=myheap->at(0);
	pop_heap(myheap);
	tops=top_elem.first;
		
	if(marked[tops.first]>-1){ break;}
	}
	
	*stnode=tops.first;
	return true;
}



//Single Element Selected ; Use marked value to check if new node;; add to subgraph
bool get_next_nodes(vector< pair<int_int, double> > *myheap, vector<double> marked, int *stnode, vector<Edge> *myEdge)
{
	int_int tops;
	pair<int_int, double> top_elem;
	if(myheap->size()==0){ return false;}
	
	//Get top element that is not marked
	while(1)
	{
		if(myheap->size()==0){ return false;}	
		top_elem=myheap->at(0);
		pop_heap(myheap);
		tops=top_elem.first;

		if(marked[tops.first]>-1){ break;}
	}
	Edge mye=create(tops.first, tops.second, top_elem.second);
	myEdge->push_back(mye);
	*stnode=tops.first;		  
	return true;
}

//Single Element Selected ; Use marked value to check if new node;; add to subgraph
bool get_next_nodes(vector< pair<int_int, double> > *myheap, vector<double> marked, int *stnode, vector<int_int> *myEdge)
{
	int_int tops;
	pair<int_int, double> top_elem;
	if(myheap->size()==0){ return false;}
	
	//Get top element that is not marked
	while(1)
	{
		if(myheap->size()==0){ return false;}	
		top_elem=myheap->at(0);
		pop_heap(myheap);
		tops=top_elem.first;
		
		if(marked[tops.first]>-1){ break;}
	}
	myEdge->push_back(tops);
	*stnode=tops.first;		  
	return true;
}




//Multiple Elements Selected; Use marked value to check if new node
bool get_next_nodes(vector< pair<int_double, double> > *myheap, vector<double> marked, vector<int> *stnode)
{
	int_double tops;
	if(myheap->size()==0){ return false;}
	
	//Clear current set
	stnode->clear();
	
	//Get first element
	pair<int_double, double> top_elem=myheap->at(0);
	pop_heap(myheap);
	tops=top_elem.first;
	double highval=top_elem.second;
	stnode->push_back(tops.first);
	
	//Get rest of top elements
	while(1)
	{
	if(myheap->size()==0){break;}
	top_elem=myheap->at(0);
	tops=top_elem.first;
		
		//remove nodes already processed
	if(marked[tops.first]==-1) 
	 {pop_heap(myheap); continue;}
		
		//keep on adding elements that all have the same high value
	if(top_elem.second==highval)	
	{stnode->push_back(tops.first);
	 pop_heap(myheap);
	}
	else{break;}
		
	}
	
	return true;
}



#endif
