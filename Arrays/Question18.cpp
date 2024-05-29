#include<bits/stdc++.h>
using namespace std;

void inttoRoman(int n){
    vector<pair<int,string>> Roman= {{1000,"M"}, {900,"DM"}, {500,"D"}, {400,"CD"}, {100,"C"},
    {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    
    string result = "";
    for (int i = 0; i < Roman.size(); i++)
    {
        while (n>=Roman[i].first)
        {
            result += Roman[i].second;
            n -= Roman[i].first;
        }  
    }
    cout<<result;
        
   
}

int main()
{
    int n = 100;
    inttoRoman(n);
}