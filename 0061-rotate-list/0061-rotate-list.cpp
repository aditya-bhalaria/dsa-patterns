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
    ListNode* countNthnode(ListNode* t,int l){
        int count=1;
        ListNode* tail=t;
        while(tail!=nullptr && count<l){
            count++;
            tail=tail->next;
        }
        return tail;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0){
            return head;
        }
        int len=1;
        ListNode* tail=head;
        while(tail->next!=nullptr){
            len++;
            tail=tail->next;
        }
    if(k%len == 0){
        return head;
    }
        k%=len;
        tail->next=head;
        tail=countNthnode(head,len-k);
        head=tail->next;
        tail->next=nullptr;
        return head;

    }
};