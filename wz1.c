#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_wz  3
typedef struct node{
    char name[15];//ѧ������
    char id[20];
    int score[max_wz];//ѧ���ĳɼ�
    int sum;
    double average;
    struct node *next;
}Student;
Student *head=NULL;//����ͷָ��Ϊ��
char classname[3][20]={"��ѧ","Ӣ��","�����"};
int Menu()
{
    system("cls");
    fflush(stdin);
    printf("�Զ���1504 ���� 5120154343\n");
    printf("****************************\n");
    printf("*****ѧ���ɼ�����ϵͳ******\n");
    printf("****************************\n");
    printf("1-��ʼ��\n");
    printf("2-����ѧ����Ϣ\n");
    printf("3-��������ѧ����ƽ�������ܺ�\n");
    printf("4-��ӡ�ɱ�\n");
    printf("5-����ѧ��������ɾ��ѧ����Ϣ\n");
    printf("6-����������ѧ��\n");
    printf("7-��ѧ�Ų���ѧ��\n");
    printf("8-�༶������Ϊ\n");
    printf("9-����ѧ���ɼ�\n");
    printf("0-�˳�\n");
    return 0;
}
Student *Init()
{
    int i;
    Student *head;
    head=(Student*)malloc(sizeof(Student));
    head->next=NULL;
    return head;
}
char check_id(char *s)
{
    int i;
    if(strlen(s)==0||strlen(s)>10)
        return 0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            return 1;
    }
    return 0;
}
char check_name(char *s)
{
    int i;
    if(strlen(s)==0||strlen(s)>20)
        return 0;
    for(i=0;i<strlen(s);i++)
    {
         if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            return 1;
    }
    return 0;
}
int check_score(int s)
{
    if(s>=0||s<=100)
        return 1;
    return 0;
}
char is_sameid(char *s)
{
    Student *p=head->next;
    while(p!=NULL)
    {
        if(strcmp(s,p->id)==0)
            return 1;
        p=p->next;
    }
    return 0;
}
//����ѧ����Ϣ
void Input_Score(Student *p)
{
    int i;
    printf("\n������ѧ��:\n");
    do
    {
        gets(p->id);
        if(!check_id(p->id))
        {
            printf("����ѧ�Ų���ȷ,����������ѧ��:\n");
        }
        else if(is_sameid(p->id))
        {
            printf("��id�Ѿ�����,����������ѧ��:\n");
        }
    }
    while(!(check_id(p->id)&&!is_sameid(p->id)));
    //��������
    printf("����������:\n");
    do
    {
        gets(p->name);
        if(!check_name(p->name))
        {
            printf("�������������ȷ������������:");
        }
    }
    while(!check_name(p->name));
    //����ɼ�
    for(i=0;i<3;i++)
    {
      do
     {
           printf("������%s�ɼ�:",classname[i]);
           scanf("%d",&p->score[i]);
           if(!check_score(p->score[i]))
           {
               printf("����ĳɼ�����ȷ\n����������%s�ĳɼ�:",classname[i]);
           }

     }while(!check_score(p->score[i]));
    }
    p->average=-1;
    p->sum=-1;
}
//ͷ�巨����ڵ�
void insert_before()
{
    Student *s=(Student*)malloc(sizeof(Student));
    Input_Score(s);
    s->next=head->next;
    head->next=s;
}
//���ѧ���ɼ���Ϣ
void Output_Score(Student *p)
{
    int i;
    printf("\n����������:%s,������ѧ��:%s\n",p->name,p->id);
   for(i=0;i<3;i++)
   {
           printf("�����%s�ĳɼ�:",classname[i]);
           printf("%d",p->score[i]);
   }
   printf("�ܷ�:%d,ƽ����:%.2f\n",p->sum,p->average);
}
//ɾ���ڵ�
void delete_Node(Student *q)
{
    Student *p=head;
    while(p->next!=q)
    {
        p=p->next;
    }
    p->next=q->next;
    free(q);
}
//����ѧ���ɼ�
void Insert_List()
{
    int x;
    int i;
    printf("����Ҫ���������:");
    scanf("%d",&x);
    while(x!=0)
    {
        getchar();
        Student *p=(Student*)malloc(sizeof(Student));
        printf("������ѧ��:");
        do
        {
            gets(p->id);
          if(!check_id(p->id))
          {
            printf("����ѧ�Ų���ȷ������������ѧ��:\n");
          }
          else if(is_sameid(p->id))
          {
            printf("��id�Ѿ����֣�����������ѧ�ţ�\n");
          }
        }
        while(!(check_id(p->id)&&!is_sameid(p->id)));
        printf("����������:");
        do
        {
            gets(p->name);
            if(!check_name(p->name))
            {
              printf("�������������ȷ������������:");
            }
        }while(!check_name(p->name));
        for(i=0;i<3;i++)
        {
            fflush(stdin);
            printf("������%s�ɼ�:",classname[i]);
            scanf("%d",&p->score[i]);
            do
            {
                if(!check_score(p->score[i]))
               {
                 printf("����ĳɼ�����ȷ\n����������%s�ĳɼ�:",classname[i]);
               }

            }while(!check_score(p->score[i]));
        }
        p->average=-1;
        p->sum=-1;
        p->next=head->next;
        head->next=p;
        x--;
    }
}
//��ѧ�Ų���
Student *Search_ID(char *id)
{
    Student *p=head->next;
    while(p!=NULL)
    {
        if(strcmp(p->id,id)==0)
            break;
        p=p->next;
    }
    return p;
}
//����������
Student *Search_name(char *name)
{
    Student *p=head->next;
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
            break;
        p=p->next;
    }
    return p;
}
//�������
void Out_List()
{
    Student *p;
    p=head->next;
    while(p!=NULL)
    {
        Output_Score(p);
        p=p->next;
    }
}
//ɾ��ָ��ѧ����Ϣ
void delete_Student()
{
    Student *p;
    fflush(stdin);
    char str[15];
    char judge[10];
    printf("������Ҫɾ����ѧ����ѧ�Ż�����:");
    do
    {
       gets(str);
       if(!(check_id(str)||check_name(str)))
       {
           printf("�������ѧ�Ż���������������������:\n");
       }
    }while(!(check_name(str)||check_id(str)));
    //�ж���Ϊѧ�Ż�����Ϊ����
    if(str[0]>'0'&&str[0]<'9')
    {
        p=Search_ID(str);
        if(p==NULL)
        {
            printf("��ѧ�Ų�����\n");
        }
        else
        {
            Output_Score(p);
            printf("�Ƿ�Ҫɾ����ѧ�ţ�ȷ�ϰ�y������������������˳�");
            gets(judge);
            if(strcmp(judge,"y")==0)
            {
                delete_Node(p);
            }
            printf("ɾ���ɹ�\n");
        }
    }
    else
    {
        p=Search_name(str);
         if(p==NULL)
         {
             printf("������������\n");
         }
         else
        {
           Output_Score(p);
           printf("�Ƿ�Ҫɾ����������ȷ�ϰ�y���������ⰴ�������˳�");
           gets(judge);
           if(strcmp(judge,"y")==0)
           {
               delete_Node(p);
           }
           printf("ɾ���ɹ�\n");
        }
        fflush(stdin);
    }
}
//�˳�
void Quit()
{
  Student *p;
  p=head->next;
  while(p!=NULL)
  {
      Quit(p->next);
      free(p);
  }
  exit(0);
}
//������˵�ƽ�������ܷ�
void  Count_score()
{
    Student *p;
    int i;
    p=head->next;
    while(p!=NULL)
    {
        for(i=0;i<3;i++)
        {
            p->sum=p->sum+p->score[i];
        }
        p->average=p->sum*1.0/3;
        p=p->next;
    }
}
//����༶������
int  Count_people()
{
    Student *p;
    int summ=0;
    p=head->next;
    while(p!=NULL)
    {
        summ=summ+1;
        p=p->next;
    }
    return summ;
}
//����༶��ƽ����
void  Count_mark()
{
    Student *p;
    int m;
    p=head->next;
    float aclam=0;
    while(p!=NULL)
    {
        aclam=aclam+p->sum;
        p=p->next;
    }
    m=Count_people();
    printf("�༶ƽ����Ϊ��%.2f",aclam/m);
}
//����������ѧ���ɼ�
void Searchname_Student()
{
    char name[10];
    int i=0;
    Student *p=head->next;
    getchar();
    printf("��������Ҫ���ҵ�ѧ������:");
    do
    {
        gets(name);
        if(!check_name(name))
        {
            printf("������������ȷ������������:");
        }

    }while(!check_name(name));
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            Output_Score(p);
            i=1;
        }
       p=p->next;
    }
    if(i==0)
    {
        printf("�Ҳ���������\n");
    }
}
void Searchid_Student()
{
    char id[10];
    int i=0;
    Student *p=head->next;
    getchar();
    printf("��������Ҫ���ҵ�ѧ����ѧ��:");
    do
    {
        gets(id);
        if(!check_id(id))
        {
            printf("����ѧ�Ų���ȷ������������:");
        }

    }while(!check_id(id));
    while(p!=NULL)
    {
        if(strcmp(p->id,id)==0)
        {
            Output_Score(p);
            i=1;
        }
       p=p->next;
    }
    if(i==0)
    {
        printf("�Ҳ�����ѧ��\n");
    }

}
void main()
{
    int x,n,ak;
    Student *q;
    Menu();
    while(1)
    {
        printf("������������:");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            head=Init();
            printf("��ʼ���ɹ�\n");
            break;
        case 2:
            printf("���������:");
            scanf("%d",&n);
            getchar();
            while(n!=-1)
            {
                insert_before();
                printf("���������:");
                scanf("%d",&n);
                getchar();
            }
            break;
        case 3:
            Count_score();
            printf("����ƽ���ֺ��ܺͳɹ�!");
            break;
        case 4:
            Out_List();
            printf("��ӡ�ɹ�!");
            break;
        case 5:
            delete_Student();
            break;
        case 6:
            Searchname_Student();
            break;
        case 7:
            Searchid_Student();
            break;
        case 8:
            ak=Count_people();
            printf("�༶������Ϊ:%d\n",ak);
            break;
        case 9:
            Insert_List();
            break;
        case 0:
            Quit();
            break;
        default:printf("�������\n\n");
        }
    }
}
