class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int z=timePoints.size();
        vector<int> aa(z);
        bitset<1440> cc=0;
        for(int i=0; i<z; i++){
            int a = ((timePoints[i][0]-'0')*10+timePoints[i][1]-'0')*60+(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
            aa[i] = a;
                if(cc[a]==1){
                    return 0;
                }
            cc[a] = 1;
        }
int fg=1440;
           for (int i = 0; i < z - 1; i++) {
            for (int j = i + 1; j < z; j++) {
                int as = abs(aa[i] - aa[j]);
                if(as>1440 - as){
                    as=1440-as;
                }  
                if (as < fg) {
                    fg = as;
                }
            }
        }
        return fg;
    }
};