#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int numRescueBoat(vector<int> &people, int limit){
    sort(people.begin(), people.end());
    int i = 0, j = people.size()-1;
    int no_of_boat = 0;
    while(i<=j){
        if(people[i]+people[j] <= limit){
            no_of_boat++;
            i++;j--;
        }
        else{
            no_of_boat++;
            j--;
        }
    }
    return no_of_boat;
}

int main(){
    vector<int> people = {3,5,3,4};
    int limit = 5  ;
    cout<<numRescueBoat(people, limit);

}