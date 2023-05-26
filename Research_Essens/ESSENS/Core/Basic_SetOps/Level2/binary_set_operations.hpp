#ifndef BINARY_SET_OPERATIONS_HPP
#define BINARY_SET_OPERATIONS_HPP
#include "order_elements.hpp"
using namespace std;
 
//Assumes elements are unique
//Elements should be sorted in increasing order
//Intersection
//Difference
//Subset
//Sorted Merge

/******Intersect Two Sets ***/
//Should be sorted
template <class AnyType>
vector<AnyType> intersect(vector<AnyType> elista, vector<AnyType> elistb,bool (func) ( AnyType, AnyType))
{ 
	//Create output vector
	vector<AnyType> elistc;
	elistc.resize(elista.size()+elistb.size());
	typename std::vector<AnyType>::iterator it;
	
	//Execute intersection
	it=set_intersection(elista.begin(),elista.end(), elistb.begin(), elistb.end(), elistc.begin(), func);
	
	//Resize output
	 elistc.resize(it-elistc.begin());
	
	return elistc;
}


//Default
template <class AnyType>
vector<AnyType> intersect(vector<AnyType> elista, vector<AnyType> elistb)
{ return intersect(elista, elistb, inc);}

/******Find Difference of A-B ***/
//Should be sorted
template <class AnyType>
vector<AnyType> difference(vector<AnyType> elista, vector<AnyType> elistb, bool (func) (AnyType, AnyType))
{ 
	//Create output vector
	vector<AnyType> elistc;
	elistc.resize(elista.size());
	typename std::vector<AnyType>::iterator it;
	
	//Execute intersection
	it=set_difference(elista.begin(),elista.end(), elistb.begin(), elistb.end(), elistc.begin(),func);
	
	//Resize output
	elistc.resize(it-elistc.begin());
	
	return elistc;
}

//Default
template <class AnyType>
vector<AnyType> difference(vector<AnyType> elista, vector<AnyType> elistb)
{ return difference(elista, elistb, inc);}




/********Merge Lists A and B***********/
//Should be sorted
//has Repeats

template <class AnyType>
vector<AnyType> merge(vector<AnyType> elista, vector<AnyType> elistb, bool (func) (AnyType, AnyType))
{ 
	//Create output vector
	vector<AnyType> elistc;
	elistc.resize(elista.size()+elistb.size());
	typename std::vector<AnyType>::iterator it;
	
	//Execute intersection
	it=merge(elista.begin(),elista.end(), elistb.begin(), elistb.end(), elistc.begin(), func);
	
	//Resize output
	elistc.resize(it-elistc.begin());
	return elistc;
}
/***** End of Function ***/

//Default
template <class AnyType>
vector<AnyType> merge(vector<AnyType> elista, vector<AnyType> elistb)
{ 
	//Create output vector
	return merge(elista, elistb, inc);
}
/***** End of Function ***/


//Should be sorted
//has Repeats

template <class AnyType>
vector<AnyType> merge(AnyType e1, vector<AnyType> elistb, bool (func) (AnyType, AnyType))
{ 
	//Create vector of element
	vector<AnyType> elista;
	elista.resize(1);
	elista[0]=e1;
	
	//Create output vector
	vector<AnyType> elistc;
	elistc.resize(1+elistb.size());
	typename std::vector<AnyType>::iterator it;
	
	//Execute intersection
	it=merge(elista.begin(),elista.end(), elistb.begin(), elistb.end(), elistc.begin(),func);
	
	//Resize output
	elistc.resize(it-elistc.begin());
	return elistc;
}


//Default
template <class AnyType>
vector<AnyType> merge(AnyType e1, vector<AnyType> elistb)
{ 
	vector<AnyType> e1_vec;
	e1_vec.resize(0);
	e1_vec.push_back(e1);
	return merge(e1_vec,elistb);
}



//Subset
//Checks if B is a subset of A
//Should be sorted

template <class AnyType>
bool issubset(vector<AnyType> elista, vector<AnyType> elistb, bool (func) (AnyType, AnyType))
{ 
	//Find Intersection
	vector<AnyType> elistc=intersect(elista, elistb, func);
	
	//Check if Intersection equal to B
	return (elistc.size()==elistb.size());
}

//Default
template <class AnyType>
bool issubset(vector<AnyType> elista, vector<AnyType> elistb)
{ return issubset(elista, elistb, inc);}
//******* End of Functions **************/


#endif