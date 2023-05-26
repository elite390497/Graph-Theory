#ifndef UPDATE_VALUES_HPP
#define UPDATE_VALUES_HPP

#include "ADJ/add_edge.hpp"
using namespace std;

//Join to Acyclic Graph
//Used nodes marked in vector
void acyclic0(int node1, vector<int_double> neighbors, vector<double> elements, A_Network *Y)
{
	vector<Edge> myedge;
	Edge mye;
	
	for(int i=0;i<neighbors.size();i++)
	{
	  if((elements[neighbors[i].first]==0))
		 { mye=create(node1, neighbors[i].first, neighbors[i].second);
		 //myedge.push_back(mye);
		 add_edge(Y,mye);
		 }
	} //end of for
		 
		 //add_edges(Y,myedge);		   
}
/******** End of Function *****/


//Join to Acyclic Graph
//Blacklist visited Nodes
//Fontwise  Traversal
//Single Element Added
//Weighted Traversal
void update_values_acyclic0(Edge tops,  vector<int> *stnode, vector<int> *blacklist, A_Network *Y)
{
	
	int mynode;
	get(tops,"node2",&mynode);
	stnode->push_back(mynode);
	*blacklist=merge(mynode, *blacklist);
	add_edge(Y,tops);			   
}
/******** End of Function *****/


//Join to Chordal Graph
//Blacklist visited Nodes
//Single Node  Traversal
//Multiple Element Added
//Weighted Traversal
void update_values_chordal0(Edge tops,  int *stnode, vector<int> *blacklist,  vector<Edge> neighbors, A_Network *Y)
{
	
	int mynode;
	get(tops,"node2",&mynode);
	*stnode=mynode;
	*blacklist=merge(mynode, *blacklist);
	add_edge(Y,tops);	
	//vector<int_double> myvec;
	
	//Add neighbors if they form chordal
	//Check if chordal--neighbors(node2) should be subset of neighbors of (node1)
	/*int node1;
	int node2;
	vector<int> neighbors1;
	vector<int> neighbors2;
	clock_t q;
	
	cout << "galu \n";
	cout << "::::: "<< neighbors.size()<<"\n";
	q=clock();
	get(neighbors[0],"node1",&node1);
	//myvec.clear();
	//myvec=Y->at(node1).ListW; 
	getx_neighbors(node1, Y->at(node1).ListW, &neighbors1);
	cout << "palu \n";
	for(int i=0;i<neighbors.size();i++)
	{
		

		get(neighbors[i],"node2",&node2);
		//myvec.clear();
		//myvec=Y->at(node2).ListW; 
		getx_neighbors(node2, Y->at(node2).ListW, &neighbors2);
	//	cout << "chalu "<< i <<":;" << node2 <<"\n";	
		
	if(issubset(neighbors1, neighbors2))
	   {  add_edge(Y,neighbors[i]);	}
		
	} //end of for
	q=clock()-q;
	
	cout << "Time---"<< ((float)q)/CLOCKS_PER_SEC <<"\n";*/
	
	
	return;
}
/******** End of Function *****/

#endif
