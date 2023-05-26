#ifndef ADD_MULTIPLE_EDGE_HPP
#define ADD_MULTIPLE_EDGE_HPP
#include "ADJ/network_defs.hpp"
#include "binary_set_operations.hpp"
#include "ADJ/add_edge.hpp"
using namespace std;

 
//---Add edges from one source to many destinations
// Weight is set to one
void add_edgeS(A_Network *X, int src, vector<int> dest)
{
	//Add node1 --> node2s
	//Get Edge info
int node1=src;
int node2;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	
	//Initialize destinations;
	vector<int_double> colvals;
	int_double cv;
	colvals.resize(0);
	
	for(int i=0;i<dest.size();i++)
	{
		//Set destination
		node2=dest[i];
		
		if((node2<0) || (node2>=X->size()))
		{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
	
		cv.first=node2;
		cv.second=1;
		colvals.push_back(cv);
	}

	//Add Edge to node1;
	ADJ_Bundle Alist;	
	Alist=X->at(node1);
	Alist.ListW=merge (colvals,Alist.ListW);
	X->at(node1)=Alist;

	
	//Add node2s-->node1
	for(int i=0;i<dest.size();i++)
	{	
		Edge mye=create(dest[i],node1,1);	
		add_edge(X,mye,0,1);
	}
	
return;}

/*****************/

//---Add edges from one source to many destinations
// Weight is given
void add_edgeS(A_Network *X, int src, vector<int_double> dest)
{
	//Add node1 --> node2s
	//Get Edge info
	int node1=src;
	int node2;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	
	for(int i=0;i<dest.size();i++)
	{
		//Set destination
		node2=dest[i].first;
		
		if((node2<0) || (node2>=X->size()))
		{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
	}
	
	//Add Edge to node1;
	ADJ_Bundle Alist;	
	Alist=X->at(node1);
	Alist.ListW=merge (dest,Alist.ListW);
	X->at(node1)=Alist;
	
	
	//Add node2s-->node1
	int_double colvals1;
	double wt;
	colvals1.first=node1;
	for(int i=0;i<dest.size();i++)
	{	
		node2=dest[i].first;
		wt=dest[i].second;
		Alist=X->at(node2);
		colvals1.second=wt;
		Alist.ListW=merge (colvals1,Alist.ListW);
		X->at(node2)=Alist;
	}
	
return;}

//---Add edges from one source to many destinations
// Unidirectional;
//dir =0 is bidirectional dir=1 is unidirectional;
void add_edgeS(A_Network *X, int src, vector<int> dest, bool dir)
{
	//Add node1 --> node2s
	//Get Edge info
	int node1=src;
	int node2;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	
	//Initialize destinations;
	vector<int_double> colvals;
	int_double cv;
	colvals.resize(0);
	
	for(int i=0;i<dest.size();i++)
	{
		//Set destination
		node2=dest[i];
		
		if((node2<0) || (node2>=X->size()))
		{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
		
		cv.first=node2;
		cv.second=1;
		colvals.push_back(cv);
	}
	
	//Add Edge to node1;
	ADJ_Bundle Alist;	
	Alist=X->at(node1);
	Alist.ListW=merge (colvals,Alist.ListW);
	X->at(node1)=Alist;
	
	if(dir==0)
	{
	//Add node2s-->node1
	for(int i=0;i<dest.size();i++)
	{	
		Edge mye=create(dest[i],node1,1);	
		add_edge(X,mye,0,1);
	}
	}
	
return;}

/*****************/

//---Add edges from one source to many destinations
// Weight is given
// Unidirectional;
//dir =0 is bidirectional dir=1 is unidirectional;
void add_edgeS(A_Network *X, int src, vector<int_double> dest, bool dir)
{
	//Add node1 --> node2s
	//Get Edge info
	int node1=src;
	int node2;	
	
	//Check if the nodes exists
	if((node1<0) || (node1>=X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	
	//Initialize destinations;
	vector<int_double> colvals;
	int_double cv;
	colvals.resize(0);
	
	for(int i=0;i<dest.size();i++)
	{
		//Set destination
		node2=dest[i].first;
		
		if((node2<0) || (node2>=X->size()))
		{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
	}
	
	//Add Edge to node1;
	ADJ_Bundle Alist;	
	Alist=X->at(node1);
	Alist.ListW=merge (dest,Alist.ListW);
	X->at(node1)=Alist;
	
	if(dir==0)
	{
	//Add node2s-->node1
	for(int i=0;i<dest.size();i++)
	{	
		Edge mye=create(dest[i].first,node1,dest[i].second);	
		add_edge(X,mye,0,1);
	}
	}
	
return;}


//Add edge list
//Sorted and undirected
void add_edgeS(A_Network *X,  vector<Edge> edges)
{

	for(int i=0;i<edges.size();i++)
	{
	 add_edge(X,edges[i]);	
	}

return;}


void add_edgeS(A_Network *X,  vector<int_int> edges)
{
	
	for(int i=0;i<edges.size();i++)
	{
		add_edge(X,edges[i]);	
	}
	
return;}

//Add edge list
//---Option for edges to be sorted sort=1; unsort=0;
//Option for being directed or not node1->node2; undir=1; dir=0;

void add_edgeS(A_Network *X,  vector<Edge> edges, bool undir, bool sort)
{
	
	for(int i=0;i<edges.size();i++)
	{
		add_edge(X,edges[i],undir,sort);	
	}
	
return;}


/******* End of Functions **************/



#endif
