#ifndef ADJ_CREATE_NETWORK_HPP
#define ADJ_CREATE_NETWORK_HPP
#include "structure_defs.hpp"
#include "order_elements.hpp"
#include "unary_set_operations.hpp"
#include "ADJ/network_defs.hpp"


using namespace std;

//==Level1 Functions
//Edges are sorted
//create_Network (creates ADJ network)

/**** Storing Network in Adjacency List ******/
void create_Network(vector<Edge>* b, int bf_size, A_Network* X, int Ns)
{
	if (bf_size > 0) { cout << "ESSENS:ERROR:: No Buffers in Adjacency List \n"; }
	//Initialize
	ADJ_Bundle AList; //create current Adj_Bundle
	int_double colvals;
	int current_node = -1;

	//Read Through the list of edges	 
	for (int i = 0; i < b->size(); i++)
	{
		//Read each entry of edgelist
		int node1 = b->at(i).node1;
		int node2 = b->at(i).node2;
		double edge_wt = b->at(i).edge_wt;

		// printf("%d %d \n", node1, node2);
		//Initailize and Add Row
		if (current_node != node1)
		{
			if (current_node > -1) //Update network after each row
			{
				//Update Rows
				X->push_back(AList); //Add row and neighbors to network;
				AList.ListW.clear(); //Clear List of Edges;

			} //end of if

			//Add missing vertices if necessary
			current_node++;
			while (current_node != node1)
			{
				AList.Row = current_node;
				X->push_back(AList); //Add row and neighbors to network;
				AList.ListW.clear(); //Clear List of Edges;
				current_node++;
			}

			//Set to next node
			current_node = node1;
			AList.Row = current_node;
		} //end of if

		//Add Columns corresponding to the rows
		colvals.first = node2;
		colvals.second = edge_wt;
		AList.ListW.push_back(colvals);

	} //end of for

	//Clear edgelist
	b->clear();

	//Add the final buffers
	//No need of buffer space becuase link can be easily appended

	//Update Rows
	X->push_back(AList); //Add row and neighbors to network;
	AList.ListW.clear(); //Clear AList;

	// printf("lll \n");
	 //Add remaining nodes that are only dests
	if (!(Ns == -1))
	{
		current_node++;
		while (current_node != Ns)
		{
			AList.Row = current_node;
			X->push_back(AList); //Add row and neighbors to network;
			AList.ListW.clear(); //Clear List of Edges;
			current_node++;
		}
	}

	return;

}
/***** End of Function **********/

//Create network of n singleton nodes
void create_Network(int n, int bf_size, A_Network* X)
{
	//if(bf_size>0){cout << "ESSENS:ERROR:: No Buffers in Adjacency List \n";}
	//Initialize
	ADJ_Bundle AList; //create current Adj_Bundle
	int_double colvals;
	int current_node = -1;


	//Read Through the list of edges	 
	for (int i = 0; i < n; i++)
	{
		//Read each entry of edgelist
		//Initailize and Add Row
		if (current_node != i)
		{
			if (current_node > -1) //Update network after each row
			{
				//Update Rows
				X->push_back(AList); //Add row and neighbors to network;
				AList.ListW.clear(); //Clear List of Edges;

			} //end of if

			//Set to next node
			current_node = i;
			AList.Row = current_node;
		} //end of if

		//Create ListW
		AList.ListW.resize(0);

	} //end of for


	//Update Rows
	X->push_back(AList); //Add row and neighbors to network;
	AList.ListW.clear(); //Clear AList;

	return;

}
/***** End of Function **********/



#endif
