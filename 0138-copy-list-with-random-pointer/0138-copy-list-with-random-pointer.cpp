/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertLL(Node* head){
     Node* temp=head;
     while(temp){
        Node* newNode=new Node(temp->val);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
     }
    }
    void LinkRandom(Node* head){
        Node* temp=head;
        while(temp){
        Node* copyNode=temp->next;
        if(temp->random){
            copyNode->random=temp->random->next;
        }
        else{
            copyNode->random=nullptr;
        }
        temp=temp->next->next;
        }
        
    }

    Node* linkFinalLL(Node* head){
        Node* dummy=new Node(-1);
        Node* temp=head;
        Node* res=dummy;
        while(temp){
             res->next=temp->next;
             temp->next=temp->next->next;
             temp=temp->next;
             res=res->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertLL(head);
        LinkRandom(head);
        return linkFinalLL(head);
    }
};