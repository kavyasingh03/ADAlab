#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    if (!head || !head->next) return head; 


    head = reverseList(head);
    
    struct ListNode* curr = head;
    struct ListNode* prev = head;
    int maxVal = head->val;


    while (curr && curr->next) {
        if (curr->next->val < maxVal) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
            maxVal = curr->val;
        }
    }

    return reverseList(head);
}
