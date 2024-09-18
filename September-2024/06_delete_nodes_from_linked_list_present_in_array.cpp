// 3217. Delete Nodes From Linked List Present in Array

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr){
            if(st.find(curr->val) != st.end()){
                ListNode *delNode = curr;
                curr = curr->next;
                prev->next = curr;
                delete delNode;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};