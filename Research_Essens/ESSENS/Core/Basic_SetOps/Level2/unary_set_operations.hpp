#ifndef UNARY_SET_OPERATIONS_HPP
#define UNARY_SET_OPERATIONS_HPP
#include "order_elements.hpp"
#include "extract_elements.hpp"
#include <algorithm>      
using namespace std;

//All These Functions are Defined in  STL C++
//The compare function has been modified to accomodate different datasets


//Change from list to vector
//This will be obsolete when we do template for containers
template <class AnyType>
vector<AnyType> list_to_vector(list<AnyType> mylist)
{
vector<AnyType> new_node;
new_node.clear();
    

while(!mylist.empty())
{
    new_node.push_back(mylist.back());
    mylist.pop_back();
}//end of while
    
    
    
    return new_node;
}
/******* End of Functions **************/
    

//Sort
/******Sort Vectors of Elements***/
template <class AnyType>
void sort(vector<AnyType> *e1, bool (func) (const AnyType , const AnyType))
{  sort(e1->begin(), e1->end(), func); return;}

//Default
template <class AnyType>
void sort(vector<AnyType> *e1)
{  sort(e1, inc); return;}
/******* End of Functions **************/

//Heap Functions
/******Creating Heap from Vectors of Elements***/
template <class AnyType>
void make_heap(vector<AnyType> *e1, bool (func) (const AnyType , const AnyType))
{ make_heap(e1->begin(), e1->end(), func); return;}

//Default
template <class AnyType>
void make_heap(vector<AnyType> *e1)
{ make_heap(e1, inc); return;}
/******* End of Functions **************/

/******Pop Top of Heap from Vectors of Elements***/
template <class AnyType>
void pop_heap(vector<AnyType> *e1, bool (func) (const AnyType , const AnyType))
{ pop_heap(e1->begin(), e1->end(), func); 
  e1->pop_back();
 return;}

//Default
template <class AnyType>
void pop_heap(vector<AnyType> *e1)
{ pop_heap(e1, inc); 
return;}
/******* End of Functions **************/

/******Push into Heap one Elements***/
template <class AnyType>
void push_heap(vector<AnyType> *e1, AnyType a, bool (func) (const AnyType , const AnyType))
{e1->push_back(a); 
 push_heap(e1->begin(), e1->end(), func); return;}

//Default
template <class AnyType>
void push_heap(vector<AnyType> *e1, AnyType a)
{ push_heap(e1,a, inc); return;}
/******* End of Functions **************/


/******Push into Heap multiple Elements***/
template <class AnyType>
void push_heap(vector<AnyType> *e1, vector<AnyType> a, bool (func) (const AnyType , const AnyType))
{
	for(int i=0;i<a.size();i++)
	{
	e1->push_back(a[i]); 
push_heap(e1->begin(), e1->end(), func); 
	}
	return;}

/******* End of Functions **************/

//Max Min
/******Find Max from Vectors of Elements***/
template <class AnyType>
AnyType max_element(vector<AnyType> e1, bool (func) (const AnyType , const AnyType))
{return *max_element(e1.begin(), e1.end(), func);}

//Default
template <class AnyType>
AnyType max_element(vector<AnyType> e1)
{return max_element(e1, inc);}
/******* End of Functions **************/

/******Find Min from Vectors of Elements***/
template <class AnyType>
AnyType min_element(vector<AnyType> e1, bool (func) (const AnyType , const AnyType))
{return *min_element(e1.begin(), e1.end(), func);}


//Default
template <class AnyType>
AnyType min_element(vector<AnyType> e1)
{return min_element(e1, inc);}
/******* End of Functions **************/


//Contains
/****Checks if Given Element in Vector ******/


//reduce Type1, Type2 ==> Type3
//Finds index of given value; else returns -1;
template <class Type1, class Type2, class Type3 >
bool contains(vector<Type1> e1, const string &opt1, Type2 e2, const string &opt2, Type3 common)
{
	bool found=false;
	Type3 entry1, entry2;
	
	get(e2,opt2,&entry2);
	for(int i=0;i<e1.size();i++)
	{   get(e1[i], opt1, &entry1);
		if(!compare(entry1,entry2)) {found=true; break;}
	}
	return found;
}

//Finds indices of all matching values; else returns -1;
template <class Type1, class Type2, class Type3 >
void contains(vector<Type1> e1, const string &opt1, Type2 e2, const string &opt2, Type3 common, vector<int> *index)
{
	index->resize(0);
	Type3 entry1, entry2;
	
	get(e2,opt2,&entry2);
	for(int i=0;i<e1.size();i++)
	{   get(e1[i], opt1, &entry1);
		if(!compare(entry1,entry2)) {index->push_back(i);}
	}
	
	return;
}


//Returns indices and values of all matching values; else returns -1;
template <class Type1, class Type2, class Type3 >
void contains(vector<Type1> e1, const string &opt1, Type2 e2, const string &opt2, Type3 common, vector<Type1> *elements, vector<int> *index)
{
	elements->resize(0);
	index->resize(0);
	Type3 entry1, entry2;
	pair<Type1, int> myEs;
	
	get(e2,opt2,&entry2);
	for(int i=0;i<e1.size();i++)
	{   get(e1[i], opt1, &entry1);
		if(!compare(entry1,entry2)) 
		{elements->push_back(e1[i]);
		index->push_back(i);}
		
	}
	
	return;
}
///////////////

//Finds index of given value; else returns -1;
//Assumes the vector is sorted in increasing order. Therefore breaks when reaches higher numbers

bool binary_search(vector<int> e1, int e2)
{
	bool found=false;
	found=binary_search(e1.begin(), e1.end(),e2);
	return found;
}

//reduce Type2 ==> Type1
//Finds index of given value; else returns -1;
//Assumes the vector is sorted in increasing order. Therefore breaks when reaches higher numbers
template <class Type1, class Type2 >
bool contains_sort(vector<Type1> e1, Type2 e2, const string &opt2)
{
	bool found=false;
	Type1 entry2;
	get(e2,opt2,&entry2);
	
	for(int i=0;i<e1.size();i++)
	{
		if(!compare(e1[i],entry2))
		{found=true; break;}
		if(compare(e1[i],entry2)<0)
		{break; }
	}
	return found;
}


template <class Type1, class Type2 >
bool contains_sort(Type2 e2, vector<Type1> e1, const string &opt2)
{
	bool found=false;
	Type2 entry2;
	
	
	for(int i=0;i<e1.size();i++)
	{
		get(e1[i],opt2,&entry2);
		if(!compare(e2,entry2))
		{found=true; break;}
		if(compare(entry2,e2)<0)
		{break; }
	}
	return found;
}

//Finds index of given value; else returns -1;
//Assumes the vector is sorted in increasing order. Therefore breaks when reaches higher numbers
template <class Type1>
bool contains_sort(vector<Type1> e1, Type1 e2)
{
	bool found=false;
	for(int i=0;i<e1.size();i++)
	{
		if(!compare(e1[i],e2))
		{found=true; break;}
		if(compare(e1[i],e2)<0)
		{break; }
	}
	return found;
}




///////////////////
//reduce Type2 ==> Type1
//Finds index of given value; else returns -1;
template <class Type1, class Type2 >
bool contains(vector<Type1> e1, Type2 e2, const string &opt2)
{
	bool found=false;
	Type1 entry2;
	get(e2,opt2,&entry2);
	
	for(int i=0;i<e1.size();i++)
	{
	if(!compare(e1[i],entry2))
	{found=true; break;}
	}
	return found;
}

//First Element is large
//Finds indices of all matching values; else returns -1;
template <class Type1, class Type2>
void contains(vector<Type1> e1, const string &opt2, Type2 e2,  vector<int> *index)
{
	index->resize(0);
	Type2 entry2;
	for(int i=0;i<e1.size();i++)
	{   
		get(e1[i],opt2,&entry2);
		if(!compare(e2,entry2))
		{index->push_back(i);}
	}
	
	return;
}

//Returns indices and values of all matching values; else returns -1;
template <class Type1, class Type2>
void contains(vector<Type1> e1, const string &opt2, Type2 e2,  vector<Type1> *elements, vector<int> *index)
{
	elements->resize(0);
	index->resize(0);
	
    Type2 entry2;
	for(int i=0;i<e1.size();i++)
	{   
		get(e1[i],opt2,&entry2);
		if(!compare(e2,entry2))
		{elements->push_back(e1[i]);
		index->push_back(i);}
		
	}
	
	return;
}

//Second Element is large
//Finds indices of all matching values; else returns -1;
template <class Type1, class Type2>
void contains(vector<Type1> e1, Type2 e2, const string &opt2, vector<int> *index)
{
	index->resize(0);
	Type1 entry2;
	get(e2,opt2,&entry2);
	for(int i=0;i<e1.size();i++)
	{   
		if(!compare(e1[i],entry2))
		{index->push_back(i);}
	}
	
	return;
}

//Returns indices and values of all matching values; else returns -1;
template <class Type1, class Type2>
void contains(vector<Type1> e1, Type2 e2, const string &opt2, vector<Type1> *elements, vector<int> *index)
{
	elements->resize(0);
	index->resize(0);
	
    Type1 entry2;
	get(e2,opt2,&entry2);
	
	for(int i=0;i<e1.size();i++)
	{   
		if(!compare(e1[i],entry2))
		{elements->push_back(e1[i]);
		index->push_back(i);}
		
	}
	return;
}


//Default;
//Finds index of given value; else returns -1; compares exact elements
template <class Type1>
bool contains(vector<Type1> e1, Type1 e2)
{
	bool found=false;
	
	for(int i=0;i<e1.size();i++)
	{   if(!compare(e1[i],e2)) 
	{found=true; break;}
	}
	return found;
}

template <class Type1>
void contains(vector<Type1> e1, Type1 e2, vector<int> *index)
{
	index->resize(0);
	
	for(int i=0;i<e1.size();i++)
	{   if(!compare(e1[i],e2)) 
			{index->push_back(i);}
	}
	
	return;
}

/***********************/


//Unique
//Set should be sorted
/******Create Unique Vectors of Elements***/
template <class AnyType>
vector<AnyType> unique(vector<AnyType> e1, bool (func) (AnyType , AnyType))
{ 
	vector<AnyType> Out;
	Out=e1;
	
	//Get unique elements
	typename vector<AnyType>::iterator it;
	it=unique(Out.begin(), Out.end(), func);
	
	//Resize to get unique elements only
	Out.resize(distance(Out.begin(),it));
	
	return Out;			   
}

/******* End of Function **************/

//Unique based on a particular field
template <class Type1, class Type2>
vector<Type1> unique(vector<Type1> e1, const string &opt, bool (func) (Type2 , Type2), Type2 common)
{ 
	vector<Type1> Out, elements;
	Out.resize(0);
	vector<Type2> entry;
	vector<int> index;
	
	//Extract Fields
	get_all(e1, opt, &entry);
	//Get Unique Based on Fields
	entry=unique(entry, func);
	
	//Find entries in Oe1 that match
	for (int i=0;i<entry.size();i++)
	{ contains(e1,opt,entry[i],&elements, &index);	
	Out.push_back(elements[0]);}	  
				
return Out;			   
}
/******* End of Function **************/				  
				  
				  
		//Default
				  template <class AnyType>
				  vector<AnyType> unique(vector<AnyType> e1)
				  { 
				  vector<AnyType> Out;
				  Out=unique(e1,eq);
				  return Out;			   
				  }
	/******* End of Functions **************/

/***** Max and Min ******/

#endif
