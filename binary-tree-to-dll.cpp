//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
//Execution Time:0.12
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void inord(Node* root,queue<int>&q){
        if(root==NULL){
            return;
        }
        inord(root->left,q);
        q.push(root->data);
        inord(root->right,q);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        queue<int>q;
        inord(root,q);
        if(q.size()==0 || q.size()==1){
            return root;
        }
        Node* head=new Node();
        head->data=q.front();
        Node* t=head;
        q.pop();
        while(!q.empty()){
            Node* a=new Node();
            a->data=q.front();
            q.pop();
            t->right=a;
            a->left=t;
            t=t->right;
        }
        return head;
    }
};
