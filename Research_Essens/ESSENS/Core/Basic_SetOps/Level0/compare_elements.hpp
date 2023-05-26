#ifndef COMPARE_ELEMENTS_HPP
#define COMPARE_ELEMENTS_HPP
#include "structure_defs.hpp"
using namespace std;

//Compares Two Elements a,b
//returns 0 if a==b
//returns -1 if a<b
//returns +1 if a>b

/****** Compares Relations *******/

//Single Elements
template <class AnyType>
int compare(AnyType e1, AnyType e2)
{ if(e1==e2){return 0;}
	if(e1<e2){return 1;}
	if(e1>e2){return -1;}
}

//Pairs of Elements
//Options
template <class Type1, class Type2>
int compare(pair<Type1, Type2> e1, pair <Type1, Type2> e2, const string &opt)
{ int val=-100;
	
	if(opt=="first"){val=compare(e1.first, e2.first); return val;}
	if(opt=="second"){val=compare(e1.second, e2.second); return val;}
	if(opt=="both"){val=!(!compare(e1.first, e2.first) && !compare(e1.second, e2.second)); return val;}
	 
//Defaul--no match
cout <<"ESSENS:ERROR:: ** Option" << opt << "Not Defined \n"; val=-100;
return val;
}

//Deafult
template <class Type1, class Type2>
int compare(pair<Type1, Type2> e1, pair <Type1, Type2> e2)
{ return compare(e1, e2, "both");}

//Strings
int compare (string s1, string s2)
{
	if(s1.compare(s2)==0) {return 0;}
	if(s1.compare(s2)>0) {return 1;}
	if(s1.compare(s2)<0) {return -1;}
}

//Edges
//0 if equal
//1 if not
//-1 if edge_wt is less


//Options
int compare( Edge e1, Edge e2, const string &opt)
{
	int val=-100;
		 //Comparing Only one element"
	if(opt=="node1") {val=compare(e1.node1, e2.node1); return val;}
	if(opt=="node2") {val=compare(e1.node2, e2.node2); return val;}
	if(opt=="wt") {val=compare(e1.edge_wt, e2.edge_wt); return val;}
	

	  //Comparing both ends	
		if(opt== "end_dir")
		{if( (compare(e1.node1,e2.node1)==0) && (compare(e1.node2,e2.node2)==0)) {val=0;}
		else{val=1;}	  
		return val;}
	
		if(opt== "end_undir")
			{if( (compare(e1.node1,e2.node1)==0) && (compare(e1.node2,e2.node2)==0)) {val=0;}
			else {
			if( (compare(e1.node1,e2.node2)==0) && (compare(e1.node2,e2.node1)==0)){val=0;} 
		    else{val=1;}
			}
		return val;}
	
	//Matches any one end
		if(opt== "any_dir")
		{if( (compare(e1.node1,e2.node1)==0) || (compare(e1.node2,e2.node2)==0)) {val=0;}
		else{val=1;}	  
		return val;}
	
		if(opt== "any_undir")
		{if( (compare(e1.node1,e2.node1)==0) || (compare(e1.node2,e2.node2)==0)) {val=0;}
		else {
		if( (compare(e1.node1,e2.node2)==0) || (compare(e1.node2,e2.node1)==0)){val=0;} 
		else{val=1;}
		}
		return val;}
			
			
	  //Comparing all features	
		if(opt== "all_dir")
		{if( (compare(e1.node1,e2.node1)==0) && (compare(e1.node2,e2.node2)==0)&& (compare(e1.edge_wt,e2.edge_wt)==0)) {val=0;}
		else{val=1;}	  
		return val;}
	  
		if(opt== "all_undir")
		{ if( (compare(e1.edge_wt,e2.edge_wt)==0))
			{if( (compare(e1.node1,e2.node1)==0) && (compare(e1.node2,e2.node2)==0)) {val=0;}
		      else {
		       if( (compare(e1.node1,e2.node2)==0) && (compare(e1.node2,e2.node1)==0)){val=0;}
				else{val=1;}
			  }
			}
		   else{val=1;}
		return val;}
	
		//Defaul--no match
	     cout <<"ESSENS:ERROR:: -- Option" << opt << "Not Defined \n"; val=-100;
	
	return val;
}

//Default
int compare( Edge e1, Edge e2)
{ return compare(e1, e2, "end_dir");}



/******* End of Functions **************/


#endif
