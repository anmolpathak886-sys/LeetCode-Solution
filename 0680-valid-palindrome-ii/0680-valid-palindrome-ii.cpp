class Solution {
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
     unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int odd_counts = 0;
        for (auto& pair : freq) {
            if (pair.second % 2 != 0) {
                odd_counts++;
            }
        }
        if (odd_counts > 3) return false;
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;   
    }
};