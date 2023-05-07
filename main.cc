/*
 The idea behind this little project is to make use of STL
 and build a kind of tcl interpreter ( or simulator! ? )
 
 I am not very inclined towards building everything that
 tcl does, that wouldn't be wise. : ) Main focus is to build
 some of the basic things ( Listed in README.md ) that can 
 execute a small program out of a tcl script file.

*/
/*
DEBUG MODE:
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

#include "common_includes.h"

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
	  proc_type proc_list;
	  string inp;
	  vector<string> split_cmd;
	  bool custom_prc=false;

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
		removeDupWord(inp,split_cmd,0);
		if(inp.substr(0,4)=="exit") { break; }
		if(inp.substr(0,4)=="help") { help(); }

		/*
	   if user wants to process a proc/function
	    */
	  if (inp.substr(0,4)=="proc") {
		cout<<"Init proc"<<endl;
		proc(inp.substr(5,inp.length()),proc_list);
	  } else {
		
		/*
		 if it wasn't custom prc then
		 execute normal commands..
		*/
		if(!proc_execute(inp,proc_list)) {
			cout<<parse_cmd(inp,vars)<<endl;
		}
		custom_prc=false;
	  }

	  	DBG("You have entered :"<<inp<<endl);
		/*
		We call this nice routine who should 
		handle all the job of cmds parsing.
		*/
	  	
	}	 
}

