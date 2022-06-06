// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// AVL tree node
typedef struct AVLwithparent {
    struct AVLwithparent* left;
    struct AVLwithparent* right;
    int key;
    struct AVLwithparent* par;
    int height;
} AVL;

void Updateheight(AVL* root){
    if (root != NULL) {
        int val = 1;
        if (root->left != NULL)
            val = root->left->height + 1;

        if (root->right != NULL)
            val = max(
                val, root->right->height + 1);
        root->height = val;
    }
}

AVL* _search(AVL* root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

AVL* LLR(AVL* root){
    AVL* tmpnode = root->left;
    root->left = tmpnode->right;
    if (tmpnode->right != NULL)
        tmpnode->right->par = root;
    tmpnode->right = root;
    tmpnode->par = root->par;
    root->par = tmpnode;
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
    root = tmpnode;
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
    return root;
}

AVL* RRR(AVL* root){
    AVL* tmpnode = root->right;
    root->right = tmpnode->left;
    if (tmpnode->left != NULL)
        tmpnode->left->par = root;
    tmpnode->left = root;
    tmpnode->par = root->par;
    root->par = tmpnode;
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL) tmpnode->par->right = tmpnode;
    }
    root = tmpnode;
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
    return root;
}

AVL* LRR(AVL* root){
    root->left = RRR(root->left);
    return LLR(root);
}

AVL* RLR(AVL* root){
    root->right = LLR(root->right);
    return RRR(root);
}

AVL* Insert(AVL* root, AVL* parent, int key){

    if (root == NULL) {
        root = new AVL;
        if (root == NULL) cout << "Error in memory" << endl;
        else {
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = key;
        }
    }

    else if (root->key > key) {
        root->left = Insert(root->left, root, key);
        int firstheight = 0;
        int secondheight = 0;

        if (root->left != NULL) firstheight = root->left->height;
        if (root->right != NULL) secondheight = root->right->height;
        if (abs(firstheight - secondheight) == 2) {
            if (root->left != NULL && key < root->left->key) root = LLR(root);
            else root = LRR(root);
        }
    }

    else if (root->key < key) {
        root->right = Insert(root->right, root, key);
        int firstheight = 0;
        int secondheight = 0;

        if (root->left != NULL) firstheight = root->left->height;
        if (root->right != NULL) secondheight = root->right->height;
        if (abs(firstheight - secondheight) == 2) {
            if (root->right != NULL
                && key < root->right->key) {
                root = RLR(root);
            }
            else root = RRR(root);  
        }
    }
    else {}
    Updateheight(root);
    return root;
}

void printpreorder(AVL* root){
    cout << "Node: " << root->key
        << ", Parent Node: ";

    if (root->par != NULL) cout << root->par->key << endl;
    else cout << "NULL" << endl;
    if (root->left != NULL) printpreorder(root->left);
    if (root->right != NULL) printpreorder(root->right);
}


vector<int> node; 

void preorder(AVL *root, int distance) {
    if (root && distance--) {
       // printf("%d (%d, %d)\n", root->key, dis, distance);
        if(!count(node.begin(), node.end(), root->key)) {
            node.push_back(root->key);
        }
        preorder(root->par, distance);
        preorder(root->left, distance);
        preorder(root->right, distance);
    }
}

AVL* avl_insert(AVL* root, int p){
    return Insert(root, NULL, p);
}

int main(){
    AVL *root, *cari; //ini sama kaya AVLNode. Tidak ada yang menjadi wadah seperti Struct AVL di Alpro ITS
    root = NULL;
    
    root = avl_insert(root, 12);
    cari = _search(root, 12);
    
    
	return 0;
}
