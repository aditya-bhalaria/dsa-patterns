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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1=list1;
        ListNode* t2=list2;;

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val <= t2->val){
             ListNode* Newnode=new ListNode(t1->val);
             temp->next=Newnode;
             temp=Newnode;
             t1=t1->next;
            }

            else{
             ListNode* Newnode=new ListNode(t2->val);
             temp->next=Newnode;
             temp=Newnode;
             t2=t2->next;
            }
        }

        while(t1){
            ListNode* Newnode=new ListNode(t1->val);
             temp->next=Newnode;
             temp=Newnode;
             t1=t1->next;
        }

        while(t2){
            ListNode* Newnode=new ListNode(t2->val);
             temp->next=Newnode;
             temp=Newnode;
             t2=t2->next;
        }
        return dummy->next;

    }
};