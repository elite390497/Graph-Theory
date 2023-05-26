#ifndef FIND_XNEIGHBORS_HPP
#define FIND_XNEIGHBORS_HPP
#include "ADJ/find_neighbors.hpp"
#include "extract_elements.hpp"
#include "order_elements.hpp"
#include "binary_set_operations.hpp"
#include "unary_set_operations.hpp"
using namespace std;



/****** Finds All Nodes Accessible at Distance <=k *******/
//defined for only one starting node---for many nodes kth distance can be conflicting
//Neighbors are not repreated
//Rows are sequential starting from 0
//Largest Row is size of A_network-1;

//Default
void get_unq_neighbors(int node, A_Network X, int k, vector<int> *neighbors)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	visited_nodes.resize(0);
	visited_nodes.push_back(node);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");

		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Update visited_nodes
		visited_nodes=merge(visited_nodes, next_level_nodes);
		
		//Update neighbors
		*neighbors=merge(*neighbors, cur_neighbors);
		
		distance++;
	}	
	*neighbors=unique(*neighbors);

	return;
}
/**** End of Function ***/

//Varied Neighbor Type
//no blacklist
template<class Type1>
void get_unq_neighbors(int node, A_Network X, int k, vector<Type1> *neighbors, const string &opt1)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<Type1> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	visited_nodes.resize(0);
	visited_nodes.push_back(node);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		get_all(cur_neighbors, opt1, &next_level_nodes);
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Update visited_nodes
		visited_nodes=merge(visited_nodes, next_level_nodes);
		
		//Update neighbors
		*neighbors=merge(*neighbors, cur_neighbors);
		
		distance++;
	}	
	
	*neighbors=unique(*neighbors,opt1,eq,next_level_nodes[0]);
	return;
}

/**** End of Function ***/

//With blacklist
template<class Type1, class Type2>
void get_unq_neighbors(int node, A_Network X, int k, vector<Type1> *neighbors, vector<Type2> blacklist, const string &node_prop, const string &blk_prop)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<Type1> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;   //Set of nodes reached
	vector<int> next_level_nodes; //Source nodes for each level
	vector<int> black_nodes; //List of nodes not to traverse;

	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	visited_nodes.resize(0);
	visited_nodes.push_back(node);
	black_nodes.resize(0);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		get_all(cur_neighbors, node_prop, &next_level_nodes);
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Add new nodes to visited nodes
		visited_nodes=merge(visited_nodes,next_level_nodes);
		
		//remove blacklist nodes from next_level_nodes
		get_all(blacklist,blk_prop,&black_nodes);
		next_level_nodes=difference(next_level_nodes, black_nodes);
		
		//Add new neighbors to total_neighbors
		*neighbors=merge(*neighbors, cur_neighbors);
		
		distance++;
	}
	
	*neighbors=unique(*neighbors,node_prop,eq,next_level_nodes[0]);
	return;
}
/**** End of Function ***/



/****** Finds All Nodes Accessible at Distance <=k *******/
//defined for only one starting node---for many nodes kth distance can be conflicting
//Neighbors are  repeated including starting node;
//This traversal will cause cycles
//Rows are sequential starting from 0
//Largest Row is size of A_network-1;

//Default
void get_all_neighbors(int node, A_Network X, int k, vector<int> *neighbors)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> next_level_nodes; //Source nodes for each level
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors);
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Update neighbors
		*neighbors=merge(*neighbors, cur_neighbors);
		
		distance++;
	}	
	
	return;
}
/**** End of Function ***/

//Varied Neighbor Type
//no blacklist
template<class Type1>
void get_all_neighbors(int node, A_Network X, int k, vector<Type1> *neighbors, const string &opt1)
{
	//Check for errors
	if((node==-1) || (node==X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<Type1> cur_neighbors; //Set of neighbors at each level
	vector<int> next_level_nodes; //Source nodes for each level
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors);
		
		//Obtain next level nodes
		get_all(cur_neighbors, opt1, &next_level_nodes);
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Update neighbors
		*neighbors=merge(*neighbors, cur_neighbors);
		
		distance++;
	}	
	
	return;
}

/**** End of Function ***/

//With blacklist
template<class Type1, class Type2>
void get_all_neighbors(int node, A_Network X, int k, vector<Type1> *neighbors, vector<Type2> blacklist, const string &node_prop, const string &blk_prop)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<Type1> cur_neighbors; //Set of neighbors at each level
	vector<int> next_level_nodes; //Source nodes for each level
	vector<int> black_nodes; //List of nodes not to traverse;
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	black_nodes.resize(0);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors);
		
		//Obtain next level nodes
		get_all(cur_neighbors, node_prop, &next_level_nodes);
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		
		//remove blacklist nodes from next_level_nodes
		get_all(blacklist,blk_prop,&black_nodes);
		next_level_nodes=difference(next_level_nodes, black_nodes);
		
		//Add new neighbors to total_neighbors
		*neighbors=merge(*neighbors, cur_neighbors);
		
		distance++;
	}
	
	return;
}
/**** End of Function ***/

/****** Finds Distance Neighbors at Distance ==k *******/
//defined for only one starting node---for many nodes kth distance can be conflicting
//Neighbors can be repeated
//Rows are sequential starting from 0
//Largest Row is size of A_network-1;
//Return neigbors at distance ==k

//Default
void get_neighbors(int node, A_Network X, int k, vector<int> *neighbors)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	visited_nodes.resize(0);
	visited_nodes.push_back(node);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Update visited_nodes
		visited_nodes=merge(visited_nodes, next_level_nodes);
		
		//Update neighbors
		*neighbors=cur_neighbors;
		
		distance++;
	}	
		return;
}
/**** End of Function ***/



//Varied Neighbor Type
//no blacklist
template<class Type1>
void get_neighbors(int node, A_Network X, int k, vector<Type1> *neighbors, const string &opt1)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<Type1> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	visited_nodes.resize(0);
	visited_nodes.push_back(node);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		get_all(cur_neighbors, opt1, &next_level_nodes);
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Update visited_nodes
		visited_nodes=merge(visited_nodes, next_level_nodes);
		
		//Update neighbors
		*neighbors=cur_neighbors;
		distance++;
	}	
	
	return;
}

/**** End of Function ***/

//With blacklist
template<class Type1, class Type2>
void get_neighbors(int node, A_Network X, int k, vector<Type1> *neighbors, vector<Type2> blacklist, const string &node_prop, const string &blk_prop)
{
	//Check for errors
	if((node==-1) || (node>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node << "Does not exist \n"; return;}
	
	//clear neighbors;
	neighbors->clear();
	
	vector<Type1> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;   //Set of nodes reached
	vector<int> next_level_nodes; //Source nodes for each level
	vector<int> black_nodes; //List of nodes not to traverse;
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node);
	visited_nodes.resize(0);
	visited_nodes.push_back(node);
	black_nodes.resize(0);
	int distance=0;
	while(distance<k)
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		get_all(cur_neighbors, node_prop, &next_level_nodes);
		if(next_level_nodes.size()==0) {cout << "ESSENS:INFO  All nodes reached by level" << distance <<"\n"; break;}
		
		//Add new nodes to visited nodes
		visited_nodes=merge(visited_nodes,next_level_nodes);
		
		//remove blacklist nodes from next_level_nodes
		get_all(blacklist,blk_prop,&black_nodes);
		next_level_nodes=difference(next_level_nodes, black_nodes);
		
		//Add new neighbors to total_neighbors
		*neighbors= cur_neighbors;
		
		distance++;
	}
	
		return;
}
/**** End of Function ***/


/****Shortest Path Length ***/
//Find shortest path from node to target node(s)
//Only int taken as nodes
//-1 means disconnected

//Default
int shortest_path(int node1, int node2, A_Network X)
{
	//Check for errors
	if((node1==-1) || (node1>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return -1;}
	
	if((node2==-1) || (node2>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node2 << "Does not exist \n"; return -1;}

	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	int path=-1;
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node1);
	visited_nodes.resize(0);
	visited_nodes.push_back(node1);
	int distance=0;
	while(1) //Until node is found or no new node can be reached
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {break;}//no new nodes obtained
		
		//Add new nodes to visited nodes
		visited_nodes=merge(visited_nodes,next_level_nodes);
		
		if(contains(next_level_nodes, node2)){path=distance+1; break;}

		distance++;
	}	
	return path;
}
/**** End of Function ***/

//With Blacklist
template <class Type2>
int shortest_path(int node1, int node2, A_Network X,vector<Type2> blacklist,const string &blk_prop)
{
	
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	vector<int> black_nodes; //List of nodes not to traverse;
	int path=-1;
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node1);
	visited_nodes.resize(0);
	visited_nodes.push_back(node1);
	black_nodes.resize(0);
	int distance=0;
	while(1) //Until node is found or no new node can be reached
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {break;}//no new nodes obtained
		
		//Add new nodes to visited nodes
		visited_nodes=merge(visited_nodes,next_level_nodes);
		
		//remove blacklist nodes from next_level_nodes
		get_all(blacklist,blk_prop,&black_nodes);
		next_level_nodes=difference(next_level_nodes, black_nodes);
		
		if(contains(next_level_nodes, node2)){path=distance+1; break;}
		
		distance++;
	}	
	return path;
}
/**** End of Function ***/



//With Valid
int shortest_path(int node1, int node2, A_Network X,vector<int> valid)
{
	
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	int path=-1;
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node1);
	visited_nodes.resize(0);
	visited_nodes.push_back(node1);
	
	int distance=0;
	while(1) //Until node is found or no new node can be reached
	{
		//Get neighbors and sort them
		bool found=get_neighbors(next_level_nodes, X, node2, &cur_neighbors, visited_nodes);
		if(found){path=distance+1; break;}
		
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {path=-1;break;}//no new nodes obtained
		
		//Add new nodes to visited nodes
		visited_nodes=merge(next_level_nodes,visited_nodes);
		
		//keep only neighbors from valid nodes
		next_level_nodes=intersect(next_level_nodes, valid);
		if(next_level_nodes.size()==0){path =-1; break;}
		
		distance++;
	}	
	return path;
}


/**** End of Function ***/


//With Valid
int shortest_path(vector<int> nodes, int node2, int node3, A_Network X,vector<int> valid)
{
	
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	int path=0;
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes=nodes;
	visited_nodes.resize(0);
	visited_nodes=nodes;
	
	bool found,f2,f3;
	f2=false;
	f3=false;
	while(1) //Until node is found or no new node can be reached
	{
		//Get neighbors and sort them
		found=false;
		get_neighbors(next_level_nodes, X, node2, node3, f2,f3, &cur_neighbors, visited_nodes);
		
		if(found)
		{
		if(contains_sort(cur_neighbors, node2)){f2=true;}
		if(contains_sort(cur_neighbors, node3)){f3=true;}
			if(f2 && f3){path=1; break;}
		}
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {path=-1;break;}//no new nodes obtained
		
		//Add new nodes to visited nodes
		visited_nodes=merge(next_level_nodes,visited_nodes);
		
		//keep only neighbors from valid nodes
		next_level_nodes=intersect(next_level_nodes, valid);
		if(next_level_nodes.size()==0){path =-1; break;}
	
		//distance++;
	}	
	return path;
}


/**** End of Function ***/


/**** End of Function ***/



//Over Multiple nodes
//Default
vector<int> shortest_path(int node1, vector<int> nodes2, A_Network X)
{
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	vector<int> path (nodes2.size(), -1);
	int node2;
	
	//Check for errors
	if((node1==-1) || (node1==X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return path;}
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node1);
	visited_nodes.resize(0);
	visited_nodes.push_back(node1);
	
	int distance=0;
	int found=0;
	while(1) //Until node is found or no new node can be reached
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {break;}//no new nodes obtained
		
		//Add new nodes to visited nodes
		visited_nodes=merge(visited_nodes,next_level_nodes);
		
		for(int i=0;i<nodes2.size();i++)
		{ node2=nodes2[i];
			if(node2>-1) //if not alread found;
			{
			 if(contains(next_level_nodes, node2))
				{path[i]=distance+1;
				 nodes2[i]=-1;  
				 found++;}//end of if
			}//end of if
		} //end of for;
		
		if(found==nodes2.size()) {break;}
		
		distance++;
	}	
	return path;
}
/**** End of Function ***/

//with blacklist
template<class Type2>
vector<int> shortest_path(int node1, vector<int> nodes2, A_Network X,vector<Type2> blacklist,const string &blk_prop)
{
	vector<int> cur_neighbors; //Set of neighbors at each level
	vector<int> visited_nodes;
	vector<int> next_level_nodes; //Source nodes for each level
	vector<int> black_nodes; //List of nodes not to traverse;
	vector<int> path (nodes2.size(), -1);
	int node2;
	
	//Check for errors
	if((node1==-1) || (node1>=X.size()))
	{cout <<"ESSENS:ERROR::   Row" << node1 << "Does not exist \n"; return path;}
	
	//continue until distance k reached
	next_level_nodes.resize(0);
	next_level_nodes.push_back(node1);
	visited_nodes.resize(0);
	visited_nodes.push_back(node1);
	black_nodes.resize(0);
	
	int distance=0;
	int found=0;
	while(1) //Until node is found or no new node can be reached
	{
		//Get neighbors and sort them
		get_neighbors(next_level_nodes, X, &cur_neighbors, visited_nodes, "first");
		
		//Obtain next level nodes
		next_level_nodes=cur_neighbors;
		if(next_level_nodes.size()==0) {break;}//no new nodes obtained
		
		//Add new nodes to visited nodes
		visited_nodes=merge(visited_nodes,next_level_nodes);
		
		//remove blacklist nodes from next_level_nodes
		get_all(blacklist,blk_prop,&black_nodes);
		next_level_nodes=difference(next_level_nodes, black_nodes);
		
		for(int i=0;i<nodes2.size();i++)
		{ node2=nodes2[i];
			if(node2>-1) //if not alread found;
			{
				if(contains(next_level_nodes, node2))
				{path[i]=distance+1;
					nodes2[i]=-1;  
				found++;}//end of if
			}//end of if
		} //end of for;
		
		if(found==nodes2.size()) {break;}
		
		distance++;
	}	
	return path;
}
/**** End of Function ***/


///=================================================================================================

#endif
