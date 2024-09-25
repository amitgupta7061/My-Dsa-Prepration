#include<iostream>
#include<vector>
using namespace std;


// salary[0] -> captain   salary[1] -> assistant
// x -> assistant - captain

vector<vector<int>> dp;

int f(vector<vector<int>> &salary, int i, int x){
    if(i >= salary.size()) return 0;

    if(x == 0)
        return salary[i][1] + f(salary, i+1, x+1);
    else if(x == salary.size()-i)
        return salary[i][0] + f(salary, i+1, x-1);
    else
        return min(salary[i][0]+f(salary, i+1, x-1), salary[i][1]+f(salary, i+1, x+1));      
}

int min_cost_to_makeCrew(vector<vector<int>> &salary){
    dp.resize(salary.size()+1,vector<int>(3,-1));
    return salary[0][1] + f(salary, 1, 1);
}

int main(){
    vector<vector<int>> salary = {{10000,7000},{9000,3000},{6000,4000},{5000,1000},{9000,3000},{8000,6000}};

    cout<<min_cost_to_makeCrew(salary);
}
