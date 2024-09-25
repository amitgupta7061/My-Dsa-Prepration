#include<iostream>
using namespace std;
int main(){
    string str[] = {"0123","0023","456","00182","940","2901"};
    int max = -1;
    for(int i=0;i<6;i++){
        int temp = stoi(str[i]);
        if(max<temp) max = temp;
    }
    cout<<max<<endl;
}