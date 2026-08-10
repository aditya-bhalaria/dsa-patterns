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
    ListNode* revFunc(ListNode* newhead){
        ListNode* prev=nullptr;
        ListNode* t=newhead;
        ListNode* front=newhead;
        while(t!=nullptr){
            front=front->next;
            t->next=prev;
            prev=t;
            t=front;
        }
        return prev;
    }
    
    ListNode* findKthNode(ListNode* hd,int count){
        while(hd!=nullptr){
            count--;
            if(count==0){
                return hd;
            }
            hd=hd->next;
        }
        return nullptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==nullptr){
                if(prev) prev->next=temp;
                return head;
            }

            ListNode* nextNode=kthNode->next;
            kthNode->next=nullptr;
            revFunc(temp);
            if(head==temp){
                head=kthNode;
            }
            else{
                prev->next=kthNode;
            }

            prev=temp;
            temp=nextNode;
            
        }
        return head;
    }
};