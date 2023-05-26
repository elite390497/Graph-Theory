 #ifndef STRUCTURE_DEFS_HPP
#define STRUCTURE_DEFS_HPP

#include<iostream>
#include<vector> 
#include<algorithm>
#include <iterator>
#include<utility>
#include <fstream>
#include<cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include<list>
using namespace std; 


/******* Network Structures *********/
//Note: Edges are not ordered, unless specified by code
// Node+Weight = -1;0 indicates buffer space
//Structure for Edge
struct Edge
{ int node1;
	int node2;
double edge_wt;};

Edge create (int n1, int n2, double wt)
{
	Edge e;
	e.node1=n1;
	e.node2=n2;
	e.edge_wt=wt;
	
	return e;
}



/**** End of Edge ****/

/*** Pairs ***/
typedef pair<int, int> int_int;  /** /typedef pair of integers */
typedef pair<int, double> int_double; /** /typedef pair of integer and double */
typedef pair<double, int> double_int; /** /typedef pair of integer and double */

template<class AnyType1, class AnyType2>
pair<AnyType1, AnyType2> create (AnyType1 e1, AnyType2 e2)
{
	pair<AnyType1, AnyType2> mypair;
	mypair.first=e1;
	mypair.second=e2;
	
	return mypair;
}
/*** End of Pairs ***/

/*** Maps ****/
typedef map<string,int> map_st_int;
typedef map<int,string> map_int_st;
typedef map<string,string> map_st_st;
 
/**** Find Key by Value for Maps ***/
string find_key(map_st_int MyMap, int value)
{
 map<string, int>::const_iterator it;
 string key = " ";
	
	bool found =false;	
	//Go through Map to find key
	for (it = MyMap.begin(); it != MyMap.end(); ++it)
	{
		if (it->second == value)
		{key = it->first;
		 found=true;
		 break;}
	}
		
	if(!found) {cout <<"ESSENS:ERROR:: Key to Value not Found in Map \n";}
	return key;	
}
/*** End of Function ***/


#endif
