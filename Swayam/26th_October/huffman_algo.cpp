#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Tree node for huffman
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Min-heap comparator
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Recursive function to generate codes
void getCodes(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCode[root->ch] = str; // If it's leaf node
    getCodes(root->left, str + "0", huffmanCode);
    getCodes(root->right, str + "1", huffmanCode);
}

void huffmanCoding(const string &text)
{
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : text)
        freq[c]++;

    // Build priority queue (min-heap) of tree nodes
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto &pr : freq)
        pq.push(new Node(pr.first, pr.second));

    // Build the Huffman tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }
    Node *root = pq.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;
    getCodes(root, "", huffmanCode);

    // Print Huffman codes
    cout << "Huffman Codes:\n";
    for (auto &pr : huffmanCode)
        cout << pr.first << " : " << pr.second << "\n";

    // Encode input string
    string encoded = "";
    for (char c : text)
        encoded += huffmanCode[c];
    cout << "Encoded string: " << encoded << "\n";
}

int main()
{
    string text = "huffman";
    huffmanCoding(text);
    return 0;
}
