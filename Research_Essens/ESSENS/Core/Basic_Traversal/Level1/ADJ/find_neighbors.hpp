#ifndef FIND_NEIGHBORS_HPP
#define FIND_NEIGHBORS_HPP
#include "ADJ/network_defs.hpp"
#include "unary_set_operations.hpp"
using namespace std;


/****** Finds Distance 1 Neighbors *******/


//For single node =======
//For single nodes use only the corresponding row; not the entire network
//neighbors+wt
void get_neighbors(int node, vector<int_double> Vrow, vector<int_double> *neighbors)
{
	//clear neighbors;
	neighbors->clear();
	
	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{neighbors->push_back(Vrow[i]);}
	
return;}

/******* End of Function ***/

//only neighbors
void get_neighbors(int node, vector<int_double> Vrow, vector<int> *neighbors)
{
	//clear neighbors;
	neighbors->clear();
	
	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{neighbors->push_back(Vrow[i].first);}
	
return;}
/******* End of Function ***/

//only neighbors
void get_neighbors(int node, vector<int_double> Vrow, vector<int> *neighbors, vector<int> blacklist, vector<int> valid)
{
	//clear neighbors;
	neighbors->clear();
	
	
	//Add the neighbors;
	int ind=0;
	for(int i=0;i<Vrow.size();i++)
	{
		if(!contains_sort(blacklist, Vrow[i].first))
	{
		
	//if(contains_sort(valid, Vrow[i].first))
		int j=ind;
		for(;j<valid.size();j++)
	{ 
		if(valid[j]==Vrow[i].first)
		{neighbors->push_back(Vrow[i].first);
			ind=j+1;
		break;}
	}
		
	}
		if(ind==valid.size()){break;}
	}
	
return;}
/******* End of Function ***/


//only neighbors
void get_neighbors(int node, vector<int_double> Vrow, vector<int> *neighbors, vector<int> blacklist)
{
	//clear neighbors;
	neighbors->clear();
	
	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{if(!contains_sort(blacklist, Vrow[i].first))
	{
			neighbors->push_back(Vrow[i].first);
	}
	}
	
return;}
/******* End of Function ***/

//only edgelist
void get_neighbors(int node, vector<int_double> Vrow, vector<Edge> *neighbors)
{
	
	//clear neighbors;
	neighbors->clear();
	
	Edge mye;
	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{mye=create(node,Vrow[i].first, Vrow[i].second);
	 neighbors->push_back(mye);}
	
return;}
/**** End of Function ***/


// Get neighbors with blacklist
//Assume blacklist is sorted in increasing order
//neighbors+wt
template<class Type1>
void get_neighbors(int node, vector<int_double> Vrow, vector<int_double> *neighbors, vector<Type1> blacklist, const string &edge_prop)
{
	//clear neighbors;
	neighbors->clear();

	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{if(!contains_sort(blacklist, Vrow[i], edge_prop))
	neighbors->push_back(Vrow[i]);}	
	
return;
}

//only neighbors
template<class Type1>
void get_neighbors(int node, vector<int_double> Vrow, vector<int> *neighbors, vector<Type1> blacklist, const string &edge_prop)
{
	//clear neighbors;
	neighbors->clear();
	
	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{if(!contains_sort(blacklist, Vrow[i], edge_prop))
	 neighbors->push_back(Vrow[i].first);}	
	
return;}

//only edgelist
template<class Type1>
void get_neighbors(int node, vector<int_double> Vrow, vector<Edge> *neighbors, vector<Type1> blacklist, const string &edge_prop)
{
	//clear neighbors;
	neighbors->clear();
	
	Edge mye;
	//Add the neighbors;
	for(int i=0;i<Vrow.size();i++)
	{ if(!contains_sort(blacklist, Vrow[i], edge_prop))
		{mye=create(node,Vrow[i].first, Vrow[i].second);
		neighbors->push_back(mye);}
	}
	
return;}

/******* End of Functions **************/

//=================================
//For multiple nodes =======
//Send Network X, only if size of nodes is large enough. Otherwise use repeated calls to single nodes.
//neigbors will be repeated

//neighbors+wt
void get_neighbors(vector<int> nodes, A_Network X, vector<int_double> *neighbors)
{
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
	
	//Check for errors
	if((node<-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//Add the neighbors;
	for(int i=0;i<X[node].ListW.size();i++)
	{neighbors->push_back(X[node].ListW[i]);}
	
	} //end of for
	
//sort the neigbors
	sort(neighbors);
	
return;}

/******* End of Function ***/

//For multiple nodes =======
//Send Network X, only if size of nodes is large enough. Otherwise use repeated calls to single nodes.
//neigbors will be repeated

//neighbors+wt
void get_neighbors(vector<int> nodes, A_Network X, vector<int> *neighbors)
{
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Check for errors
		if((node<-1) || (node>=X.size()))
		{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
		
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{neighbors->push_back(X[node].ListW[i].first);}
		
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
	
return;}

/******* End of Function ***/



//only edgelist
void get_neighbors(vector<int> nodes, A_Network X, vector<Edge> *neighbors)
{
	
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Check for errors
		if((node<-1) || (node>=X.size()))
		{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
		
		Edge mye;
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{mye=create(node,X[node].ListW[i].first, X[node].ListW[i].second);
		neighbors->push_back(mye);}
		
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
		
return;}

/**** End of Function ***/


// Get neighbors with blacklist
//Assume blacklist is ordered in increasing order
//neighbors+wt
template<class Type1>
void get_neighbors(vector<int> nodes, A_Network X, vector<int_double> *neighbors, vector<Type1> blacklist, const string &edge_prop)
{
	
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Check for errors
		if((node<-1) || (node>=X.size()))
		{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
		
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{
			if(!contains_sort(blacklist, X[node].ListW[i], edge_prop)) 
			{neighbors->push_back(X[node].ListW[i]);}
		}
		
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
	
	return;
}

//only neighbors
template<class Type1>
void get_neighbors(vector<int> nodes, A_Network X, vector<int> *neighbors, vector<Type1> blacklist, const string &edge_prop)
{
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Check for errors
		if((node<-1) || (node>=X.size()))
		{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
		
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{
			if(!contains_sort(blacklist, X[node].ListW[i], edge_prop)) 
			{neighbors->push_back(X[node].ListW[i].first);}
		}
		
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
			
return;}

//only neighbors
template<class Type1>
void get_neighbors(vector<int> nodes, A_Network X, vector<int> *neighbors, vector<Type1> blacklist)
{
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Check for errors
		if((node<-1) || (node>=X.size()))
		{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
		
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{
			if(!contains_sort(blacklist, X[node].ListW[i].first)) 
			{neighbors->push_back(X[node].ListW[i].first);}
		}
		
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
	
return;}

//only neighbors
template<class Type1>
bool get_neighbors(vector<int> nodes, A_Network X, int node1, vector<int> *neighbors, vector<Type1> blacklist)
{
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	bool found=false;
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{
			if(X[node].ListW[i].first==node1) {found=true; break;}
			
			if(!contains_sort(blacklist, X[node].ListW[i].first)) 
			{neighbors->push_back(X[node].ListW[i].first);}
			
		}
		
		if(found){break;}
	} //end of for
	
	//sort the neigbors
	if(!found)
	{
	sort(neighbors);
	*neighbors=unique(*neighbors);
	}
	
return found;}

template<class Type1>
bool get_neighbors(vector<int> nodes, A_Network X, int node1, int node2, bool f1, bool f2, vector<int> *neighbors, vector<Type1> blacklist)
{
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	bool found=false;
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{
			if(!contains_sort(blacklist, X[node].ListW[i].first)) 
			{neighbors->push_back(X[node].ListW[i].first);}
			if(!f1){
			if(X[node].ListW[i].first==node1) {found=true;}}
			if(!f2) {
			if(X[node].ListW[i].first==node2) {found=true;}}
			if(found){break;}
		}
		
		if(found){break;}
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
	*neighbors=unique(*neighbors);
	
return found;}


//only edgelist
template<class Type1>
void get_neighbors(vector<int> nodes, A_Network X, vector<Edge> *neighbors, vector<Type1> blacklist, const string &edge_prop)
{
	
	//clear neighbors;
	neighbors->clear();
	
	//Iterate Through all the nodes 
	for (int k=0; k< nodes.size(); k++)
	{
		int node=nodes[k];
		
		//Check for errors
		if((node<-1) || (node>=X.size()))
		{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
		
		Edge mye;
		//Add the neighbors;
		for(int i=0;i<X[node].ListW.size();i++)
		{
			if(!contains_sort(blacklist, X[node].ListW[i], edge_prop))
			{mye=create(node,X[node].ListW[i].first, X[node].ListW[i].second);
			neighbors->push_back(mye);}
		}
		
	} //end of for
	
	//sort the neigbors
	sort(neighbors);
	
return;}

/******* End of Functions **************/

#endif
