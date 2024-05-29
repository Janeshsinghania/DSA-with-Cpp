#include<bits/stdc++.h>
using namespace std;

int consecutive(vector<int> arr){
    unordered_set<int> st(arr.begin(),arr.end());
    int count = 0;
    for(auto x: st){
        if(st.find(x-1)==st.end()){
            int num = x;
            int currentcount = 1;
            while(st.find(num+1)!=st.end()){
                num += 1;
                currentcount += 1;
            }
            count = max(count,currentcount);
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    int result = consecutive(arr);
    cout<<result;
}
