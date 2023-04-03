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

            /*
              Extract func name <proc proc_name >
              Store function name on second word 
              
             proc_name = substr(x,y);
            */


            /*
             Traverse through each variable and store in map<string,string>
             Map null value, since we don't have any idea during initial phase of values


                for(each spaced variable) starting from "{" till "}"
                proc_var[variable] = "NULL"
            */

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

            /*
             assign this structure to proc_list.
            */
           proc_body[proc_vars]=proc_code;
           proc_list[inp.substr(0,4)]=proc_body;

/*
 For debug mostly
*/
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



}

#endif