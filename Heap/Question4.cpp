#include<bits/stdc++.h>
using namespace std;

class MedianFinder{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder(){}
    void add(int x){
        if(maxHeap.empty()||x<maxHeap.top()){
            maxHeap.push(x);
        }else{
            minHeap.push(x);
        }

        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian(){
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }else{
            return maxHeap.top();
        }
    }
};

int main()
{
    MedianFinder mf;
    mf.add(2);
    mf.add(3);
    cout<<"Median :"<<mf.findMedian()<<endl;
    mf.add(4);
    cout<<"Median :"<<mf.findMedian()<<endl;
    return 0;
}