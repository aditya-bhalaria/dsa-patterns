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
    ListNode* reverse(ListNode* h2){
        ListNode* t2=h2;
        ListNode* p=nullptr;
        while(t2!=nullptr){
            ListNode* front=t2->next;
            t2->next=p;
            p=t2;
            t2=front;
        }
        return p;
    }
    ListNode* findKth(ListNode* h){
        ListNode* t=h;
        int count=1;
        while(t!=nullptr){
            if(count==2){
                return t;
            }
            else{
                t=t->next;
                count++;
            }
        }
        return t;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* kthNode=findKth(temp);
            if(kthNode==nullptr){
                prev->next=temp;
                return head;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=nullptr;
            reverse(temp);
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