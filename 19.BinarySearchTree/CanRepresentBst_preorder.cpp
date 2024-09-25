#include<bits/stdc++.h>
using namespace std;


int canRepresentBST(vector<int> &preorder, int n) {
    stack<int> st;
    int root = INT_MIN;
    for(int i = 0; i < n; i++){
        while(st.size() > 0 and preorder[i] > st.top()){
            root = st.top();
            st.pop();
        }
        if(preorder[i] < root) return false;
        st.push(preorder[i]);
    }
    return true;
}

int main(){
    vector<int> preorder = {2, 4, 3};
    cout<<canRepresentBST(preorder,preorder.size());
}