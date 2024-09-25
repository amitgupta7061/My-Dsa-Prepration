#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    stack<int> st;
    st.push(arr[n-1]);
    int ans[n];
    ans[n-1] = -1;
    int i = n-2;
    while(i>=0){
        while(st.size()!=0 && st.top()<arr[i]) st.pop();
        if(st.size()==0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i--]);
    }
    for(int i:ans) cout<<i<<" ";
}