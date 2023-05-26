#ifndef INPUT_TO_COMMS_HPP
#define INPUT_TO_COMMS_HPP

#include "structure_defs.hpp"
using namespace std;


 
 
/**** Reading File to get Communities of Vertices******/
//First row:Vertex
//Second row: Community

void readin_community(char *file, vector<int_int> *comm_vec)
{
	
	
	//File reading parameters
	FILE *comm_file;
	char line[128];
    int_int v_comm;
    
    comm_vec->clear();
	 

	comm_file=fopen(file, "r");
	while(fgets(line,128,comm_file) != NULL)
	{
        int n1,n2;
		//Read line 
		sscanf(line,"%d %d",&n1,&n2);
        v_comm.first=n1;
        v_comm.second=n2;
        comm_vec->push_back(v_comm);
        
	}//end of while
	fclose(comm_file);


	
	return;
}

/********* End of Function **********/




	
#endif
