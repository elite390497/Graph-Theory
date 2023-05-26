#ifndef DEL_EDGE_HPP
#define DEL_EDGE_HPP
#include "ADJ/network_defs.hpp"
#include "extract_elements.hpp"
#include "unary_set_operations.hpp"
using namespace std;


//Delete Single Edge
//ASSUMPTIONS---
//Both nodes should exist in the network
//Weight is not considered when checking for edges to delete
//======
//---remove both ends from network
void del_edge(A_Network *X, Edge mye)
{

 ADJ_Bundle Alist;	
	
//Get Edge info
int node1=mye.node1;	
int node2=mye.node2;	
vector<int> index;
		
	//Check if the nodes exists
	if((node1<0) || (node1==X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	if((node2<0) || (node2==X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}

	
	//Remove node1-->node2
		Alist=X->at(node1);
		//Find if node2 is connected to node1
		contains (Alist.ListW,"first",node2, "all",node2, &index); 
		if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node1 << "->"<< node2<<" Does not exist \n"; return;}
		
		//Erase node from list
		Alist.ListW.erase(Alist.ListW.begin()+index[0]);
	//Udate Alist
	X->at(node1)=Alist;
	
	//Remove node2-->node1
	Alist=X->at(node2);
	//Find if node2 is connected to node1
	contains (Alist.ListW,"first",node1, "all",node1, &index); 
	if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node2 << "->"<< node1<<" Does not exist \n"; return;}
	
	//Erase node from list
	Alist.ListW.erase(Alist.ListW.begin()+index[0]);
	//Udate Alist
	X->at(node2)=Alist;
	
	return;}



//ASSUMPTIONS---
//Both nodes should exist in the network
//Weight is not considered when checking for edges to delete
//======
//---remove only specified end from network--0 node1--node2 removed ; 1 node2--node1 removes
void del_edge(A_Network *X, Edge mye, int dir)
{
	
	ADJ_Bundle Alist;	
	
	//Get Edge info
	int node1=mye.node1;	
	int node2=mye.node2;	
	vector<int> index;
	
	//Check if the nodes exists
	if((node1<0) || (node1==X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	if((node2<0) || (node2==X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return;}
	
	if(dir==0)
	{
	//Remove node1-->node2
	Alist=X->at(node1);
	//Find if node2 is connected to node1
	contains (Alist.ListW,"first",node2, "all",node2, &index); 
	if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node1 << "->"<< node2<<" Does not exist \n"; return;}
	
	//Erase node from list
	Alist.ListW.erase(Alist.ListW.begin()+index[0]);
	//Udate Alist
	X->at(node1)=Alist;
	}
	
	else{
	
	if(dir==1)
	{
	//Remove node2-->node1
	Alist=X->at(node2);
	//Find if node2 is connected to node1
	contains (Alist.ListW,"first",node1, "all",node1, &index); 
	if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node2 << "->"<< node1<<" Does not exist \n"; return;}
	
	//Erase node from list
	Alist.ListW.erase(Alist.ListW.begin()+index[0]);
	//Udate Alist
	X->at(node2)=Alist;
	}
	
	else {cout <<"ESSENS:ERROR:: Opion for dir=" <<dir <<" not defined \n"; return;}
	} //edn of first else
return;}
/******* End of Functions **************/



#endif
