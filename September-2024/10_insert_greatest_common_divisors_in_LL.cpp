// 2807. Insert Greatest Common Divisors in Linked List

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prevNode = head;
        ListNode* currNode = head->next;

        while(currNode){
            int gcd = __gcd(currNode->val, prevNode->val);
            ListNode* temp = new ListNode(gcd);
            temp->next = currNode;
            prevNode->next = temp;
            
            prevNode = currNode;
            currNode = currNode->next; 
        }

        return head;
    }
};