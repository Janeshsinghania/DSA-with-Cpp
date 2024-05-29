#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s){
    vector<string> words;
    int n = s.size();
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if(s[i]==' '){
            words.push_back(temp);
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    words.push_back(temp);
    if(pattern.size()!=words.size()){
        return false;
    }
    unordered_map<char,string> m;
    set<string> st;
    for (int i = 0; i < pattern.size(); i++)
    {
        if(m.find(pattern[i])!=m.end()){
            if(m[pattern[i]]!=words[i]){
                return false;
            }
        }
        else{
                if(st.count(words[i])>0){
                    return false;
                }
                m[pattern[i]] = words[i];
                st.insert(words[i]);
        }
    }
    return true;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    bool result = wordPattern(pattern,s);
    if(result){
        cout<<"Valid word pattern";
    }
    else{
        cout<<"Invalid word pattern";
    }
    return 0;
}