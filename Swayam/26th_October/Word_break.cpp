#include <bits/stdc++.h>
using namespace std;

// Node definition for Trie
struct Node{
    Node*links[26];   // For each character 'a'-'z', link to the next node
    bool flag=0;      // True if a word ends at this node

    // Returns true if there is a link for character ch
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    // Creates a link for character ch to given node temp
    void put(char ch,Node*temp){
        links[ch-'a']=temp;
    }

    // Returns node linked via character ch
    Node*get(char ch){
        return links[ch-'a'];
    }

    // Checks if this node marks the end of a word
    bool isend(){
        return flag;
    }

    // Marks this node as the end of a word
    void setend(){
        flag=1;
    }
};

class Trie{
    unordered_map<string, bool> memo; // Cache for memoization (for DP)

    public: 
    Node*root;

    Trie(){
        root=new Node(); // Initialize the root node
    }

    // Inserts word into Trie
    void insert(string word){
        Node*temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])) // Create link for missing character
                temp->put(word[i],new Node());
            temp=temp->get(word[i]); // Move to the next node
        }
        temp->setend(); // Last node is end of a word
    }

    // Checks if exact word is present in Trie
    bool findword(string word){
        Node*temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])) // Missing path means word not found
                return false;
            temp=temp->get(word[i]);
        }
        return temp->isend(); // Return true only if word ends at last node
    }

    // Recursively check if word can be split into dictionary words (Word Break logic)
    bool solve(string word){
        if(word.size()==0) return true; // Empty string => success
        if(memo.find(word) != memo.end()) return memo[word]; // Return cached result

        // Try all prefixes
        for(int i=1;i<=word.size();i++){
            if(findword(word.substr(0,i))){               // Prefix is a dictionary word
                bool ans =solve(word.substr(i));          // Recurse for the rest
                if(ans==true)return true;                 // If remaining can be split, done
            }
        }
        memo[word] = false;   // No valid split found—store in memo and return
        return false;
    }
};

class Solution {
public:
    // Loads dictionary into Trie and initiates Word Break check
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(int i=0;i<wordDict.size();i++){
            t.insert(wordDict[i]);
        }
        return t.solve(s);
    }
};


int main() {
    // Sample input from the Word Break problem on leetcode
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    Solution sol;
    // Execute wordBreak and print result
    bool canBreak = sol.wordBreak(s, wordDict);

    cout << (canBreak ? "Yes, can be segmented." : "No, cannot be segmented.") << endl;

    // Another test
    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << (sol.wordBreak(s2, dict2) ? "Yes" : "No") << endl; // Output: Yes

    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << (sol.wordBreak(s3, dict3) ? "Yes" : "No") << endl; // Output: No

    return 0;
}
