#include<bits/stdc++.h>
using namespace std;


void wordsInStringDestruction(string s){
    vector<string> v;
    for(int i=0; i<s.size(); i++){
        string temp = "";
        for(int j=i; j<s.size(); j++){
            if(s[j] == ' '){
                break;
            }else{
                temp += s[j];
                i++;
            }
        }

        v.push_back(temp);
    }

    for(auto &u: v){cout<<u<<"-";}
    int i = 0;
    int j = i+1;
    while (i < v.size()){
        j = i+1;
        while(j < v.size()){
            if(v[i] == v[j]){
                v.erase(v.begin()+i);
                j--;
                v.erase(v.begin()+j);
                i--;
            }else{
                j++;
            }
        }
        i++;
    }

    cout<<endl<<"---------------"<<endl<<" : "<<v.size()<<endl;

}


int main(){
    wordsInStringDestruction("abc abc");
    wordsInStringDestruction("ab aa aa bcd ab");
    wordsInStringDestruction("abc def def abc def");
}
