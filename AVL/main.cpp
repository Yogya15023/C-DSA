#include <iostream>

using namespace std;
struct node{
struct node *lchild;
int data;
int height;
struct node *rchild;}*root=NULL;
int nodeheight(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild?hl+1:0;
    hr=p && p->rchild?hr+1:0;
    return hl>hr?hl+1:hr+1;
}
int balance(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild?hl+1:0;
    hr=p && p->rchild?hr+1:0;
    return hl-hr;
}
struct node * LLrotation(struct node *p)
{
 struct node *pl=p->lchild;
 struct node *plr=pl->rchild;
 pl->rchild=p;
 p->lchild=plr;
 p->height=nodeheight(p);
 pl->height=nodeheight(pl);
 if(p==root)
        pl=root;
 return pl;
}
struct node * LRrotation(struct node *p)
{
 struct node *pl=p->lchild;
 struct node *plr=pl->rchild;
 p->lchild=plr->rchild;
 pl->rchild=plr->lchild;
 plr->rchild=p;
 plr->lchild=pl;
 pl->height=nodeheight(pl);
 p->height=nodeheight(p);
 plr->height=nodeheight(plr);
 if(root==p)
        root=plr;
 return plr;
}
struct node * RRrotation(struct node *p)
{
 struct node *pr=p->rchild;
 struct node *prr=pr->lchild;
 pr->lchild=p;
 p->rchild=prr;
 p->height=nodeheight(p);
 pr->height=nodeheight(pr);
 if(p==root)
        pr=root;
 return pr;
}
struct node * RLrotation(struct node *p)
{
 struct node *pr=p->rchild;
 struct node *prl=pr->lchild;
 p->rchild=prl->lchild;
 pr->lchild=prl->rchild;
 prl->rchild=pr;
 prl->lchild=p;
 pr->height=nodeheight(pr);
 p->height=nodeheight(p);
 prl->height=nodeheight(prl);
 if(root==p)
        root=prl;
 return prl;
}
struct node * rInsert(struct node *p, int key) {
   struct node *t=NULL;
    if (p == NULL){
        t = new node;
        t->data = key;
        t->height=1;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }

    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    p->height=nodeheight(p);
    if(balance(p)==2 && balance(p->lchild)==1)
    {
        return LLrotation(p);
    }
    else if(balance(p)==2 && balance(p->lchild)==-1)
    {
        return LRrotation(p);
    }
    else if(balance(p)==-2 && balance(p->lchild)==1)
    {
        return RLrotation(p);
    }
    else if(balance(p)==-2 && balance(p->lchild)==-1)
    {
       return RRrotation(p);
    }
    return p;  // key == p->data?
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<endl;
        inorder(p->rchild);
    }
}
int main()
{
    root=rInsert(root,10);
    rInsert(root,5);
    rInsert(root,30);
    rInsert(root,40);
    rInsert(root,20);
    rInsert(root,15);
    rInsert(root,25);
    inorder(root);
    return 0;
}
