#include<bits/stdc++.h>
using namespace std;

string getspace(int n){
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s+= " ";
    }
    return s;
}

string getline(vector<string> words, int start, int end, int counter, int maxWidth){
    string res = words[start];
    int spaces = maxWidth - counter ;                  //counter == lettercount
    if(start==end){
        res+= getspace(spaces);
        return res;
    }
    int noofSpace = spaces/(end-start);
    int extraSpace = spaces%(end-start);
    string space0 = getspace(noofSpace);
    string space1 = space0 + " ";
    for (int i = 0; i < end-start; i++)
    {
        res = res + (i < extraSpace? space1:space0) + words[start + 1 +i];
    }
    return res;
}

void fullJustify(vector<string> words, int maxWidth){
    int n = words.size();
    int i=0,j=0;
    int counter = 0;
    vector<string> res;
    while (i<n && j<n)
    {
        int len = words[j].length();
        counter += len;
        if(counter + j-i > maxWidth){
            counter -= len;
            res.push_back(getline(words,i,j-1,counter,maxWidth));
            i=j;
            counter = 0;
        }
        else{
            j++;
        }
    }
    if(counter){
        string last = words[i];
        for (int x =i+1; x < j; x++)
        {
            last = last + " " + words[x];
        }
        last = last + getspace(maxWidth - last.size());
        res.push_back(last);
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
    
}

int main()
{
    vector<string> words ={"This","is","an","example","of","text","justification"};
    fullJustify(words,16);

    return 0; 
}