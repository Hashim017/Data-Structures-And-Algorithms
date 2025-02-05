#include <iostream> 
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int val)
    {
        left = nullptr;
        right = nullptr;
        this -> val = val;
        height = 0;
    }
};
int getHeight(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root -> height;
}
int getBalanceFactor(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return getHeight(root -> left) - getHeight(root -> right);
}
Node* leftRotate(Node* x)
{
    Node* y = x -> right;
    Node* T2 = y -> left;

    x -> right = T2;
    y -> left = x;

    x -> height = max(getHeight(x -> right), getHeight(x -> left));
    y -> height = max(getHeight(y -> right), getHeight(y -> left));

    return y;
}
Node* rightRotate(Node* y)
{
    Node* x = y -> left;
    Node* T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    x -> height = max(getHeight(x -> right), getHeight(x -> left));
    y -> height = max(getHeight(y -> right), getHeight(y -> left));
    return x;
}
Node* insert(Node* root, int key)
{
    if (root == nullptr)
    {
        Node* temp = new Node(key);
        return temp;
    }
    if (key > root -> val)
    {
        root -> right = insert(root -> right, key);
    }
    else if (key < root -> val)
    {
        root -> left = insert(root -> left, key);
    }
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && key < root -> left -> val)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && key > root -> right -> val)
    {
        return leftRotate(root);
    }
    // Left Right Case
    if (bf > 1 && key > root -> left -> val)
    {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && key < root -> right -> val)
    {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;
}
Node* getPre(Node* root)
{
    root = root -> left;
    if (root == nullptr)
    {
        return root;
    }
    while (root -> right != nullptr)
    {
        root = root -> right;
    }
    return root;
}
Node* deletion(Node* root, int key)
{
    // First Delete node using standard BST delete Function
    Node* pre;
    if (root == nullptr)
    {
        return root;
    }
    else if (root -> left == nullptr && root -> right == nullptr)
    {
        if (root -> val == key)
        {
            root = nullptr;
        }
        return root;
    }

    if (key < root -> val)
    {
        root -> left = deletion(root -> left, key);
    }
    else if (key > root -> val)
    {
        root -> right = deletion(root -> right, key);
    }
    else
    {
        pre = getPre(root);
        if (pre != nullptr)
        {
            root -> val = pre -> val;
            root -> left = deletion(root -> left, pre -> val);
        }
        else if (root -> right != nullptr)
        {
            return root -> right;
        }
        else if (root -> right == nullptr)
        {
            return nullptr;
        }
    }
        // step 2 Update height of the current tree
        root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && getBalanceFactor(root -> left) >= 0)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && getBalanceFactor(root -> right) <= 0)
    {
        return leftRotate(root);
    }
    // Left Right Case
    if (bf > 1 && getBalanceFactor(root -> left) < 0)
    {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && getBalanceFactor(root -> right) > 0)
    {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }

        return root;
    
}
void preOrder(Node* root)
{
    if (root != nullptr)
    {
        cout << root -> val << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}




int main()
{
    Node* root = new Node(9);
    Node* temp = root;
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 20);
    root = insert(root, 17);
    deletion(temp, 8);
    preOrder(root);

}



// problems 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void storeTree(TreeNode* root, vector<TreeNode*>& vec)
    {
        if (root != nullptr)
        {
            storeTree(root -> left, vec);
            vec.push_back(root);
            storeTree(root -> right, vec);
        }
    }
    TreeNode* buildTree(vector<TreeNode*>& vec, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
            int mid = (start + end) / 2;
            TreeNode* node = vec[mid];
            node -> left = buildTree(vec, start, mid - 1);
            node -> right = buildTree(vec, mid + 1, end);
            return node;

    }
    TreeNode* balanceBST(TreeNode* root)
    {
        vector<TreeNode*> vec;
        storeTree(root, vec);
        int n = vec.size();
        return buildTree(vec, 0, n - 1);
    }
};


// problem 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = getHeight(root -> left);
        int right = getHeight(root -> right);
        if (left > right)
        {
            return left + 1;
        }
        else 
        {
            return right + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if (root != nullptr)
        { 
            int bf = getHeight(root -> left) - getHeight(root -> right);
            if (bf > 1 || bf < -1)
            {
                return false;
            }  
            if (isBalanced(root -> left) == false || isBalanced(root -> right) == false)
            {
                return false;
            }
        }
        return true;
    }
};