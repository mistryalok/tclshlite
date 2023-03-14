#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>

#ifdef DBGMODE
#define DBG(x) cout<<x<<endl;
#else
#define DBG(x) //x
#endif
using namespace std;

/* This guy removes spaces ' ' from string */
void removeDupWord(string str,vector<string>& vec)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            DBG(word << endl);
	    vec.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    cout << word << endl;
    vec.push_back(word);
}

void proc_set(string inp, map<string,string>& vars) {
	DBG("Called with inp ="<<inp<<endl);
	vector<string> split_cmd;
	string var="";
	int i=0;
	DBG("Printing wors");
	removeDupWord(inp,split_cmd);
	cout<<"Printing wors done"<<endl;
	vars[split_cmd.at(0)]=split_cmd.at(1);
	//while(inp.substr(i,1)!=" ") {
	//	var.append(inp.substr(i,1),i,1);
	//	i++;
	//}
	//cout<<var;
	//cout<<i;
	//#ifdef(1)
	//vars.insert(pair<string,string>(var,inp.substr(i+1,size(inp))));
	//vars[var]=inp.substr(i+1,size(inp));
	map<string,string>::iterator it = vars.begin();

  	// Iterate through the map and print the elements
  	while (it != vars.end())
  	{
  	  DBG("Key: " << it->first << ", Value: " << it->second << std::endl);
  	  ++it;
  	}
	//#endif
}

void proc_puts(string inp, map<string,string>& vars) {
	DBG("Data is"<<vars[inp.substr(1,inp.length())]<<endl);
	cout<<vars[inp.substr(1,inp.length())]<<endl;
}

int main() {
	  stack<string> cmds_stack;
	  map<string,string> vars;
	  string inp;
	cout<<"Welcome to tclshlite.."<<endl;
	while(1) {
	  cout<<"tclshlite>";

	  getline(cin,inp);
	  cout<<"You have entered :"<<inp<<endl;
	  if (inp.substr(0,4)=="set ") {
	  	proc_set(inp.substr(4,inp.length()),vars);
	  	
	  }
	  if (inp.substr(0,4)=="puts") {
	  		proc_puts(inp.substr(5,inp.length()),vars);
	  }
	}
	

}

