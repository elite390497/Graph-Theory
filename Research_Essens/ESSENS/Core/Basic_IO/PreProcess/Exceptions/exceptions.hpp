#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include<iostream>
#include "exceptions.hpp"
using namespace std;




/******** Start of Functions ************/

/***Start of Function***/
/*!
 \brief Argument Type is not valid
 */

void exception_invalid_type()
{
	cout << "ESSENS:ERROR:: Only Type 1 is  Accepted \n";
	return ;	
}	
/** End of Function **/
	

/***Start of Function***/
/*!
 \brief Weight is not Integer or Double
 */

void exception_weight_string() 
{
	cout << "ESSENS:ERROR:: Weight Not Integer or Double \n";
	return ;	
}	
/** End of Function **/




/******** End of All  Functions ************/
	
#endif
