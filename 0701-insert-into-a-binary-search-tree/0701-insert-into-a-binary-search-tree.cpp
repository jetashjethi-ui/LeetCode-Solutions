class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){return new TreeNode(val);}
        TreeNode*t=root;
        while(true){
            if(val<t->val&&t->left!=nullptr){t=t->left;}
            else if(val>t->val&&t->right!=nullptr){t=t->right;}
            else if(val<t->val&&t->left==nullptr){
                TreeNode*temp=new TreeNode(val);
                t->left=temp;
                break;
            }
            else if(val>t->val&&t->right==nullptr){
                TreeNode*temp=new TreeNode(val);
                t->right=temp;
                break;
            }
        }
        return root;
    }
};