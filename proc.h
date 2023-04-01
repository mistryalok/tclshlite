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


            /*
              Store function name on second word 
              
            */


            /*
             Traverse through each variable and store in map<string,string>
                proc_var
            */

            /*
             store the code in vector 
                proc_code
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