#ifndef _HELP_H_
#define _HELP_H_

void help() {
    cout<<"Following commands are supported so far"<<endl;
    cout<<"set <var> <values>"<<endl;
    cout<<"set <var> $<var>"<<endl;
    cout<<"set <var> [cmd]"<<endl;
    cout<<"puts $<var>"<<endl;
    cout<<"puts <string>"<<endl;
}

#endif