#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> num1, vector<int> num2){
    int n = num1.size();
    int m = num2.size();
    if(n>m){
        return findMedian(num2,num1);
    }
    int left = 0;
    int right = n; 
    while(left<=right){
        int mid1 = (left+right)/2;
        int mid2 = (n+m+1)/2 - mid1;
        int l1 = (mid1==0)? INT_MIN : num1[mid1-1];
        int l2 = (mid2==0)? INT_MIN : num2[mid2-1];
        int r1 = (mid1==n)? INT_MAX : num1[mid1];
        int r2 = (mid2==m)? INT_MAX : num2[mid2];
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0){
                return (max(l1,l2) + min(r1,r2))/2.0;
            }else{
                return max(l1,l2);
            }
        }
        else if(l1>r2){
            right = mid1-1;
        }else{
            left = mid1+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> num1 = {1,2};
    vector<int> num2 = {3,4,5};
    double result = findMedian(num1,num2);
    cout<<"Median of the two sorted arrays: "<<result;
    return 0;
}