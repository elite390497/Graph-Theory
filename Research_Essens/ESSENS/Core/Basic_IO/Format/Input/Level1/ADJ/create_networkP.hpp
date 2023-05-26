#ifndef ADJ_CREATE_NETWORKP_HPP
#define ADJ_CREATE_NETWORKP_HPP
#include "structure_defs.hpp"
#include "ADJ/network_defs.hpp"


using namespace std;

//==Level1 Functions
//Edges are sorted
//create_Network (creates ADJ network)

//Create network of n singleton nodes
void create_NetworkP(int n, A_Network *X, int p)
{
    ADJ_Bundle AList; //create current Adj_Bundle
    
    //Set size of X
    X->resize(n, AList);
#pragma omp parallel num_threads(p)
    {
        //Work will be divided amongst p threads in the for loop
#pragma omp for nowait
        for(int i=0;i<n;i++)
        {
            //Update Rows
            AList.Row=i;
            AList.ListW.clear(); //Clear List of Edges;
            
         X->at(i)=AList; //Add row and neighbors to network;
        } //end of for
    }
    
	return;
    }

/***** End of Function **********/


	
#endif
