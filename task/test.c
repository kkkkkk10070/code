#include<stdio.h>
#include<stdlib.h>
typedef int elementype;
typedef struct Node
{
    elementype data;
    struct Node *next;
}node;
node *initnode()
{
 node *head=(node*)malloc(sizeof(node));
 head->next=NULL;
 return head;
}
void inserthead(node *L,elementype e)
{
    node *p=(node*)malloc(sizeof(node));
    p->next=L->next;
    L->next=p;
    p->data=e;
} 
void listnode(node *L)
{
    node *p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
node* get_tail(node *L)
{
    node *tail;
    tail = L;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}
node* inserttail(node *tail,elementype e)
{
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}
int insernode(node*L,int pos,elementype e)
{
    node *p=L;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            printf("插入失败\n");
            return 0;
        }
    }
    node *q=(node*)malloc(sizeof(node));
    q->next=p->next;
    p->next=q;
    q->data=e;
    return 1;
}
node *reverse(node *L)
{
     node *first=NULL;
     node *second=L->next;
     node *third;
     while(second!=NULL)
     {
        third=second->next;
        second->next=first;
        first=second;
        second=third;
     }
     node *reverse=initnode();
     reverse->next=first;
     return reverse;
}
void reorder(node *L)
{
    node *fast=L->next;
    node *slow=L;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    node *first=NULL;
    node *second=slow->next;
    slow->next=NULL; 
    node *third;
    while(second!=NULL)
    {
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    node *q1=L->next;
    node *q2=first;
    node *p1,*p2;
    while(q1!=NULL&&q2!=NULL)
    {
        p1=q1->next;
        p2=q2->next;
        q1->next=q2;
        q2->next=p1;
        q1=p1;
        q2=p2;
    }

}
int iscircle(node *L)
{
    node *fast=L;
    node *slow=L;
    while(fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            printf("it is a circle");
            return 1;
        }
    }
    printf("it is not a circle");
    return 0;
}
node *findcirclebegin(node *L)
{
    node *fast=L;
    node *slow=L;
    while(fast->next!=NULL&&fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            node *p=fast;
            int count=1;
             while(p->next!=slow)
             {
                p=p->next;
                count++;
             }
             fast=L;
             slow=L;
             for(int i=0;i<count;i++)
             {
                fast=fast->next;
             }
             while(fast!=slow)
             {
                fast=fast->next;
                slow=slow->next;
             }
             return slow;
        }
    }
    return NULL;
}
node *find_circlebegin(node *L)
{
    node *fast=L;
    node *slow=L;
    while(fast->next!=NULL&&fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
           node *p=L;
           while(p!=slow)
           {
            p=p->next;
            slow=slow->next;
           }
           return slow;
        }
    }
    return NULL;
}
int main()
{
    node *L=initnode();
    node *tail=get_tail(L);
    tail=inserttail(tail,1);
    tail=inserttail(tail,2);
    tail=inserttail(tail,3);
    node *T=tail;
    tail=inserttail(tail,4);
    tail=inserttail(tail,5);
    tail=inserttail(tail,6);
    tail=inserttail(tail,7);
    tail=inserttail(tail,8);
     tail=inserttail(tail,9);
    tail->next=T;
   node *answer=find_circlebegin(L);
   printf("%d",answer->data);
}
