#include <stdlib.h>

/**
 * Definition for a binary tree node is already provided.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* constructBST(int* preorder, int* index, int size, int upperBound) {
    if (*index >= size || preorder[*index] > upperBound) return NULL;
    

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*index];
    root->left = root->right = NULL;

    (*index)++;


    root->left = constructBST(preorder, index, size, root->val); 
    root->right = constructBST(preorder, index, size, upperBound);

    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int index = 0;
    return constructBST(preorder, &index, preorderSize, __INT_MAX__);
}
