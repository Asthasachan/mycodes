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



//gfg sol->
class Solution
{
    public:
    //Function to convert a binary tree to doubly linked list.
    void bToDLLUtil(Node *root, Node **head_ref)
    {
        //base case for recursion.
        if(root == NULL)
            return;
    
        //calling function recursively to convert right subtrees.
        bToDLLUtil(root->right, head_ref);
    
        //inserting root into doubly linked list.
        root->right = *head_ref;
    
        //changing left pointer of previous head.
        if (*head_ref != NULL)
            (*head_ref)->left = root;
    
        //changing head of doubly linked list.
        *head_ref = root;
    
        //calling function recursively to convert left subtrees.
        bToDLLUtil(root->left, head_ref);
    }

    public:
    //Function to convert binary tree to doubly linked list and return it.
    Node* bToDLL(Node *root)
    {
        Node *head = NULL;
        //calling the function for conversion.
        bToDLLUtil(root,&head);
        return head;
        
    }
};    
