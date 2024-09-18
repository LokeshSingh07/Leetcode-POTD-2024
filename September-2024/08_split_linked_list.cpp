// 725. Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step1: Find length of linked list
        ListNode* curr = head;
        int L = 0;
        while(curr){
            curr = curr->next;
            L++;
        }

        // Step2: 
        int eachBucketNodes = L / k;
        int remainderNodes  = L % k;
        vector<ListNode*> result(k, NULL);

        curr = head;
        ListNode* prev = NULL;
        for(int i=0; curr && i<k; i++){
            result[i] = curr;
            for(int cnt = 1; cnt <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); cnt++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            remainderNodes--;
        }

        return result;
    }
};