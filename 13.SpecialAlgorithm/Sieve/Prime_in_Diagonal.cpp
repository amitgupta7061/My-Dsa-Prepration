#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i == 0) return false;
    return true;
}

int diagonal_prime(vector<vector<int>> &nums){
    int mx = -1, n = nums.size();
    for(int i = 0; i < n; i++){
        if(isPrime(nums[i][i])) mx = max(mx, nums[i][i]);
        if(isPrime(nums[i][n-i-1])) mx = max(mx, nums[i][n-i-1]);
    }
    return mx;
}

int main(){
    vector<vector<int>> nums = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};

    cout<<diagonal_prime(nums);
}