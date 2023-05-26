//
//  set_opposite_index.hpp
//  
//
//  Created by Sanjukta Bhowmick on 7/19/19.
//

#ifndef set_opposite_index_hpp
#define set_opposite_index_hpp

/*** Sets the index of where n1 is in the neighbor list of its neighbors for undirected networks **/

void set_opposite_index(A_Network *X)
{
    
    for(int i=0;i<X->size();i++)
    {
        
       //Go through neighbors of i
        for(int x=0;x<X->at(i).ListW.size();x++)
        {
            int n=X->at(i).ListW[x].first;
            
            //Go through the list of neighbors of its neighbors
            int index=0;
            int m;
            for(int y=0;y<X->at(n).ListW.size();y++)
            {
                
                 m=X->at(n).ListW[y].first;
                if(m==i){break;}  //If original vertex found--break
                index++;  //Otherwise update index
            }//end of for y
            
           // printf("%d--%d --%d--%d\n", i,n,m,index);
            
            //Update the index
            X->at(i).Ops.push_back(index);
        }//end of for x
    } //end of for i
    
    

    return;
}

#endif /* set_opposite_index_hpp */
