#ifndef CLUSTERING_COEFFICIENT_HPP
#define CLUSTERING_COEFFICIENT_HPP
#include "unary_set_operations.hpp"
#include "binary_set_operations.hpp"
#include "ADJ/find_neighbors.hpp"

using namespace std;

//Computes the clustering co-efficient of a node with respect to all/subset of its neighbors


/*** Compute Clustering Coefficient ***/
void compute_CC(A_Network X, vector<int> node_set, double *cc)
{
    if(node_set.size()<2) {printf ("ESSENS ERROR: Clustering Coefficient Needs at Least 2 Entries \n"); return;}
    *cc=0.0;
    double numerator=0.0;
    double denominator=0.0;
    vector<int> common_neighs;
    common_neighs.clear();
    
    sort(&node_set);
       for(int i=0;i<node_set.size();i++)
    { int nx=node_set[i];
        vector<int> myneighbors;
        myneighbors.clear();
        
        get_neighbors(nx, X[nx].ListW, &myneighbors);
        
        //No need to sort myneighbors as neighbors aranged in increasing order
        common_neighs=intersect(myneighbors, node_set);
        numerator=numerator+(double)common_neighs.size();
        
    }//end of for
    
    double total_nodes=(double)node_set.size();
    denominator=total_nodes*(total_nodes-1);
    *cc=numerator/denominator;
    
    return;
}

//Weighted CCA as per Barrat 2004
//CC(i)= [Sum_j,k (wij+wik) ]/[(wi)*(n-1)] (n=#of neighbors) for all triangles i-j-k
void compute_CCW(int ni, A_Network X, vector<int> node_set, double *cc)
{
    if(node_set.size()<2) {printf ("ESSENS ERROR: Clustering Coefficient Needs at Least 2 Entries \n"); return;}
    *cc=0.0;
    double numerator=0.0;
    double denominator=0.0;
    double wi=0.0;
    sort(&node_set);
    
    
        //neighbors of ni
        for(int j=0;j<X[ni].ListW.size();j++)
        {
            int nj=X[ni].ListW[j].first;
            
            if(!binary_search(node_set.begin(), node_set.end(),nj)) {continue;}
            
            double wij=X[ni].ListW[j].second;
             wi=wi+wij;
            
            //neighbors of nj
            for(int k=0;k<X[nj].ListW.size();k++)
            {
                int nk=X[nj].ListW[k].first;
                 if(!binary_search(node_set.begin(), node_set.end(),nk)) {continue;}
                
                
                //neighbors of nk
                for(int l=0;l<X[nk].ListW.size();l++)
                {
                    int nl=X[nk].ListW[l].first;
                    
                    //Found triangle
                    if(nl==ni)
                    {  double wik=X[nk].ListW[l].second;
                        numerator=numerator+(wij+wik);}
                    
                }//end of for l
                
            }//end of for k
        
        }//end of for j
    
    
    double total_nodes=(double)node_set.size();
    denominator=(total_nodes-1)*wi*2;
    *cc=numerator/denominator;
    
    return;
}


void compute_CC(A_Network X, int node, double *cc)
{
    *cc=0.0;
    double numerator=0.0;
    double denominator=0.0;
    vector<int> common_neighs;
    common_neighs.clear();

    
    vector<int> node_set;
    node_set.clear();
    get_neighbors(node,X[node].ListW, &node_set);
    sort(&node_set);
    
    for(int i=0;i<node_set.size();i++)
    { int nx=node_set[i];
        vector<int> myneighbors;
        myneighbors.clear();
        
        get_neighbors(nx, X[nx].ListW, &myneighbors);
        sort(&myneighbors);
        
        common_neighs=intersect(myneighbors,node_set);
        numerator=numerator+(double)common_neighs.size();
        
    }//end of for
    
    double total_nodes=(double)node_set.size();
    denominator=total_nodes*(total_nodes-1);
    *cc=numerator/denominator;
    
    return;
}

/******* End of Functions **************/


#endif
