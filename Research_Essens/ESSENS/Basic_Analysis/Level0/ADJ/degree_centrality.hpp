#ifndef DEGREE_CENTRALITY_HPP
#define DEGREE_CENTRALITY_HPP
#include "unary_set_operations.hpp"

using namespace std;




//Compares Two Elements a,b
//returns 0 if a==b
//returns -1 if a<b
//returns +1 if a>b

/****** Degree Centrality *******/
//Degrees Unordered
void degree_centrality(A_Network *X, vector<int> *degreeC, int_int *maxD)
{
	//Initialize degreeC
	degreeC->resize(X->size(),0);
	
	//Initialize maxD
	maxD->first=-1; //vertex with maximum degree
	maxD->second=-1; //value of maxdegree
	
	for(int i=0; i<X->size(); i++)
	{
		degreeC->at(i)=X->at(i).ListW.size(); //compute degree of each vertex
		//update maxD
	    if(maxD->second <degreeC->at(i))
		{maxD->first=i; maxD->second=degreeC->at(i);}
	}
	
	return;	
}



//Degrees of the vertices
void degree_centrality(A_Network *X, vector<int_int> *degreeC)
{
	//Initialize degreeC
	degreeC->resize(0);
	int_int D;
	
	for(int i=0; i<X->size(); i++)
	{
		D.first=i;
		D.second=X->at(i).ListW.size();
		degreeC->push_back(D);
	}
	return;	
}
/******* End of Functions **************/

//Distribution of Degree in increasing form
void degree_distribution(A_Network X, vector<int> *degreeC)
{
	//Initialize degreeC
	degreeC->resize(0);	
	
	for(int i=0; i<X.size(); i++)
	{
		//Extend degree sequence
		if(X[i].ListW.size()>degreeC->size())
		{ degreeC->resize((X[i].ListW.size()+1),0);}
		
		degreeC->at(X[i].ListW.size())++;
	}
	
	return;	
}
/******* End of Functions **************/


#endif
