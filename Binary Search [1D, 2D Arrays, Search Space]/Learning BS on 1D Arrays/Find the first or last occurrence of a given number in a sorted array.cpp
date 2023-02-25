Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]







class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;int j=nums.size()-1;int first_index,last_index;
        bool flag=false;vector<int>ro;int mid;
        while(i<=j){
            mid=i+(j-i)/2;
            if(nums[mid]==target){
                last_index = mid;
                i=mid+1;
                flag = true;
            }
            else if(nums[mid]>target) j=mid-1;
            else i=mid+1;
        }
        i=0;j=nums.size()-1;
        while(i<=j){
             mid=i+(j-i)/2;
            if(nums[mid]==target){
                first_index = mid;
                j=mid-1;
              //  flag = true;
            }
            else if(nums[mid]>target) j=mid-1;
            else i=mid+1;
        }
    if(flag) {ro.push_back(first_index);ro.push_back(last_index);}
        else ro={-1,-1};
        return ro;
    }
};
