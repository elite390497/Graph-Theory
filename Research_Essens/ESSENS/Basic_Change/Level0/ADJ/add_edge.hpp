#ifndef ADD_EDGE_HPP
#define ADD_EDGE_HPP
#include "ADJ/network_defs.hpp"
#include "extract_elements.hpp"
#include "binary_set_operations.hpp"
using namespace std;


//Add Single Edge
//Both end nodes  exist in the network
// The edge does not exist--otherwise duplicates are added

//Default 
//---Undirected Edge Add
//---Edges in network are sorted in increasing order.
void add_edge(A_Network *X, Edge mye)
{
	
 int_double colvals;
 ADJ_Bundle Alist;	

	//Get Edge info
int node1=mye.node1;	
int node2=mye.node2;	
double wt=mye.edge_wt;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	if((node2<0) || (node2>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}

	//Add Edge to node1;
	Alist=X->at(node1);
	colvals.first=node2;
	colvals.second=wt;
	Alist.ListW=merge (colvals,Alist.ListW);
	X->at(node1)=Alist;
	
	//Add Edge to node2;
	Alist=X->at(node2);
	colvals.first=node1;
	colvals.second=wt;
	Alist.ListW=merge (colvals,Alist.ListW);
	X->at(node2)=Alist;
	
return;}
/******* End of Functions **************/



//---Undirected Edge Add
//---Edges in network are sorted in increasing order.
void add_edge(A_Network *X, int_int nodes)
{
	
	int_double colvals;
	ADJ_Bundle Alist;	
	
	//Get Edge info
	int node1=nodes.first;	
	int node2=nodes.second;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	if((node2<0) || (node2>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
	
	//Add Edge to node1;
	Alist=X->at(node1);
	colvals.first=node2;
	colvals.second=1;
	Alist.ListW=merge (colvals,Alist.ListW);
	X->at(node1)=Alist;
	
	//Add Edge to node2;
	Alist=X->at(node2);
	colvals.first=node1;
	colvals.second=1;
	Alist.ListW=merge (colvals,Alist.ListW);
	X->at(node2)=Alist;
	
return;}
/******* End of Functions **************/

//---Undirected Edge Add
//---Option for edges to be sorted sort=1; unsort=0;
//Option for being directed or not node1->node2; undir=1; dir=0;
void add_edge(A_Network *X, Edge mye, bool undir, bool sort)
{
	int_double colvals;
	ADJ_Bundle Alist;	
	
	//Get Edge info
	int node1=mye.node1;	
	int node2=mye.node2;	
	double wt=mye.edge_wt;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	if((node2<0) || (node2>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
	
	//This edge will be added always
	//Add Edge to node1;
	Alist=X->at(node1);
	colvals.first=node2;
	colvals.second=wt;
	if(sort) {Alist.ListW=merge (colvals,Alist.ListW);}
	else {Alist.ListW.push_back(colvals);}
	X->at(node1)=Alist;
	
	//This edge will added only if undirected
	if(undir)
	{
	//Add Edge to node2;
	Alist=X->at(node2);
	colvals.first=node1;
	colvals.second=wt;
	if(sort) {Alist.ListW=merge (colvals,Alist.ListW);}
	else {Alist.ListW.push_back(colvals);}
	X->at(node2)=Alist;
	} //end of if
	
	
return;}

/******* End of Functions **************/

//---Undirected Edge Add
//---Edges in network are sorted in increasing order.
void add_edge(vector<int_double> *X1, vector<int_double> *X2, int_int nodes)
{
	
	int_double colvals;
	
	//Get Edge info
	int node1=nodes.first;	
	int node2=nodes.second;	
	
		//Add Edge to node1;
	colvals.first=node2;
	colvals.second=1;
	*X1=merge (colvals,*X1);
	*X1=unique(*X1);
	
	//Add Edge to node2;
	colvals.first=node1;
	colvals.second=1;
	*X2=merge(colvals,*X2);
	*X2=unique(*X2);
	
	
return;}
/******* End of Functions **************/



#endif
