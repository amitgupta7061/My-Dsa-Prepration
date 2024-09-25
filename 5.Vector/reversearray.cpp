#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int i = 0,j = n-1;
    while(i<j){
        swap(v[i++],v[j--]);
    }
    for(int p: v) cout<<p<<" ";
}