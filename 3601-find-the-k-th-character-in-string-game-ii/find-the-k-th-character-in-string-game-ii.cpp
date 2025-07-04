class Solution {
public:
    char helper(vector<int> &op, int opIndex, long long k, char base, vector<long long> &length){
        if(opIndex == 0) return base;
        long long half = length[opIndex - 1];
        if(op[opIndex - 1] == 0){
            // op 0 s ->> ss
            if(k <= half) return helper(op, opIndex - 1, k, base, length);
            else return helper(op, opIndex - 1, k - half, base, length);
        }
        else{
            if(k <= half) return helper(op, opIndex - 1, k, base, length);
            else{
                char ch = helper(op, opIndex-1, k-half,base,length);
                return (ch=='z')?'a':ch+1;
            }
        }
    }
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long>length(operations.size()+1);
        length[0]=1;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i]==0) length[i+1]=length[i]*2;
            else length[i+1]=length[i]*2;
            if(length[i+1]>k) length[i+1]=k+1;
        }
        return helper(operations, operations.size(), k, 'a', length);
    }
};