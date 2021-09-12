/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void reverse(ListNode* &ans, ListNode *head)
    {
        if(head == NULL)
            return;
        
        if(head -> next == NULL)
        {
            ans = head;
            return;
        }
        
        reverse(ans, head -> next);
        head -> next -> next = head;
        head -> next = NULL;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode *ans = NULL;
        reverse(ans, head); 
        
        return ans;        
    }
};

////https://leetcode.com/problems/reverse-linked-list/
