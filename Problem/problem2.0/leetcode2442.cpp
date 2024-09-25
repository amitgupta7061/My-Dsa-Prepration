#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int nums[10] = {1,13,10,12,31};
    int n = (sizeof(nums)/sizeof(nums[0]))/2,k = n;
    for(int i=0;i<n;i++){
        int temp = nums[i];
        int num = 0;
        while(temp>0){
            int rem = temp%10;
            num = (num*10)+rem;
            temp /= 10;
        }
        //cout<<num<<endl;
        nums[k++] = num;
    }
    unordered_set<int> s;
    for(int i:nums) s.insert(i);
    cout<<s.size();

}