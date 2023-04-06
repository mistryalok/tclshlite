#ifndef _UTIL_H_
#define _UTIL_H_
#include "common_includes.h"

/* 
 This guy removes spaces ' ' from string 
 and stores the spaced string into a vector
 */
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
    // provided number of splits are sgmnt.
        if(sgmnt!=0) {
            //cout<<"Entering"<<endl;
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
            else {
                word = word + x;
            }
            // if user says, sgmnt is 0, means
            // he wants to split until he gets full
            // string parsed.
        } else if (x == ' ') {
            vec.push_back(word);
            word ="";
        } else {
            word = word + x;
        }
	// if there is no space,
	// then keep on concatinating
	// the word into the word.!
       
    }
    DBG("Word we formed is"<<word << endl);
    // push the last words into vector
    vec.push_back(word);
}


string remove_a_char(string str,char str_to_rm)
{
    // Start with empty string
    string word = "";
    // traverse through all char in string
    for (auto x : str)
    {
        if (x == str_to_rm)
            {
                //do nothing
            } 
        else {
            word = word + x;
            }
    } 
    return word;
}

#endif //_UTIL_H_