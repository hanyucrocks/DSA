class Solution {
public:
    int solve(int n, int head, int step, bool lefttoright){
        if(n == 1) return head;
        if(lefttoright == 1 or n % 2 != 0){
            head = head + step;
        }
        n = n / 2;
        step = step * 2;
        lefttoright = !lefttoright;
        return solve(n, head, step, lefttoright);
    }
    int lastRemaining(int n) {
        // arr
        // 1 to n tak
        // pehle odd places wale num hatao, phir even places wale num hatao
        int head = 1, step = 1;
        bool lefttoright = 1;
        return solve(n, head, step, lefttoright);
    }
};