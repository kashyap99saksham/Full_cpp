//copy constructor is make ,used to copy one object into another object.
//we use reference variable coz if not then it call default constructor and go infinitly
#include<iostream>  
#include<stdio.h> 

using namespace std; 

class Test 
{ 
	public: 
	Test() {} 
	Test(const Test &t) 
	{ 
		cout<<"Copy constructor called "<<endl; 
	} 
	
	Test& operator = (const Test &t) 
	{ 
		cout<<"Assignment operator called "<<endl; 
		return *this; 
	} 
}; 

// Driver code 
int main() 
{ 
	Test t1, t2; 
	t2 = t1; 
	Test t3 = t1; 
	getchar(); 
	return 0; 
} 
//HERE:
t2 = t1; // calls assignment operator, same as "t2.operator=(t1);" 
Test t3 = t1; // calls copy constructor, same as "Test t3(t1);" 
