#ifndef PRINT_FORMAT_OTHERS_HPP
#define PRINT_FORMAT_OTHERS_HPP

#include "structure_defs.hpp"
using namespace std;

//==Level1 Functions
 /**print_element (Prints specified elements)
 //int, double,string
 //pairs<int_int> <int_double>
 //Edge **/

/**** Print Single Types **************/
template <class AnyType>
void print_element(AnyType mye)
{cout << mye <<"\n";}

template <class AnyType>
void print_element(AnyType mye, char *filename)
{ofstream myfile;	
myfile.open (filename, ios::trunc); //append to existsing file
myfile << mye <<"\n";}

//Using Maps
void print_element(int mye, map_st_int MyMap)
{cout << find_key(MyMap,mye) <<"\n";}

void print_element(int mye, map_st_int MyMap, char *filename)
{ofstream myfile;	
	myfile.open (filename, ios::app); //append to existsing file
myfile << find_key(MyMap,mye) <<"\n";}


/******* End of Function **************/

/******* Print Pairs **************/

void print_element(int_int mye)
{cout << mye.first <<"::"<<mye.second<<"\n";}

void print_element(int_double mye)
{cout << mye.first <<"::"<<mye.second<<"\n";}

/*
template <class Type1, class Type2>
void print_element(pair<Type1,Type2> mye, char *filename)
{ofstream myfile;	
	myfile.open (filename, ios::app); //append to existsing file
myfile << mye.first <<"::"<<mye.second<<"\n";}*/


//Using Maps
void print_element(int_int mye, map_st_int MyMap)
{cout << find_key(MyMap,mye.first) <<"::"<<find_key(MyMap,mye.second)<<"\n";}

template <class Type1>
void print_element(pair<int,Type1> mye, map_st_int MyMap)
{cout << find_key(MyMap,mye.first) <<"::"<<mye.second<<"\n";}

void print_element(int_int mye, map_st_int MyMap, char *filename)
{ofstream myfile;	
	myfile.open (filename, ios::app); //append to existsing file
myfile << find_key(MyMap,mye.first) <<"::"<<find_key(MyMap,mye.second)<<"\n";}

template <class Type1>
void print_element(pair<int,Type1> mye, map_st_int MyMap, char *filename)
{ofstream myfile;	
	myfile.open (filename, ios::app); //append to existsing file
myfile << find_key(MyMap,mye.first) <<"::"<<mye.second<<"\n";}
/******* End of Function **************/

/******* Print Edges **************/
void print_element(Edge mye)
{cout << mye. node1 <<"::"<<mye.node2 <<"::"<<mye.edge_wt <<"\n";}

void print_element(Edge mye, char *filename)
{ofstream myfile;	
	myfile.open (filename, ios::app); //append to existsing file
myfile << mye. node1 <<" "<<mye.node2 <<" "<<mye.edge_wt <<"\n";}

//Using Maps
void print_element(Edge mye, map_st_int MyMap)
{cout << find_key(MyMap,mye.node1) <<"::"<< find_key(MyMap,mye.node2)  <<"::"<<mye.edge_wt <<"\n";}

void print_element(Edge mye, map_st_int MyMap, char *filename)
{ofstream myfile;	
	myfile.open (filename, ios::app); //append to existsing file
myfile << find_key(MyMap,mye.node1) <<"::"<< find_key(MyMap,mye.node2)  <<"::"<<mye.edge_wt <<"\n";}
/******* End of Function **************/


template <class Type1, class Type2>
void print_element(pair<Type1,Type2> mye)
{print_element(mye.first); 
print_element(mye.second);}


#endif
