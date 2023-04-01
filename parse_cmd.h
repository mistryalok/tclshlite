#ifndef _PARSE_CMD_
#define _PARSE_CMD_

#include "common_includes.h"


/*
 Commands are supposed to be only within below variations.
 set <var> <value>
 set <var> <var>
 set <var> [<cmd>]
 puts <var>
 puts <value>
 puts [<cmd>]
*/

string parse_cmd(const string& inp,map<string,string>& vars) {
	DBG(" Command parsing invoked with cmd :: "<< inp<<endl);
    /*
     Checkig if its "set "
    */
	  if (inp.substr(0,4)=="set ") {
	  	proc_set(inp.substr(4,inp.length()),vars);
		return "";	  	
	  }
      /*
       Checking if its "puts "
      */
	  if (inp.substr(0,5)=="puts ") {
	  		return proc_puts(inp.substr(5,inp.length()),vars);
	  }

	
    /*
        if user wants to parse a tcl file then no worries.
    */
	  if (inp.substr(0,7)=="source ") {
			cout<<"Invoking file read"<<endl;
			fstream src_file;
			src_file.open(inp.substr(7,inp.length()-7), ios::in); 
			if(src_file.is_open()) {
				string cmd;
				/*
				 For each line, parse commands..
				*/
				while(getline(src_file,cmd)) {
					cout<<parse_cmd(cmd,vars)<<endl;
				}
				src_file.close();
			}
			return "";
	   }
}

#endif //_PARSE_CMD_