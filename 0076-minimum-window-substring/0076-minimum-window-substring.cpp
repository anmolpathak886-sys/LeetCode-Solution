class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128,0);
        for(char c: t)count[c]++;
        int left=0,min_len=INT_MAX,start=-1,req=t.length();
        for(int right=0;right<s.length();right++){
            if(count[s[right]]>0) req--;
            count[s[right]]--;
            while(req==0){
                if(right-left+1<min_len){
                    min_len=right-left+1;
                    start=left;
                }
                count[s[left]]++;
                if(count[s[left]]>0)req++;
                left++;
            }
        }
        return start==-1?"":s.substr(start,min_len);
    }
};