#include<iostream>
using namespace std;
int main(){
    int arr[] = {5,6,8,9,5,3};
    int *ptr = arr;
    ptr[0] = 8;
    cout<<ptr[1]<<endl;
    cout<<ptr[0]<<endl;
    
}