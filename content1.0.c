#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
struct node
{
    int nu;
    char name[20];
    char sex[10];
    char num[20];
    char add[50];
    char qq[20];
    struct node *next;
};
typedef struct node Node;
typedef struct node *Link;
void is_malloc_ok(Link *new_node)
{
    if(*new_node == NULL)
    {
        printf("malloc error\n");
        exit(-1);
    }
}
void creat_node(Link *new_node)
{
    *new_node = (Link)malloc(sizeof(Node));
    is_malloc_ok(new_node);
}
void creat_link(Link *head)
{
    creat_node(head);
    (*head)->next = *head;
}
void insert_node_tail(Link head,Link new_node)
{
    Link p = NULL;
    p = head;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->next = head;
}
void display_link(Link head)
{
    Link p = NULL;
    p = head->next;
    if(p == head)
    {
        printf("该通讯录为空\n");
        return;
    }
    while(p != head)
    {
        printf("序号:%d\t名字：%s\n",p->nu,p->name);
        printf("\t性别:%s\n",p->sex);
        printf("\t电话号码:%s\n",p->num);
        printf("\t家庭住址:%s\n",p->add);
        printf("\tQQ:%s\n",p->qq);
        p = p->next;
    }
}
int len_link(Link head)
{
    int len = 0;
    Link p = NULL;
    p = head;
    while(p->next != head)
    {
        len++;
        p = p->next;
    }
    return (len);
}
Link search_link(Link head,char human[])
{
    Link q = NULL;
    Link p = NULL;
    q = head->next;
    p = head->next;
    while(p != head && strcmp(p->name,human) != 0)
    {
        q = p;
        p = p->next;
    }
    return p;
}
void remove_link(Link head,char human[])
{
    Link p = NULL;
    Link q = NULL;
    p = q = head;
    while(strcmp(p->name,human) != 0 && p->next != head)
    {
        q = p;
        p = p->next;
    }
        if(strcmp(p->name,human) == 0)
        {
        q->next = p->next;
        free(p);
        }
        else
        {
        printf("找不到要删除的联系人\n");
        }
}
void sort_link(Link head)
{
	int len;
	len = len_link(head);
	Link p = head->next;
	Link q = head->next;
	Link r = head->next;
	Link s = head->next;
	int i;
	if(len == 3 )
	{
		s = r->next;
		if(r->nu > s->nu)
		{
			r = s->next;
			head->next = s;
			s->next = r;
		}
	}
	else if(len > 3)
	{
		for(i=0;i<len;i++)
		{
			p = head->next;
			q = head->next;
			r = head->next;
			s = head->next;
		for(;s != head;)
		{
			if(p == q)
			{
				if(q->nu > r->nu)
				{
					head->next = r;
					r->next = q;
					q->next = s;

					p = p->next;
					q = p->next;
					r = q->next;
					s = r->next;

				}
				else
				{
					p = q;
					q = r;
					r = s;
					s = s->next;
				}

			}
			else
			{
				if(q->nu > r->nu)
				{
					p->next = r;
					r->next = q;
					q->next = s;

					p = p->next;
					q = p->next;
					r = q->next;
					s = r->next;

				}
				else
				{
					p = q;
					q = r;
					r = s;
					s = s->next;
				}

			}

		}

		if(s == head)
			{
				if(q->nu > r->nu)
				{
					p->next = r;
					r->next = q;
					q->next = s;
				}
			}

		}
	}
}
void modify_link(Link head,char human[])
{
    Link result = NULL;
    result = search_link(head,human);
    if(result == head)
    {
    printf("没找到这个人\n");
    }
    else
    {
        printf("请输入你想要修改的姓名:\n");
        scanf("%s",result->name);
        printf("请输入你想要修改的性别:\n");
        scanf("%s",result->sex);
        printf("请输入你想要修改的电话号码:\n");
        scanf("%s",result->num);
        printf("请输入你想要修改的家庭住址:\n");
        scanf("%s",result->add);
        printf("请输入你想要修改的QQ号:\n");
        scanf("%s",result->qq);
    }
}
void black_list(Link head,char human[])
{
    Link q = NULL;
    Link p = NULL;
    q = head;
    p = head->next;
    while(p != head && strcmp(p->name,human) != 0)
    {
        q = p;
        p = p->next;
    }
    if(strcmp(p->name,human) == 0)
    {
        q->next = p->next;
    }
    else
    {
        printf("未找到联系人\n");
    }
    printf("请输入你想要移回的人\n");
    scanf("%s",human);
    if(strcmp(p->name,human) == 0)
    {
        q->next = p;
        q->next->next = p->next;
    }

}
void interface(void)
{
    printf("***********************************************************\n");
    printf("**        KEY 0 <<>>  向通讯录中添加联系人               **\n");
    printf("**        KEY 1 <<>>  显示通讯录中联系人                 **\n");
    printf("**        KEY 2 <<>>  显示通讯录中联系人个数             **\n");
    printf("**        KEY 3 <<>>  查找通讯录中联系人                 **\n");
    printf("**        KEY 4 <<>>  给通讯录中联系人排序               **\n");
    printf("**        KEY 5 <<>>  删除通讯录中联系人                 **\n");
    printf("**        KEY 6 <<>>  显示菜单栏                         **\n");
    printf("**        KEY 7 <<>>  修改联系人信息                     **\n");
    printf("**        KEY 8 <<>>  把联系人加入黑名单                 **\n");
    printf("**        KEY 9 <<>>  退出通讯录                         **\n");
    printf("***********************************************************\n");
}
void release_link(Link head)
{
    Link p = NULL;
    while(head->next != head)
    {
        p = head->next;
        head->next = p->next;
        free(p);
    }
}
void read(Link head)
{
    FILE *fp = fopen("list.text","a+");
    Link p = NULL;
    p = head->next;
    while(!feof(fp))
    {
        Link new = (Link)malloc(sizeof(Node));
        fscanf(fp,"%s",new->name);
        fscanf(fp,"%s",new->sex);
        fscanf(fp,"%s",new->num);
        fscanf(fp,"%s",new->add);
        fscanf(fp,"%s",new->qq);
        p = p->next;
    }
    fclose(fp);
}
void write(Link head)
{
    int len = 0;
    len = len_link(head);
    FILE *fp = fopen("list.text","w+");
    Link p = NULL;
    p = head->next;
    while(len--)
    {
        fprintf(fp,"%s\t",p->name);
        fprintf(fp,"%s\t",p->sex);
        fprintf(fp,"%s\t",p->num);
        fprintf(fp,"%s\t",p->add);
        fprintf(fp,"%s\n",p->qq);
        p = p->next;
    }
    fclose(fp);
}
void case_0(Link head)
{
    int n,i;
    Link new_node = NULL;
    printf("请输入要插入的人数\n");
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        creat_node(&new_node);
        printf("请输入名字：");
        scanf("%s",new_node->name);
        printf("请输入性别：");
        scanf("%s",new_node->sex);
        printf("请输入电话号码:");
        scanf("%s",new_node->num);
        printf("请输入家庭住址:");
        scanf("%s",new_node->add);
        printf("请输入QQ号:");
        scanf("%s",new_node->qq);
        new_node->nu = i + 1;
        insert_node_tail(head,new_node);
    }

}
void case_1(Link head)
{
    display_link(head);
    printf("*********************\n");

}
void case_2(Link head)
{
    int len = 0;
    len = len_link(head);
    printf("通讯录里有%d人\n",len);
    printf("*********************\n");

}
void case_3(Link head)
{
    Link result = NULL;
    char human[20];
    int len;
    printf("请输入你想要查找的人:");
    scanf("%s",human);
    result = search_link(head,human);
    if(result == head)
    {
    printf("没找到这个人\n");
    }
    else
    {
    printf("你想要查询的人是:%s\n序号:%d\n性别:%s\n电话号码为:%s\n家庭住址为:%s\nQQ号为:%s\n",result->name,result->nu,result->sex,result->num,result->add,result->qq);
    }
    printf("*********************\n");
}
void case_4(Link head)
{
    printf("排序成功\n");
    sort_link(head);
    display_link(head);
    printf("*********************\n");
}
void case_5(Link head)
{
    char human[20];
    printf("请输入要删除的人:\n");
    scanf("%s",human);
    remove_link(head,human);
    display_link(head);
    printf("*********************\n");
}
void case_6()
{
    interface();
}
void case_7(Link head)
{
    char human[20];
    printf("请输入你想要修改的人:\n");
    scanf("%s",human);
    modify_link(head,human);
    display_link(head);
    printf("*********************\n");
}
void case_8(Link head)
{
    char human[20];
    printf("请输入你想要加入黑名单的人:\n");
    scanf("%s",human);
    black_list(head,human);
    display_link(head);
    printf("*********************\n");
}
void case_9(Link head)
{
    release_link(head);
    exit(0);
}
int main(int argc,char *argv[])
{
    int fd;
    fd = open("list.text",O_RDWR|O_CREAT,0755);
    if(-1 == fd)
    {
        printf("open error\n");
        exit(-1);
    }
    Link head = NULL;
    Link new_node = NULL;
    Link result = NULL;
    creat_link(&head);
    int i,n,len,key;
    char human[20];
    read(head);
    interface();
    while(1)
   {
        printf(">>KEY A WORD<< :");
        scanf("%d",&key);
        switch(key)
        {
            case 0:
            case_0(head);
            break;
            case 1:
            case_1(head);
            break;
            case 2:
            case_2(head);
            break;
            case 3:
            case_3(head);
            break;
            case 4:
            case_4(head);
            break;
            case 5:
            case_5(head);
            break;
            case 6:
            case_6();
            break;
            case 7:
            case_7(head);
            break;
			case 8:
            case_8(head);
            break;
            case 9:
           // case_9(head);
            write(head);
            exit(0);
            break;
            default:
            printf("ERROR KEY!!!\n");
            break;
        }
   }
    return 0;
}
