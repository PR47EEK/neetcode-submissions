class Solution {
public:

    string encode(vector<string>& strs) {
        string s  = "";
        for(auto x : strs) {
            s += to_string(x.size()) + "#" + x;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        cout << s <<endl;
        for(int i = 0; i < s.size(); i++) {
            string temp = "";
            int k = i;
            while(s[k] != '#') {
                temp += s[k];
                k++;
            }
            int len = stoi(temp);
            temp = "";
            i = k;
            for(int j = i+1; j <= i + len; j++) {
                temp += s[j];
            }
            i = i + len;
            strs.push_back(temp);
        }
        return strs;
    }
};
