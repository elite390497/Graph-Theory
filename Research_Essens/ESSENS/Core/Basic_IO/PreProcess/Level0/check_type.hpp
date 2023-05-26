#ifndef CHECK_TYPE_HPP
#define CHECK_TYPE_HPP

#include<iostream>
#include <sstream>
using namespace std;

/******** Start of Functions ************/

/*** Start of Function ***/
/*!
 \brief Check whether input is string
 */
bool check_int(string s) {

	bool answer=true;
	
	for(int i=0;i<s.size();i++)
	{
		if(!isdigit(s[i])) {answer=false; break;}
	}
		   
return answer;
	
}
/*** End of Function ***/


/*** Start of Function ***/
/*!
 \brief Check whether input is double
 */
bool check_double(std::string const& s) {
	std::istringstream ss(s);
	double d;
	//return (ss >> d);
    return true;
}
/*** End of Function ***/

/******** End of All  Functions ************/

#endif
