#include <stdio.h>
#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
        } else {
            prev = curr;
        }
        curr = prev->next;
    }

    head = dummy->next;
    free(dummy);
    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
