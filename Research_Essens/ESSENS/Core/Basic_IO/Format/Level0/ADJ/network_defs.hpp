#ifndef ADJ_NETWORK_DEFS_HPP
#define ADJ_NETWORK_DEFS_HPP

#include"structure_defs.hpp"
#include<list>
using namespace std;

//Structure in STATIC Adjacency List---For diagram go to () 
//Rows=global ID of the rows
//For edges connected with Rows
//NListW.first=Column number
//NListW.second=Value of edge
//Ops: For undirected graphs point to index of node2-node1
struct ADJ_Bundle
{
	int Row;
	vector <int_double> ListW;
	vector<int> Ops;

	//Constructor
	ADJ_Bundle()
	{
		ListW.resize(0);
		Ops.resize(0);
	}

	//Destructor
	void clear()
	{
		while (!ListW.empty()) { ListW.pop_back(); }
		while (!Ops.empty()) { Ops.pop_back(); }
	}
};

typedef  vector<ADJ_Bundle> A_Network;


#endif
