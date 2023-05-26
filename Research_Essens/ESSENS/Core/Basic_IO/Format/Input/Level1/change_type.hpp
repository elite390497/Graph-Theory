#ifndef CHANGE_TYPE_HPP
#define CHANGE_TYPE_HPP

#include "ADJ/create_network.hpp"
#include "CSR/create_network.hpp"
using namespace std;

/****List of Functions ******/
//==Level2 Functions	
/**k 
 ==Default buffer size=0
 ==Default input_file "E_input.txt"
 == Calls
 create_network()
 --Overloaded as;
 (Network); DONE
 (Network, buffer);
 (input_file,Network);
 (input_file,Network,buffer);
 

/**** Conversion Between Networks ****/ 
template <class myNetworkType>
void change_type (vector<Edge> e, myNetworkType *X)
{ create_network(e,X);}

template <class myNetworkType>
void change_type (myNetworkType X, vector<Edge> *elist)
{ print_edgelist(X,elist);}

template <class myNetworkType1, class myNetworkType2>	
void change_type (myNetworkType1 X1, myNetworkType1 *X2);
{ vector<Edge> elist;
	print_edgelist(X1, *elist);
	change_type(elist, X2);
}
/********* End of Function **********/

	
#endif
