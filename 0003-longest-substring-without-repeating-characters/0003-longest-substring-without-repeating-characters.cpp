class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left) {
                left = charMap[currentChar] + 1;
            }
            charMap[currentChar] = right;
            maxLength =max(maxLength, right - left + 1);
        }
        return maxLength;
    }
    
};