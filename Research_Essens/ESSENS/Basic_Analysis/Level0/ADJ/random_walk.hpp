#ifndef RANDOM_WALK_HPP
#define RANDOM_WALK_HPP
#include "unary_set_operations.hpp"

using namespace std;


//Compares Two Elements a,b
//returns 0 if a==b
//returns -1 if a<b
//returns +1 if a>b

/****** Degree Centrality *******/
//Degrees Unordered
void random_walk(A_Network X, vector<int_int> *visitC, vector < vector<int> > *paths, int len, int number, bool repeat)
{
	//Seed for random number generator
    srand (time(NULL));
    int max_val=(int)X.size();
    
    //Initialize path
    paths->clear();
    vector<int> single_path;
    vector<int> sorted_path;
    
    //List of neighbors
    vector<int> neighbors;
    int index;
    
    visitC->clear();
    int_int dummy;
    for(int k=0;k<(int)X.size();k++)
    {  dummy.first=k;
        dummy.second=0;
        visitC->push_back(dummy);}
        
        
    //For loop for number of paths travelled
    for(int i=0; i< number; i++)
    {
     single_path.clear();
      
        //Randomly select starting node
        int node=rand()%max_val;
     
    //For loops for length of path travelled
        for(int j=0; j<len;j++)
        {
            
            single_path.push_back(node);
            visitC->at(node).second++;
            
             //get neighbors
            get_neighbors(node, X[node].ListW, &neighbors);
            
            //If no repeatition allowed use only leftover neighbors
            if(!repeat)
            {
            sort(&neighbors);
            sorted_path=single_path;
                sort(&sorted_path);
            neighbors=difference(neighbors,sorted_path);
            }
            
            if(neighbors.size()==0) {break;}
            
            //get index of next neighbor
            index=rand()%(int)neighbors.size();
            
            //get next node
            node=neighbors[index];
            
            
            
        }
        single_path.push_back(node);
        visitC->at(node).second++;
        
        
        paths->push_back(single_path);
        
    }
    
    //Sort in decscending order
    sort(visitC, dec_second);
	return;	
}



/******* End of Functions **************/


#endif
