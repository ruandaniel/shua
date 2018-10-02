42. Trapping Rain Water

Sol1:
DP: calculate whats max height on the left and right of every index
O(n)

// how much water index i can save = min(maxLeft, maxRight) - height[i]
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        int n = height.size();
        vector<int> leftMax(n, height[0]), rightMax(n, height[n - 1]);
        int res = 0;
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
            rightMax[n - 1 - i] = max(rightMax[n - i], height[n - 1 - i]);
        }
        for (int i = 1; i < n - 1; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};