#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lcaHelper(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lcaHelper(root->left, p, q);
    TreeNode *right = lcaHelper(root->right, p, q);

    if (left == nullptr)
    {
        return right;
    }
    else if (right == nullptr)
    {
        return left;
    }
    else
    {
        return root;
    }
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    TreeNode *res = lcaHelper(root, p, q);
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;

    TreeNode *result = lowestCommonAncestor(root, p, q);
    std::cout << result->val << std::endl;
    return 0;
}

// The idea is to go through the tree in a preorder fashion
// If the current node is null or the current node is either p or q, return the current node
// Then recursively call the left and right children of the current node and assign them to a variable l and r respectively.
// If l is null, htat means that both p and q are in the right subtree, so return r
// If r is null, that means that both p and q are in the left subtree, so return l
// If both l and r are not null, that means that p and q are in different subtrees, so return the current node root