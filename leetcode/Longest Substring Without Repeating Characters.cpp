class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        int map[256];
        memset(map, -1, sizeof(map));
        
        int start = 0;
        int longest = 0;
        
        for(int i=0; i<n; i++)
        {
            if(start <= map[s[i]])
            {
                start = map[s[i]]+1;
            }
            map[s[i]] = i;
            longest = max(longest, i-start+1);
        }
        return longest;
    }
};


//Solution 2: less memory, more time
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool map[256];
        memset(map, false, sizeof(map));
        int start = 0;
        int n = s.size();
        int longest = 0;
        for(int i=0; i<n; i++)
        {
            while(map[s[i]])
            {
                map[s[start]] = false;
                start++;
            }
            map[s[i]] = true;
            longest = max(longest, i-start+1);
        }
        return longest;
    }
};
