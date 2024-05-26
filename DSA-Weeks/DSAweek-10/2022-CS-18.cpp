#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void InsertInBST(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node<T>* current = root;
            while (true) {
                if (data < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    // Q # 2
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        return new TreeNode(val);
        if(val> root->val)
        root->right=insertIntoBST(root->right,val);
        else if(val < root->val)
        root->left=insertIntoBST(root->left, val);
        return root;
    }

    bool SearchInBST(T data) {
        Node<T>* current = root;

        while (current != nullptr) {
            if (data == current->data) {
                return true;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return false;
    }

    void RecursivePrinting(Node<T>* current) {
        if (current == nullptr) {
            return;
        }

        RecursivePrinting(current->left);
        cout << current->data << " ";
        RecursivePrinting(current->right);
    }

    void Start() {
        RecursivePrinting(root);
    }

    void End() {
        cout << endl;
    }

    bool areSameTrees(BinaryTreeNode* tree1, BinaryTreeNode* tree2) {
        if (tree1 == nullptr && tree2 == nullptr) {
            return true;
        }

        if (tree1 == nullptr || tree2 == nullptr) {
            return false;
        }

        if (tree1->data != tree2->data) {
            return false;
        }

        return areSameTrees(tree1->left, tree2->left) && areSameTrees(tree1->right, tree2->right);
    }

    int countEvenNodes(BinaryTreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->data % 2 == 0) {
            return 1 + countEvenNodes(root->left) + countEvenNodes(root->right);
        } else {
            return countEvenNodes(root->left) + countEvenNodes(root->right);
        } 
    }

    int height(BinaryTreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    bool validateBST(BinaryTreeNode* root, int minVal, int maxVal) {
        if (root == nullptr) {
            return true;
        }

        if (root->data < minVal || root->data > maxVal) {
            return false;
        }

        return validateBST(root->left, minVal, root->data - 1) && validateBST(root->right, root->data + 1, maxVal);
    }

    bool isBST(BinaryTreeNode* root) {
        Node *prev = nullptr;
        
        if (root != nullptr) {
            if(!isBST(root->left)){
                return false;
            }
            if(prev != nullptr && root->data <= prev->data){
                return false;
            }
            prev = root;
            return (isBST(root->right))
        }
        return true;
    }

    void inOrderTraversal(Node *root, std::vector<int> &sortedArray) {
        if (root == nullptr) {
            return;
        }

        inOrderTraversal(root->left, sortedArray);
        sortedArray.push_back(root->data);
        inOrderTraversal(root->right, sortedArray);
    }

    void sortArray(int arr[], int n) {
        Node *root = nullptr;
        std::vector<int> sortedArray;

        for (int i = 0; i < n; i++) {
            insertNode(root, arr[i]);
        }

        inOrderTraversal(root, sortedArray);

        for (int i = 0; i < n; i++) {
            arr[i] = sortedArray[i];
        }
    }

    int countSingleChildNodes(Node *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right != nullptr) {
            return 1;
        } else
    
        if (root->left != nullptr && root->right == nullptr) {
            return 1;
        } else {
            return countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
        }
    }

    int countLeaves(Node *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        } 
        else {
            return countLeaves(root->left) + countLeaves(root->right);
        }
    }

    void outputTree(Node* root, int level) {
        if (root == nullptr) {
            return;
        }

        outputTree(root->right, level + 1);
        cout << string(level * 2, ' ') << root->data << endl;
        outputTree(root->left, level + 1);
    }
};

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class RandomizedBinaryTree {
private:
    BinaryTreeNode *root;

    void insertHelper(BinaryTreeNode *&node, int data) {
        if (node == nullptr) {
            node = new BinaryTreeNode(data);
        } else {
            if (rand() % 2 == 0) {
                insertHelper(node->left, data);
            } else {
                insertHelper(node->right, data);
            }
        }
    }

    void preorderHelper(BinaryTreeNode *node) {
        if (node == nullptr) {
            return;
        }
        preorderHelper(node->left);
        cout << node->data << " ";
        preorderHelper(node->right);
    }

public:
    RandomizedBinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        insertHelper(root, data);
    }

    void preorder() {
        preorderHelper(root);
        cout << endl;
    }
};


// Q # 4 (a)

class Solution {
public:
    vector<int> v;
    
    void inorder(TreeNode* root){  // left, root, right
        if(root==nullptr){return;}
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return v;    
    }
};

// Q # 4 (b)

class Solution {
public:
   vector<int> ans;
   void postorder(TreeNode* root)  // left, right, root
   {
       if(root == nullptr) return;
       postorder(root->left);
       postorder(root->right);
       ans.push_back(root->val);
   }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

// Q # 4 (c)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { // root, left, right
        vector<int> preorder;
        if(root==NULL){
            return preorder;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->val);

            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};

// Q # 5

class Solution {
public:
    vector<vector<int>>ans;
    void solve(TreeNode *root){
        if(root==NULL) return;

        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            ans.push_back(temp);
        }
    
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root);
        return ans;
    }
};


int main(){
    BinarySearchTree<int> bst;

    bst.InsertInBST(4);
    bst.InsertInBST(5);
    bst.InsertInBST(6);
    bst.InsertInBST(1);
    bst.InsertInBST(2);
    bst.InsertInBST(3);
    bst.InsertInBST(7);
    bst.InsertInBST(8);
    bst.InsertInBST(9);


    if (bst.SearchInBST(10)) {
        std::cout << "10 found in the BST" << std::endl;
    } else {
        std::cout << "10 not found in the BST" << std::endl;
    }

    bst.Start();
    bst.End();

    RandomizedBinaryTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.preorder();

    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // outputTree(root, 0);

    return 0;
}