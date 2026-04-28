class Solution {
public:
    int characterReplacement(string s, int k) {
         int start = 0;
         int n = s.size();
         vector<int> freq(26,0);
         int maxFreq = 0; // one char with maxfreq
         int substringMaxLen = 0;
         for(int end = 0; end < n; end++)
         {
            int ch = s[end] - 'A';
            freq[ch] += 1;
            maxFreq = max(maxFreq, freq[ch]);
            bool isValid = (end + 1 - start - maxFreq <= k); // windowSize - maxfreq <= k
            if(!isValid)
            {
                //we will remove first char of window
                int removedChar = s[start] - 'A';
                freq[removedChar] -= 1;
                start += 1;
            }
            substringMaxLen = end + 1 - start;
         }
         return substringMaxLen;
    }
};
