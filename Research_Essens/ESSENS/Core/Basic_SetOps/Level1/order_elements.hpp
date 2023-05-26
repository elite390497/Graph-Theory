#ifndef ORDER_ELEMENTS_HPP
#define ORDER_ELEMENTS_HPP
#include "compare_elements.hpp"
#include<algorithm>
using namespace std;


/****** Functions to Denote Order *******/

//-------Increasing order


//Pairs of Elements
//--increment by first
 template <class AnyType>
bool inc_first(AnyType e1, AnyType e2)
{ 
  if(compare(e1.first,e2.first)==0)
  { return (compare(e1.second, e2.second)==1);}
 else
	{ return (compare(e1.first, e2.first)==1);}
}

template <class AnyType>
bool inc_first_only(AnyType e1, AnyType e2)
{ return (compare(e1.first, e2.first)==1);}

//--increment by second
template <class AnyType>
bool inc_second(AnyType e1, AnyType e2)
{ 
	if(compare(e1.second,e2.second)==0)
	{return (compare(e1.first, e2.first)==1);}
	else
	{return (compare(e1.second, e2.second)==1);}
}

template <class AnyType>
bool inc_second_only(AnyType e1, AnyType e2)
{ return (compare(e1.second, e2.second)==1);}

//Default 
template <class AnyType1, class AnyType2>
bool inc( pair<AnyType1, AnyType2> e1, pair<AnyType1, AnyType2> e2)
{ return inc_first(e1,e2);}


//Strings
bool inc(const string s1, const string s2){ return (s1.compare(s2)<=0); }
	
//Edges
//--increment by node1
bool inc_node1(Edge e1,  Edge e2)
{
	if(e1.node1==e2.node1)
		{return (e1.node2 <e2.node2);}
	else
		{return (e1.node1 < e2.node1);}
}
			
//--increment by node2
bool inc_node2( Edge e1, Edge e2)
{
    if(e1.node2==e2.node2)
    {return (e1.node1 <e2.node1);}
    else
    {return (e1.node2 < e2.node2);}
	
}		

//--increment by weight
bool inc_wt( Edge e1, Edge e2)
{ return (compare(e1.edge_wt,e2.edge_wt)==1);}

//Default
bool inc( Edge e1,  Edge e2)
{ return inc_node1(e1,e2);}

//Single Elements
template<class AnyType>
bool inc(AnyType e1,  AnyType e2) { return (compare(e1,e2)==1);}

/******* End of Functions **************/



//-------Decreasing order


//Pairs of Elements
//--decrement by first
template <class AnyType>
bool dec_first(AnyType e1, AnyType e2)
{ 
	if(compare(e1.first,e2.first)==0)
	{ return (compare(e1.second, e2.second)==-1);}
	else
	{ return (compare(e1.first, e2.first)==-1);}
}

template <class AnyType>
bool dec_first_only(AnyType e1, AnyType e2)
{ return (compare(e1.first, e2.first)==-1);}

//--increment by second
template <class AnyType>
bool dec_second(AnyType e1, AnyType e2)
{ 
	if(compare(e1.second,e2.second)==0)
	{return (compare(e1.first, e2.first)==-1);}
	else
	{return (compare(e1.second, e2.second)==-1);}
}

template <class AnyType>
bool decc_second_only(AnyType e1, AnyType e2)
{ return (compare(e1.second, e2.second)==-1);}

//Default 
template <class AnyType1, class AnyType2>
bool dec( pair<AnyType1, AnyType2> e1, pair<AnyType1, AnyType2> e2)
{ return dec_first(e1,e2);}

//Strings
bool dec (string s1, string s2){ return (s1.compare(s2)>0); }

//Edges
//--decrement by node1
bool dec_node1( Edge e1, Edge e2)
{
	if(compare(e1.node1,e2.node1)==0)
	{return (compare(e1.node2, e2.node2)==-1);}
	else
	{return (compare(e1.node1, e2.node1)==-1);}
}

//--decrement by node2
bool dec_node2( Edge e1, Edge e2)
{
	if(compare(e1.node2,e2.node2)==0)
	{return (compare(e1.node1, e2.node1)==-1);}
	else
	{return(compare(e1.node2, e2.node2)==-1);}
}		

//--decrement by weight
bool dec_wt( Edge e1, Edge e2) {return (compare(e1.edge_wt, e2.edge_wt)==-1);}	
	

//Default
bool dec( Edge e1,  Edge e2)
{ return dec_node1(e1,e2);}

//Single Elements
template<class AnyType>
bool dec(AnyType e1,  AnyType e2) { return (compare(e1,e2)==-1);}
/******* End of Functions **************/



/*** Functions to Denote Equality*********/
template<class AnyType>
bool eq(const AnyType e1,  const AnyType e2) { return (e1==e2);}

//Pairs of Elements
//--equality by first
template <class AnyType>
bool eq_first(AnyType e1, AnyType e2) { return (e1.first==e2.first);}

//--equality by second
template <class AnyType>
bool eq_second(AnyType e1, AnyType e2) { return (e1.second==e2.second);}

//--equality by first and second
/*template <class AnyType>
bool eq(AnyType e1, AnyType e2) { return ((e1.first==e2.first) && (e1.second==e2.second));}*/
	
//Edges
//--equality by node1
bool eq_node1( Edge e1, Edge e2) {return ((e1.node1==e2.node1)) ; }
//--equality by node2
bool eq_node2( Edge e1, Edge e2) {return (e1.node2==e2.node2); }	
//--equality by weight
bool eq_wt( Edge e1, Edge e2) {return (e1.edge_wt==e2.edge_wt); }
//--equality by node1 and node2
bool eq_both( Edge e1, Edge e2) {return ((e1.node1==e2.node1) && (e1.node2==e2.node2)); }
//--equality by node1 and node2 and weight
bool eq( Edge e1, Edge e2) {return ((e1.node1==e2.node1) && (e1.node2==e2.node2) && (e1.edge_wt==e2.edge_wt) ); }

//Strings
//Check strings
bool eq(const string s1, const string s2){ return ( (s1.compare(s2)<0) ); }

/******* End of Functions **************/

/*** Functions to Denote Non Equality*********/
template<class AnyType>
bool neq(const AnyType &e1,  const AnyType &e2) { return (!(e1==e2));}

//Pairs of Elements
//--equality by first
template <class AnyType>
bool neq_first(AnyType e1, AnyType e2) { return (!(e1.first==e2.first));}

//--equality by second
template <class AnyType>
bool neq_second(AnyType e1, AnyType e2) { return (!(e1.second==e2.second));}


/******* End of Functions **************/

#endif
