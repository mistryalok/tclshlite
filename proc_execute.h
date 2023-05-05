#ifndef _PROC_EXECUTE_H
#define _PROC_EXECUTE_H
#include "common_includes.h"

bool proc_execute(string cmd,proc_type& proc_list) {
    /*
    look if cmd string has match with any of the stored
    proc in proc_list.. 
    */
    PROC_SPACE p_space;
    // p_space = map{p_vars, p_code }
    PROC_VARS p_vars;
    PROC_CODE p_code;
    // This contains list of proc user has added.
    // p_list_it->first points to name of proc
    // p_list_it->second points to body of proc i.e PROC_SPACE
	  proc_type::iterator p_list_it = proc_list.begin();
    // this is to traverse through each proc code
    // lines ( essentially to execute it.)
    PROC_CODE::iterator p_code_it = p_code.begin();
    PROC_SPACE::iterator p_space_it;
    PROC_VARS::iterator p_vars_it;



   
    
        /*
		 Check if it falls in one of the proc
		 user has added
		 */
    cout<<"Searching for proc"<<endl;
		while(p_list_it!=proc_list.end()) {
            cout<<"Finding this proc "<<cmd<<endl;
            cout<<"First is :"<<p_list_it->first<<endl;
            /* 
				Call proc and setup its
				own kind of stack/varialbe
				space
				*/
			if(cmd==p_list_it->first) {
          
				
				cout<<"Custom proc is called as : "<<p_list_it->first<<endl;
                p_space = p_list_it->second;
                p_space_it = p_space.begin();
                p_vars = p_space_it->first;
                p_code = p_space_it->second;
                p_vars_it = p_vars.begin();
                p_code_it = p_code.begin();
                while(p_vars_it!=p_vars.end()) {
                  cout<<"Printing variable "<<p_vars_it->first<<" has "<<p_vars_it->second<<endl;
                  ++p_vars_it;
                }//p_space=proc_list[cmd];
                while(p_code_it!=p_code.end()) {
                  cout<<"Printing code "<<*p_code_it<<endl;
                  p_code_it++;
                }
                //p_code_it = p_space;
                //parse_cmd()
                
                return true;
			}
            ++p_list_it;
		}
        return false;
   /*
    if there is match, then quickly go and execute 
    each of the cmds using parse_cmd and then go back 
    to normal execution.

   */
}
 
#endif