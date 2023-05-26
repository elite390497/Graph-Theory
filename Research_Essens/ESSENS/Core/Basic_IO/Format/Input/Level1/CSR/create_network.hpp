#ifndef CSR_CREATE_NETWORK_HPP
#define CSR_CREATE_NETWORK_HPP
#include "structure_defs.hpp"
#include "CSR/network_defs.hpp"

using namespace std;

//==Level1 Functions
//Edges are sorted
//create_Network (creates CSR network)
//==For buffers column=-1, value=0;

/**** Storing Network in CSR Format ******/
void create_Network(vector<Edge> b, int bf_size, C_Network *X)
{
	 //Initialize
	 int_int rids;
	 int_double colvals;
	 int current_node=-1;
	int row_index=0;
	 
	 //Read Through the list of edges	 
	  for(int i=0;i<b.size();i++)
	   {
        //Read each entry of edgelist
		 int node1=b[i].node1;
		 int node2=b[i].node2;
		 double edge_wt=b[i].edge_wt;
		 
		 //Initailize and Add Row
		 if(current_node!=node1)
		 {
			  if(current_node >-1) //Update network after each row
			  {
			 //Add buffer spaces after columns of each row--except first row	 
				 for(int bf=0;bf<bf_size;bf++)
				 {   colvals.first=-1;
					 colvals.second=0.0;
					 X->ListW.push_back(colvals);
					 row_index++;
				 } //end of for
				  
				  //Update Rows
				  X->Row_Info.push_back(rids); //Add to rids
				  
			 } //end of if
			
			 //Set to next node
			 current_node=node1;
			 rids.second=current_node; //Set current node
			 rids.first=row_index; //Get Index from where next column starts
		 } //end of if
		 
		 //Add Columns corresponding to the rows
		 colvals.first=node2;
		 colvals.second=edge_wt;
		 X->ListW.push_back(colvals);
		 row_index++;
		 
	 } //end of for
	
	
	//Clear edgelist
	b.clear();
	
	 //Add the final buffers
	 for(int bf=0;bf<bf_size;bf++)
	 {colvals.first=-1;
		 colvals.second=0.0;
		 X->ListW.push_back(colvals);
	 row_index++;}
	
	//Update Rows
	X->Row_Info.push_back(rids); //Add to rids
	
	//Delimiter to mark end of Rows in Bundle
	rids.first=row_index;
	rids.second=-1;
	X->Row_Info.push_back(rids); //Add to rids
	
	 return;
 }


 /********* End of Function **********/
	
#endif
