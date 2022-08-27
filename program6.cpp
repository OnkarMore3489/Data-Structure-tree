//practice

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE,**PPNODE;

class Tree
{
    private:
           PNODE first;
           int size;

    public:
           Tree();
           void Insert(int no);
           bool Search(int no);
};

Tree::Tree()
{
    first=NULL;
    size=0;
}

void Tree::Insert(int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->lchild=NULL;
    newn->rchild=NULL;

    if(first==NULL)
    {
        first=newn;
    }
    else 
    {
        PNODE temp=first;

        while(1)
        {
            if(temp->data=no)
            {
                cout<<"Dublicate Node"<<"\n";
                delete newn;
                break;
            }
            else if(no < temp->data)
            {
                if(temp->lchild==NULL)
                {
                    temp->lchild=newn;
                    break;
                }
                temp=temp->lchild;
            }
            else if(no > temp->data)
            {
                if(temp->rchild==NULL)
                {
                    temp->rchild=newn;
                    break;
                }
                temp=temp->rchild;
            }
        }
    }
}

bool Tree::Search(int no)
{
    PNODE temp=first;
    bool bRet=false;

    while(temp!=NULL)
    {
        if(temp->data==no)
        {
            bRet=true;
            break;
        }
        else if(no < temp->data)
        {
            temp=temp->lchild;
        }
        else if(no > temp->data)
        {
            temp=temp->rchild;
        }
    }
}
int main()
{
    return 0;
}