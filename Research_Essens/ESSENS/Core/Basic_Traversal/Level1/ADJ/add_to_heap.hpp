#ifndef ADD_TO_HEAP_HPP
#define ADD_TO_HEAP_HPP
using namespace std;
#include "ADJ/add_multiple_edge.hpp"

//Functions for adding neighbors to connected subgraph
//BFS--multiple nodes
//Neighbors stored as int_double
void add_to_heap_bfs(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_double, double> > *myheap, A_Network *Y)
{
	int node;
	pair<int_double,double> myval;
	vector<int_double> myDest;
	myDest.resize(0);
	
	//get next value
	double next_val=element_vals->at(prvnode)+1;
	//change prvnode val to show its been processed
	element_vals->at(prvnode)=-1;
    
  
	
	for(int i=0;i<neighbors.size();i++)
	{
		node=neighbors[i].first;
        
      
       
		//if(element_vals->at(node)>-1) //check if edge valid
            if(element_vals->at(node)==0)//check if it is not visited
		{  element_vals->at(node)=next_val; //distance from start node
			myval.second=element_vals->at(node);
			myval.first=neighbors[i];
			push_heap(myheap, myval, dec_second);
			myDest.push_back(neighbors[i]);
            
		}//end of if
		
	}//end of for
	

	add_edgeS(Y,prvnode,myDest);
}
/******** End of Function *****/
/////////////////////////////////


 //CHD--multiple nodes
 void add_to_heap_chd(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_double, double> > *myheap, A_Network *Y)
 {
 int node;
 pair<int_double,double> myval;
 vector<int_double> myDest;
 myDest.resize(0);
vector<int> neighbors1;	 
 vector<int> neighbors2;
	 
 //change prvnode val to show its been processed
  element_vals->at(prvnode)=-1;	 
  get_neighbors(prvnode, Y->at(prvnode).ListW, &neighbors1);
		 for(int i=0;i<neighbors.size();i++)
	 {
	 node=neighbors[i].first;
	
		 //Check if new node
		 if(element_vals->at(node)>-1)
		 {
			 //Check if edge valid
			get_neighbors(node, Y->at(node).ListW, &neighbors2);
			
		if(issubset(neighbors1, neighbors2)) //valid if subset
	{  element_vals->at(node)=element_vals->at(node)+neighbors[i].second; //number of connections to start_nodes
		myval.second=element_vals->at(node);
		myval.first=neighbors[i];
		 push_heap(myheap, myval, inc_second);
		myDest.push_back(neighbors[i]);
	} //end of if
	 } //end of if
		 
 }//end of for
 
	
	 add_edgeS(Y,prvnode,myDest);
 }
 /******** End of Function *****/
/////////////////////////////////


//MAXST--single node to be pushed by heap
void add_to_heap_maxst(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_int, double> > *myheap)
{
	int node;
	pair<int_int,double> myval;
	
	//change prvnode val to show its been processed
	element_vals->at(prvnode)=-1;	 

	for(int i=0;i<neighbors.size();i++)
	{
		node=neighbors[i].first;
		
		//Check if new node
		if(element_vals->at(node)>-1)
		{
		//	if(element_vals->at(node)<neighbors[i].second); //number of connections to start_nodes
			{
			  	myval.second=neighbors[i].second;
				myval.first.first=neighbors[i].first;
				myval.first.second=prvnode;
				push_heap(myheap, myval, inc_second);
			} //end of if
			
			} //end of if
		
	}//end of for
	
}
/******** End of Function *****/
///////////////////////////////////


//MINST--single node to be pushed by heap
void add_to_heap_minst(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_int, double> > *myheap)
{
    int node;
    pair<int_int,double> myval;
    
    //change prvnode val to show its been processed
    element_vals->at(prvnode)=-1;
    
    for(int i=0;i<neighbors.size();i++)
    {
        node=neighbors[i].first;
        
        //Check if new node
        if(element_vals->at(node)>-1)
        {
            //	if(element_vals->at(node)<neighbors[i].second); //number of connections to start_nodes
            {
                myval.second=neighbors[i].second;
                myval.first.first=neighbors[i].first;
                myval.first.second=prvnode;
                push_heap(myheap, myval, dec_second);
            } //end of if
            
        } //end of if
        
    }//end of for
    
}
/******** End of Function *****/
///////////////////////////////////

//DFS--single node to be pushed by heap
void add_to_heap_dfs(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_int, double> > *myheap)
{
	int node;
	pair<int_int,double> myval;
	
	//get next value
	double next_val=element_vals->at(prvnode)+1;
	//change prvnode val to show its been processed
	element_vals->at(prvnode)=-1;	 
	
	
	for(int i=0;i<neighbors.size();i++)
	{
		node=neighbors[i].first;
		
		if(element_vals->at(node)>-1) //check if edge valid
		{  element_vals->at(node)=next_val; //distance from start node
			myval.second=element_vals->at(node);
			myval.first.first=neighbors[i].first;
			myval.first.second=prvnode;
			push_heap(myheap, myval, inc_second);
		}//end of if
		
		
		
	}//end of for
	
}
/******** End of Function *****/
///////////////////////////////////


//RANDOM--single node--no repeats
void add_to_heap_rnd(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_int, double> > *myheap)
{
	int node;
	pair<int_int,double> myval;
	
	
	//get next value
	double next_val=element_vals->at(prvnode)+1;
	//change prvnode val to show its been processed
	element_vals->at(prvnode)=-1;	 
	
	for(int i=0;i<neighbors.size();i++)
	{
		node=neighbors[i].first;
		
		if(element_vals->at(node)>-1) //check if edge valid
		{  element_vals->at(node)=rand()%10; //distance from start node
			myval.second=element_vals->at(node);
			myval.first.first=neighbors[i].first;
			myval.first.second=prvnode;
			push_heap(myheap, myval, inc_second);
		}//end of if
		
		
		
	}//end of for
	
}
/******** End of Function *****/


//Random--Multiple node--no repeats
void add_to_heap_rnd1(int prvnode, vector<int_double> neighbors,  vector<double> *element_vals, vector< pair<int_double, double> > *myheap, A_Network *Y)
{
	int node;
	pair<int_double,double> myval;
	vector<int_double> myDest;
	myDest.resize(0);
	
	//get next value
	double next_val=element_vals->at(prvnode)+1;
	//change prvnode val to show its been processed
	element_vals->at(prvnode)=-1;
	
	for(int i=0;i<neighbors.size();i++)
	{
		node=neighbors[i].first;
		
		if(element_vals->at(node)>-1) //check if edge valid
		{  element_vals->at(node)=rand()%10; //distance from start node
			myval.second=element_vals->at(node);
			myval.first=neighbors[i];
			push_heap(myheap, myval, dec_second);
			myDest.push_back(neighbors[i]);
		}//end of if
		
	}//end of for
	
	
	add_edgeS(Y,prvnode,myDest);
}
/******** End of Function *****/
/////////////////////////////////


#endif
