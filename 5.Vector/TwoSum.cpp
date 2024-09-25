#include<iostream>
#include<vector>
using namespace std;
int main(){
    int target;
    cout<<"Enter target: ";
    cin>>target;
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
    int i=0,j = n-1;
    while(i<j){
        if(v[i]+v[j]==target){
            cout<<"("<<v[i]<<","<<v[j]<<")"<<endl;
            i++;j--;
        }
        else if((v[i]+v[j])>target) j--;
        else i++;
    }
}