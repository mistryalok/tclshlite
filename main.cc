#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;

void removeDupWord(string str,vector<string>& vec)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            cout << word << endl;
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
	cout<<"Called with inp ="<<inp<<endl;
	vector<string> split_cmd;
	string var="";
	int i=0;
	cout<<"Printing wors"<<endl;
	removeDupWord(inp,split_cmd);
	cout<<"Printing wors done"<<endl;
	vars[split_cmd.at(1)]=split_cmd.at(0);
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
  	  std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  	  ++it;
  	}
	//#endif
}

int main() {

	cout<<"Welcome to tclshlite.."<<endl;
	while(1) {
	  cout<<"tclshlite>";
	  stack<string> cmds_stack;
	  map<string,string> vars;
	  string inp;
	  getline(cin,inp);
	  cout<<"You have entered"<<inp;
	  if (inp.substr(0,4)=="set ") {
	  	proc_set(inp.substr(4,size(inp)),vars);
	  	
	  }
	  if (inp.substr(0,5)=="puts") {
	  	//proc_puts(inp);
	  }
	}
	

}

