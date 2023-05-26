#ifndef PRINTOUT_NETWORK_HPP
#define PRINTOUT_NETWORK_HPP

#include "ADJ/print_format_network.hpp"
#include "CSR/print_format_network.hpp"
#include<map>
#include "check_type.hpp"
#include "exceptions.hpp"
#include "structure_defs.hpp"
using namespace std;

 //==Level2 Functions	
 /**print_network
 ==Default DEBUG=False
 == Output File with same name is overwritten
 == Calls
 print_edgelist() // DEBUG=False
 print_detail()  //DEBUG=True
 --Overloaded as;
 (Network); 
 (Network, DEBUG); 
 (Network, outputfile);
 (Network, DEBUG, outputfile); **/ 
 
/**** Print Network ******/
template <class myNetworkType>
void print_network(myNetworkType X)
{
	print_edgelist(X);
	cout <<"---\n";
	return;
}

template <class myNetworkType>
void print_network(myNetworkType X, map_st_int MyMap)
{
	print_edgelist(X, MyMap);
	cout <<"---\n";
	return;
}

template <class myNetworkType>
void print_network(myNetworkType X, bool DEBUG)
{
	if(DEBUG) {print_detail(X);cout <<"---\n";}
	if(!DEBUG) {print_edgelist(X);cout <<"---\n";}
	return;
}

template <class myNetworkType>
void print_network(myNetworkType X, char *filename)
{
	print_edgelist(X,filename);
	cout <<"---\n";
	return;
}

template <class myNetworkType>
void print_network(myNetworkType X, bool DEBUG, char *filename)
{
	if(DEBUG) {print_detail(X, filename);cout <<"---\n";}
	if(!DEBUG) {print_edgelist(X, filename);cout <<"---\n";}
	return;
}


template <class myNetworkType>
void print_network(myNetworkType C, map_int_st MyMap, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists
    
	
	for(int j=0;j<C.size();j++)
	{
		string mynode=MyMap.find(C[j].Row)->second;
        
		for(int k=0;k<C[j].ListW.size();k++)
		{ 
			myfile << mynode << " " << MyMap.find(C[j].ListW[k].first)->second  << " " << C[j].ListW[k].second << "\n";
		} //end of for (ListW)
	}//end of for (Row_Info)
	
	//Close File
	myfile.close();
	cout <<"---\n";
	return;
}

/********* End of Function **********/

	
#endif
