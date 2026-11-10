class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    int key;
    int freq;
    Node(int d1 , Node* n1 , Node* p1,int k,int f){
        data=d1;
        next=n1;
        prev=p1;
        key=k;
        freq=f;
    }
    Node(int d1){
       data=d1;
       next=prev=nullptr;
       key=-1;
       freq=0;
    }
    Node(int k1 , int d1){
       key=k1;
       data=d1;
       freq=1;
       next=prev=nullptr;
    }
    Node(int k1 , int d1, int f){
       key=k1;
       data=d1;
       freq=f;
       next=prev=nullptr;
    }
};

class DLL{
    public:
    Node* head;
    Node* tail;
    public:
    DLL(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
};
void Insertion(Node* head , Node* toInsert){
    toInsert->next=head->next;
    toInsert->next->prev=toInsert;
    head->next=toInsert;
    toInsert->prev=head;
}
void Deletion(Node* todelete){
  Node* temp=todelete;
  Node* p=temp->prev;
  p->next=temp->next;
  temp->next->prev=p;  
}

class LFUCache {
public:
unordered_map<int,DLL>FreqMap;
unordered_map<int,Node*>mp;
int size=0;
int capacity_;
int minFreq=0;
    LFUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
      if(mp.find(key)==mp.end()) return -1;
      Node* node=mp[key];
      int oldFreq=node->freq;
      int newFreq=oldFreq+1;
      Deletion(node);
      FreqMap[newFreq];
      node->freq=newFreq;
      Insertion(FreqMap[newFreq].head,node);
      if(minFreq==oldFreq && FreqMap[oldFreq].head->next==FreqMap[oldFreq].tail) minFreq++;
      return node->data;
    }
    
    void put(int key, int value) {
        if(capacity_==0) return;
        
        if(size<capacity_){
         if(mp.find(key)==mp.end()){
            size++;
            Node* put=new Node(key,value,1);
            mp[key]=put;
            FreqMap[put->freq];
            Insertion(FreqMap[put->freq].head,put);
            minFreq=1;
         }
         else{
            Node* node=mp[key];
            node->data=value;
            int oldFreq=node->freq;
            int newFreq=oldFreq+1;
            Deletion(node);
            node->freq=newFreq;
            FreqMap[node->freq];
            Insertion(FreqMap[node->freq].head,node);
            if(minFreq==oldFreq && FreqMap[oldFreq].head->next==FreqMap[oldFreq].tail) minFreq++;
         }
        }
        else{
          if(mp.find(key)==mp.end()){
            Node* remove=FreqMap[minFreq].tail->prev;
            Deletion(FreqMap[minFreq].tail->prev);
            mp.erase(remove->key);
            delete(remove);
            Node* put=new Node(key,value);
            mp[key]=put;
            minFreq=1;
            Insertion(FreqMap[put->freq].head,put);
          }
          else{
           Node* update=mp[key];
           update->data=value;
           Deletion(update);
           int oF=update->freq;
           int nf=oF+1;
           FreqMap[nf];
           update->freq=nf;
           Insertion(FreqMap[nf].head,update);
           if(minFreq==oF && FreqMap[oF].head->next==FreqMap[oF].tail) minFreq++;
           
          }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */