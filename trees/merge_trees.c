/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #include <stdlib.h>
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    struct TreeNode *root3;
    if(root1!=NULL && root2!=NULL){
        root3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
        if(root3==NULL)
            exit(0);
        root3->val=root1->val+root2->val;
        root3->left=mergeTrees(root1->left, root2->left);
        root3->right=mergeTrees(root1->right, root2->right);
        return root3;
        }
    if(root1==NULL && root2!=NULL){
        root3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
        if(root3==NULL)
            exit(0);
        root3->val=root2->val;
        root3->left=mergeTrees(NULL, root2->left);
        root3->right=mergeTrees(NULL, root2->right);
        return root3;
        }
    if(root2==NULL && root1!=NULL){
        root3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
        if(root3==NULL)
            exit(0);
        root3->val=root1->val;
        root3->left=mergeTrees(root1->left, NULL);
        root3->right=mergeTrees(root1->right, NULL);
        return root3;
        }
    if(root1==NULL && root2==NULL){
        root3=NULL;
        return NULL;
        }
    root3->left=mergeTrees(root1->left, root2->left);
    root3->right=mergeTrees(root1->right, root2->right);
    return root3;

}