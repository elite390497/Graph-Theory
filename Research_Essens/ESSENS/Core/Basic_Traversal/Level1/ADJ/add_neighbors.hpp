#ifndef ADD_NEIGHBORS_HPP
#define ADD_NEIGHBORS_HPP
using namespace std;


//Functions for adding neighbors to connected subgraph
//BFS--single node
//Neighbors stored as int_double
template <class Type1, class Type2>
void add_to_heap_bfs(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_double, double> > * myheap)
{
	int node;
	pair<int_double,double> myval;
	
	//get next value
	Type2 next_val=element_vals->at(prvnode)+1;
	
	for(int i=0;i<neighbors.size();i++)
	{
		node=neighbors[i].first;
		
		if(element_vals->at(node)==0)
		{  element_vals->at(node)=next_val; //distance from start node
			myval.second=element_vals->at(node);
			myval.first=neighbors[i];
			push_heap(myheap, myval, dec_second);
		}//end of if

	}//end of for
	
}
/******** End of Function *****/





///////////////////////////////////
//DFS--single node
template <class Type1, class Type2>
void add_to_heap_dfs(int prvnode, vector<Edge> neighbors,  vector<Type2> *element_vals, vector< pair<Type1, Type2> > * myheap, vector<Edge> *myEdges)
{
	int node;
	pair<Type1,double> myval;
	
	prvnode=neighbors[0].node1;
	for(int i=0;i<neighbors.size();i++)
	{	
		node=neighbors[i].node2;
		element_vals->at(node)=element_vals->at(prvnode)+1; //depth
		myval.second=element_vals->at(node);
		myval.first=neighbors[i];
		push_heap(myheap, myval, inc_second);
	}//end of for
	
	
	
}
/******** End of Function *****/

//MAXST--Font of Nodes
template <class Type1, class Type2>
void add_to_heap_maxst(vector<Edge> neighbors,  vector<Type2> *element_vals, vector< pair<Type1, Type2> > * myheap)
{
	int node;
	double weight;
	pair<Edge,double> myval;
	
	for(int i=0;i<neighbors.size();i++)
	{get(neighbors[i], "node2", &node);
	 get(neighbors[i], "wt", &weight);	
		
		if(element_vals->at(node)<weight) //critical value=max weight
		{
		element_vals->at(node)=weight;
		myval.second=element_vals->at(node);
		myval.first=neighbors[i];
		push_heap(myheap, myval, inc_second);
		} //end of if
		
	}//end of for
	
}
/******** End of Function *****/
/*
//CHD--Font of Nodes
template <class Type1, class Type2>
void add_to_heap_chd(vector<Edge> neighbors,  vector<Type2> *element_vals, vector< pair<Type1, Type2> > * myheap)
{
	int node1, node2;
	double weight;
	vector<int> neighbors1;
	vector<int> neighbors2;
	pair<Edge,double> myval;
	
	getx_neighbors(node1, Y->at(node1).ListW, &neighbors1);
	for(int i=0;i<neighbors.size();i++)
	{get(neighbors[i], "node2", &node2);
	 get(neighbors[i], "wt", &weight);
		
		//check if edges are suitable for addition
			getx_neighbors(node2, Y->at(node2).ListW, &neighbors2);
		if(issubset(neighbors1, neighbors2))
		{  element_vals->at(node2)=element_vals->at(node2)+weight; //number of connections to start_nodes
			myval.second=element_vals->at(node2);
			myval.first=neighbors[i];
			push_heap(myheap, myval, inc_second);
		} //end of if
		
	}//end of for

}
/******** End of Function *****/

#endif
