#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_wz  3
typedef struct node{
    char name[15];//学生姓名
    char id[20];
    int score[max_wz];//学生的成绩
    int sum;
    double average;
    struct node *next;
}Student;
Student *head=NULL;//是其头指针为空
char classname[3][20]={"数学","英语","计算机"};
int Menu()
{
    system("cls");
    fflush(stdin);
    printf("自动化1504 王中 5120154343\n");
    printf("****************************\n");
    printf("*****学生成绩管理系统******\n");
    printf("****************************\n");
    printf("1-初始化\n");
    printf("2-输入学生信息\n");
    printf("3-计算所有学生的平均分与总和\n");
    printf("4-打印成表\n");
    printf("5-查找学号与姓名删除学生信息\n");
    printf("6-按姓名查找学生\n");
    printf("7-按学号查找学生\n");
    printf("8-班级总人数为\n");
    printf("9-插入学生成绩\n");
    printf("0-退出\n");
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
//输入学生信息
void Input_Score(Student *p)
{
    int i;
    printf("\n请输入学号:\n");
    do
    {
        gets(p->id);
        if(!check_id(p->id))
        {
            printf("输入学号不正确,请重新输入学号:\n");
        }
        else if(is_sameid(p->id))
        {
            printf("此id已经出现,请重新输入学号:\n");
        }
    }
    while(!(check_id(p->id)&&!is_sameid(p->id)));
    //输入姓名
    printf("请输入姓名:\n");
    do
    {
        gets(p->name);
        if(!check_name(p->name))
        {
            printf("输入的姓名不正确，请重新输入:");
        }
    }
    while(!check_name(p->name));
    //输入成绩
    for(i=0;i<3;i++)
    {
      do
     {
           printf("请输入%s成绩:",classname[i]);
           scanf("%d",&p->score[i]);
           if(!check_score(p->score[i]))
           {
               printf("输入的成绩不正确\n请重新输入%s的成绩:",classname[i]);
           }

     }while(!check_score(p->score[i]));
    }
    p->average=-1;
    p->sum=-1;
}
//头插法插入节点
void insert_before()
{
    Student *s=(Student*)malloc(sizeof(Student));
    Input_Score(s);
    s->next=head->next;
    head->next=s;
}
//输出学生成绩信息
void Output_Score(Student *p)
{
    int i;
    printf("\n请输入姓名:%s,请输入学号:%s\n",p->name,p->id);
   for(i=0;i<3;i++)
   {
           printf("请输出%s的成绩:",classname[i]);
           printf("%d",p->score[i]);
   }
   printf("总分:%d,平均分:%.2f\n",p->sum,p->average);
}
//删除节点
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
//插入学生成绩
void Insert_List()
{
    int x;
    int i;
    printf("你想要插入的人数:");
    scanf("%d",&x);
    while(x!=0)
    {
        getchar();
        Student *p=(Student*)malloc(sizeof(Student));
        printf("请输入学号:");
        do
        {
            gets(p->id);
          if(!check_id(p->id))
          {
            printf("输入学号不正确，请重新输入学号:\n");
          }
          else if(is_sameid(p->id))
          {
            printf("此id已经出现，请重新输入学号：\n");
          }
        }
        while(!(check_id(p->id)&&!is_sameid(p->id)));
        printf("请输入姓名:");
        do
        {
            gets(p->name);
            if(!check_name(p->name))
            {
              printf("输入的姓名不正确，请重新输入:");
            }
        }while(!check_name(p->name));
        for(i=0;i<3;i++)
        {
            fflush(stdin);
            printf("请输入%s成绩:",classname[i]);
            scanf("%d",&p->score[i]);
            do
            {
                if(!check_score(p->score[i]))
               {
                 printf("输入的成绩不正确\n请重新输入%s的成绩:",classname[i]);
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
//按学号查找
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
//按姓名查找
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
//输出链表
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
//删除指定学生信息
void delete_Student()
{
    Student *p;
    fflush(stdin);
    char str[15];
    char judge[10];
    printf("请输入要删除的学生的学号或姓名:");
    do
    {
       gets(str);
       if(!(check_id(str)||check_name(str)))
       {
           printf("你输入的学号或者姓名错误，请重新输入:\n");
       }
    }while(!(check_name(str)||check_id(str)));
    //判断是为学号还是是为姓名
    if(str[0]>'0'&&str[0]<'9')
    {
        p=Search_ID(str);
        if(p==NULL)
        {
            printf("此学号不存在\n");
        }
        else
        {
            Output_Score(p);
            printf("是否要删除此学号，确认按y，其他按任意键可以退出");
            gets(judge);
            if(strcmp(judge,"y")==0)
            {
                delete_Node(p);
            }
            printf("删除成功\n");
        }
    }
    else
    {
        p=Search_name(str);
         if(p==NULL)
         {
             printf("此姓名不存在\n");
         }
         else
        {
           Output_Score(p);
           printf("是否要删除此姓名，确认按y，其他任意按键可以退出");
           gets(judge);
           if(strcmp(judge,"y")==0)
           {
               delete_Node(p);
           }
           printf("删除成功\n");
        }
        fflush(stdin);
    }
}
//退出
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
//计算个人的平均分与总分
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
//计算班级总人数
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
//计算班级的平均分
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
    printf("班级平均分为：%.2f",aclam/m);
}
//按姓名查找学生成绩
void Searchname_Student()
{
    char name[10];
    int i=0;
    Student *p=head->next;
    getchar();
    printf("请输入你要查找的学生姓名:");
    do
    {
        gets(name);
        if(!check_name(name))
        {
            printf("输入姓名不正确！请重新输入:");
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
        printf("找不到此姓名\n");
    }
}
void Searchid_Student()
{
    char id[10];
    int i=0;
    Student *p=head->next;
    getchar();
    printf("请输入你要查找的学生的学号:");
    do
    {
        gets(id);
        if(!check_id(id))
        {
            printf("输入学号不正确！请重新输入:");
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
        printf("找不到此学号\n");
    }

}
void main()
{
    int x,n,ak;
    Student *q;
    Menu();
    while(1)
    {
        printf("请输入命令编号:");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            head=Init();
            printf("初始化成功\n");
            break;
        case 2:
            printf("请输入序号:");
            scanf("%d",&n);
            getchar();
            while(n!=-1)
            {
                insert_before();
                printf("请输入序号:");
                scanf("%d",&n);
                getchar();
            }
            break;
        case 3:
            Count_score();
            printf("计算平均分和总和成功!");
            break;
        case 4:
            Out_List();
            printf("打印成功!");
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
            printf("班级总人数为:%d\n",ak);
            break;
        case 9:
            Insert_List();
            break;
        case 0:
            Quit();
            break;
        default:printf("输入错误\n\n");
        }
    }
}
