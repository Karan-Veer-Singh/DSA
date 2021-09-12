// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return NULL;
        
        Node *curr = head;
        Node *n = head;
        
        while(curr)
        {
            n = curr -> next;
            Node *t = new Node(curr -> val);
            curr -> next = t;
            t -> next = n;
            
            curr = n;
        }
        
        curr = head;
        
        while(curr)
        {
            curr -> next -> random = (curr -> random != NULL) ? curr -> random -> next : NULL;
            curr = curr -> next -> next;
        }
        
        Node *original = head;
        Node *copy = head -> next;
        Node *temp = copy;
        
        while(original)
        {
            original -> next = original -> next -> next;
            copy -> next = (copy -> next != NULL) ? copy -> next -> next : NULL;
            
            original = original -> next;
            copy = copy -> next;
        }
        
        return temp;
        
    }
};
