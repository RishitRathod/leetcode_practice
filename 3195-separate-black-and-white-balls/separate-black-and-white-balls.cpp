class Solution {
public:
    long long minimumSteps(string s) {
        long s1=0;
        int b=0;
        for(int i=0;  i< s.length(); i++){
            if(s[i]=='0'){
                s1 = s1 + b;
            }
            else{
                b = b+1;
            }
        }
return s1;
        
    }
};