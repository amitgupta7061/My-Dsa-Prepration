#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int min_product(vector<int> &nums){
    int cn = 0, cz = 0, cp = 0, product_pos = 1, product_neg = 1, largest_neg = INT_MIN; // cn -> count of negative  cz -> count of zero
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 0){
            cn++;
            product_neg *= nums[i];
            largest_neg = max(largest_neg, nums[i]);
        }
        else if(nums[i] == 0) cz++;
        else{
            cp++;
            product_pos *= nums[i];
        }
    }
    if(cn == 0){
        if(cz > 0) return 0;
        else{
            auto it = min_element(nums.begin(), nums.end());
            return *it;
        }
    }
    else {
        if(cn%2 == 0){
            return (product_neg / largest_neg) * product_pos;
        }
        else{
            return product_neg * product_pos;
        }
    }
}

int main(){
    vector<int> nums = {-2, -3, 1, 4, -2};
    cout<<min_product(nums); 

}