 75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

T.C =0(N)
S.C = 0(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
    //DUTCH NATIONAL FLAG  Algorithm
        //three pointer low,mid,high
        //intitution:copy te ache.. //starting to low -1 sob 0 hobe,low to 
//mid -1 sob 1 hobe ar mid to 
//high unsorted thakbe...jeta sort //korchi...high+1 theke n-1 sob 2 thakbe
   int n = nums.size();
   int low=0,mid=0,high=n-1;
   while(mid<=high){
       if(nums[mid]==0){
           swap(nums[low],nums[mid]);
           low++;mid++;

       }
       else if(nums[mid]==1){
           mid++;
       }
       else{
           swap(nums[mid],nums[high]);
           high--;
       }
   }

    


    }
};
