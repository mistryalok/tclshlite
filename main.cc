#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <fstream>

//#define DBGMODE
#ifdef DBGMODE
#define DBG(x) cout<<x<<endl;
#else
#define DBG(x) //x
#endif
using namespace std;
string parse_cmd(const string& inp,map<string,string>& vars);
void proc_set(string inp, map<string,string>& vars);
string proc_puts(string inp, map<string,string>& vars);
/* This guy removes spaces ' ' from string */
void removeDupWord(string str,vector<string>& vec,int sgmnt)
{
    // Start with empty string
    string word = "";
    int splt_idx=0;
    // traverse through all char in string
    for (auto x : str)
    {
	// if there is space, then
	// push this word into vector
        if ((x == ' ') && (splt_idx!=sgmnt))
        {
            DBG(word << endl);
	    vec.push_back(word);
	    // Once you push it into vectro
	    // make string empty again to fetch
	    // the next word.
            word = "";
	    splt_idx++;
        }
	// if there is no space,
	// then keep on concatinating
	// the word into the word.!
        else {
            word = word + x;
        }
    }
    DBG(word << endl);
    // push the last words into vector
    vec.push_back(word);
}
string parse_cmd(const string& inp,map<string,string>& vars) {
	DBG("Parse command called with args "<< inp<<endl);
	  if (inp.substr(0,4)=="set ") {
	  	proc_set(inp.substr(4,inp.length()),vars);
		return "";	  	
	  }
	  if (inp.substr(0,4)=="puts") {
	  		return proc_puts(inp.substr(5,inp.length()),vars);
	  }
	cout<<"To source file"<<endl;
	  //if (inp.substr(0,6)=="source ") {
			cout<<"Invoking file read"<<endl;
			fstream src_file;
			src_file.open(inp.substr(7,inp.length()-7), ios::in); 
			if(src_file.is_open()) {
				string cmd;
				while(getline(src_file,cmd)) {
					cout<<parse_cmd(cmd,vars)<<endl;
				}
				src_file.close();
			}
			return "Finished parsing!";
	  //}
}

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

string proc_puts(string inp, map<string,string>& vars) {
	DBG("Data is"<<vars[inp.substr(1,inp.length())]<<endl);
	//cout<<vars[inp.substr(1,inp.length())]<<endl;
	return vars[inp.substr(1,inp.length())];
}



int main() {
	  stack<string> cmds_stack;
	  map<string,string> vars;
	  string inp;
	  cout<<"########################################"<<endl;
	  cout<<"# Welcome to tclshlite..               #"<<endl;
	  cout<<"# 					#"<<endl;
	  cout<<"# Author: Alok Mistry          	#"<<endl;
	  cout<<"# Type ./tclshlite -help for more info.#"<<endl;
	  cout<<"########################################"<<endl;

	// so we keep on looping until user says no more please.
	while(1) {
	  	cout<<"%";
	  	getline(cin,inp);
	  	DBG("You have entered :"<<inp<<endl);
		// We call this nice routine who should 
		// handle all the job of cmds parsing.
	  	cout<<parse_cmd(inp,vars)<<endl;
	}	 
	

}

