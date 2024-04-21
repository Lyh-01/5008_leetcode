/*
 *Yihan Lu
 *https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 */
#include <stddef.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};


int dfs(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return dfs(root->left) + root->val + dfs(root->right);
}

int product_f(struct TreeNode* root, unsigned long long* max, int sum) {
	if(max == NULL || root == NULL) {
		return 0;
	}
	int local_sum = root->val;
	local_sum += product_f(root->left, max, sum);
	local_sum += product_f(root->right, max, sum);

	int another_sum = sum - local_sum;
	unsigned long long product = (unsigned long long) local_sum * (unsigned long long) another_sum;
	if (product > *max) {
		*max = product;
	}
	return local_sum;
}

int maxProduct(struct TreeNode* root){
	if(root == NULL) {
		return 0;
	}
	unsigned long long max = 0;
	int sum = dfs(root);
	product_f(root, &max, sum);
	return max % 1000000007;
}
