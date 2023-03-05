Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int max_div=INT_MIN;int min_div=1;
        int mid,sm_div;
        for(int i=0;i<n;i++){
        max_div=max(nums[i],max_div);
        }
        while(min_div<=max_div){
            mid=min_div+(max_div-min_div)/2;
            int m=check(nums,mid,threshold);
            if(m<=threshold){
                sm_div=mid;
                max_div=mid-1;
            }
            else min_div=mid+1;
        }
        return sm_div;
    }
public:
    int check(vector<int>&nums,int mid,int threshold){
        int co=0;int m,y;
        for(int i=0;i<nums.size();i++){
            if(mid==0) {co=INT_MIN;break;}
             m = nums[i]/mid;
            if (nums[i]%mid==0){
                 y = m;
            }
            else y=m+1;
            co+=y;
            
        }
        if(co<=threshold) return co;
        else return INT_MAX;
    }
};
