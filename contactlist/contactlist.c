#define _CRT_SECURE_NO_WARNINGS 1

//6512345 zy12345 Joe Blogs


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//函数声明
void  menu();
int cont_str(char*);


void  menu() {
    printf("1) Print contact list \n"
        "2) Add a contact \n"
        "3) Modify a contact \n"
        "4) Delete a contact \n"
        "5) Search \n"
        "6) Quit \n"
        "Option:");
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


typedef struct Entry {
    char name[100];
    char number[100];
    char email[100];
    char department[100];
}Info;

typedef struct LinkNode {
    Info data;
    struct LinkNode* next;
}LinkNode;

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
//增
void addNode(LinkNode* L) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* p = L->next;
    fflush(stdin);
    printf("Name:");
    getchar();
    fgets(s->data.name, 20, stdin);
    printf("Number:");
    scanf("%s", s->data.number);
    //判断手机号码是否为空
    if (cont_str(s->data.number) == 0)
    {
        printf("Phone number cannot be empty,ignoring entry.");
        return;
    }
    int flag = judgenumber(s->data.number);
    if (flag == 0)
        return;
    //遍历链条，判断是否存在重复的手机号码
    while (p != NULL) {
        if (strcmp(p->data.number, s->data.number) == 0)
        {
            printf("Entry already exist,ignoring duplicate entry.");
            return;
        }
        p = p->next;
    }
    printf("Email:");
    getchar();

    int i = getch(s->data.email);
    if (i != 0)
    {
        flag = judgeemail(s->data.email);
        if (flag == 0)
            return;
    }
    printf("Department:");
    i = getch(s->data.department);
    s->next = L->next;
    L->next = s;

}

//删
void deleteNode(LinkNode* L) {
    LinkNode* s, * r;
    char stunum[100];

    s = L->next;
    r = L;

    printf("Enter phone number to delete(return to cancel):");
    getchar();

    while (s != NULL && strcmp(stunum, s->data.number) != 0)
    {
        r = s;
        s = s->next;
    }
    if (s == NULL) {
        //如果找不到该记录，返回主菜单。
        return;
    }
    else
    {
        free(s);
        //删除成功
        r->next = s->next;
        printf("Successfully deleted the entry for %s\n", stunum);
    }
}

//改
void Modify(LinkNode* L) {
    LinkNode* s;
    s = L->next;
    int len = 0;
    char num[100];
    char name[100];
    char number[100];
    char email[100];
    char department[100];
    printf("Enter phone number to modify:");
    scanf("%s", num);

    while (s != NULL) {
        if (strcmp(num, s->data.number) != 0) {
            printf("Entry does not exist.\n");
            return;
        }
        else if (strcmp(num, s->data.number) == 0) {
            printf("Enter  new  name(return to keep[%s]):", s->data.name);
            getchar();
            len = getch(name);
            if (len)
                strcpy(s->data.name, name);
            printf("Enter  new  number(return to keep[%s]:", s->data.number);
            len = getch(number);
            if (len)
                strcpy(s->data.number, number);
            printf("Enter  new  email(return to keep[%s]:", s->data.email);
            len = getch(email);
            if (len)
                strcpy(s->data.email, email);
            printf("Enter  new  department(return to keep[%s]:", s->data.department);
            len = getch(department);
            if (len)
                strcpy(s->data.department, department);

        }
        s = s->next;
    }

}
int is_in(char* c, char* s)
{
    int i = 0, j = 0, flag = 0;
    while (i < strlen(s) && j < strlen(c)) {
        if (s[i] == c[j]) {//如果字符相同则两个字符都增加
            i++;
            j++;
        }
        else {
            i = i - j + 1; //主串字符回到比较最开始比较的后一个字符
            j = 0;     //字串字符重新开始
        }
        if (j == strlen(c)) { //如果匹配成功
            flag = 1;  //字串出现
            break;
        }
    }
    return flag;
}

//查
void Seek(LinkNode* L) {
    LinkNode* p;
    printf("Search:");
    char search_string[100];
    getchar();
    p = L->next;
    while (p != NULL) {

        if (is_in(search_string, p->data.department) || is_in(search_string, p->data.name) || is_in(search_string, p->data.number) || is_in(search_string, p->data.email))
        {
            printf("%s\t", p->data.number);
            printf("%s ", p->data.email);
            printf("%s ", p->data.name);
            printf("(%s)\n", p->data.department);

        }

        p = p->next;
    }
    return;
}
//output
void output(LinkNode* L) {
    LinkNode* p;
    p = L->next;
    while (p != NULL) {
        printf("%s\t", p->data.number);
        printf("%s ", p->data.email);
        printf("%s ", p->data.name);
        printf("(%s)\n", p->data.department);
        p = p->next;
    }
}
int main()
{
    LinkNode* L;
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
    while (1) {
        menu();
        //清空输入缓存中的字符串，因为getchar方法中回车键也会被输入
        fflush(stdin);
        char option;
        option = getchar();

        if (option != '\n' && option != '\r') {
            switch (option) {
            case '1':
                output(L);

                break;
            case '2':
                fflush(stdin);
                addNode(L);

                break;
            case '3':
                Modify(L);
                break;
            case '4':
                deleteNode(L);

                break;
            case '5':
                Seek(L);
                break;
            case '6':
                free(L);
                return 0;

                break;
            default:
                printf("Unknown option! \n");
            }
        }
    }
}
