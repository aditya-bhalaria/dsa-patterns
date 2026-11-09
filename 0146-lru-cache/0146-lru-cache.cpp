class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    int key;

    Node(int d1 , Node* n1 , Node* p1,int k){
        data=d1;
        next=n1;
        prev=p1;
        key=k;
    }
    Node(int d1){
       data=d1;
       next=prev=nullptr;
       key=-1;
    }
    Node(int k1 , int d1){
       key=k1;
       data=d1;
       next=prev=nullptr;
    }
};

void Insertion(Node* head , Node* toInsert){
    toInsert->next=head->next;
    toInsert->next->prev=toInsert;
    head->next=toInsert;
    toInsert->prev=head;
}
void DllDeletion(Node* todelete){
  Node* temp=todelete;
  Node* p=temp->prev;
  p->next=temp->next;
  temp->next->prev=p;  
}

class LRUCache {
public:
Node* head=new Node(-1);
Node* tail=new Node(-1);

unordered_map<int,Node*>mp;
int size=0;
int capacity_;
    LRUCache(int capacity) {
        capacity_=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        DllDeletion(node);
        Insertion(head,node);
        return node->data;
    }
    
    void put(int key, int value) {
        if(capacity_==0) return;
        
        if(size<capacity_){
            if(mp.find(key)==mp.end()){
            size++;
            Node* n=new Node(key,value);
            Insertion(head,n);
            mp[key]=n;
            }
            else{
                Node* n=mp[key];
                DllDeletion(n);
                Insertion(head,n);
                n->data=value;
            }
        }
        else{
          if(mp.find(key)==mp.end()){
          mp.erase(tail->prev->key);
          Node* lru=tail->prev;
          DllDeletion(tail->prev);
          Node* ins=new Node(key,value);
          mp[key]=ins;
          Insertion(head,ins);
          delete(lru);
          }
          else{
            Node* n=mp[key];
            DllDeletion(n);
            Insertion(head,n);
            n->data=value;
          }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */