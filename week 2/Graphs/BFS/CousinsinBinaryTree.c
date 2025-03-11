#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void findNodeInfo(struct TreeNode* root, int target, int depth, struct TreeNode* parent, int *foundDepth, struct TreeNode** foundParent) {
    if (root == NULL) return;

    if (root->left && root->left->val == target) {
        *foundDepth = depth + 1;
        *foundParent = root;
        return;
    }
    if (root->right && root->right->val == target) {
        *foundDepth = depth + 1;
        *foundParent = root;
        return;
    }

    findNodeInfo(root->left, target, depth + 1, root, foundDepth, foundParent);
    findNodeInfo(root->right, target, depth + 1, root, foundDepth, foundParent);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    if (root == NULL) return false;

    int depthX = -1, depthY = -1;
    struct TreeNode *parentX = NULL, *parentY = NULL;

    findNodeInfo(root, x, 0, NULL, &depthX, &parentX);
    findNodeInfo(root, y, 0, NULL, &depthY, &parentY);

    return (depthX == depthY) && (parentX != parentY);
}
