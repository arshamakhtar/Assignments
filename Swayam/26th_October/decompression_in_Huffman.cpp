#include <iostream>
#include <string>
using namespace std;

// Huffman Tree ka Node structure
struct Node {
    char ch;
    Node* left;
    Node* right;
    Node(char c = '\0', Node* l = nullptr, Node* r = nullptr) : ch(c), left(l), right(r) {}
};

// Decode Huffman encoded string
string huffmanDecode(Node* root, const string& encoded) {
    string result = "";
    Node* curr = root;  // Root se start karo

    // Har bit ko traverse karo
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        // Agar leaf node mil gaya (character hai), toh append karo
        if (!curr->left && !curr->right) {
            result += curr->ch;
            curr = root;  // Wapas root pe jao next character ke liye
        }
    }
    return result;
}

// Demo ke liye ek chota Huffman tree bana diya
Node* demoTree() {
    // maan lo 'a' - 00, 'b' - 01, 'c' - 1
    Node* root = new Node();
    root->left = new Node();
    root->left->left = new Node('a');
    root->left->right = new Node('b');
    root->right = new Node('c');
    return root;
}

int main() {
    // Maan lo encoded string "01100" hai, mapping se output "bac" hona chahiye
    string encoded = "01100";
    Node* root = demoTree();

    string decoded = huffmanDecode(root, encoded);
    cout << "Decoded string: " << decoded << endl; // Output: bac

    // memory cleanup (demo mein skip kiya)
    return 0;
}
