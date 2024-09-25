#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &num1, vector<int> &num2, vector<int> &result){
    int n1 = num1.size(), n2 = num2.size();
    int i = 0, j = 0, k = 0;
    while (i < n1 and j < n2){
        if(num1[i] <= num2[j]) result[k++] = num1[i++];
        else result[k++] = num2[j++];
    }
    while (i < n1) result[k++] = num1[i++];
    while (j < n2) result[k++] = num2[j++];
}

void merge_sort(vector<int> &arr){
    int n = arr.size();
    if(n < 2) return;
    int n1 = n/2 , n2 = n - n/2;
    vector<int> num1(n1);
    vector<int> num2(n2);
    for(int i = 0; i < n1; i++) num1[i] = arr[i];
    for(int i = 0; i < n2; i++) num2[i] = arr[i+n1];
    merge_sort(num1);
    merge_sort(num2);
    merge(num1, num2, arr);
    num1.clear();
    num2.clear();
}

int main(){
    vector<int> arr{-9,-2,-3,-1,-5,-4,-6,-7,-8};
    merge_sort(arr);
    for(auto ele : arr) cout<<ele<<" ";
}