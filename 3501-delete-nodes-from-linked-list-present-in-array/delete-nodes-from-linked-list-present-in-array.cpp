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
        ListNode* d = new ListNode(-1);
        ListNode* t = d;
        set<int> set1;
        for(auto it : nums){
            set1.insert(it);
        }
        while(head!=NULL){
            if(set1.find(head->val)==set1.end()){
                t->next = head;
                t = t->next;
            }
            head = head->next;
        }
        t->next = NULL;
        return d->next;
    }
};