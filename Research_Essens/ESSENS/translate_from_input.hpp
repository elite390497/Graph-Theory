#ifndef TRANSLATE_FROM_INPUT_HPP
#define TRANSLATE_FROM_INPUT_HPP

#include<iostream>
#include "node_node_weight.hpp"
#include "node_weight_node.hpp"
#include "node_node.hpp"
#include "check_type.hpp"
#include "exceptions.hpp"
#include "structure_defs.hpp"
using namespace std;




/******** Start of Functions ************/
/*!
 \brief Calls Level1 translation function
 */
/*** Selects Correct Translation Function ***/
void translate_input(char *file, int type, char *gfile, char *mapfile)
{	
	
	switch (type)
	{ case 1:
			node_node_wt(file, gfile, mapfile); break;
	 case 2:
		//node_wt_node(file, mapfile,nodemap,revmap); break;
     case 4:
		//	node_node(file, nodemap,revmap); break;
	default:		
			exception_invalid_type(); break;
	}
	
	return ;	
}
/*** End of Function ***/


/*** Creates Map from nodes in mapfile to Actual Values ***/
void create_map(char *file,  map_int_st *revmap)
{
    
    string st1, st2;
    std::pair<std::map<int,string>::iterator,bool> ret;
    string line;
    stringstream linestream;
    int i=0;
    ifstream dataFile(file, ios::in); //Open input file
    while(getline(dataFile, line))
    {
        //Readline
        linestream.clear();
        linestream<<line;
        linestream >> st1 >> st2;
        
        int num=atoi(st2.c_str());
        ret=revmap->insert( std::pair<int,string>(num,st1) );
        
    }//end of while
    dataFile.close();
    
    return;
}
/*** End of Function ***/


/*** Creates Map from nodes in mapfile to Actual Values ***/
void create_map(int nodes,  map_int_st *revmap)
{
    
    string st1;
    std::pair<std::map<int,string>::iterator,bool> ret;
    string line;
    stringstream linestream;
    int i=0;
    for(int i=0;i<nodes;i++)
    {
        st1=static_cast<ostringstream*>( &(ostringstream() << i) )->str();
        ret=revmap->insert( std::pair<int,string>(i,st1) );
    }
    
    return;
}
/*** End of Function ***/


/******** End of All  Functions ************/		
#endif
