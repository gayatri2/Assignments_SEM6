#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node*left;
    node*right;
    node()
    {
        left=right=NULL;
    }
};
class tree
{
    node*root;
    public:
    tree()
    {
        root=NULL;
    }
    node* getRoot()
    {
        return root;
    }
    bool isempty()
    {
	    return (root == NULL);
    }
    void insert();
    void bfs(node*root);
    void dfs(node*root);
};
void tree::insert()
{
    node*p=new node;
    node*curr=NULL;
    int flag;
    int x;
    cout << "Enter the data to be inserted:"<<endl;
    cin >> x;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    if(isempty())
    {
        root=p;
    }
    else
    {
        curr = root; flag=0;
        do
        {
            if(p->data > curr->data)
            {
                if(curr->right==NULL)
                {
                    curr->right=p;
                    flag=1;
                }
                else
                {
                    curr=curr->right;
                }
            }      
            else if (p->data < curr->data)
            {
                if(curr->left==NULL)
                {
                    curr->left=p;
                    flag=1;
                }
                else
                {
                    curr=curr->left;
                }
            }
            else
            {
                cout << "Duplicated not allowed."<<endl;
                return;
            }
        }while(flag==0);
        
            
        
    }
}
void tree::bfs(node* root)
{
 /*Time complexity: O(n) ie no of nodes
    Space complexity: best- O(1), worst- O(n)
  */

  
  if (root == NULL)
  {
      cout << "Empty"<< endl;
      return;
  }  
 
    // Create an empty queue for level order traversal
    queue<node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        node *current = q.front();
        cout << current->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (current->left != NULL)
            q.push(current->left);
 
        /*Enqueue right child */
        if (current->right != NULL)
            q.push(current->right);
    }
}
void tree::dfs(node* root)
{
      if (root == NULL) {
        
        return;
    }
    dfs(root->left);
    dfs(root->right);
    cout << root->data << " ";
}
int main()
{
    tree t1;
    char ans;
    do
    {
        cout << endl << "MENU:\n 1.INSERT\n 2.LEVEL ORDER TRAVERSAL(BFS)\n 3.DFS"<<endl;
        int choice;
        cout << "Enter choice:"<<endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                t1.insert();
            }break;
            
            case 2:{
                t1.bfs(t1.getRoot());
            }break;
            case 3:{
                t1.dfs(t1.getRoot());
            }break;
            default: "Wrong choice!";
            
        }  
        
        
        cout << "Enter menu again?(y/n)" << endl;
        cin >> ans;
    } while (ans=='y');
    return 0;
}