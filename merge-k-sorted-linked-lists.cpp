//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#
struct compare{
       bool operator()(Node* a,Node* b){
        return (a->data>b->data);
        }
    };
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node* dummy=new Node(0);
           Node* last=dummy;
           priority_queue<Node*,vector<Node*>,compare>pq;
           for(int i=0;i<K;i++){
               if(arr[i]!=NULL)
               pq.push(arr[i]);
           }
           if(pq.empty()){
               return NULL;
           }
           while(!pq.empty()){
               Node* temp=pq.top();pq.pop();
               last->next=temp;
               last=last->next;
               if(temp->next!=NULL){
                   pq.push(temp->next);
               }
               
           }
           return dummy->next;
    }
