#ifndef _PARSE_CMD_
#define _PARSE_CMD_

#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

#include "proc_set.h"
#include "proc_puts.h"

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

#endif //_PARSE_CMD_