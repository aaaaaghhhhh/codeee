#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//函数声明
int cont_str(char* s); //判断字符串是否为空
int judgeemail(char str[]);//判断邮箱是否合法
int judgenumber(char str[]);//判断无效号码 
int getch(char s[]);
void menu()



typedef struct people {
char name[100];
char number[100];
char email[100];
char department[100];
}info;

typedef struct linknode {
	info date;
	struct linknode* pnext;
}linknode;

linknode* phead = NULL;

void CreateHeadNode()
{
    phead = (linknode*)malloc(sizeof(linknode));
    if (phead == NULL)
    {
        printf("error\n");
        return;
    }
    else
    {
        phead->pnext = NULL;

    }
}
//}

//2.添加一个新节点
void AddNewNode(linknode* head)
{
	linknode* p_find = phead;
	struct node* p_new = NULL;
	//尾插法 遍历
	while (p_find->pnext != NULL)
	{
		p_find = p_find->pnext;
	}
	p_new = (struct node*)malloc(sizeof(struct node));

    printf("Name:");
    getchar();
    fgets(p_new->data.name, 20, stdin);
    printf("Number:");
    scanf("%s", p_new->data.number);
    //判断手机号码是否为空
    if (cont_str(p_new->data.number) == 0)
    {
        printf("Phone number cannot be empty,ignoring entry.");
        return;
    }
    int flag = judgenumber(p_new->data.number);
    if (flag == 0)
        return;
    //遍历链条，判断是否存在重复的手机号码
    while (p_find != NULL) 
    {
        if (strcmp(p_find->data.number, p_new->data.number) == 0)
        {
            printf("Entry already exist,ignoring duplicate entry.");
            return;
        }
        p_find = p_find->pnext;
    }
    printf("Email:");
    getchar();

    int i = getch(p_new->data.email);
    if (i != 0)
    {
        flag = judgeemail(p_new->data.email);
        if (flag == 0)
            return;
    }
    printf("Department:");
    i = getch(p_new->data.department);
    p_new->pnext = p_find->pnext;
    p_find->pnext = p_new;

}


int main()
{
    CreateHeadNode();
    menu();
    return 0;
}

//menu
void menu()
{
    //int a = 0;
    printf("1) Print contact list \n"
        "2) Add a contact \n"
        "3) Modify a contact \n"
        "4) Delete a contact \n"
        "5) Search \n"
        "6) Quit \n"
        "Option:");

    while (1) {
        char option;
        option = getchar();

        if (option != '\n' && option != '\r') {
            switch (option)
            {
            case 1:
                AddNewNode(phead);
                break;
            default:
                printf("Unknown option\n");

            }
        }
    }


}






//判断字符串是否为空
int cont_str(char* s)
{
    int i = 0;
    while (s[i++] != '\0');
    return i;
}






int judgeemail(char str[])//判断邮箱是否合法 
{
    int ret = 1;
    int len = strlen(str);
    if (len >= 5)
    {
        int idx_at = -1;
        int idx_point = -1;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '@')
            {
                if (i > 0 && idx_at < 0)
                {
                    idx_at = i;
                    continue;
                }
                else
                {
                    ret = 0;
                    break;
                }
            }
            else if (idx_at < 0)//判断@之前的
            {
                if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_' && str[i] != '.' && str[i] != '&')
                {
                    ret = 0;
                    break;

                }
                else if (str[i] == '_' || str[i] == '.' || str[i] == '&')
                {
                    if (i <= 0 || !(isalpha(str[i - 1]) || isdigit(str[i - 1])))
                    {
                        ret = 0;
                        break;
                    }
                }
            }
            else//判断@之后的 
            {
                if (str[i] == '.')//记录@后第一个出现.的位置，且保证不会出现第二个 
                {
                    if (len - i > 2)
                    {
                        idx_point = i;
                        continue;
                    }
                    else
                    {
                        ret = 0;
                        break;
                    }
                }
                else if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '&')
                {
                    ret = 0;
                    break;
                }
            }
        }
        if (idx_at < 0 || idx_point < 0)
            ret = 0;
        else
        {
            for (int k = idx_point + 1; k < len; k++)
            {
                if (str[k] == '&')
                {
                    ret = 0;
                    break;
                }
            }
        }
    }
    else
        ret = 0;

    if (ret == 0)
        printf("Invalid email id.\n");
    return ret;
}

int judgenumber(char str[])//判断无效号码 
{
    int ret = 1;
    int len = strlen(str);
    if (len > 1)
    {
        int num_l = 0;
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '(' && str[i] != ')')
            {
                ret = 0;
                break;
            }
            else
            {
                if (str[i] == '(')
                    num_l++;
                else if (str[i] == ')')
                {
                    if (num_l > 0)
                        num_l--;
                    else
                    {
                        ret = 0;
                        break;
                    }
                }
            }
        }
        if (num_l != 0)
            ret = 0;
    }
    else
        ret = 0;
    if (ret == 0)
        printf("Invalid phone number.\n");
    return ret;
}


//typedef struct Entry {
//char name[100];
//char number[100];
//char email[100];
//char department[100];
//}Info;
//
//typedef struct LinkNode {
//Info data;
//struct LinkNode* next;
//}LinkNode;

int getch(char s[])
{
    char ch;
    int i = 0;
    scanf("%c", &ch);
    while (1)
    {
        if (ch == '\n')
            break;
        s[i] = ch;
        scanf("%c", &ch);
        i = i + 1;
    }
    s[i] = '\0';
    return i;
}



//typedef struct people {
//	char name[100];
//	char number[100];
//	char email[100];
//	char department[100];
//}info;
//
//typedef struct linknode {
//	info date;
//	struct linknode* next;
//}linknode;
//
//linknode* head = NULL;
//
//void CreateHeadNode()
//{
//	head = (linknode*)malloc(sizeof(linknode));
//	if (head == NULL)
//	{
//		printf("error\n");
//		return;
//	}
//	else
//	{
//		head->next = NULL;
//
//	}
//}
//












