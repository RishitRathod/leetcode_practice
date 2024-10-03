class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int remainder = sum % p;
        if (remainder == 0) {
            return 0;
        }

        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1; 

        int currentMod = 0;
        int minLength = n;

        for (int i = 0; i < n; i++) {
            currentMod = (currentMod + nums[i]) % p;

            int neededMod = (currentMod - remainder + p) % p;

            if (prefixMod.find(neededMod) != prefixMod.end()) {
                minLength = min(minLength, i - prefixMod[neededMod]);
            }
            prefixMod[currentMod] = i;
        }
        return minLength == n ? -1 : minLength;
    }
};
