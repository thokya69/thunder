//binary search tree
#include <iostream>
using namespace std;

// Define a node for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        // Handle duplicate entry (optional)
        cout << "Duplicate entry: " << value << "\n";
    }

    return root;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to perform an in-order traversal and display the tree
void displayTree(Node* root) {
    if (root != nullptr) {
        displayTree(root->left);
        cout << root->data << " ";
        displayTree(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // a) Insert
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // b) Delete
    int valueToDelete = 30;
    cout << "Deleting node with value " << valueToDelete << "\n";
    root = deleteNode(root, valueToDelete);

    // c) Search
    int searchValue = 40;
    cout << "Searching for value " << searchValue << ": " << (search(root, searchValue) ? "Found" : "Not found") << "\n";

    // d) Display tree (in-order traversal)
    cout << "In-order traversal of the BST: ";
    displayTree(root);
    cout << "\n";

    return 0;
}