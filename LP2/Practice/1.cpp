#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node()
    {
        left=right=NULL;
    }
};
class tree{
    node*root;
    public:
    tree()
    {
        root=NULL;
    }
    node* getroot()
    {
        return root;
    }
    void insert();
    void dfs(node*root);
    void bfs(node*root);
    
};
void tree::insert()
{
    node*p=new node;
    node*current=NULL;
    
    int x;
    cout <<"Enter the data you want to insert:"<<endl;
    cin >> x;
    int flag;
    p->data=x;
    p->left = NULL; 
    p->right =NULL;
    if(root==NULL)
    {
        root=p;
    }
    else
    {
        current=root;  flag=0;
        do
        {
            if(current->data < p->data)//right subtree
            {
                if(current->right==NULL)
                {
                    current->right=p;
                    flag=1;
                }
                else
                {
                    current=current->right;       
                }
            }
            else if(current->data > p->data)//left subtree
            {
                if(current->left==NULL)
                {
                    current->left=p;
                    flag=1;
                }
                else
                {
                    current=current->left; 
                }
            }   
            else
            {
                cout << "Duplicate entry not allowed!!!!"<<endl;
                return;
            }
        } while (flag==0);
        
        
    }
}
void tree::bfs(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        node*temp=q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left!=NULL)
        {
            q.push(temp->left);

        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);

        }

    }
}
void tree::dfs(node*root)
{
    if(root==NULL)
    {
         return;
    }
    dfs(root->left);
    dfs(root->right);
    cout << root->data << " ";
}
int main()
{
    
    char ans;
    tree t;
    do
    {
        cout << "MENU:\n 1. insert\n 2.dfs\n 3.bfs\n 4.stop\n";
        int choice;
        cout << "Enter choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:{
                t.insert();
            }break;
            case 2:{
                t.dfs(t.getroot());//postorder tree traversal
            }break;
            case 3:{
                t.bfs(t.getroot());
            }break;
        
            default:{cout << "Invalid choice"<<endl;}
        }
        
        cout << "Enter main menu again?(y/n)"<<endl;
        cin >> ans;
    } while (ans=='y');
    
    return 0;
}