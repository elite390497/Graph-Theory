#ifndef COMBINE_NETWORKSX_HPP
#define COMBINE_NETWORKSX_HPP

#include "ADJ/network_traversal.hpp"
#include "ADJ/find_Xneighbors.hpp"
#include "ADJ/add_multiple_edge.hpp"
#include "binary_set_operations.hpp"
using namespace std;


template<class Type1>
void find_candidate_edgesX(A_Network X, A_Network Y, int node1, vector<Type1> *edge_list)
{

	int node2;
	int_int myedge;
	vector<int> neighbors, neighborsX, neighborsY, neighborsZ, neighborsi, neighborsj;
	vector<int> neighborsXX, neighborsYY, neighborsZZ; 	vector<int> blacklist;
	

		//Find distance 1 neighbors in i in chordal network Y
		get_neighbors(node1,Y[node1].ListW, &neighbors); //find a Adj to v
		if(neighbors.size()<2){return;} //If only one neighbor no edge can be formed
		
		//else find neighbors that are connected but not in Y
		//nodes not to be checked in blacklist
		blacklist.resize(0);
		blacklist.push_back(node1);
		for (int j=0;j<neighbors.size();j++)
		{
			int node2=neighbors[j];
			blacklist=merge(node2,blacklist);
		   
			//Find triangulating edges in  X;
			get_neighbors(node2,X[node2].ListW,&neighborsX, blacklist,neighbors); //get neighbors of node2;
		    if(neighborsX.size()==0){continue;}
			
			//Find triangulating edges in chordal Y;
			get_neighbors(node2,Y[node2].ListW,&neighborsj,blacklist,neighbors); //get neighbors of node2;
			
			//Collect edges in X but not in Y and Z
			if(neighborsj.size()>0){
				neighborsi=difference(neighborsX, neighborsj); 
				}
			else {neighborsi=neighborsX;}
			
			//cout << neighborsi.size() << "===\n";
			//add to edge_list
			for(int k=0;k<neighborsi.size();k++)
			  {myedge.first=min(node2, neighborsi[k]);
				myedge.second=max(node2, neighborsi[k]);
				  edge_list->push_back(myedge);
			} //end of for k			
			
		} //end of for j
		
	
return;
}
///////// End of Function 



void find_addable_edgesX(A_Network X, A_Network *Y, vector<int_int> edge_list)
{
	int a=-1, b=-1, path;
	vector<int> neighborsaY, neighborsbY, IYab,IXab, diffneighbors;
	vector<int> DYa, DYb;
	
	bool addable=false;
	bool deletable =false;
	int edge_add=0;
	int edge_del=0;
	bool found;
	int_int myedge;
	
	for (int i=0;i<edge_list.size();i++)
	{
		cout << edge_list.size() << "::"<< i <<"...\n";
		myedge=edge_list[i];
	
		a=myedge.first;
		b=myedge.second;
		addable=false;
		
		//Find IC(a,b)=Adj(a)^Adj(b)
		get_neighbors(a,Y->at(a).ListW,&neighborsaY); //get neighbors of a;
		get_neighbors(b,Y->at(b).ListW,&neighborsbY); //get neighbors of b;
		IYab=intersect(neighborsaY, neighborsbY);
		
		//pick top one
		int v=IYab[0];
		//find neighbors of v1 in Y but not in IYab
		get_neighbors(v,Y->at(v).ListW,&diffneighbors, IYab); //get neighbors of v not in IYab;
		path=0;
		
		
		//Conditions for addable
		//C1: join a and b if no diffneighbors
		if(diffneighbors.size()==0){addable=true; }
		else {
			//C2: Find neighbors of a in diffneighbors
			DYa=intersect(diffneighbors, neighborsaY);
			//If zero then a is disconnected--join
			if(DYa.size()==0) {addable=true;}
			else {
				//C3: Find neighbors of b in diffneighbors
				DYb=intersect(diffneighbors, neighborsbY);
				//If zero then b is disconnected--join
				if(DYb.size()==0){addable=true;}
				else {
					//C4: If there is no path from a to b using diffneighbors only
					path=shortest_path(a,b,*Y,diffneighbors);
					if(path==-1) {addable=true;}
				} //end of else
			}//end of else
						
		} //end of else

		//if addable--add to Y
		if(addable==true)
		{
			edge_add++;
			add_edge(&Y->at(a).ListW, &Y->at(b).ListW,myedge);
			//store affected nodes
			find_candidate_edgesX(X, *Y, a, &edge_list);
			find_candidate_edgesX(X, *Y, b, &edge_list);			
		}
		
		sort(&edge_list);
		edge_list=unique(edge_list);
		
	} //end of while
	cout << "Number of Edges Added :" << edge_add << "\n";
	cout << "Number of Edges Delted :" << edge_del << "\n";
	
	return;
}


//Add edges from X that form a triangle in Z
void add_edges_chdX(A_Network X, A_Network *Y)
{
	
	int total_nodes=X.size();
	vector<int_int> edge_list;
		
	//Initially check all vertices
	for(int i=0;i<total_nodes;i++)
	{find_candidate_edgesX(X,*Y,i,&edge_list);}
	sort(&edge_list);
	edge_list=unique(edge_list);
	
	//find candidate_edges
	cout << edge_list.size() << "\n";
	find_addable_edgesX(X,Y, edge_list); 
	
	
return;}
/******* End of Function **************/

//ICPP Algorithm

//Add edges from X that form a triangle in Z
void add_edges_chdPP(A_Network X, A_Network *Y)
{
	
	int total_nodes=X.size();
	vector<int_int> lp;
	int_int dx;
	dx.first=-1;
	dx.second=-1;
	lp.resize(total_nodes,dx);
	vector<int> Q1;
	Q1.resize(0);
	vector< vector<int> > chordal;
	vector<int> dummy;
	dummy.resize(1);
	dummy[0]=-1;
	chordal.resize(total_nodes, dummy);
	
	create_Network(total_nodes, 0,Y);

	
	//Obtain Lowest Parent of Each Vertex
	for(int i=0;i<total_nodes;i++)
	{
	
		if(X[i].ListW.size() >0)
		{
		 if(X[i].ListW[0].first < i)
		{
		lp[i].first=X[i].ListW[0].first; //This is beaucse the networks are sorted
		lp[i].second=0;	
		Q1.push_back(lp[i].first);
		}
		} //end of if
		else{lp[i].first=-1;
		     lp[i].second=-1;}
		
	}

	sort(&Q1);
	Q1=unique(Q1);
	
	vector<int> Q2;
	Q2.resize(0);
	vector<int> cW, cV, cX, cZ;
	int_int myedge;
	vector<int> neighbors;
	
	while(Q1.size()!=0)
	{
		Q2.resize(0);
		for(int x=0;x<Q1.size();x++)
		{
			
			int v=Q1[x];
			//cout << v << ":::"<< X[v].ListW.size() <<"+++"<<Q1.size() <<".."<<x<<"\n";
			if(X[v].ListW.size()>0)
			{
		get_neighbors(v, X[v].ListW, &neighbors);
			}

		//Check if subset
		//w=neighbors[i]
		for(int i=0;i< neighbors.size();i++)
		{   int w=neighbors[i];
			if(lp[w].first==v)
				{
					cW.clear();
					cW.clear();
					cX.clear();
					cZ.clear();
				//chordal of w
					 cW=chordal[w];
					 cV=chordal[v];
					
					//If subset if cW intersect cV gives cW
					cX=intersect(cW,cV);
					cZ=difference(cW,cX);
					if(cZ.size()==0) //is a subset==add v to w
					{
						chordal[w].push_back(v); //add v to chordal w
						myedge.first=w;
						myedge.second=v;
						
						add_edge(&Y->at(w).ListW, &Y->at(v).ListW,myedge); //add edge to y
						
						
						//Update lp[w]
						int k=lp[w].second+1;
						if(X[w].ListW.size() >k)
						{
						if(X[w].ListW[k].first < w)
						{
							lp[w].first=X[w].ListW[k].first; //This is beaucse the networks are sorted
							lp[w].second=k;
							Q2.push_back(lp[w].first);
						}
						}
						else{lp[i].first=-1;
						lp[i].second=-1;}	
					}//end of if
				
				} //end of if
			
				}//end of for i
			
				}//end of for x
		
		sort(&Q2);
		Q2=unique(Q2);
		
		Q1=Q2;
		
	} //end of while
	
	
return;}




#endif
