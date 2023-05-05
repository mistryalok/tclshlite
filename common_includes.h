#ifndef _COMMON_INCLUDES_
#define _COMMON_INCLUDES_
#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <fstream>


using namespace std;
/* This is to store function/proc code 
i.e 
    puts $a
    set b "ads"
*/
typedef vector<string> PROC_CODE;
/*
 This is to store proc argument variables
 i.e 
    proc_abc { a b c } {
        Blah.. blah..
    }
    We will store this varialbes "a", "b" & "c" 
    in map, since they need to be uniq with a
    null/nothing value.

    Later, when someone calls this proc in tclsh,
    we will assign values he provided at runtime.
 */
typedef map<string,string> PROC_VARS;

/*
    This defines a codespace/procspace of each
    proc that user has source/written.

    here, on left side, we will store all the 
    variable and on the right side, we will
    store all the code corresponding to that
    proc.
    This we need to do since, each variable space
    is exclusive for corresponding proc code.
*/
typedef map<PROC_VARS,PROC_CODE > PROC_SPACE;
/*
    Eventually, we need to do one more map
    to tag/assign a string of proc for the
    proc space we just created above.!
*/
typedef map<string,PROC_SPACE> proc_type;
#include "util.h"
#include "proc_set.h"
#include "proc_puts.h"
#include "proc.h"
#include "parse_cmd.h"
#include "help.h"
#include "proc_execute.h"



#endif