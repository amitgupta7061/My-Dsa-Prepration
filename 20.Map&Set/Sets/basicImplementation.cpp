#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(1);
    s.insert(5);
    s.erase(1);
    cout<<"size: "<<s.size()<<endl;
    for(int i:s) cout<<i<<" ";
    cout<<endl;
    int target = 40;
    if(s.find(target) != s.end()) // target exist 
        cout<<"exists"<<endl;
    else cout<<"Not exists";

}

// random order me element hota hai
