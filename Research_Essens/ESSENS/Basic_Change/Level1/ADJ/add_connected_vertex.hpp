#ifndef ADD_CONNECTED_VERTEX_HPP
#define ADD_CONNECTED_VERTEX_HPP

#include "extract_elements.hpp"
#include "unary_set_operations.hpp"
#include "ADJ/add_multiple_edge.hpp"
using namespace std;

//Add Single Vertex
//Vertex is numbered as the last row, i.e. X->size();
//Is not connected with rest of the network
//If id is not given mapped as string of integer
void add_connected_vertex(A_Network *X, map_st_int *nodemap, vector<int_double> neighs)
{
	int node=X->size(); //Initialize node;
	add_vertex(X, nodemap);
	add_edgeS(X,node,neighs);
	
return;}

void add_connected_vertex(A_Network *X, string st1, map_st_int *nodemap, vector<int_double> neighs)
{
	int node=X->size(); //Initialize node;
	add_vertex(X, st1, nodemap);
	add_edgeS(X,node,neighs);
	
return;}

void add_connected_vertex(A_Network *X,  vector<int_double> neighs)
{
	int node=X->size(); //Initialize node;
	add_vertex(X);
	add_edgeS(X,node,neighs);
	
return;}


void add_connected_vertex(A_Network *X, map_st_int *nodemap, vector<int_double> neighs, bool dir)
{
	int node=X->size(); //Initialize node;
	add_vertex(X, nodemap);
	add_edgeS(X,node,neighs,dir);
	
return;}

//==with only neighbors; no weights
void add_connected_vertex(A_Network *X, map_st_int *nodemap, vector<int> neighs)
{
	int node=X->size(); //Initialize node;
	add_vertex(X, nodemap);
	add_edgeS(X,node,neighs);
	
return;}

void add_connected_vertex(A_Network *X, string st1, map_st_int *nodemap, vector<int> neighs)
{
	int node=X->size(); //Initialize node;
	add_vertex(X, st1, nodemap);
	add_edgeS(X,node,neighs);
	
return;}

void add_connected_vertex(A_Network *X,  vector<int> neighs)
{
	int node=X->size(); //Initialize node;
	add_vertex(X);
	add_edgeS(X,node,neighs);
	
return;}


void add_connected_vertex(A_Network *X, map_st_int *nodemap, vector<int> neighs, bool dir)
{
	int node=X->size(); //Initialize node;
	add_vertex(X, nodemap);
	add_edgeS(X,node,neighs,dir);
	
return;}

/******* End of Function **************/






#endif
