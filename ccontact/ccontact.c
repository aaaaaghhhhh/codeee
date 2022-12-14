#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//��������
void menu();
int cont_str(char*);

void menu()
{
    printf("1) Print contact list \n"
        "2) Add a contact \n"
        "3) Modify a contact \n"
        "4) Delete a contact \n"
        "5) Search \n"
        "6) Quit \n"
        "Option:");
}
//�ж��ַ����Ƿ�Ϊ��
int cont_str(char* s)
{
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i;
}

int judgeemail(char str[]) //�ж������Ƿ�Ϸ�
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
            else if (idx_at < 0) //�ж�@֮ǰ��
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
            else //�ж�@֮���
            {
                if (str[i] == '.') //��¼@���һ������.��λ�ã��ұ�֤������ֵڶ���
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

int judgenumber(char str[]) //�ж���Ч����
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

typedef struct Entry
{
    char name[100];
    char number[100];
    char email[100];
    char department[100];
} Info;

typedef struct LinkNode
{
    Info data;
    struct LinkNode* next;
} LinkNode;

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
//��
void addNode(LinkNode* L)
{
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* p = L->next;
    setbuf(stdin, NULL);
    printf("Name:");
    // fgets(s->data.name, 20, stdin);
    int len = getch(s->data.name);
    printf("Number:");
    scanf("%s", s->data.number);
    //�ж��ֻ������Ƿ�Ϊ��
    if (cont_str(s->data.number) == 0)
    {
        printf("Phone number cannot be empty,ignoring entry.");
        return;
    }
    int flag = judgenumber(s->data.number);
    if (flag == 0)
        return;
    //�����������ж��Ƿ�����ظ����ֻ�����
    while (p != NULL)
    {
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

//ɾ
void deleteNode(LinkNode* L)
{
    LinkNode* s, * r;
    char stunum[100];

    s = L->next;
    r = L;

    printf("Enter phone number to delete(return to cancel):");
    // getchar();
    // fgets(stunum, 20, stdin);
    int len = getch(stunum);
    while (s != NULL && strcmp(stunum, s->data.number) != 0)
    {
        // printf("fjjfd");
        r = s;
        s = s->next;
    }
    if (s == NULL)
    {
        //����Ҳ����ü�¼���������˵���
        return;
    }
    else
    {
        //ɾ���ɹ�
        r->next = s->next;
        free(s);
        printf("Successfully deleted the entry for %s\n", stunum);
    }
}

//��
void Modify(LinkNode* L)
{
    LinkNode* s;
    s = L->next;
    int len = 0;
    char num[100];
    char name[100];
    char number[100];
    char email[100];
    char department[100];
    printf("Enter phone number to modify:");
    len = getch(num);
    int flag = 0;
    while (s != NULL)
    {
        if (strcmp(num, s->data.number) != 0 && flag == 0)
        {
            printf("Entry does not exist.\n");
            return;
        }
        else if (strcmp(num, s->data.number) == 0)
        {
            //fflush(stdin);
            //getchar();
            printf("Enter  new  name(return to keep[%s]):", s->data.name);

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
        flag = 1;
    }
}
int is_in(char* c, char* s)
{
    int i = 0, j = 0, flag = 0;
    while (i < strlen(s) && j < strlen(c))
    {
        if (s[i] == c[j])
        { //����ַ���ͬ�������ַ�������
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; //�����ַ��ص��Ƚ��ʼ�Ƚϵĺ�һ���ַ�
            j = 0;         //�ִ��ַ����¿�ʼ
        }
        if (j == strlen(c))
        {             //���ƥ��ɹ�
            flag = 1; //�ִ�����
            break;
        }
    }
    return flag;
}

//��
void Seek(LinkNode* L)
{
    LinkNode* p;
    printf("Search:");
    char search_string[100];
    int len = getch(search_string);
    // printf("%s\n",search_string);
    p = L->next;
    while (p != NULL)
    {

        // ptintf("%d\n",is_in(search_string,p->data.department));
        // ptintf("%d\n",is_in(search_string,p->data.name));
        // ptintf("%d\n",is_in(search_string,p->data.number));
        // ptintf("%d\n",is_in(search_string,p->data.email));
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
// output
void output(LinkNode* L)
{
    LinkNode* p;
    p = L->next;

    while (p != NULL)
    {
        char* name;
        printf("%s\t", p->data.number);
        printf("%s ", p->data.email);
        // name = p->data.name;
        // name[strlen(name) - 1] = 0;
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
    while (1)
    {
        menu();
        //������뻺���е��ַ�������Ϊgetchar�����лس���Ҳ�ᱻ����
        fflush(stdin);
        char op[100], option;
        int len = getch(op);
        if (len > 1) {
            printf("Unknown option! \n");
            continue;
        }
        else {
            option = op[0];
        }

        if (option != '\n' && option != '\r')
        {
            switch (option)
            {
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
