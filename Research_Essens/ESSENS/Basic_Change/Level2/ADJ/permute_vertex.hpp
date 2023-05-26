#ifndef PERMUTE_VERTEX_HPP
#define PERMUTE_VERTEX_HPP


using namespace std;

//Permute the vertices in the graph based on the order

A_Network permute_vertex(A_Network X, vector<int> permute_list)
{
    A_Network Y;
    create_Network(X.size(),0, &Y);
    for(int i=0;i<X.size();i++)
    {
        int r=permute_list[X[i].Row];
        Y[r].ListW=X[i].ListW;
        
        for(int j=0;j<Y[r].ListW.size();j++)
        {
        
            Y[r].ListW[j].first=permute_list [ Y[r].ListW[j].first];
        }//end of for j
        
        //sort the edge list to keep the nodes sorted
        sort(&Y[r].ListW);
        
    }//end of for i
    
    
	
return Y;}
/******* End of Function **************/

#endif
