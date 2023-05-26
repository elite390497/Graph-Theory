#ifndef CSR_NETWORK_DEFS_HPP
#define CSR_NETWORK_DEFS_HPP

#include"structure_defs.hpp"
using namespace std; 

//Structure  in STATIC CSR format---For diagram go to () 
//Row_Info.first=global ID of the rows
//Row_Info.second=index of the column in row (i)
//NListW.first=Column number
//NListW.second=Value of edge
struct CSR_Bundle
{ 
  vector<int_int> Row_Info;
  vector <int_double> ListW;
	
	//Constructor
	CSR_Bundle()
	{Row_Info.resize(0);
	ListW.resize(0);}
	
	//Destructor
	void clear()
	{
	 while(!Row_Info.empty()){Row_Info.pop_back();}
	 while(!ListW.empty()){ListW.pop_back();}
	}
			
};

//Structure for Network: 
typedef CSR_Bundle C_Network;


#endif
