#ifndef ADJ_PRINT_FORMAT_NETWORK_HPP
#define ADJ_PRINT_FORMAT_NETWORK_HPP

#include "ADJ/network_defs.hpp"
#include "structure_defs.hpp"
using namespace std;

//==Level1 Functions
/**print_edgelist (in CSR/ADJ format) in corresponding directories
 --Overloaded as;
 (Network); DONE
 (Network, Edglist (EdgeOnly/Edge)); DONE
 (Network, edgelist); DONE
 (Network, ouputfile); DONE**/
 
/**print_detail (in CSR/ADJ format) in corresponding directories
 //ADJ Format
 //---Row ID:
 //---ColumnID and Values as (C:_V:_)
 --Overloaded as;
 (Network); DONE
 (Network, ouputfile); DONE**/


/**** Print Network with Data Structure **************/
void print_detail(A_Network C)
{
	for(int j=0;j<C.size();j++)
	{
		cout << "GRows: " << C[j].Row << "\n";
		
		for(int k=0;k<C[j].ListW.size();k++)
		{  
			cout << " C: " << C[j].ListW[k].first;
            cout << " V: " << C[j].ListW[k].second;
            cout << " O: " << C[j].Ops[k] <<"**";
		} //end of for (ListW)
		cout <<"\n";
	} //end of for (ADJ Network)
		
	return;
}

void print_detail(A_Network C, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists
	
	for(int j=0;j<C.size();j++)
	{
		myfile << "GRows: " << C[j].Row << "\n";
		
		for(int k=0;k<C[j].ListW.size();k++)
		{  
			myfile << "C: " << C[j].ListW[k].first;
			myfile << "V: " << C[j].ListW[k].second << "**"; 
		} //end of for (ListW)
		myfile <<"\n";
	} //end of for (ADJ Network)
		
	//Close File
	myfile.close();
	
	return;
}
/******* End of Function **************/


/******* Print Network as Edge List (Node Node Wt) without Details of Data Structure**************/
void print_edgelist (A_Network C)
{
	for(int j=0;j<C.size();j++)
		{
			for(int k=0;k<C[j].ListW.size();k++)
				{ 
				cout << C[j].Row << " " <<  C[j].ListW[k].first << " " << C[j].ListW[k].second << "\n";
				} //end of for (ListW)
		}//end of for (Row_Info)
	
	return;
}


void print_edgelist (A_Network C, vector<Edge> *elist)
{
	elist->resize(0);
	Edge e;
	
	for(int j=0;j<C.size();j++)
	{
		for(int k=0;k<C[j].ListW.size();k++)
		{ 
			//Get Edge Values
			e.node1=C[j].Row;
			e.node2=C[j].ListW[k].first;
			e.edge_wt=C[j].ListW[k].second;
			
			elist->push_back(e); //Add to list
			
		} //end of for (ListW)
	}//end of for (Row_Info)
	
	return;
}

void print_edgelist (A_Network C, map_st_int MyMap)
{
	
	for(int j=0;j<C.size();j++)
	{
		cout << j <<"\n";
		string mynode=find_key(MyMap,C[j].Row);
		for(int k=0;k<C[j].ListW.size();k++)
		{ 
			cout << mynode << " " <<  find_key(MyMap,C[j].ListW[k].first) << " " << C[j].ListW[k].second << "\n";
		} //end of for (ListW)
	}//end of for (Row_Info)
	
	return;
}

void print_edgelist (A_Network C, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists

	for(int j=0;j<C.size();j++)
	{
		for(int k=0;k<C[j].ListW.size();k++)
		{ 
			myfile << C[j].Row << " " <<  C[j].ListW[k].first << " " << C[j].ListW[k].second << "\n";
		} //end of for (ListW)
	}//end of for (Row_Info)

	//Close File
	myfile.close();
	
	return;
}

void print_edgelist (A_Network C, map_st_int MyMap, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists
	
	for(int j=0;j<C.size();j++)
	{
		cout << j <<"\n";
		string mynode=find_key(MyMap,C[j].Row);
		for(int k=0;k<C[j].ListW.size();k++)
		{ 
			myfile << mynode << " " <<  find_key(MyMap,C[j].ListW[k].first) << " " << C[j].ListW[k].second << "\n";
		} //end of for (ListW)
	}//end of for (Row_Info)
	
	//Close File
	myfile.close();
	
	return;
}


/******* End of Function ****/


#endif
