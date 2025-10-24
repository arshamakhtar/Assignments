#include <bits/stdc++.h>
using namespace std;

// Node ka structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

// Level order (with -1 as NULL) se tree banao
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front(); q.pop();
        // left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Top view function
vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    // hd = horizontal distance, map to store first node at each hd
    map<int, int> hdMap;
    queue<pair<Node*, int>> q; // pair<node, hd>
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int hd = p.second;

        // Agar horizontal distance pehle nahi aaya to map me daalo
        if (hdMap.find(hd) == hdMap.end()) {
            hdMap[hd] = node->data;
        }

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto x : hdMap) {
        ans.push_back(x.second);
    }
    return ans;
}

int main() {
    int n;
    cin >> n; // Kitne elements (level order, -1 for NULL)
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);
    vector<int> ans = topView(root);

    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
