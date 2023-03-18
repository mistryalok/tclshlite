#ifndef _PROC_SET_
#define _PROC_SET_
#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;
#include "util.h"

string parse_cmd(const string& inp,map<string,string>& vars);
void proc_set(string inp, map<string,string>& vars) {
	DBG("Called with inp ="<<inp<<endl);
	/* 
	Split command into chunks.. i.e set variable "abcd" = 
	in Vector<string> store below..

	1. variable
	2. "abcd"
	*/
	vector<string> split_cmd;
	string var="";
	int i=0;
	DBG("Printing wors");
	removeDupWord(inp,split_cmd,1);
	DBG("Printing wors done"<<endl);
	/* 
	Take abcd into a string to manupulate.. or check
	if there is recursive call
	*/
	string in_d = split_cmd.at(1);
	DBG("String is "<<in_d<<endl);
	if(in_d.substr(0,1)=="[") {
		DBG("It's recursive"<<endl);
		split_cmd[1]=parse_cmd(in_d.substr(1,(in_d.length()-2)),vars);
		vars[split_cmd.at(0)]=split_cmd.at(1);
	} else if(in_d.substr(0,2)=="${") {
		DBG("Its variable recursive"<<endl);
		split_cmd[1]=vars[in_d.substr(2,in_d.length()-3)];
		DBG("Here is string :"<<in_d.substr(2,in_d.length()-3)<<endl);
		DBG("HEre is split cmd 0 "<<split_cmd.at(0)<<endl);
		DBG("HEre is split cmd 1 "<<split_cmd.at(1)<<endl);
		vars[split_cmd.at(0)]=split_cmd.at(1);
	} else {
		vars[split_cmd.at(0)]=split_cmd.at(1);
	}
	//while(inp.substr(i,1)!=" ") {
	//	var.append(inp.substr(i,1),i,1);
	//	i++;
	//}
	//cout<<var;
	//cout<<i;
	//#ifdef(1)
	//vars.insert(pair<string,string>(var,inp.substr(i+1,size(inp))));
	//vars[var]=inp.substr(i+1,size(inp));
	auto it = vars.begin();

  	// Iterate through the map and print the elements
  	while (it != vars.end())
  	{
  	  DBG("Key: " << it->first << ", Value: " << it->second << std::endl);
  	  ++it;
  	}
	//#endif
}

#endif // _PROC_SET_