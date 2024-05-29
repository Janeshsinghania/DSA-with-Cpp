#include<bits/stdc++.h>
using namespace std;

int maxCapital(vector<int> capital, vector<int> profit, int k, int w){
    vector<pair<int,int>> projects;
    for (int i = 0; i < capital.size(); i++)
    {
        projects.push_back({capital[i],profit[i]});
    }
    int i = 0;
    priority_queue<int> pq;  //maxHeap

    while (k>0)
    {
        while (i<projects.size() && projects[i].first<=w)
        {
            pq.push(projects[i].second);
            i++;
        }
        if(!pq.empty()){
            w+=pq.top();
            pq.pop();
            k--;
        }else{
            break;
        }
    }
    return w;
}

int main()
{
    vector<int> capital = {0,1,2};
    vector<int> profit = {1,2,3};
    int k = 3;
    int w = 0;

    int maxProfit = maxCapital(capital,profit,k,w);
    cout<<"Max profit is: "<<maxProfit;
    return 0;
}