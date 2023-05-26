#ifndef SELECT_ELEMENTS_HPP
#define SELECT_ELEMENTS_HPP
#include<algorithm>
#include "binary_set_operations.hpp"
using namespace std;


/****** Functions to Select Set of Network Elements *******/
//Pick Two Random Edges that are disconnected
void pick_random_2edges(A_Network X, vector<Edge> *edges)
{
	//Inititialize
	edges->clear();
	int i=0;
	int v1, v2,v3,v4,ind, wt;
	int_double dummy;
	int nodes=X.size();
	Edge mye;
	vector<int> nodes_selected;
	nodes_selected.clear();
	
	

	//Select first Edge  
		//Select first node
		srand (time(NULL));
		v1=rand()%nodes;
		
		//Select connector from adjacency list
			srand (time(NULL));
		ind=rand()%X[v1].ListW.size();
		v2=X[v1].ListW[ind].first;
		wt=X[v1].ListW[ind].second;
		
		nodes_selected.push_back(v1);
		nodes_selected.push_back(v2);
	
	mye=create(v1,v2,wt);
	edges->push_back(mye);

	//Keep Selecting second edge until condition met
	while(1)
	{
		//Select first node
		srand (time(NULL));
		v3=rand()%nodes;
		
		
		//go back if v3 been selected
		if(contains(nodes_selected,v3)) {continue;} 
		   
		 //go back if v2 connected to v3
		   if(contains_sort(v2, X[v3].ListW,"first")){continue;}
		
		//Select connector from adjacency list
		srand (time(NULL));
		ind=rand()%X[v3].ListW.size();
		v4=X[v3].ListW[ind].first;
		wt=X[v3].ListW[ind].second;
		
		  //go back if v4 been selected
		   if(contains(nodes_selected,v4)) {continue;}    
			//go back if v4 connected to v1
			  if(contains_sort(v4,X[v1].ListW, "first")){continue;}
				 
				 break;		 
	}
	
				 mye=create(v3,v4,wt);
				 edges->push_back(mye);
	
	
	return;
}

/******* End of Functions **************/

//Pick Random Edges; Edges are distinct but may or may not be connected
//If in=TRUE pick edges that are in the network
//If in ==FALSE pick edges that are NOT in the network
void pick_random_edges(A_Network X, vector<Edge> *edges, int num, bool in)
{
	//Inititialize
	edges->clear();
	int i=0;
	int v1, v2,a,b,ind, wt;
	vector<int> src;
	src.clear();
	
	vector<int> dest;
	dest. clear();
	
	int_double dummy;
	int nodes=X.size();
	Edge mye;
	vector<int> nodes_selected;
	nodes_selected.clear();
	
	int it=0;
	
    v2=0;
	while(it < num)
	{
	//Select first Edge  
	//Select first node
		srand (v2+time(0));
	v1=rand()%nodes;
		
	if(in)	
	{
	//Select connector from adjacency list
		srand (v1+time(0));
	ind=rand()%X[v1].ListW.size();
	v2=X[v1].ListW[ind].first;
	wt=X[v1].ListW[ind].second;
	} 
   else
	{
		while(1)
		{
		//Select connector from adjacency list
			srand (v1+time(0));
		v2=rand()%nodes;
		//check if it is not connected
			if(!contains_sort(v2, X[v1].ListW, "first") && (!(v1==v2))){wt=1; break;};
		} //out when we find the vertex
	} //end of if
	
		a=min(v1,v2);
		b=max(v1,v2);
	mye=create(a,b,wt);
		
		//check if edge is not alread selected add it
		if(!contains_sort(*edges, mye))
		{ *edges=merge(mye,*edges); it++;}
		
		
		
	//cout << it <<"==\n";
	} //end of while
	return;
}

/******* End of Functions **************/

#endif
