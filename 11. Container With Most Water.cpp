11. Container With Most Water

Sol1:
Two pointer
O(n)


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, res = 0;
        while (l < r) {
            res = max (min(height[l], height[r]) * (r - l), res);
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};