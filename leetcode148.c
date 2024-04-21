#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* findMiddle(struct ListNode* head) {
	struct ListNode* fast = head->next;
	struct ListNode* low = head;
	while(fast && fast->next) {
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}

struct ListNode* merge(struct ListNode* h1, struct ListNode* h2) {
	//base case
	if(!h1) {
		return h2;
	}
	if(!h2) {
		return h1;
	}
	//recursion
	if(h1->val < h2->val) {
		h1->next = merge(h1->next, h2);
		return h1;
	} else {
		h2->next = merge(h1, h2->next);
		return h2;
	}
}

struct ListNode* sortList(struct ListNode* head) {
	if(!head || !head->next) {
		return head;
	}
	struct ListNode* l = head;
	struct ListNode* middle = findMiddle(head);
	struct ListNode* h = middle->next;
	middle->next = NULL;

	l = sortList(l);
	h = sortList(h);
	
	return merge(l,h);
}






