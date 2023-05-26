#ifndef NETWORK_TRAVERSAL_HPP
#define NETWORK_TRAVERSAL_HPP
#include "ADJ/find_neighbors.hpp"
#include "ADJ/add_to_heap.hpp"
#include "ADJ/get_next_nodes.hpp"
#include "ADJ/update_values.hpp"
using namespace std;

/*** User Defined ***/
//1. Weighted: Yes or No
//2. Initial Blacklist
//3. Critical Values
//4. Output Form
//5. Stop: nodes*%; edge*%; node found; edge found; (0,1,2,3,..)
/**************************/
//Weighted
//No Blacklist
//No Critical Values
//Output Form A_Network
//Stop when all vertices reached


void traversalX_000(int node, A_Network X, void(*add_to_heap)(int, vector<int_double>, vector<double>*, vector< pair<int_int,double> >*), int times,A_Network *Y)
{
	//Initialize Output Network
	int total_nodes=X.size();
	create_Network(total_nodes,0,Y);
	
	//Initialize start_node
	int start_node=node;
	
	//Initialize critical values and place them in heap
	vector< pair<int_int,double> > myheap; 
	myheap.resize(0);
	make_heap(&myheap);
	
	//Priority element for each node
	vector<double> element_vals;
	element_vals.resize(X.size(),0);
	element_vals[start_node]=1;
	
	//Initialize neighbors
	vector<int_double> neighbors;
	
	//Initailize edgelist
	vector<int_int> myEdges;
	myEdges.resize(0);
	
	//continue while a valid node remains
	int it=0;
	while (it<times)
	{
		//Check for errors
		if((start_node<-1) || (start_node>=total_nodes))
		{cout <<"ESSENS:ERROR::   Row" << start_node << "Does not exist \n"; return;}
		
		//Get the next set of neighbors
		get_neighbors(start_node,X[start_node].ListW, &neighbors);
		
		//Update heap based on new values 
		add_to_heap(start_node,neighbors, &element_vals, &myheap);
		
		//Update Y and start node
		//single node updated by heap top
		if(!get_next_nodes(&myheap, element_vals,&start_node, &myEdges)){break;}
		
		it++;
		//cout << it << "\n";
	} //end of while
	
	add_edgeS(Y, myEdges);
		
	return;
}
/******** End of Function *****/

#endif
