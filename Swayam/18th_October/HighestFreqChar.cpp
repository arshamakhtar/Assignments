char highestFreqChar(string s) {
    unordered_map<char,int> mp;
    for (char c : s) mp[c]++;
    char ans = ' ';
    int freq = 0;
    for (auto &p : mp) {
        if (p.second > freq) {
            freq = p.second;
            ans = p.first;
        }
    }
    return ans;
}
