3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", which the length is 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Sol1:
HashSet: mark if a char appeared already in current window
O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int l = 0, r = 0, res = 0;
        while (l < s.size() && r < s.size()) {
            if (us.find(s[r]) == us.end()) {
                us.insert(s[r]);
                res = max(res, r - l + 1);
                r++;
            } else {
                us.erase(s[l++]);
            }
        }
        return res;
    }
};

Sol2:
HashTable: mark last index of the char
O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0, res = 0;
        for (int j = 0; j < s.size(); j++) {
            if (m.find(s[j]) != m.end() && m[s[j]] >= i) {
                i = m[s[j]] + 1;
            }
            res = max(res, j - i + 1);
            m[s[j]] = j;
        }
        return res;
    }
};
