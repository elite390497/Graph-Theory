#ifndef DEl_MULTIPLE_EDGE_HPP
#define DEL_MULTIPLE_EDGE_HPP
#include "ADJ/network_defs.hpp"
#include "extract_elements.hpp"
#include "unary_set_operations.hpp"
#include "ADJ/del_edge.hpp"
using namespace std;



//Single source multiple destination
//No weight given
void del_edgeS(A_Network *X, int src, vector<int> dest)
{
 	
//Get Edge info
int node1=src;	
	
	//Check if the nodes exists
	if((node1<0) || (node1==X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
		
	//Remove node1-->node2s
	ADJ_Bundle Alist;
	vector<int> index;
		Alist=X->at(node1);
	
	
	
	for(int i=0; i<dest.size();i++)
	{
		//Find if node2 is connected to node1
		contains (Alist.ListW,"first",dest[i], "all",dest[i], &index); 
		if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node1 << "->"<< dest[i]<<" Does not exist \n"; return;}
		
		//Erase node from list
		Alist.ListW.erase(Alist.ListW.begin()+index[0]);
	}
	//Udate Alist
	X->at(node1)=Alist;
	
	for(int i=0;i<dest.size();i++)
	{
		Edge mye=create(dest[i],src,1);
		del_edge(X,mye,0);
	}//end of for
	
return;}



//Single source multiple destination
//No weight given
//dir=0 node1->node2 dir=1 node2->node1
void del_edgeS(A_Network *X, int src, vector<int> dest, bool dir)
{
 	
	//Get Edge info
	int node1=src;	
	
	//Check if the nodes exists
	if((node1<0) || (node1==X->size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return;}
	
	//Remove node1-->node2s
	if(dir==0)
	{
	ADJ_Bundle Alist;	
	Alist=X->at(node1);
	vector<int> index;
	
	for(int i=0; i<dest.size();i++)
	{
		//Find if node2 is connected to node1
		contains (Alist.ListW,"first",dest[i], "all",dest[i], &index); 
		if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node1 << "->"<< dest[i]<<" Does not exist \n"; return;}
		
		//Erase node from list
		Alist.ListW.erase(Alist.ListW.begin()+index[0]);
	}
	//Udate Alist
	X->at(node1)=Alist;
	}
	
	if(dir==0)
	{
	for(int i=0;i<dest.size();i++)
	{
		Edge mye=create(dest[i],src,1);
		del_edge(X, mye,0);
	}//end of for
	} //end of if
	
return;}


//Delete set of edges
void del_edgeS(A_Network *X, vector<Edge> edges)
{
	
	
	Edge mye;
	ADJ_Bundle Alist;
	for (int i=0;i<edges.size();i++)
	{ cout << i <<"\n";
		mye=edges[i];
		
		//Get Edge info
		int node1=mye.node1;	
		int node2=mye.node2;	
		vector<int> index;
		
		//Check if the nodes exists
		if((node1<0) || (node1==X->size()))
		{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n";}
		if((node2<0) || (node2==X->size()))
		{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n";}
		
		
		//Remove node1-->node2
		Alist=X->at(node1);
		//Find if node2 is connected to node1
		contains (Alist.ListW,"first",node2, "all",node2, &index); 
		if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node1 << "->"<< node2<<" Does not exist \n";}
		else {
		//Erase node from list
		Alist.ListW.erase(Alist.ListW.begin()+index[0]);}
		//Udate Alist
		X->at(node1)=Alist;
		
		//Remove node2-->node1
		Alist=X->at(node2);
		//Find if node2 is connected to node1
		contains (Alist.ListW,"first",node1, "all",node1, &index); 
		if(index.size()==0){cout <<"ESSENS:ERROR::   Edge" << node2 << "->"<< node1<<" Does not exist \n";}
		else {
		//Erase node from list
		Alist.ListW.erase(Alist.ListW.begin()+index[0]);}
		//Udate Alist
		X->at(node2)=Alist;
	}	
	
	return;
}

//One side only
//dir=0; del node1->node2; dir=1 del node2-->node1
void del_edgeS(A_Network *X, vector<Edge> edges, bool dir)
{
	Edge mye;
	ADJ_Bundle Alist;
	for (int i=0;i<edges.size();i++)
	{ cout << i <<"\n";
		mye=edges[i];
	
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
	
	}	
	
	return;
}


//Single source multiple destination
//weight given
void del_edgeS(A_Network *X, int src, vector<int_double> dest)
{
	vector<int> mydest;
	get_all(dest, "first", &mydest);
	del_edgeS(X, src, dest);
	
return;}

//With Options
//Single source multiple destination
//weight given
//dir=0 bidirectional dir=1 unidirectional
void del_edgeS(A_Network *X, int src, vector<int_double> dest, bool dir)
{
	vector<int> mydest;
	get_all(dest, "first", &mydest);
	del_edgeS(X, src, mydest,dir);
	
return;}
/******* End of Functions **************/



#endif
