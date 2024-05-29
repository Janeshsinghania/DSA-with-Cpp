#include<bits/stdc++.h>
using namespace std;
class RandomizedSet{
    vector<int> v;
    unordered_map<int,int> Map;
    public:
    bool insert(int val){
         if(Map.find(val)!=Map.end()){
            return false;
         }
         v.push_back(val);
         Map[val] = v.size() - 1;
         return true;
    }

    bool remove(int val){
        if(Map.find(val)== Map.end()){
            return false;
        }
        int lastElement = v.back();
        int valindex = Map[val];
        v[valindex] = lastElement;
        Map[lastElement] = valindex;

        v.pop_back();
        Map.erase(val);
        return true;
    }
    int getRand(){
        int randomIndex = rand() % v.size();
        return v[randomIndex];
    }
};

int main()
{
    RandomizedSet mySet;
    cout<<(mySet.insert(1)? true:false)<<endl;
    cout<<(mySet.remove(2)? true:false)<<endl;
    cout<<(mySet.insert(2)? true:false)<<endl;
    cout<<(mySet.getRand())<<endl;
    cout<<(mySet.remove(1)? true:false)<<endl;
    cout<<(mySet.insert(2)? true:false)<<endl;
    cout<<(mySet.getRand())<<endl;

}