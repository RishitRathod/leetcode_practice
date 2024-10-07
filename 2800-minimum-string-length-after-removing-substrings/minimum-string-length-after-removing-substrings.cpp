class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int f=n;
        for(int i=0; i<n-1; ){
            if(s.substr(i,2)=="AB" || s.substr(i,2)=="CD"){
                s.erase(i,2);
                n=s.size();
                if(i>0){
                    i--;
                } 
            }
            else{
                i++;
            }
        }
        return s.size();
    }
};