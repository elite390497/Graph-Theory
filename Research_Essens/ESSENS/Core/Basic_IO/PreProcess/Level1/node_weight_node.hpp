#ifndef NODE_WEIGHT_NODE_HPP
#define NODE_WEIGHT_NODE_HPP

#include<iostream>
#include<vector> 
#include<fstream>
#include<sstream>
#include<map>
#include "check_type.hpp"
#include "exceptions.hpp"
#include "structure_defs.hpp"
using namespace std;

/****List of Functions ******
 == Default graph_file graphXX
 == Default map_file mapXX
 ==Default error; printed on screen
 ==Calls 
 check_int
 check_double
 execption_weight_string()
  node_node_wt
 --Overloaded as; 
 (input file); DONE 
***** End of Description*****/


/******** Start of Functions ************/
/*
 Input: Edge List from File (Node Node Weight) \n
 Translates Edgelist from String to Numbers \n
 Stores EdgeList as Numbers to graphXX \n
 Stores Map of String to Number in nodemap \n
 */

void node_wt_node(char *file, map_st_int *nodemap, map_int_st *revmap) 
{
    //Activity1: Translate Strings to Numbers
	string st1, st2, wt;
	std::pair<std::map<string,int>::iterator,bool> ret;
	std::pair<std::map<int,string>::iterator,bool> retR;
	string line;
	stringstream linestream;
	int i=0; 

	ofstream myfile;
	myfile.open ("graphXX", ios::trunc); //Open graph_file
	
	ifstream dataFile(file, ios::in); //Open input file
	while(getline(dataFile, line))
	{
	    //Readline
		linestream<<line; 	
		linestream >> st1 >> wt >> st2; 
		
		//Add strings st1, st2 to map if it does not yet exist
		ret=nodemap->insert ( std::pair<string,int>(st1,i) );
		if(ret.second==true){
		retR=revmap->insert ( std::pair<int,string>(i,st1) );
		i++;}
		
		ret=nodemap->insert ( std::pair<string,int>(st2,i) );
		if(ret.second==true){
		retR=revmap->insert ( std::pair<int,string>(i,st2) );
		i++;}
		
		//Check if wt is int or double
		if(!check_int(wt) && !check_double(wt)) //If it is string--raise exception 
		{ exception_weight_string(); break;}
		
		linestream.clear();
		
		//Output transalted nodes to graph_file
		myfile << nodemap->find(st1)->second <<" "<<nodemap->find(st2)->second<<" "<<wt<<"\n";
		
	} //end of reading file
	//Close File
	myfile.close();
	
	//========= Done Activity 1 =============//
	
	
	//Activity2: Store Map for Back Translation
	ofstream myfile1;
	myfile1.open ("mapXX", ios::trunc); //Open map file
	
	//Output to mapfile
	std::map<string,int>::iterator it;
	for (it=nodemap->begin(); it!=nodemap->end(); ++it)
		myfile1 << it->first << " " << it->second << "\n";
	
	//Close File
	myfile1.close();
	//========= Done Activity 2 =============//
	
	return ;	
}
	
/******** End of All  Functions ************/		
#endif
