/*ID:maosong1
LANG:C++
PROB:frac1
*/
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	int num,den;
	struct node* next,*pre;
};
int n;
void dfs(node* head,node *tail)
{
	if((head->num+tail->num)>n || (head->den+tail->den)>n) return;
	node *p=(node *)malloc(sizeof(node));
	p->num=head->num+tail->num;p->den=head->den+tail->den;
	head->next=p;p->pre=head;p->next=tail;tail->pre=p;//printf("test");
	dfs(head,p);dfs(p,tail);
}
int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	node *head=(node *)malloc(sizeof(node));
	node *tail=(node *)malloc(sizeof(node));
	head->num=0;head->den=1;head->next=tail;head->pre=NULL;
	tail->num=tail->den=1;tail->next=NULL;tail->pre=head;
	dfs(head,tail);
	while(head!=NULL)
	{
		printf("%d/%d\n",head->num,head->den);
		head=head->next;
	}
	return 0;
}