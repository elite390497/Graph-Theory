#ifndef COMBINE_NETWORKS_HPP
#define COMBINE_NETWORKS_HPP

#include "ADJ/network_traversal.hpp"
#include "ADJ/find_Xneighbors.hpp"
#include "ADJ/add_multiple_edge.hpp"
#include "binary_set_operations.hpp"
using namespace std;


//Combine Two Networks
//Add edges from X that form a triangle in Z
void add_triangles_chd(A_Network X, A_Network *Z)
{
	int total_nodes=X.size();
	
	vector<int> neighborsX;
	vector<int> neighborsY;
	vector<int> neighbors;
	
	int node1;
	int_int myedge;
	vector<int_int> myQ;
	vector<int> neighborsi;
	vector<int> neighborsj;
	vector<int> blacklist;

	A_Network Y=*Z;
	
	//Create Initial Set of Edges to be added
	for(int i=0;i<total_nodes;i++)
	{
		cout << i << "\n";
		//Find distance 1 neighbors in i in chordal network Y
		get_neighbors(i,Y[i].ListW, &neighbors); //find a Adj to v
				
		blacklist.resize(0);
		blacklist.push_back(i);
	
		if(neighbors.size()==1){continue;}
		//Find distance from each neighbor
		for (int j=0;j<neighbors.size();j++)
		{
			int node1=neighbors[j];
			blacklist=merge(node1,blacklist);
			
			//Find triangulating edges in chordal Y;
			get_neighbors(node1,Y[node1].ListW,&neighborsY,blacklist,neighbors); //get neighbors of node1;
			//Find triangulating edges in  X;
			get_neighbors(node1,X[node1].ListW,&neighborsX, blacklist,neighbors); //get neighbors of node1;
			
			if(neighborsX.size()==0){continue;}
			
			if(neighborsY.size()>0){
			//Find edges in X but not in Y
			neighborsi=difference(neighborsX, neighborsY); //find triangles a--b--v--a
			//neighborsi=intersect(neighborsj, neighbors);
			}
			else {neighborsi=neighborsX;}
				
			for(int k=0;k<neighborsi.size();k++)
			{myedge.first=min(node1, neighborsi[k]);
				myedge.second=max(node1, neighborsi[k]);
				myQ=merge(myedge, myQ);
			} //end of for k			
			
		} //end of for j
		
		}//end of for i
	myQ=unique(myQ);
	print_vector(myQ);
	//Done Creating Initial Set
	
	vector<int> neighborsaY;
	vector<int> neighborsbY;
	vector<int> neighborsvY;
	vector<int> diffneighbors;
	vector<int> DYa;
	vector<int> DYb;
	vector<int> IYab;
		
	int it=1;
		while(myQ.size()>0)
		{
			cout << "========== "<< it <<"\n";
			it++;
			myedge=myQ.back();
			myQ.pop_back();
			print_element(myedge);
			
			int a=myedge.first;
			int b=myedge.second;
			bool joined=false;
			
			//Find IC(a,b)=Adj(a)^Adj(b)
			get_neighbors(a,Y[a].ListW,&neighborsaY); //get neighbors of a;
			get_neighbors(b,Y[b].ListW,&neighborsbY); //get neighbors of b;
			//intersect
			IYab=intersect(neighborsaY, neighborsbY);
			//print_vector(IYab);
			
			//pick top one
			int v=IYab[0];
			//find neighbors of v1 in Y
			get_neighbors(v,Y[v].ListW,&diffneighbors, IYab); //get neighbors of v;
		
			//get neighbors of v1 not in IC(a,b)
			//diffneighbors=difference(neighborsvY,IYab);
			//print_vector(diffneighbors);
			
			//Find neighbors of a in diffneighbors
			DYa=intersect(diffneighbors, neighborsaY);
			//If zero then a is disconnected
			if(DYa.size()==0) {joined=true;}
			else{
			
			//Find neighbors of b in diffneighbors
			DYb=intersect(diffneighbors, neighborsbY);
				//If zero then b is disconnected
				if(DYb.size()==0){joined=true;}
				
				//check for path from a to b
				else {	
				int path=shortest_path(a,b,Y,diffneighbors);
					if(path==-1){joined=true;}
				}
			
			} //end of else;
		
			
				//if(a,b) in
			if(joined)
			{ 
				cout << "join " << a  << ":"<< b << "\n";	
				//Add (a,b) to Y
				add_edge( &Y, myedge);
				
				//Find edges from neighbors of a
				neighbors=neighborsaY;
				neighbors=merge(b, neighbors);
				
				if(neighbors.size( )>1)
				{
				for (int j=0;j<neighbors.size()-1;j++)
				{
					blacklist.resize(0);
					blacklist.push_back(a);
					int node1=neighbors[j];
					blacklist=merge(node1,blacklist);
					
					//Find triangulating edges in chordal Y;
					get_neighbors(node1,Y[node1].ListW,&neighborsY,blacklist,neighbors); //get neighbors of node1;
					//Find triangulating edges in  X;
					get_neighbors(node1,X[node1].ListW,&neighborsX, blacklist,neighbors); //get neighbors of node1;
					
					
					if(neighborsX.size()==0){continue;}
					
					if(neighborsY.size()>0){
						//Find edges in X but not in Y
						neighborsi=difference(neighborsX, neighborsY); //find triangles a--b--v--a
						//neighborsi=intersect(neighborsj, neighbors);
					}
					else {neighborsi=neighborsX;}
					
					for(int k=0;k<neighborsi.size();k++)
					{
						myedge.first=min(node1, neighborsi[k]);
						myedge.second=max(node1, neighborsi[k]);
						myQ=merge(myedge, myQ);
					} //end of for k		
					
				} //end of for j
				}//end of if
				
				//Find edges from neighbors of b
				neighbors=neighborsbY;
				neighbors=merge(a, neighbors);
				
				if(neighbors.size()>1)
				{
				blacklist.resize(0);
				blacklist.push_back(b);
				for (int j=0;j<neighbors.size();j++)
				{
							
					int node1=neighbors[j];
					blacklist=merge(node1,blacklist);
					
					//Find triangulating edges in chordal Y;
					get_neighbors(node1,Y[node1].ListW,&neighborsY,blacklist,neighbors); //get neighbors of node1;
					//Find triangulating edges in  X;
					get_neighbors(node1,X[node1].ListW,&neighborsX, blacklist,neighbors); //get neighbors of node1;
				
					if(neighborsX.size()==0){continue;}
					
					if(neighborsY.size()>0){
						//Find edges in X but not in Y
						neighborsi=difference(neighborsX, neighborsY); //find triangles a--b--v--a
						//neighborsi=intersect(neighborsj, neighbors);
					}
					else {neighborsi=neighborsX;}
					
					for(int k=0;k<neighborsi.size();k++)
					{
						myedge.first=min(node1, neighborsi[k]);
						myedge.second=max(node1, neighborsi[k]);
						myQ=merge(myedge, myQ);
					} //end of for k	
				} //end of for j
				} //end of if
				
				
				
			}//end of if
			
			myQ=unique(myQ);
		//	print_vector(myQ);
			
		} //end of while
		
	
	
	*Z=Y;

		
	
	
return;}
/******* End of Function **************/


//Combine Two Networks
//Add edges from X that form a triangle in Z
void combine_networks_tri(A_Network X, A_Network *Z)
{

	int total_nodes=X.size();
	int node1, node2;
	vector<int> di_neighborsY;
	vector<int> d1_neighborsX;
	vector<int> d1_neighborsY;
	vector<int> d1_neighborsXY;
	
	A_Network Y=*Z;
	for(int i=0;i<total_nodes;i++)
	{
		//Find distance 1 neighbors in Y
		get_neighbors(i,Y[i].ListW, &di_neighborsY);
		
		if(di_neighborsY.size()==1){continue;}
	
		//Check How many di_neighborsY are also d1_neighbors in Y
		sort(&di_neighborsY);
		for(int j=0; j<di_neighborsY.size();j++)
		{
			node1=di_neighborsY[j];
			d1_neighborsXY.resize(0);
			for(int k=j+1; k<di_neighborsY.size();k++)
			{
				node2=di_neighborsY[k];

				//Check if not neighbor of Y--then 
				if(!contains_sort(node2, Z->at(node1).ListW,  "first"))
				   { 
					   //Check if neighbor of X
					   if(contains_sort(node2,X[node1].ListW, "first"))
				   {d1_neighborsXY.push_back(node2);}
				   } //end of if
						   
			} // end of for
			
			//Add edges to Z
			add_edgeS(Z, node1, d1_neighborsXY);
		}//end of for -j
	}//end of for -i	

	
return;}
/******* End of Function **************/



#endif
