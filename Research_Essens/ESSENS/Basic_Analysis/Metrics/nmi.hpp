#ifndef NMI_HPP
#define NMI_HPP
#include "unary_set_operations.hpp"
#include "binary_set_operations.hpp"

using namespace std;



/****** NMI Computation *******/
//Assume that the communities are bunched together and ordered consecutively
//Also nodes in each community ordered consecutively--required for intersection
//Assume communities start from 0
double get_nmi(vector<int_int> *C1, vector<int_int> *C2)
{
	//Largest community ID in C1
    int maxC1=C1->at(C1->size()-1).second;
    
    //Largest community ID in C2
    int maxC2=C2->at(C2->size()-1).second;
    
    int curC1=0; //st community
    int curC2=0; //current community C2
    
    vector<int> C1_set; //nodes in C1
    vector<int> C2_set; //nodes in C2
    vector<int> nij;
    int i=0;
    int j=0;
    
    int n=C1->size();
    double  pij_vals[maxC1+1][maxC2+1];
  
    
    while(i<C1->size())
    {
        //find vertices in the community curC1
        C1_set.clear();
        while(C1->at(i).second==curC1 && i<C1->size())
        {C1_set.push_back(C1->at(i).first);
            i++;
        if(i==C1->size()){break;}
        }
      
        
        j=0;
        curC2=0;
        while(j<C2->size())
        {
            //find vertices in the community curC2
              C2_set.clear();
            while(C2->at(j).second==curC2 )
            {C2_set.push_back(C2->at(j).first);
            j++;
                
            if(j==C2->size()){break;}
            }
         
            //Find pij (intersection of elements in C1 and C2)
            pij_vals[curC1][curC2]=0;
            nij.clear();
            nij=intersect(C1_set, C2_set);
           double pij=double(nij.size())/double(n);
            
            
            
            //Update pij in array
            pij_vals[curC1][curC2]=pij;
            
            //update community in set 2
            curC2++;
        
        }//end of while
        
        
        //update community in set 1
        curC1++;
    
    }//end of while
    
    
    
/*== Caluclating Pij_vals DONE ===*/
    
    //Computing NMI
    
    //comupte pi+ and HX
   double pi[maxC1+1];
    double hx=0;
    for(int i=0;i<=maxC1; i++)
    {

        pi[i]=0;
        for(j=0;j<=maxC2;j++)
        {pi[i]=pi[i]+ pij_vals[i][j];}
        
        
        if(pi[i]>0)
        {hx=hx+pi[i]*log(pi[i]);}
    }

    
     //comupte pj+ and HY
    double pj[maxC2+1];
    double hy=0;
    for(int j=0;j<=maxC2; j++)
    {
        pj[j]=0;
        for(i=0;i<=maxC1;i++)
        {pj[j]=pj[j]+ pij_vals[i][j];}

        
        if(pj[j]>0)
        {hy=hy+pj[j]*log(pj[j]);}
    }
   
    
    
    //Compute IXY
    double Ixy=0.0;
    for(int i=0;i<=maxC1; i++)
     for(int j=0;j<=maxC2; j++)
     {
        // printf("%d %d %f--\n", i, j, pij_vals[i][j]);
         if(pi[i]>0 && pj[j]>0 &&pij_vals[i][j]>0)
         {Ixy=Ixy+pij_vals[i][j]*log((pij_vals[i][j])/(pi[i]*pj[j]));}
         
       // printf("%d %d %f \n", i, j, Ixy);
       
     }

    //Comput NMI
    double NMI=-2*Ixy/(hx+hy);
    
	return NMI;
}




/**** Weighted NMI Computation as per Labatut Paper ***
void get_nmiW(vector<int_int> *C1, vecor<int_int> *C2)
{
    
    
    
    
    
    return;
}

*/







/******* End of Functions **************/






#endif
