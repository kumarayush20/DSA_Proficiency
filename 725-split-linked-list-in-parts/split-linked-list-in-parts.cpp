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

// TC: O(K+L) or O(K*L/K)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }

        int eachBucketNodes = len/k;
        int remainderNodes = len%k;

        vector<ListNode*> result(k, NULL);

        curr = head;
        ListNode* prev = NULL;

        for(int i=0; i<k; i++){
            result[i] = curr;
            for(int cnt = 1; cnt<=eachBucketNodes + (remainderNodes > 0 ? 1 : 0); cnt++){
                prev = curr;
                curr = curr->next;
            }
            if(prev!=NULL){
                prev->next = NULL;
            }         
            remainderNodes--;
        }

        return result;
    }
};