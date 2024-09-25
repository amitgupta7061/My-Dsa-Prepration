#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>  st; int n = asteroids.size();
    for(int i = 0; i < n; i++){
        if(asteroids[i] > 0) st.push_back(asteroids[i]);
        else{
            while(st.size() > 0 and st.back() > 0 and st.back() < abs(asteroids[i])) st.pop_back();
            if(st.size() > 0 and st.back() == abs(asteroids[i])) st.pop_back();
            else if(st.empty() or st.back() < 0) st.push_back(asteroids[i]); 
        }
    }
    return st;
}

int main(){
    vector<int> asteroids = {5,10,-5};
    vector<int> result = asteroidCollision(asteroids);

    for(auto ele : result) cout<<ele<<" ";
}