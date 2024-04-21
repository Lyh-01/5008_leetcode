/*
 *Yihan Lu
 *https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
 */
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

void countGood(struct TreeNode* root, int* res, int max) {
	if(!root) return;
	if(root->val >= max) {
		max = root->val;
		(*res)++;
	}
	countGood(root->left, res, max);
	countGood(root->right, res, max);
}

int goodNodes(struct TreeNode* root){
	int res = 1;
	countGood(root->left, &res, root->val);
	countGood(root->right, &res, root->val);
	return res;
}

