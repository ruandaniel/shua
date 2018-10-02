121. Best Time to Buy and Sell Stock


Sol:
Two pointers
O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, res = 0;
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r++;
            } else {
                res = max (res, prices[r++] - prices[l]);
            }
        }
        return res;
    }
};