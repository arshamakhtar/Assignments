#include <bits/stdc++.h>
using namespace std;

// Ye function bulls and cows ka hint return karta hai
string getHint(string s, string g) 
{
    vector<int> map(10);

    int n = s.size();
    int cntb = 0; // bulls count

    // Secret number ke digits ki frequency count karo
    for(int i = 0 ; i < n ; i++)
    {
        map[s[i] - '0']++;
    }

    // Bulls count karo (same digit same position)
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == g[i])
        {
            cntb++;
            map[s[i] - '0']--; // bulls ke liye frequency reduce karo
        }
    }

    int cnt2 = 0; // cows count
    // Cows count karo (same digit lekin alag position)
    for(int i = 0 ; i < n ; i++)
    {
        if(g[i] == s[i]) continue; // bulls already counted
        if(map[g[i] - '0'])
        {
            cnt2++;
            map[g[i] - '0']--;
        }
    }

    // Result string bana ke return karo "xAyB" format me
    string ans = to_string(cntb) + 'A' + to_string(cnt2) + 'B';
    return ans;
}

int main() {
    string secret, guess;
    cin >> secret >> guess; // input secret and guess strings
    cout << getHint(secret, guess); // output bulls and cows hint
    return 0;
}
