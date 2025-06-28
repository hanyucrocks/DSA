class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int swaps = 0;
        for(int i = 0; i < n; i+=2){
            int first = row[i];
            int expected = first ^ 1;
            if(row[i+1]!=expected){
                // search karenge
                for(int j = i + 2; j < n; j++){
                    if(row[j]==expected){
                        swap(row[j], row[i+1]);
                        swaps++;
                        break;
                    }
                }
            }
        }
        return swaps;
    }
};