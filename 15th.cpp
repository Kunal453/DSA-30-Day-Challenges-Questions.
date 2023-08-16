// Check whether two string are isomorphic. Note: Two strings are isomorphic if one-to-one mapping is possible for every character of first string to every character of second string while preserving the orders of the characters?

#include<bits/stdc++.h>
using namespace std;


void checkIsomorphic(string s1, string s2){
    if(s1.size() != s2.size()){

        cout<<"-------------------"<<endl<<"False : Not a isomorphic pair"<<endl;
        return ;
    }
    char lasta=s1[0];
    char lastb =s2[0];
    for(int i=1; i<s1.size(); i++){
         if(s1[i] == lasta){
            if(s2[i] != lastb){
            cout<<"-------------------"<<endl<<"False : Not a isomorphic pair"<<endl;
                return;
            }
         }else{
            lasta = s1[i];
            if(s2[i] == lastb){
            cout<<"-------------------"<<endl<<"False : Not a isomorphic pair"<<endl;
                return;
            }else{
                lastb = s2[i];
            }
         }
    }

    cout<<"-------------------"<<endl<<"True  : It's a Isomorphic pair"<<endl;
}

int main(){
    checkIsomorphic("egg","add");
    checkIsomorphic("foo","bar");
    checkIsomorphic("paper","title");
    checkIsomorphic("hello","hilly");
    checkIsomorphic("abcd","efgh");
    checkIsomorphic("aab","xyz");
    checkIsomorphic("abab","cdcd");
    checkIsomorphic("abc","def");
    checkIsomorphic("xyzxyz","abcabc");
    checkIsomorphic("abc","abcd");
    checkIsomorphic("aab","xyz");
    checkIsomorphic("aaa","bbb");
}

