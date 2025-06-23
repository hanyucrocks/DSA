class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5}; // intitializes the primes array
        vector<int> indices = {0, 0, 0}; // intializes indoices for multiples
        vector<int> uglyArr(1, 1);

        for(int i = 1; i < n; i++){
            vector<int> next_uglies = {
                uglyArr[indices[0]] * primes[0],
                uglyArr[indices[1]] * primes[1],
                uglyArr[indices[2]] * primes[2]
            };
            int mini = *min_element(next_uglies.begin(), next_uglies.end());
            uglyArr.push_back(mini);
            
            for(int j = 0; j < 3; j++){
                if(next_uglies[j] == mini) ++indices[j];
            }
        }
        return uglyArr[n-1];
    }
};