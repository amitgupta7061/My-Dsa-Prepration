#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; // n- number of boxes, m-- l-r to fill box 
    cin>>n>>m;
    vector<int> f(n+1, 0);
    vector<int> l(n+1, 0), r(n+1, 0);
    for(int i = 0; i < m; i++){
        int L, R; // fill coin till left to right
        cin>>L>>R;
        l[L]++; r[R]++;
    }
    f[1] = l[1];
    for(int i = 2; i <= n; i++)
        f[i] = l[i] - r[i-1] + f[i-1];  
    vector<int> c(10000005, 0); 
    for(int i = 0; i <= n; i++)
        c[f[i]]++;
    for(int i = c.size() - 2; i >= 0; i--) // suffix sum
        c[i] = c[i] + c[i+1];
    int q;
    cin>>q; // q -> number of qu
    while(q--){
        int num;
        cin>>num;
        cout<<"ans: "<<c[num]<<"\n";
    }
}
