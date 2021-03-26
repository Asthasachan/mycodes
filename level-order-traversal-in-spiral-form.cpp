//gfg Execution Time:0.01
vector<int> findSpiral(Node *root)
{
    //Your code here
    
    vector<int>p;
    if(root==NULL){
        return p;
    }
    stack<Node*> s1; 
    stack<Node*> s2; 
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            p.push_back(temp->data);
            if (temp->right!=NULL)
                s2.push(temp->right);
            if (temp->left!=NULL)
                s2.push(temp->left);
        }
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
              p.push_back(temp->data);
            if (temp->left!=NULL)
                s1.push(temp->left);
            if (temp->right!=NULL)
                s1.push(temp->right);
        }
    }
    return p;
    
}
