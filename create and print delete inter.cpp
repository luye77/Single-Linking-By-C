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
/*�����ͷָ�룬��ӡ����*/
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
/*����һ�����������ر�ͷָ��*/
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
        p->next = NULL;   //ֻ��ͷ�������
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

 
/*����Ĳ��������headΪ�����ͷ��elemΪҪ�����Ԫ�أ�positionΪ�����λ��
 *��elem��������position������position<=0ʱ��������ͷ����
*/
Lnode *insertList(Lnode *head,int elem,int position)
{
    Lnode *current, *p;
    int i = position - 1;
    current = head;

    /*�ҵ���position���ڵ�*/
    while (i > 0 && current->next != NULL)
    {
        current = current->next;
        i--;
    }

    if (i > 0)   //�����С�������λ��position
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

/*ɾ������head�����е�Ԫ��elem������ͷ���head*/
Lnode *deleteElem(Lnode *head,int elem)
{
    Lnode *p = head;
    Lnode *ptemp;
    int flag = 0;  //��¼�����elem�ĸ���

    while (1)
    {
        if (head->data == elem)  //ɾ��ͷ�������
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
            else //���һ�����
            {
               free(ptemp);
               ptemp =NULL;
               p->next = NULL;
               break;
            }
        }
        else  //û��ɾ�����ʱ����ѯ��һ�����
        {
            p = p->next;
        }
    }
    printf("%d number '%d' was found and deleted.\n", flag, elem);
    return head;
}


/*���������򣬸�������ͷ��㡣*/
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