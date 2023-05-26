#ifndef CSR_PRINT_FORMAT_NETWORK_HPP
#define CSR_PRINT_FORMAT_NETWORK_HPP

#include "CSR/network_defs.hpp"
#include "structure_defs.hpp"
using namespace std;

//==Level1 Functions
/**print_edgelist (in CSR/ADJ format) in corresponding directories
 --Overloaded as;
 (Network); DONE
 (Network, Edglist (Edge)); DONE
 (Network, edgelist); DONE
 (Network, ouputfile); DONE
 
 /**print_detail (in CSR/ADJ format) in corresponding directories
 //CSR Format
 //---Row ID:
 //---Column Index:
 //---ColumnID and Values as (C:_V:_)
 --Overloaded as;
 (Network); DONE
 (Network, ouputfile); DONE**/
 
/**** Print Network with Buffers and Keeping Data Structure **************/
void print_detail(C_Network C)
{
	int start=-1;
	for(int j=0;j<C.Row_Info.size()-1;j++)
	{
		cout << "GRows: " << C.Row_Info[j].second << "::Index: " << C.Row_Info[j].first << "\n";
		for(int k=C.Row_Info[j].first;k<C.Row_Info[j+1].first;k++)
		{  
			cout << "C: " << C.ListW[k].first;
			cout << "V: " << C.ListW[k].second << "**";
		} //end of for (ListW)
		
		cout <<"\n";
	} //end of for (Row_Info)
	
	
	return;
}

void print_detail(C_Network C, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists
	
	for(int j=0;j<C.Row_Info.size()-1;j++)
	{
		myfile << "GRows: " << C.Row_Info[j].second << "::Index: " << C.Row_Info[j].first << "\n";
		for(int k=C.Row_Info[j].first;k<C.Row_Info[j+1].first;k++)
		{  
			myfile << "C: " << C.ListW[k].first;
			myfile << "V: " << C.ListW[k].second << "**"; 
		}//end of for (ListW)
	   myfile <<"\n";
		
	}//end of for (Row_Info)
	
	//Close File
	myfile.close();
	
	return;
}
/******* End of Function **************/



/******* Print Network as Edge List (Node Node Wt) without Buffer or Details of Data Structure**************/
void print_edgelist (C_Network C)
{
	for(int j=0;j<C.Row_Info.size();j++)
		{
			if(C.Row_Info[j].second==-1) {break;} //Do not consider buffers
			
			for(int k=C.Row_Info[j].first;k<C.Row_Info[j+1].first;k++)
			{ if(C.ListW[k].first==-1){break;}
				cout << C.Row_Info[j].second << " " <<  C.ListW[k].first << " " << C.ListW[k].second << "\n";
			} //end of for (ListW)
			
		}//end of for (Row_Info)
	
	return;
}

/******/

void print_edgelist (C_Network C, vector<Edge> *elist)
{
	elist->resize(0);
	Edge e;
	
	for(int j=0;j<C.Row_Info.size();j++)
	{
		if(C.Row_Info[j].second==-1) {break;} //Do not consider buffers
		for(int k=C.Row_Info[j].first;k<C.Row_Info[j+1].first;k++)
		{ 
			if(C.ListW[k].first==-1){break;}
			//Get Edge Values
			e.node1=C.Row_Info[j].second;
			e.node2=C.ListW[k].first;
			e.edge_wt=C.ListW[k].second;
			
			elist->push_back(e); //Add to list
			
		} //end of for (ListW)
	}//end of for (Row_Info)
	
	return;
}

/******/

void print_edgelist (C_Network C, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists

	
	for(int j=0;j<C.Row_Info.size();j++)
	{
		if(C.Row_Info[j].second==-1) {break;} //Do not consider buffers
		
		for(int k=C.Row_Info[j].first;k<C.Row_Info[j+1].first;k++)
		{ if(C.ListW[k].first==-1){break;}
			myfile << C.Row_Info[j].second << " " <<  C.ListW[k].first << " " << C.ListW[k].second << "\n";
		} //end of for (ListW)
		
	}//end of for (Row_Info)
	
	//Close File
	myfile.close();
	
	return;
}
/******* End of Function ****/


#endif
