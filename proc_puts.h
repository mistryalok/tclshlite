#ifndef _PROC_PUTS_
#define _PROC_PUTS_

#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;
string proc_puts(string inp, map<string,string>& vars) {
	DBG("Data is"<<vars[inp.substr(1,inp.length())]<<endl);
	//cout<<vars[inp.substr(1,inp.length())]<<endl;
	return vars[inp.substr(1,inp.length())];
}

#endif //_PROC_PUTS_