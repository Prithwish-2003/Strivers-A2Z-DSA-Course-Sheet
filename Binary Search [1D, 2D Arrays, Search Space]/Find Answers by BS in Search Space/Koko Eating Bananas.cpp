Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int value=INT_MAX;
        int mid;int y,co,value1;
        int max_speed=INT_MIN;int lo_speed=0;
        for(int i=0;i<piles.size();i++){
            max_speed=max(piles[i],max_speed);
        }
        int speed;
        while(lo_speed<=max_speed){
            mid=lo_speed+(max_speed-lo_speed)/2;
            if (check(piles,mid,h)==true){
                speed=mid;
                max_speed=mid-1;
            }
            else lo_speed=mid+1;
            }
        return speed;
    }
public:
     bool check(vector<int>&piles,int mid,int h){
         int time=0;
         for (int i=0;i<piles.size();i++){
             if(mid==0) {
                 return false;
                 break;}
             int x=piles[i]/mid;
             int y=piles[i]%mid;
             if(y==0) time += x;
             else time+=(x+1);
         }
         return time<=h;
     }
};
