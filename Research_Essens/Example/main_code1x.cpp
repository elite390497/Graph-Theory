
//INPUT HEADERS
#include "translate_from_input.hpp"
#include "input_to_network.hpp"
#include"structure_defs.hpp"

//OUTPUT HEADERS
#include "printout_network.hpp"
#include "printout_others.hpp"


/*** All Headers Required From ESSENS **/

using namespace std;

int main(int argc, char *argv[])
{       
	clock_t q, q1, q2,t;
    double startx, endx, startx1, endx1;
	
    
    
    /***** Preprocessing to Graph (GUI) ***********/
    q=clock();
    //Check if valid input is given
    if ( argc < 3) { cout << "INPUT ERROR:: At least 2 inputs required. First: filename \n Second: Filetypes: 1:node_node_wt 2:node_wt_node 3:node_node 4:node_node (Only option 1 is active now) \n Third. Name of new file \n Fourth. Name of Map file\n"; return 0;}
    //Check to see if file opening succeeded
    ifstream the_file ( argv[1] ); if (!the_file.is_open() ) { cout<<"INPUT ERROR:: Could not open file\n";}
    
    A_Network X;
    int nodes=-1;
    map_int_st revmap;
    
    //Proces File if Option Given by
    if(argc==5)
    {
        // Preprocess Nodes to Numbers
        //Stores file in argv[3]: store map in argv[4]
        //Vertices start from 0
        int type=atoi(argv[2]);
        translate_input(argv[1],type,argv[3],argv[4]);
        
        //Remove Duplicate Edges and Self Loops; Create Undirected Graphs
        // process_to_simple_undirected();
        q=clock()-q;
        cout << "Total Time for Preprocessing"<< ((float)q)/CLOCKS_PER_SEC <<"\n";
        
        /***** Preprocessing to Graph (GUI) ***********/
        
        
        /******* Read Graph (GUI) and Create Reverse Map*****************/
        //Obtain the list of edges.
        q=clock();
        readin_network(&X,argv[3],nodes);
        
        //Create Reversemap
        
        nodes=X.size();
        create_map(argv[4],&revmap);
        
        q=clock()-q;
        cout << "Total Time for Reading Network"<< ((float)q)/CLOCKS_PER_SEC <<"\n";
        /**** Read Graph (GUI) ***********/
    }
    else //no need to process the graph
    {
        /******* Read Graph (GUI) and Create Reverse Map*****************/
        //Obtain the list of edges.
        q=clock();
        readin_network(&X,argv[1],nodes);
        
        nodes=(int)X.size();
        create_map(nodes, &revmap);
        q=clock()-q;
        cout << "Total Time for Reading Network"<< ((float)q)/CLOCKS_PER_SEC <<"\n";
        /**** Read Graph (GUI) ***********/
    }

    
    //Initialize the vertex info
    printf("%d--\n",nodes);
    print_network(X);
    
   

return 0;	
}//end of main
	
	//==========================================//
	
	

