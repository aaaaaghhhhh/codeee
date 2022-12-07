// 6512345 zy12345 Joe Blogs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_n 20
#define max_nu 20
#define max_e 20
#define max_d 20

#define MAX 20

#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct Entry
{
    char name[max_n];
    char number[max_nu];
    char email[max_e];
    char department[max_d];
} Info;

typedef struct LinkNode
{
    Info data;
    struct LinkNode* next;
} LinkNode;

typedef struct Contact
{
	Info* data;//指向动态申请的空间，用来存放联系人的信息
	int sz;//记录的是当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量
}Contact;

void InitContact(Contact* pc)
{
	pc->data = (Info*)malloc(DEFAULT_SZ * sizeof(Info));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;//初始化后默认是0
	pc->capacity = DEFAULT_SZ;

	
	
}

void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		Info* ptr = (Info*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(Info));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			//perror("AddContact");
			printf("增加联系人失败\n");
			return;
		}
	}
}


//��������
void menu();
int cont_str(char*);
void FREE(LinkNode* L);

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
    CheckCapacity(L);
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* p = L->next;
    if (s == NULL) {
        printf("Unable to allocate memory.\n");
        exit(-1);
    }
    setbuf(stdin, NULL);
    printf("Name:");
    // fgets(s->data.name, 20, stdin);
    int len = getch(s->data.name);
    if (len) { printf("Number:"); };

    len = getch(s->data.number);
    //�ж��ֻ������Ƿ�Ϊ��
    printf("Email:");
    //getchar();

    int lene = getch(s->data.email);

    printf("Department:");
    int i = getch(s->data.department);
    if (len == 0)
    {
        printf("Phone number cannot be empty,ignoring entry.\n");
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
            printf("Entry already exist,ignoring duplicate entry.\n");
            return;
        }
        p = p->next;
    }
    if (lene != 0)
    {
        flag = judgeemail(s->data.email);
        if (flag == 0)
            return;
    }
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
    if (len) {};
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
    char num[MAX];
    char name[max_n];
    char number[max_nu];
    char email[max_e];
    char department[max_d];
    printf("Enter phone number to modify:");
    len = getch(num);
    if (len) {};
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
            int len1 = getch(name);
            printf("Enter  new  number(return to keep[%s]:", s->data.number);
            int len2 = getch(number);
            printf("Enter  new  email(return to keep[%s]:", s->data.email);
            int len3 = getch(email);
            printf("Enter  new  department(return to keep[%s]:", s->data.department);
            int len4 = getch(department);

            if (len2)
            {
                if (judgenumber(number) == 0)
                    return;
                LinkNode* p = L->next;
                while (p != NULL)
                {
                    if (strcmp(p->data.number, number) == 0)
                    {
                        printf("Entry already exist,ignoring duplicate entry.\n");
                        return;
                    }
                    p = p->next;
                }
            }

            if (len3)
            {
                if (judgeemail(email) == 0)
                    return;
            }
            if (len1)
                strcpy(s->data.name, name);
            if (len2)
                strcpy(s->data.number, number);
            if (len3)
                strcpy(s->data.email, email);
            if (len4)
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
    if (len) {};
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


void PrintListReversingly_Recursively(LinkNode* p, LinkNode* head)
{
    if (p == NULL)
        return;
    if (p->next != NULL)
        PrintListReversingly_Recursively(p->next, head);


    if (p == head) return;
    printf("%s\t", p->data.number);
    printf("%s ", p->data.email);
    printf("%s ", p->data.name);
    printf("(%s)\n", p->data.department);


}




// output
void output(LinkNode* L)
{
    LinkNode* p;
    p = L->next;

    while (p != NULL)
    {
        printf("%s\t", p->data.number);
        printf("%s ", p->data.email);
        // name = p->data.name;
        // name[strlen(name) - 1] = 0;
        printf("%s ", p->data.name);
        printf("(%s)\n", p->data.department);
        p = p->next;
    }
}

void FREE(LinkNode* L) {
    LinkNode* p;
    p = L->next;

    while (p != NULL)
    {
        free(p);
        p = p->next;
    }
}

int main()
{
    LinkNode* L;
    L = (LinkNode*)malloc(sizeof(LinkNode));
    if (L == NULL) {
        printf("Unable to allocate memory.\n");
        exit(-1);
    };
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
                //output(L);
                PrintListReversingly_Recursively(L, L);
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
                FREE(L);
                exit(-2);
                
                break;
            default:
                printf("Unknown option! \n");
            }
        }
    }
}
