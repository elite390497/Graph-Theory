#ifndef EXTRACT_ELEMENTS_HPP
#define EXTRACT_ELEMENTS_HPP
#include "structure_defs.hpp"
using namespace std;

//Extracts Relevant Information From Structure




//Pairs of Elements
//all
template <class Type1, class Type2>
void get(pair<Type1, Type2> e1, const string &opt, pair<Type1, Type2> *entry)
{ 
	if(opt=="all"){*entry=e1;}
	else{cout <<"ESSENS:ERROR::  Option" << opt << "Not Defined \n"; }
	
	return;
}

//first 
template <class Type1, class Type2>
void get(pair<Type1, Type2> e1, const string &opt, Type1* entry)
{ 	
  if(opt=="first"){*entry=e1.first;}
  else{cout <<"ESSENS:ERROR::  ^^^^Option" << opt << "Not Defined \n"; }
  
	
  return;
}

//second
template <class Type1, class Type2>
void get(pair<Type1, Type2> e1, const string &opt, Type2* entry)
{ 	
	if(opt=="second"){*entry=e1.second;}
	else{cout <<"ESSENS:ERROR::  Option" << opt << "Not Defined \n"; }


return;
} 


//Edges
void get(Edge e1, const string &opt, int *entry)
{ 
	if(opt=="node1"){*entry=e1.node1;}
	else {
		if(opt=="node2"){*entry=e1.node2;}
		else { cout <<"ESSENS:ERROR::  Option" << opt << "Not Defined \n"; }
	}//end of first else
	return;
}

void get(Edge e1, const string &opt, int_int *entry)
{ 
	if(opt=="ends"){entry->first=e1.node1; entry->second=e1.node2;}
		else { cout <<"ESSENS:ERROR::  Option" << opt << "Not Defined \n"; }
	return;
}

void get(Edge e1, const string &opt, double *entry)
{ 
		if(opt=="wt"){*entry=e1.edge_wt;}
		else { cout <<"ESSENS:ERROR::  Option" << opt << "Not Defined \n"; }
	return;
}


void get(Edge e1, const string &opt, Edge *entry)
{ 
	if(opt=="all"){*entry=e1;}
		else { cout <<"ESSENS:ERROR::  Option" << opt << "Not Defined \n"; }
	return;
}

//Single Elements
template <class Type1>
void get(Type1 e1, const string &opt, Type1* entry)
{ 
	if(opt=="all") {*entry=e1;}
	else{cout <<"ESSENS:ERROR::  ...Option" << opt << "Not Defined \n"; }
	return;
}

//As a vector operation
template<class Type1, class Type2>
void get_all(vector<Type1> Elements, const string &opt, vector<Type2> *Entries)
{
    Entries->resize(0);
	Type2 entry;
	for(int i=0;i<Elements.size();i++)
	{ 
		get(Elements[i], opt, &entry);
	Entries->push_back(entry);}	
	
	return;
}


/******* End of Functions **************/


#endif
