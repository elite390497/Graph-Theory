#ifndef PERMUTE_ELEMENTS_HPP
#define PERMUTE_ELEMENTS_HPP
#include "structure_defs.hpp"
using namespace std;

/****** Permute a Vector of Integers *******/

int factorial(int i)
{
    int fact=1;
    
    while(1)
    { fact=fact*i;
        i=i-1;
        if(i==0) {break;}
    }
    
    
    return fact;
}


//Assume list is sorted
vector<int> permute_elements(int nodes, int max_val)
{
    
    vector<int> perm_num;
    vector<int> mynums;
    mynums.clear();
    
    for(int j=0;j<nodes; j++)
    {mynums.push_back(j);}
    

    srand (time(NULL));
    int iters=rand()%max_val+10000;
    int i=0;
    perm_num=mynums;
   
    while(i!=iters)
    {
        int a=rand()%mynums.size();
        int b=rand()%mynums.size();
        
        int temp=perm_num[a];
        perm_num[a]=perm_num[b];
        perm_num[b]=temp;
        
        i++;
    }
    
    return perm_num;
}

/******* End of Functions **************/


#endif
