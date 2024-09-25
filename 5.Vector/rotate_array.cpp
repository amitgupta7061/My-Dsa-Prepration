#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& v,int x,int y){
    while(x<y){
        swap(v[x++],v[y--]);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    k = k%n;
    reverse(v,0,n-1);
    reverse(v,0,k-1);
    reverse(v,k,n-1);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}