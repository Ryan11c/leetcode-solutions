#include <iostream>
#include <vector>
using namespace std;

/*
To find this solution, we first find the product of the left side of the array and multiply that with 
the product of the right side excluding the current index.
*/

class Solution {
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        //left product
        int product = 1;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(product);
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] *= product;
            product *= nums[i];
        }
        return res;
    }
};