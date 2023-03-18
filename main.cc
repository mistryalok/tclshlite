/*
 The idea behind this little project is to make use of STL
 and build a kind of tcl interpreter ( or simulator! ? )
 
 I am not very inclined towards building everything that
 tcl does, that wouldn't be wise. : ) Main focus is to build
 some of the basic things ( Listed in README.md ) that can 
 execute a small program out of a tcl script file.

*/
/*
 We have a debug mode to enable some more
 info about how and where things are stored in
 map and vectors.
*/
//#define DBGMODE
#ifdef DBGMODE
#define DBG(x) cout<<x<<endl;
#else
#define DBG(x) //x
#endif

#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <fstream>
#include "parse_cmd.h"



using namespace std;

int main() {
	/*
	 This is the command stack TOBEUSED
	*/
	  stack<string> cmds_stack;
	/*
	 vars: is used to store all the various
	 variables in memory.
	*/
	  map<string,string> vars;
	  string inp;
	  cout<<"########################################"<<endl;
	  cout<<"# Welcome to tclshlite..               #"<<endl;
	  cout<<"# 										#"<<endl;
	  cout<<"# Author: Alok Mistry          		#"<<endl;
	  cout<<"# Type ./tclshlite -help for more info.#"<<endl;
	  cout<<"########################################"<<endl;

	/*
	so we keep on looping until user says no more please.
	*/ 
	while(1) {
	  	cout<<"%";
	  	getline(cin,inp);
		if(inp.substr(0,4)=="exit") { break; }
	  	DBG("You have entered :"<<inp<<endl);
		/*
		We call this nice routine who should 
		handle all the job of cmds parsing.
		*/
	  	cout<<parse_cmd(inp,vars)<<endl;
	}	 
	

}

