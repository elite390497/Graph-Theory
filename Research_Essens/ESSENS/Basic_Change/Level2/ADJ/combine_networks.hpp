#ifndef COMBINE_NETWORKS_HPP
#define COMBINE_NETWORKS_HPP

#include "ADJ/network_traversal.hpp"
#include "ADJ/find_Xneighbors.hpp"
#include "ADJ/add_multiple_edge.hpp"
#include "binary_set_operations.hpp"
using namespace std;






template<class Type1>
void find_candidate_edges(A_Network X, A_Network Y, A_Network Z, vector<int> vertex_list, vector<Type1> *edge_list)
{

	int node1, node2;
	int_int myedge;
	vector<int> neighbors, neighborsX, neighborsY, neighborsZ, neighborsi, neighborsj;
	vector<int> blacklist;
	edge_list->resize(0);
	
	//For each vertex find candidate edges
	for(int i=0;i<vertex_list.size();i++)
	{
		node1=vertex_list[i];
		
		//Find distance 1 neighbors in i in chordal network Y
		get_neighbors(node1,Y[node1].ListW, &neighbors); //find a Adj to v
		if(neighbors.size()<2){continue;} //If only one neighbor no edge can be formed
		
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
			get_neighbors(node2,Y[node2].ListW,&neighborsY,blacklist,neighbors); //get neighbors of node2;
			
			if(Z[node2].ListW.size()>0)
			{
			//Find triangulating edges in non-chordal Z
			get_neighbors(node2,Z[node2].ListW,&neighborsZ, blacklist,neighbors); //get neighbors of node2;
			//Find identify vertices that are not in Y and Z
			neighborsj=merge(neighborsZ, neighborsY);
			}
			else
			{neighborsj=neighborsY;}
			
			//Collect edges in X but not in Y and Z
			if(neighborsj.size()>0){
				neighborsi=difference(neighborsX, neighborsj); 
				}
			else {neighborsi=neighborsX;}
			
			//add to edge_list
			for(int k=0;k<neighborsi.size();k++)
			  {myedge.first=min(node2, neighborsi[k]);
				myedge.second=max(node2, neighborsi[k]);
				edge_list->push_back(myedge);
			} //end of for k			
			
		} //end of for j
		
	}//end of for i
	sort(edge_list);
	*edge_list=unique(*edge_list);
	//print_vector(*edge_list);
	
	
return;
}
///////// End of Function 



void find_addable_edges(A_Network X, A_Network *Y, A_Network *Z, vector<int_int> edge_list, vector<int> *used_vertex, bool *del_work)
{
	int a=-1, b=-1, path;
	vector<int> neighborsaY, neighborsbY, IYab,IXab, diffneighbors;
	vector<int> DYa, DYb;
	
	bool addable=false;
	bool deletable =false;
	int edge_add=0;
	int edge_del=0;
	bool found;
	used_vertex->resize(0);
	
	for(int i=0; i< edge_list.size(); i++)
	{
		a=edge_list[i].first;
		b=edge_list[i].second;
		addable=false;
		deletable=false;
		
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
			add_edge(&Y->at(a).ListW, &Y->at(b).ListW,edge_list[i]);
			//store affected nodes
			used_vertex->push_back(a);
			used_vertex->push_back(b);
		}
		else {
			//Deletable
			
			if(path>2 && *del_work)
			{ 
				int r=a;
				int p=b;
				int xt=0;
				while(xt<2)
				{
				vector<int> neighborsaX, neighborsbX, neighborsaZ, neighborsbZ, blacklist;
				//Find IG(a,b)=Adj(a)^Adj(b)
				blacklist.resize(0);
				neighborsaZ=blacklist;
				neighborsbZ=blacklist;
				
				if(Z->at(r).ListW.size()>0)
				{get_neighbors(r,Z->at(r).ListW,&neighborsaZ,blacklist,diffneighbors);}
				get_neighbors(r,X[r].ListW,&neighborsaX, neighborsaZ, diffneighbors); //get neighbors of a that are in path_nodes;
				if(neighborsaX.size()==0) 
				{edge_del++;
				add_edge(&Z->at(r).ListW, &Z->at(p).ListW,edge_list[i]);
					break;
				}
				
				else {
				if(Z->at(p).ListW.size()>0)
				{get_neighbors(p,Z->at(p).ListW,&neighborsbZ,blacklist,neighborsaX);}
				get_neighbors(p,X[p].ListW,&neighborsbX, neighborsbZ, neighborsaX); //get neighbors of b that are in path_nodes;
				
				if(neighborsbX.size()==0) 
				{edge_del++;
				add_edge(&Z->at(r).ListW, &Z->at(p).ListW,edge_list[i]);
			     break;
				}
				} //end of else
					xt++;
					r=diffneighbors[0];
				} //end of while
			} //end of if
			
		} //end of else
		
	
	}//end of for i;
	sort(used_vertex);
*used_vertex=unique(*used_vertex);	
	cout << "Number of Edges Added :" << edge_add << "\n";
	cout << "Number of Edges Delted :" << edge_del << "\n";
	if(edge_del <=edge_add*.2) {*del_work=false;}
	
	return;
}


//Add edges from X that form a triangle in Z
void add_edges_chd(A_Network X, A_Network *Y)
{
	
	int total_nodes=X.size();
	vector<int> vertex_list, used_vertex;
	vector<int_int> edge_list;
	
	//Create Network for unwanted edges
	//Number of nodes is total_nodes;
	A_Network Z;
	create_Network(total_nodes, 0,&Z);
	
	//Initially check all vertices
	vertex_list.resize(0);
	for(int i=0;i<total_nodes;i++)
	{vertex_list.push_back(i);}
	
	//find candidate_edges
	find_candidate_edges(X,*Y,Z,vertex_list,&edge_list);
	
	int it=1;
	int total_edges=total_nodes-1;
	cout << "\n Initial Edge " << total_edges << "\n";
	bool del_work=true;
	while(edge_list.size() >0)
	{
		cout << "\n Iterations: "<< it  << "\n";
			cout << "Vertices: "<< vertex_list.size() << "\n";
		cout << "Candidate Edge: "<< edge_list.size() << "\n";
	//Find addable edges for edge_list
	find_addable_edges(X,Y, &Z, edge_list, &vertex_list, &del_work); 
		
		//find candidate_edges
	find_candidate_edges(X,*Y, Z, vertex_list, &edge_list);
		it++;
	}
	
	
return;}
/******* End of Function **************/


//NOT PART OF CHORDAL ALGORITHM---
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
