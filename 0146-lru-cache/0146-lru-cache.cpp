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
        key=-1;
        next=prev=nullptr;
    }

    Node(int k1 , int d1){
        data=d1;
        key=k1;
        next=prev=nullptr;
    }
};

void Deletion(Node* todel){
    Node* temp=todel->prev;
    temp->next=todel->next;
    todel->next->prev=temp;
}

void Insertion(Node* head , Node* toins){
    toins->next=head->next;
    toins->next->prev=toins;
    head->next=toins;
    toins->prev=head;
}

class LRUCache {
public:
    int c;
    int size=0;
    Node* head=new Node(-1);
    Node* tail=new Node(-1);
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* n=mp[key];
        Deletion(n);
        Insertion(head,n);
        return n->data;
    }
    
    void put(int key, int value) {
        if(c==0) return;
        if(size<c){
            if(mp.find(key)==mp.end()){
                size++;
                Node* put=new Node(key,value);
                mp[key]=put;
                Insertion(head,mp[key]);
            }
            else{
                Node* tochange=mp[key];
                tochange->data=value;
                Deletion(tochange);
                Insertion(head,tochange);
            }
        }
        else{
         if(mp.find(key)==mp.end()){
            Node* put=new Node(key,value);
            Node* LRU=tail->prev;
            Deletion(LRU);
            mp.erase(LRU->key);
            delete(LRU);
            Insertion(head,put);
            mp[key]=put;
         }
         else{
                Node* tochange=mp[key];
                tochange->data=value;
                Deletion(tochange);
                Insertion(head,tochange);
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