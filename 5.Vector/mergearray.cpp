#include<iostream>
using namespace std;
void merge(int nums1[],int m,int nums2[],int n){
    int i = m-1,j = n-1,k = m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[k--] = nums1[i];
            i--;
        }
        else{
            nums1[k--] = nums2[j];
            j--;
        }
    }
    while(i>=0) nums1[k--] = nums1[i--];
    while(j>=0) nums1[k--] = nums2[j--];
}
int main(){
    int arr1[] = {1,2,3,0,0,0};
    int arr2[] = {2,5,6};
    merge(arr1,3,arr2,3);
    for(int i:arr1) cout<<i<<" ";
}