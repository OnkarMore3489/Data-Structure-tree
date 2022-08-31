#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->lchild=NULL;
    newn->rchild=NULL;

    if((*Head==NULL))
    {
        (*Head)=newn;
    }
    else
    {
        PNODE temp=(*Head);

        while(1)//Unconditional Loop     for(;;)
        {
            if(temp->data==no)
            {
                cout<<"Duplicate Node"<<"\n";
                delete newn;
                break;
            }
            else if(temp->data > no) //small data
            {
                if(temp->lchild==NULL)
                {
                    temp->lchild=newn;
                    break;
                }
                temp=temp->lchild;
            }
            else if(temp->data < no) //large data
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

bool Search(PNODE Head,int no)
{
    if(Head==NULL)//if tree is Empty
    {
        return false;
    }
    else//tree contain atleast one node
    {
        while(Head != NULL)
        {
            if(Head->data==no)//node sapadla
            {
                break;
            }
            else if(no > (Head->data))
            {
                Head=Head->rchild;
            }
            else if(no < (Head->data))
            {
                Head=Head->lchild;
            }
        }
        if(Head==NULL)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
}

int Count(PNODE Head)
{
    static int iCnt=0;

    if(Head!=NULL)
    {
        iCnt++;
        Count(Head->lchild);
        Count(Head->rchild);
    }
    return iCnt;
}

int CountLeaf(PNODE Head)
{
    static int iCnt=0;

    if(Head!=NULL)
    {
        if((Head->lchild==NULL) && (Head->rchild==NULL))
        {
         iCnt++;
        }
        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }
    return iCnt;
}

int CountParent(PNODE Head)
{
    static int iCnt=0;

    if(Head!=NULL)
    {
        if((Head->lchild!=NULL) || (Head->rchild!=NULL))
        {
         iCnt++;
        }
        CountParent(Head->lchild);
        CountParent(Head->rchild);
    }
    return iCnt;
}

void Inorder(PNODE Head)
{
    if(Head!=NULL)
    {
        Inorder(Head->lchild);//L
        cout<<Head->data<<"\n";//D
        Inorder(Head->rchild);//R
    }
}

void Postorder(PNODE Head)
{
    if(Head!=NULL)
    {
        Postorder(Head->lchild);//L
        Postorder(Head->rchild);//R
        cout<<Head->data<<"\n";//D
    }
}

void Preorder(PNODE Head)
{
    if(Head!=NULL)
    {
        cout<<Head->data<<"\n";//D
        Preorder(Head->lchild);//L
        Preorder(Head->rchild);//R
    }
}
int main()
{
    int no=0;
    bool bRet=false;
    int iRet=0;

    PNODE first=NULL;

    Insert(&first,51);
    Insert(&first,21);
    Insert(&first,101);

    cout<<"Enter Number to be search\n";
    cin>>no;

    bRet=Search(first,no);
    if(bRet==true)
    {
        cout<<"Data is there\n";
    }
    else 
    {
        cout<<"Data is not there\n";
    }

    iRet=Count(first);
    printf("Number of Nodes are : %d\n",iRet);

    iRet=CountLeaf(first);
    printf("Number of Leaf Nodes are : %d\n",iRet);

    iRet=CountParent(first);
    printf("Number of parent Nodes are : %d\n",iRet);

    cout<<"Inorder : \n";
    Inorder(first);

    cout<<"Postorder : \n";
    Postorder(first);

    cout<<"Preorder : \n";
    Preorder(first);
    return 0;
}