#ifndef ADD_VERTEX_HPP
#define ADD_VERTEX_HPP
#include "ADJ/network_defs.hpp"
#include "extract_elements.hpp"
#include "unary_set_operations.hpp"
using namespace std;


//Add Single Vertex
//Vertex is numbered as the last row, i.e. X->size();
//Is not connected with rest of the network
//If id is not given mapped as string of integer
void add_vertex(A_Network *X, map_st_int *nodemap)
{
int node=X->size(); //Initialize node;	
	
 //Add node to Alist
 ADJ_Bundle Alist;	
 Alist.Row=node;
 Alist.ListW.resize(0);	
 X->push_back(Alist);
	
//Change Id to string
string st1 = static_cast<ostringstream*>( &(ostringstream() << node) )->str();
	
//Add to map
std::pair<std::map<string,int>::iterator,bool> ret=nodemap->insert ( std::pair<string,int>(st1,node) );

return;}

/******* End of Function **************/

//Node Id given
void add_vertex(A_Network *X, string st1, map_st_int *nodemap)
{
	int node=X->size(); //Initialize node;	
	
	//Add node to Alist
	ADJ_Bundle Alist;	
	Alist.Row=node;
	Alist.ListW.resize(0);	
	X->push_back(Alist);
	
	//Add to map
	std::pair<std::map<string,int>::iterator,bool> ret=nodemap->insert ( std::pair<string,int>(st1,node) );
	if(ret.second==true){cout << "ESSENS:ERROR:: Node of Same Name exists \n";}
	
return;}


//Vertex is added as a temporary measure, not reflected in nodemap
void add_vertex (A_Network *X)
{
	int node=X->size(); //Initialize node;	
	
	//Add node to Alist
	ADJ_Bundle Alist;	
	Alist.Row=node;
	Alist.ListW.resize(0);	
	X->push_back(Alist);
	
return;}


#endif
