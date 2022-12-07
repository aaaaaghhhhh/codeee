// 20412865 scyry1 Run YANG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct people
{
    char* name;
    char* number;
    char* email;
    char* department;
} Info;

//Creation
typedef struct LinkNode
{
    Info data;
    struct LinkNode* next;
} LinkNode;


//Function declarations
void menu();

int leng_str(char*); //return the string length

char* getch(); //get a string

int isIn(char* a, char* b); //Used to query contacts

int check_e(char str[]); //Determine whether the email address is legitimate

int check_n(char str[]); //Determine if the number is valid

void Free_Entry(Info* e); //Used in Add_node

void Add_node(LinkNode* L); //Add contacts

void Delete_node(LinkNode* L); //Delete contacts

void Modify(LinkNode* L); //Modify contacts

void Find(LinkNode* L); //find contacts

void PrintList(LinkNode* p, LinkNode* head); //print contacts

void FREE(LinkNode* L); //free memory


//function definition
void menu()
{
    printf("1) Print contact list\n"
        "2) Add a contact\n"
        "3) Modify a contact\n"
        "4) Delete a contact\n"
        "5) Search\n"
        "6) Quit\n"
        "Option:");
}

//get a string
char* getch() 
{
    char ch, * str = (char*)malloc(sizeof(char));
    int i = 0;
    scanf("%c", &ch);
    while (1)
    {
        if (ch == '\n') 
        {
            str[i] = '\0';
            break;
        }
        str[i++] = ch;
        str = (char*)realloc(str, sizeof(char) * (i + 1));
        scanf("%c", &ch);
    }
    return str;
}

//return the string length
int leng_str(char* s)
{
    int i = 0;
    while (s[i] != '\0') 
    {
        i++;
    }
    return i;
}


//Used to query contacts
int isIn(char* a, char* b)
{
    int i = 0, j = 0, flag = 0;
    while (i < strlen(b) && j < strlen(a))
    {
        if (b[i] == a[j]) //if the chracters are equal, add one to both them
        { 
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; 
            j = 0;         
        }
        if (j == strlen(a))
        {             
            flag = 1; //Occurs if the match is successful
            break;
        }
    }
    return flag;
}

int check_e(char str[])  
{
    int pp = 1, i, t;
    int leng = strlen(str);
    if (leng >= 5)
    {
        int index_q = -1;
        int index_p = -1;
        for (i = 0; i < leng; i++)
        {
            if (str[i] == '@')
            {
                if (i > 0 && index_q < 0)
                {
                    index_q = i;
                    continue;
                }
                else
                {
                    pp = 0;
                    break;
                }
            }
            else if (index_q < 0) //judgement before @
            {
                if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_' && str[i] != '.' && str[i] != '&')
                {
                    pp = 0;
                    break;
                }
                else if (str[i] == '_' || str[i] == '.' || str[i] == '&')
                {
                    if (i <= 0 || !(isalpha(str[i - 1]) || isdigit(str[i - 1])))
                    {
                        pp = 0;
                        break;
                    }
                }
            }
            else //judgement after @
            {
                if (str[i] == '.') //record the position of '.' first appear, and it can not appear again
                {
                    if (leng - i > 2)
                    {
                        index_p = i;
                        continue;
                    }
                    else
                    {
                        pp = 0;
                        break;
                    }
                }
                else if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '&')
                {
                    pp = 0;
                    break;
                }
            }
        }
        if (index_q < 0 || index_p < 0)
            pp = 0;
        else
        {
            for (t = index_p + 1; t < leng; t++)
            {
                if (str[t] == '&')
                {
                    pp = 0;
                    break;
                }
            }
        }
    }
    else
        pp = 0;

    if (pp == 0)
        printf("Invalid email id.\n");
    return pp;
}

int check_n(char str[]) 
{
    int pp = 1, i;
    int leng = strlen(str);
    if (leng > 1)
    {
        int num1 = 0;
        for (i = 0; i < leng; i++)
        {
            if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '(' && str[i] != ')')
            {
                pp = 0;
                break;
            }
            else
            {
                if (str[i] == '(')
                    num1++;
                else if (str[i] == ')')
                {
                    if (num1 > 0)
                        num1--;
                    else
                    {
                        pp = 0;
                        break;
                    }
                }
            }
        }
        if (num1 != 0)
            pp = 0;
    }
    else
        pp = 0;
    if (pp == 0)
        printf("Invalid phone number.\n");
    return pp;
}


void Free_Entry(Info* e)
{
    free(e->name);
    free(e->number);
    free(e->email);
    free(e->department);
}


void Add_node(LinkNode* L)
{
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* p = L->next;
    if (s == NULL) {
        free(s);
        printf("Unable to allocate memory.\n");
        exit(-1);
    }
    setbuf(stdin, NULL);
    printf("Name:");
    s->data.name = getch();
    printf("Number:");
    s->data.number = getch();
    printf("Email:");
    s->data.email = getch();
    printf("Department:");
    s->data.department = getch();
    if (leng_str(s->data.number) == 0)
    {
        Free_Entry(&s->data);
        free(s);
        printf("Phone number cannot be empty,ignoring entry.\n");
        return;
    }
    int flag = check_n(s->data.number); //judgement
    if (flag == 0) {
        Free_Entry(&s->data);
        free(s);
        return;
    }

    //Traverse the chain to determine if there are duplicate mobile phone numbers
    while (p != NULL)
    {
        if (strcmp(p->data.number, s->data.number) == 0)
        {
            printf("Entry already exist,ignoring duplicate entry.\n");
            Free_Entry(&s->data);
            free(s);
            return;
        }
        p = p->next;
    }
    if (leng_str(s->data.email) != 0)
    {
        flag = check_e(s->data.email);
        if (flag == 0) {
            Free_Entry(&s->data);
            free(s);
            return;
        }

    }
    s->next = L->next;
    L->next = s;
}

void Delete_node(LinkNode* L)
{
    LinkNode* s, * r;
    char* fnum;

    s = L->next;
    r = L;

    printf("Enter phone number to delete(return to cancel):");
    fnum = getch();

    while (s != NULL && strcmp(fnum, s->data.number) != 0)
    {
        r = s;
        s = s->next;
    }
    if (s == NULL)
    {
        free(fnum);
        return; //if it is not found, return to the menu 
    }
    else
    {
        r->next = s->next;
        Free_Entry(&s->data);
        free(s);
        free(fnum);
        printf("Successfully deleted the entry for %s\n", fnum);
    }
}

void Modify(LinkNode* L)
{
    LinkNode* s;
    s = L->next;
    char* num;
    char* name;
    char* number;
    char* email;
    char* department;
    printf("Enter phone number to modify:");
    num = getch();

    if (strcmp(num, "") == 0)
    {
        free(num);
        return;
    }

    while (s != NULL)
    {
        if (strcmp(num, s->data.number) == 0)
        {
            printf("Enter  new  name(return to keep[%s]):", s->data.name);
            name = getch();  
            printf("Enter  new  number(return to keep[%s]:", s->data.number);
            number = getch(); 
            printf("Enter  new  email(return to keep[%s]:", s->data.email);
            email = getch();  
            printf("Enter  new  department(return to keep[%s]:", s->data.department);
            department = getch(); 

            if (leng_str(number))
            {
                if (check_n(number) == 0)
                {
                    free(num);
                    free(name);
                    free(number);
                    free(email);
                    free(department);
                    return;
                }

                LinkNode* p = L->next;
                while (p != NULL)
                {
                    if (strcmp(p->data.number, number) == 0)
                    {
                        printf("Entry already exist,ignoring duplicate entry.\n");
                        free(num);
                        free(name);
                        free(number);
                        free(email);
                        free(department);
                        return;
                    }
                    p = p->next;
                }
            }

            if (leng_str(email))
            {
                if (check_e(email) == 0) 
                {
                    free(num);
                    free(name);
                    free(number);
                    free(email);
                    free(department);
                    return;
                }
            }
            if (leng_str(name))
                strcpy(s->data.name, name);
            if (leng_str(number))
                strcpy(s->data.number, number);
            if (leng_str(email))
                strcpy(s->data.email, email);
            if (leng_str(department))
                strcpy(s->data.department, department);

            free(num);
            free(name);
            free(number);
            free(email);
            free(department);
            return;

        }
        s = s->next;
    }

    if (s == NULL)
    {
        printf("Entry does not exist.\n");
    }
}

void Find(LinkNode* L)
{
    LinkNode* p;
    printf("Search:");
    char* search_str;
    search_str = getch();

    p = L->next;
    while (p != NULL)
    {
        if (isIn(search_str, p->data.department) || isIn(search_str, p->data.name) || isIn(search_str, p->data.number) || isIn(search_str, p->data.email))
        {
            printf("%s\t", p->data.number);
            printf("%s\t", p->data.email);
            printf("%s ", p->data.name);
            printf("(%s)\n", p->data.department);

        }

        p = p->next;
    }

    free(search_str);
    return;
}

void PrintList(LinkNode* p, LinkNode* head)
{
    if (p == NULL)
        return;
    if (p->next != NULL)
        PrintList(p->next, head);


    if (p == head) return;
    printf("%s\t", p->data.number);
    printf("%s\t ", p->data.email);
    printf("%s ", p->data.name);
    printf("(%s)\n", p->data.department);
}

void FREE(LinkNode* L) {
    LinkNode* p, * q;
    p = L;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        Free_Entry(&q->data);
        free(q);
    }
}

int main()
{
    LinkNode* L;
    char* cc, option;
    L = (LinkNode*)malloc(sizeof(LinkNode));
    if (L == NULL) 
    {
        printf("Unable to allocate memory.\n");
        exit(-1);
    };
    L->next = NULL;
    while (1)
    {
        menu();
        //clear the string in the input cache
        fflush(stdin);
        cc = getch();
        if (leng_str(cc) > 1) {
            printf("Unknown option!\n");
            continue;
        }
        else {
            option = cc[0];
        }

        if (option != '\n' && option != '\r')
        {
            switch (option)
            {
            case '1':
                PrintList(L, L);
                break;
            case '2':
                fflush(stdin);
                Add_node(L);
                break;
            case '3':
                Modify(L);
                break;
            case '4':
                Delete_node(L);

                break;
            case '5':
                Find(L);
                break;
            case '6':
                FREE(L);
                free(cc);
                exit(-2);
                break;
            default:
                printf("Unknown option!\n");
            }
        }
        free(cc);
    }

    return 0;
}

