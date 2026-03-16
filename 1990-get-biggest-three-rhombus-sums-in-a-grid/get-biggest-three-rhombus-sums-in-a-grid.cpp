class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> sums;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                sums.insert(grid[i][j]);
                
                int maxk = min({i, j, m-1-i, n-1-j});
                
                for(int k=1;k<=maxk;k++){
                    
                    int sum = 0;
                    
                    int r = i-k, c = j;
                
                    for(int t=0;t<k;t++){
                        sum += grid[r+t][c+t];
                    }
                    
                    for(int t=0;t<k;t++){
                        sum += grid[i+t][j+k-t];
                    }
                    
                    for(int t=0;t<k;t++){
                        sum += grid[i+k-t][j-t];
                    }
                    
                    for(int t=0;t<k;t++){
                        sum += grid[i-t][j-k+t];
                    }
                    
                    sums.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        for(auto it = sums.rbegin(); it!=sums.rend() && ans.size()<3; it++){
            ans.push_back(*it);
        }
        
        return ans;
    }
};