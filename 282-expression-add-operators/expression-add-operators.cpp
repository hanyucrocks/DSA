class Solution {
public:
// hanyuc love ya
    void backtrack(string& num, int index, long curr_val, long prev_operand,
                   string expr, int target, vector<string>& result) {
        if (index == num.size()) {
            if (curr_val == target) {
                result.push_back(expr);
            }
            return;
        }
        for (int i = index; i < num.size(); i++) {
            string str_num = num.substr(index, i - index + 1);
            long curr_num = stol(str_num);
            // leading zeroes wala case break
            if (str_num.size() > 1 && str_num[0] == '0')
                break;
            if (index == 0)
                backtrack(num, i + 1, curr_num, curr_num, str_num, target,
                          result);
            else {
                // add
                backtrack(num, i + 1, curr_val + curr_num, curr_num,
                          expr + "+" + str_num, target, result);
                // sub
                backtrack(num, i + 1, curr_val - curr_num, -curr_num,
                          expr + "-" + str_num, target, result);

                // mult
                backtrack(num, i + 1,
                          curr_val - prev_operand + (prev_operand * curr_num),
                          prev_operand * curr_num, expr + "*" + str_num, target,
                          result);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty())
            return result;
        backtrack(num, 0, 0, 0, "", target, result);
        return result;
    }
};