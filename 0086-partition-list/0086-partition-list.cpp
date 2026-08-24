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
    int findGreaterthanX(ListNode* f,int x){
        while(f->next!=nullptr){
            if(f->val >= x){
                break;
            }
            f=f->next;
        }
        return f->val;
    }
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        int g=findGreaterthanX(head,x);
        ListNode* dummy=new ListNode(-1);
        ListNode* d=dummy;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* front;


        while(temp!=nullptr){
            front=temp->next;
            if(temp->val < x){
                if(head==temp){
                    head=head->next;
                }
            temp->next=nullptr;
            if(prev){
                prev->next=front;
            }
             dummy->next=temp;
             dummy=dummy->next;
             temp=front;
          }
          else{
            prev=temp;
            temp=temp->next;
          }
        }
        dummy->next=head;
        return d->next;
    }
};