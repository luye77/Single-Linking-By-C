#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Lnode;

void printList(Lnode *head);
Lnode *createList();
Lnode *insertList(Lnode *head,int elem,int position);
Lnode *deleteElem(Lnode *head,int elem);
Lnode *reverseList(Lnode *head);

 

int main()
{
    Lnode *head;
    int elem,position;

    head = createList();
    printList(head);

    printf("Input the element and the position:\n");
    scanf("%d %d", &elem, &position);
    head = insertList(head,elem,position);
    printList(head);

    head = reverseList(head);
    printf("After reversed:\n");
    printList(head);
    
    printf("Input the element you want to delete:\n");
    scanf("%d",&elem);
    head = deleteElem(head, elem);
    printList(head);
    
    return 0;
}
/*传入表头指针，打印链表*/
void printList(Lnode *head)
{
    Lnode *p = head;

    if (p == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/*创建一个新链表，返回表头指针*/
Lnode *createList()
{
    Lnode *head, *current, *p;
    int data;

    p=head = (Lnode *)malloc(sizeof(Lnode));   
    
    printf("Input integers,-1 to break,p_ADDR= %d:\n",p);
    scanf("%d",&data);
    
    if (data != -1)
    {
        p->data = data;
    }
    else
    {
        p->next = NULL;   //只有头结点的情况
        return head;
    }

    while (1)
    {
		printf("Input integers,-1 to break,p_ADDR= %d:\n",p);
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }

        current = (Lnode *)malloc(sizeof(Lnode));
        current->data = data;
        p->next = current;
        p = p->next;
    }
    p->next = NULL;

    return head;
}

 
/*链表的插入操作，head为链表表头，elem为要插入的元素，position为插入的位置
 *将elem插入至第position个结点后，position<=0时，插入至头结点后
*/
Lnode *insertList(Lnode *head,int elem,int position)
{
    Lnode *current, *p;
    int i = position - 1;
    current = head;

    /*找到第position个节点*/
    while (i > 0 && current->next != NULL)
    {
        current = current->next;
        i--;
    }

    if (i > 0)   //结点数小于输入的位置position
    {
        printf("Position is wrong!\n");
        return head;
    }

    p = (Lnode *)malloc(sizeof(Lnode));
    p->data = elem;
    p->next = current->next;
    current->next = p;
    
    return head;
}

/*删除链表head中所有的元素elem，返回头结点head*/
Lnode *deleteElem(Lnode *head,int elem)
{
    Lnode *p = head;
    Lnode *ptemp;
    int flag = 0;  //记录便表中elem的个数

    while (1)
    {
        if (head->data == elem)  //删除头结点的情况
        {
            flag++;
            head = head->next;
            free(p);
            p = head;
        }
        else
        {
            break;
        }
    }

    while (p->next != NULL)
    {
        if (p->next->data == elem )
        {
            flag++;
            ptemp = p->next;
            if (p->next->next != NULL)
            {
                p->next = p->next->next;
                free(ptemp);
                ptemp = NULL;
            }
            else //最后一个结点
            {
               free(ptemp);
               ptemp =NULL;
               p->next = NULL;
               break;
            }
        }
        else  //没有删除结点时，查询下一个结点
        {
            p = p->next;
        }
    }
    printf("%d number '%d' was found and deleted.\n", flag, elem);
    return head;
}


/*将链表逆序，该链表不带头结点。*/
Lnode *reverseList(Lnode *head)
{
    Lnode *current, *pnext, *ptemp;

    current = head;
    pnext = head->next;
    head->next =NULL;

    while (pnext != NULL)
    {
        ptemp = pnext->next;
        pnext->next = current;
        current = pnext;
        pnext = ptemp;
    }

    head = current;
    return head;
}