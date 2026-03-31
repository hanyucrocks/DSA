class Solution {
    bool isSame(string &word, string &str2, int i , int m){
        for(int j = 0; j < m; j++){
            if(word[i] != str2[j]) return false;
            i++;
        }
        return true;
    }
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        // jaha T hai waha pe str2 fill karo
        int N = n + m - 1;
        string word(N, '%');
        // T fill them with str2
        vector<bool> change(N, false);
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                int i_ = i;
                // fill with str2
                for(int j = 0; j < m; j++){
                    if(word[i_] != '%' and word[i_] != str2[j]) return "";
                    word[i_] = str2[j];
                    i_++;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(word[i] == '%'){
                word[i] = 'a';
                change[i] = 1;
            }
        }
        // process the F
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(isSame(word, str2, i, m)){
                    // agar same nikal gaya toh break karo
                    bool changed = false;
                    for(int k = i + m - 1; k >= i; k--){
                        if(change[k] == 1){
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if(changed == false) return ""; // change nahi kar paya
                }
            }
        }
        return word;
    }
};