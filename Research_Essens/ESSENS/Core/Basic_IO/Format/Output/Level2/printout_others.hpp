#ifndef PRINTOUT_OTHERS_HPP
#define PRINTOUT_OTHERS_HPP

#include "print_format_others.hpp"
using namespace std;

//==Level2 Functions
//print_vector
 //Prints the items of vectors 
 
/**** Print Vector *********/
template <class AnyType>
void print_vector(vector<AnyType> thisvector)
{
	cout <<"...\n";
	for(int i=0;i<thisvector.size();i++)
	{ print_element(thisvector[i]);}	
	cout <<"---\n";
	
	return;
}



template <class AnyType>
void print_vector(vector<AnyType> thisvector, int n)
{
	cout <<"...\n";
	int mymin=min(n,int(thisvector.size()));
	for(int i=0;i<mymin;i++)
	{ print_element(thisvector[i]);}	
	cout <<"---\n";
	
	return;
}

template <class AnyType>
void print_vector(vector<AnyType> thisvector, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists
	
	for(int i=0;i<thisvector.size();i++)
	{ print_element(thisvector[i],filename);}	
	//cout <<"---\n";
	//Close File
	myfile.close();
	
	return;
}


//Using Maps
template <class AnyType>
void print_vector(vector<AnyType> thisvector, map_st_int MyMap)
{
	cout <<"...\n";
	for(int i=0;i<thisvector.size();i++)
	{ print_element(thisvector[i], MyMap);}	
	cout <<"---\n";
	
	return;
}

template <class AnyType>
void print_vector(vector<AnyType> thisvector, map_st_int MyMap, char *filename)
{
	//Open file
	ofstream myfile;
	myfile.open (filename, ios::trunc); //clear if same named file exists
	
	for(int i=0;i<thisvector.size();i++)
	{ print_element(thisvector[i],MyMap, filename);}	
	cout <<"---\n";
	//Close File
	myfile.close();
	
	return;
}
/******* End of Function **************/



template <class AnyType>
void print_vector(vector<AnyType> thisvector, map_int_st MyMap, char *filename)
{
    //Open file
    ofstream myfile;
    myfile.open (filename, ios::trunc); //clear if same named file exists
    
    for(int i=0;i<thisvector.size();i++)
    {
      myfile << MyMap.find(thisvector[i])->second  << "  \n";
    }
    cout <<"---\n";
    //Close File
    myfile.close();
    
    return;
}
/******* End of Function **************/

#endif
