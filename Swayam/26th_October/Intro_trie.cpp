#include <bits/stdc++.h>
using namespace std;
// Trie is a prefix data structure which is used to efficiently look up if the word is present 
// in the string or not which is used to 
// this particular data structure is used as alternate of hashmap.
// as it contains prefixes of the string instead of whole string.
// thus the lookup is usually O(log n) instead of O(1) in hashmap.
// tbh idk why it even is used instead of hashmap lol 
// thats why i think this ds is actually stupid

// Trie node structure
class TrieNode {
public:
    //there can at max be 26 different letters to begin with
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    //Basic constructor
    Trie() {
        root = new TrieNode();
    }
    // Insert a word into the trie
    void insert(const string &word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for exact word
    bool search(const string &word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Check if any word starts with this prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }
};

// Example usage
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    // Searches
    cout << trie.search("apple") << endl;   // 1
    cout << trie.search("app") << endl;     // 1
    cout << trie.search("appl") << endl;    // 0
    cout << trie.startsWith("ap") << endl;  // 1
    cout << trie.startsWith("ba") << endl;  // 1
    cout << trie.startsWith("cat") << endl; // 0
    return 0;
}
