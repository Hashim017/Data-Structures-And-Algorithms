#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void InsertInBST(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) 
        {
            root = newNode;
        } 
        else 
        {
            Node* current = root;
            while (true) 
            {
                if (data < current->data) 
                {
                    if (current->left == nullptr) 
                    {
                        current->left = newNode;
                        break;
                    } 
                    else 
                    {
                        current = current->left;
                    }
                } 
                else 
                {
                    if (current->right == nullptr) 
                    {
                        current->right = newNode;
                        break;
                    } 
                    else 
                    {
                        current = current->right;
                    }
                }
            }
        }
    }

    void RecursivePrinting(Node* current) {
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

    int counteven(){
        return countEvenNodes(root);
    }

    int countEvenNodes(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->data % 2 == 0) {
            return 1 + countEvenNodes(root->left) + countEvenNodes(root->right);
        } else {
            return countEvenNodes(root->left) + countEvenNodes(root->right);
        } 
    }

    int countleaves(){
        countLeaves(root);
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

    void inOrder(){
        inorder(root);
    }

    void inorder(Node* root){  // left, root, right
        if(root==nullptr){return;}
        inorder(root->left);
        cout << (root->data) << " ";
        inorder(root->right);
    }

    void preOrder(){
        preorder(root);
    }

    void preorder(Node* root){  // root, left, right
        if(root==nullptr){return;}
        cout << (root->data) << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postOrder(){
        postorder(root);
    }

    void postorder(Node* root){  // left, right, root
        if(root==nullptr){return;}
        postorder(root->left);
        postorder(root->right);
        cout << (root->data) << " ";
    }
};



int main(){
    cout<<"awais chandio" << endl;
    BinarySearchTree bst;
    bst.InsertInBST(3);
    bst.InsertInBST(1);
    bst.InsertInBST(6);
    bst.InsertInBST(7);
    bst.InsertInBST(10);
    bst.InsertInBST(14);
    bst.inOrder();
    cout <<endl;
    bst.preOrder();
    cout <<endl;
    bst.postOrder();
    cout <<endl;
    // bst.Start();
    // cout<< endl << bst.counteven();
    // cout<< endl << bst.countleaves();

    return 0;
}