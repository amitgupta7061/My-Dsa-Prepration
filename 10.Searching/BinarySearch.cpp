#include<iostream>
using namespace std;
bool Searching(int arr[],int n,int target){
    int low = 0,high = n-1;
    while(low<=high){
        int mid = (low + high) >> 1;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) low = mid+1;
        else high = mid-1;
    }
    return false;
}
int main(){
    int n = 9,target = 13;
    int arr[] = {4,5,6,9,11,13,17,21,56};
    if(Searching(arr,n,target)) cout<<"Found";
    else cout<<"Not Found";
}