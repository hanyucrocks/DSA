typedef long long ll;

struct Event {
    ll y;
    int type; // +1 add -1 remove
    int x1, x2;
};

struct SegTree{
    struct Node{
        int cnt = 0;
        ll covered = 0;

    };
    vector<Node> tree;
    vector<ll> xs;
    int n;
    SegTree(const vector<ll> &xs_){
        xs = xs_;
        n = xs.size() - 1;
        tree.resize(4 * n);
    }
    void pull(int node, int l, int r){
        if(tree[node].cnt > 0) tree[node].covered = xs[r] - xs[l];
        else if(l + 1 ==r) tree[node].covered = 0;
        else tree[node].covered = tree[node * 2].covered + tree[node * 2 + 1].covered;
    }
    void update(int node, int l, int r, int ql, int qr, int val){
        if(qr <= l or r <= ql) return;
        if(ql <= l and r <= qr){
            tree[node].cnt += val;
            pull(node, l, r);
            return;
        }
        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid, r, ql, qr, val);
        pull(node, l, r);
    }
    void update(int l, int r, int val){
        update(1, 0, n, l, r, val);
    }
    ll query(){
        return tree[1].covered;
    }
};



class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // now... lets gooo
        // precision again...
        // are of union of squares beelow y == above y

        // double low = INT_MAX;
        // double high = INT_MIN;
        // double tot = 0.00000;
        // for(auto &square : squares){
        //     double x = square[0];
        //     double y = square[1];
        //     double l = square[2];
        //     tot += l * l;
        //     low = min(low, y);
        //     high = max(high, y+l);
        // } ghanta kaam ni aayega
        vector<ll> xs;
        vector<Event> events;
        for(auto &s : squares){
            ll x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x+l);
        }
         sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](ll x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };
        // step 3
        for (auto &s : squares) {
            ll x = s[0], y = s[1], l = s[2];
            int x1 = getX(x);
            int x2 = getX(x + l);
            events.push_back({y, +1, x1, x2});
            events.push_back({y + l, -1, x1, x2});
        }
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a.y < b.y;
        });
        // step 4 first sweep
         SegTree st(xs);
        ll totalArea = 0;
        ll prevY = events[0].y;

        for (auto &e : events) {
            long long dy = e.y - prevY;
            totalArea += dy * st.query();
            st.update(e.x1, e.x2, e.type);
            prevY = e.y;
        }
        double half = totalArea / 2.0;
         // Step 5: Second sweep
        st = SegTree(xs);
        double currArea = 0;
        prevY = events[0].y;

        for (auto &e : events) {
            ll dy = e.y - prevY;
            double slabArea = dy * st.query();

            if (currArea + slabArea >= half) {
                double needed = half - currArea;
                return prevY + needed / st.query();
            }

            currArea += slabArea;
            st.update(e.x1, e.x2, e.type);
            prevY = e.y;
        }
        return prevY;
    }
};