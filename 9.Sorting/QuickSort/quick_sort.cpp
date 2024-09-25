#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> & arr, int str_index, int end_index){
    int mid_index = (str_index + end_index)/2;
    int pivot_elmnt = arr[mid_index], cnt = 0;
    for(int i = str_index; i<= end_index; i++){
        if(i == mid_index) continue;
        if(arr[i] <= pivot_elmnt) cnt++;
    }
    int pivot_index = cnt + str_index;
    swap(arr[mid_index], arr[pivot_index]);
    int i = str_index, j = end_index;
    while (i < pivot_index and j > pivot_index){
        if(arr[i] <= pivot_elmnt) i++;
        if(arr[j] > pivot_elmnt) j--;
        else if(arr[i] > pivot_elmnt and arr[j] <= pivot_elmnt)
            swap(arr[i++], arr[j--]);
    }
    return pivot_index;
}

void Quick_sort(vector<int> & arr, int str_index, int end_index){
    if(str_index >= end_index) return;
    int pivot_index = partition(arr, str_index, end_index);
    Quick_sort(arr, str_index, pivot_index-1);
    Quick_sort(arr, pivot_index+1, end_index);
}

int main(){
    vector<int> arr{9,2,3,1,5,4,6,7,8};
    Quick_sort(arr, 0, arr.size()-1);
    for(auto ele : arr) cout<<ele<<" ";
}