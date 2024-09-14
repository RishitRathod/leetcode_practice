class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =nums.size(),k=nums[0],i=1,a=1,j=1;
        while(i<n){
          if(nums[i] > k){
           k=nums[i];
           a=1;
           j=1;
          }else if(nums[i]==k){
             a++;
            if(a>j){
                j=a;
            }
          }
          else{
            a=0;
          }
            i++;
        }
        return j;
    }
};