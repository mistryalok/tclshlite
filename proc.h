#ifndef _PROC_H_
#define _PROC_H
#include "common_includes.h"
/*
  This function will help to parse a proc and store it in a local/
  space of proc variables.
*/

void proc(string inp,proc_type& proc_list) {
 /*
 So, an example of proc is as below,

  proc myfuncname {a b c d} {
     puts $a
     set c 454
  }

  now myfuncname will be stored under map as string.. 
  map<STRING,map<map<string,string>,vector<string> > > proc_list; ( See whatever is CAPITAL used)

  Variables will be stored again in map, since they need to be unique
  map<string,map<map<STRING,STRING>,vector<string> > > proc_list; 

  Actual code that executes will be again stored in vector
   map<string,map<map<string,string>,vector<STRING> > > proc_list; 

 proc-name> -> [ variable->value] [ code string] 
 */                                     
          
          map<map<string,string>,vector<string> > proc_body;
          map<string,string> proc_vars; 
          vector<string> proc_code;
          string proc_name;
          vector<string> split_str;
            /*
              Extract func name <proc proc_name >
              Store function name on second word 
              
             proc_name = substr(x,y);
            */
                removeDupWord(inp,split_str,0);
                cout<<"Func name is "<<split_str[0]<<endl;
                proc_name = split_str[0];

            /*
             Traverse through each variable and store in map<string,string>
             Map null value, since we don't have any idea during initial phase of values
                for(each spaced variable) starting from "{" till "}"
                proc_var[variable] = "NULL"
            */
                int var_idx=0;
                string var_p;
                for(auto i = split_str.begin();i!=split_str.end();++i) {
                        // if it's other than name ( from second args ), then only store it.
                        if(var_idx>0) {
                                var_p=remove_a_char(*i,'}');
                                var_p=remove_a_char(var_p,'{');
                                if(!var_p.empty()) {
                                //DBG(<<var_p<<endl);
                                //For now keep zero.
                                proc_vars[var_p]="0";
                                }
                        }
                        var_idx++;
                }

            /*
             store the code in vector until you see "}"
             basically once <proc abc {a b c} {> command
             starts, we keep on waiting for user to enter
             the new commands.. until he enters "}" which will
             showcase end of proc.

                
                while(new_string!="}") {
                proc_code.push_back(new_string)
                }
            */
            string next_cmd;
            // you are here when user enters something
            // like this.
            // proc blah_blah {blah1 blah2 blah3} {
            cout<<"%";
	    getline(cin,next_cmd);
            while(next_cmd!="}") {
                // Push next command in vector
                proc_code.push_back(next_cmd);
                // then wait again for next cmds if there are
                // any.
                cout<<"%";
	  	getline(cin,next_cmd);
            }
            cout<<"Exiting from proc"<<endl;
            /*
             assign this structure to proc_list.
            */
           proc_body[proc_vars]=proc_code;
           proc_list[proc_name]=proc_body;

/*
 For debug mostly
*/
//#define CODE_PRINT
#ifdef CODE_PRINT
          map<string,map<map<string,string>,vector<string> > >::iterator it = proc_list.begin();
          map<map<string,string>,vector<string> >::iterator it_body;// = proc_body.begin();
          map<string,string>::iterator it_vars;
          vector<string>::iterator it_code;
          map<map<string,string>,vector<string> > body;
          map<string,string> var;
          vector<string> code;
                while(it!=proc_list.end()) {
                        cout<<it->first<<endl;
                                body=it->second;
                                it_body=body.begin();
                                while(it_body!=body.end()) {
                                        var=it_body->first;
                                        code=it_body->second;
                                        it_vars=var.begin();
                                        while(it_vars!=var.end()) {
                                                cout<<"Variables"<<endl;
                                                cout<<it_vars->first<<endl;
                                                cout<<it_vars->second<<endl;
                                        ++it_vars;
                                        }
                                                cout<<"Printing code"<<endl;
                                                for (auto element : code) {
                                                        cout << element <<endl;
                                                }
                                        cout<<"Counting"<<endl;
                                ++it_body;
                                }
                        ++it;
                }

#endif //CODE_PRINT

}

#endif