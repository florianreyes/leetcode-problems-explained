
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    stack<pair<TreeNode *, int>> tr_s;
    tr_s.emplace(root, 1);
    int max_depth = 0;
    while (!tr_s.empty())
    {
        auto [node, height] = tr_s.top();
        tr_s.pop();
        if (node != nullptr)
        {
            max_depth = max(max_depth, height);

            if (node->left)
            {
                tr_s.emplace(node->left, height + 1);
            }
            if (node->right)
            {
                tr_s.emplace(node->right, height + 1);
            }
        }
    }
    return max_depth;
}

// The logic is the following, we use a stack to store the node and the height of the node.
// We start by pushing the root node and the height of the root node which is 1.
// We then pop the top element of the stack and check if the node is not null.
// If the node is not null, we update the max_depth with the maximum of the current max_depth and the height of the node.
// We then push the left and right children of the node with the height incremented by 1.
// We continue this process until the stack is empty.