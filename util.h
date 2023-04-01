#ifndef _UTIL_H_
#define _UTIL_H_
#include "common_includes.h"

/* This guy removes spaces ' ' from string */
void removeDupWord(string str,vector<string>& vec,int sgmnt)
{
    // Start with empty string
    string word = "";
    int splt_idx=0;
    // traverse through all char in string
    for (auto x : str)
    {
	// if there is space, then
	// push this word into vector
        if ((x == ' ') && (splt_idx!=sgmnt))
        {
            DBG(word << endl);
	    vec.push_back(word);
	    // Once you push it into vectro
	    // make string empty again to fetch
	    // the next word.
            word = "";
	    splt_idx++;
        }
	// if there is no space,
	// then keep on concatinating
	// the word into the word.!
        else {
            word = word + x;
        }
    }
    DBG(word << endl);
    // push the last words into vector
    vec.push_back(word);
}

#endif //_UTIL_H_