#include<stdio.h>
#include<conio.h>
struct poly
{
int coeff;
int power;
struct poly *next;
};


struct poly *head=NULL;
struct poly *head1=NULL;
struct poly *head2=NULL;

void create(struct poly **h)
{
char ch='y';
struct poly *newn,*t;
t=*h;
while(ch=='y'||ch=='Y')
{
newn=((struct poly*)malloc(sizeof(struct poly)));
newn->next=NULL;
printf("\n ENTer coeff and pow: ");
scanf("%d%d",&newn->coeff,&newn->power);
if(*h==NULL)
*h=newn;
else
{
while(t->next!=NULL)
t=t->next;
t->next=newn;
}
printf("\n do u want : ");
scanf("%s",&ch);

}

}

void list(int c,int p)
{
struct poly *newn,*t;
newn=((struct poly*)malloc(sizeof(struct poly)));
newn->next=NULL;
newn->power=p;
newn->coeff=c;
if(head==NULL)
head=newn;
else
{
t=head;
while(t->next!=NULL)
t=t->next;
t->next=newn;
}
}


void add()
{
struct poly *p1,*p2;
p1=head1;
p2=head2;

while((p1->next!=NULL)&&(p2->next!=NULL))
{
if((p1->power)>(p2->power))
{
list(p1->coeff,p1->power);
p1=p1->next;
}

else if((p1->power)<(p2->power))
{
list(p2->coeff,p2->power);
p2=p2->next;
}
else if((p1->power)==(p2->power))
{
int c;
c=p1->coeff+p2->coeff;
list(c,p1->power);
p1=p1->next;
p2=p2->next;
}
}

while(p1->next!=NULL)
{
list(p1->coeff,p1->power);
p1=p1->next;
}

while(p2->next!=NULL)
{
list(p2->coeff,p2->power);
p2=p2->next;
}

}

void display(struct poly **h)
{
struct poly *t;
if(*h==NULL)
{
printf("\n EMPTY LIST ");
return;
}
t=*h;
while(t!=NULL)
{
printf("  %d ^ %d +",t->coeff,t->power);
t=t->next;
}
}



void main()
{
printf("\n Enter struct poly 1 : ");
create(&head1);
display(&head1);
getch();

printf("\n Enter struct poly 2 : ");
create(&head2);
display(&head2);
getch();
add();
display(&head);
getch();
}

