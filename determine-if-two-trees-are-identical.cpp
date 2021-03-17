class Solution
{
    public:
    void isiden(Node* r1,Node* r2,bool& k){
        if(r1==NULL && r2==NULL){
            return;
        }
        if(r1==NULL || r2==NULL){
            k=false;
            return;
        }
        if(r1->data!=r2->data){
            k=false;
            return;
        }
        //c=c+1;
        isiden(r1->left,r2->left,k);
        isiden(r1->right,r2->right,k);
       // c--;
    }
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
       
        bool k=true;
        isiden(r1,r2,k);
        return k;
    }
};
//Execution Time:0.16 gfg
