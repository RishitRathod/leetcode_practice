class Solution {
public:
        int maximumSwap(int num) {
        vector<int> o;
        int originalNum = num;  // Store the original number
        
        // Extract digits and store in vector `o`
        while (num != 0) {
            int a = num % 10;
            o.push_back(a);  // o contains digits in reverse order
            num = num / 10;
        }
        
        // Reverse the vector so that the digits are in correct order (most significant first)
        reverse(o.begin(), o.end());

        int n = o.size();
        vector<int> maxIdx(n);  // To track the index of the largest digit to the right
        
        // Initialize the last element's index as the largest
        maxIdx[n - 1] = n - 1;

        // Track the largest digit from the right side
        for (int i = n - 2; i >= 0; --i) {
            if (o[i] > o[maxIdx[i + 1]]) {
                maxIdx[i] = i;
            } else {
                maxIdx[i] = maxIdx[i + 1];
            }
        }

        // Find the first place where we can swap
        for (int i = 0; i < n; ++i) {
            // If the current digit is less than the largest digit to its right
            if (o[i] < o[maxIdx[i]]) {
                // Swap them
                swap(o[i], o[maxIdx[i]]);
                break;  // Only one swap is allowed
            }
        }

        // Reconstruct the number after the swap
        long long number = 0;
        for (int digit : o) {
            number = number * 10 + digit;
        }
        return number;
    }
};