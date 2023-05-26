#ifndef NMI_COMPUTATION_HPP
#define NMI_COMPUTATION_HPP
#include "unary_set_operations.hpp"
#include "binary_set_operations.hpp"

using namespace std;



/****** NMI Computation *******/
//Assume that the communities are bunched together and ordered consecutively
//Also nodes in each community ordered consecutively--required for intersection
//Assume communities start from 0
void get_nmi(vector<int_int> *C1, vecor<int_int> *C2)
{
	//Largest community ID in C1
    maxC1=C1->at(C1.size()-1).second;
    
    //Largest community ID in C2
    maxC2=C2->at(C2.size()-1).second;
    
    int curC1=0; //st community
    int curC2=0; //current community C2
    
    vector<int> C1_set; //nodes in C1
    vector<int> C2_set; //nodes in C2
    vector<int> int12;
    int i=0;
    int j=0;
    while(i<C1->size();)
    {
        //find vertices in the community curC1
        while(C1->at(i).second==curC1)
        {C1_set.push_back(C1->at(i).first);
        i++;}
        else
        {curC1++;}
        
        
        j=0;
        while(j<C2->size())
        {
            
            //find vertices in the community curC1
            while(C2->at(i).second==curC2)
            {C2_set.push_back(C2->at(i).first);
            j++;}
            else
            {curC2++;}
            
            
            //Find pij (intersection of elements in C1 and C2)
            int12=intersection(C1_set, C2, set);
        
            
        }//end of while
    
    }//end of while
    
    
    
	return;	
}




/**** Weighted NMI Computation as per Labatut Paper ***
void get_nmiW(vector<int_int> *C1, vecor<int_int> *C2)
{
    
    
    
    
    
    return;
}

*/







/******* End of Functions **************/






#endif
