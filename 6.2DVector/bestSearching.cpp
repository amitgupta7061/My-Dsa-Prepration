#include<iostream>
using namespace std;
int main(){
    int arr[][4] = {{1,4,7,11}
                   ,{2,5,8,12}
                   ,{3,6,9,16}
                   ,{10,13,14,17}};
    int target = 0;
    int i = 0,j = 3;
    while(i<4 && j>=0){
        if(arr[i][j]==target){
            cout<<"True";
            return 0;
        }
        else if(target>arr[i][j]) i++;
        else j--;
    }
    cout<<"False";
}