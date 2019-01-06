#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>



void d_node_create();
void d_display(struct double_link *head);
void d_insert_beginning(struct double_link *head);
void d_insert_last(struct double_link *head);
void d_insert_any_position(struct double_link *head);
void d_delete_beginning(struct double_link *head);
void d_delete_last_node(struct double_link *head);
void d_delete_any_position(struct double_link *head);
void d_update_beginning(struct double_link *head);
void d_update_last(struct double_link *head);
void d_update_any_position(struct double_link *head);
void d_sort_data(struct double_link *head);
void d_search(struct double_link *head);

struct double_link {
    int data;
    struct double_link *laddr;
    struct double_link *raddr;
} *d_start;

int main() {
    int n, i, d, u;
    //clrscr();
    while (1) {
        printf("\n_________________________________________________\n");
        printf("\npress 1 for create node");
        printf("\npress 2 for display");
        printf("\npress 3 for insert section");
        printf("\npress 4 for delete section");
        printf("\npress 5 for update section");
        printf("\npress 6 for data sort");
        printf("\npress 7 for searching data");
        printf("\npress 0 for Exit");
        //printf("\npress 99 clear screen");
        //printf("\n\npress 0 for exit");
        printf("\n________________________________________________\n");
        printf("\n Enter your choice:\n");
        scanf("%d", &n);
        switch (n) {
            case 0:
            {
                exit(0);
                break;
            }
            case 1:
            {
                d_node_create();
                break;
            }
            case 2:
            {
                d_display(d_start);
                break;
            }
            case 3:
            {
                printf("\npress 1 for insert beginning");
                printf("\npress 2 for insert last");
                printf("\npress 3 for insert any position\n");
                scanf("%d", &i);
                switch (i) {
                    case 1:
                    {
                        d_insert_beginning(d_start);
                        break;
                    }
                    case 2:
                    {
                        d_insert_last(d_start);
                        break;
                    }
                    case 3:
                    {
                        d_insert_any_position(d_start);
                        break;
                    }
                    default:
                    {
                        printf("\n sorry! wrong choice, Try again\n");
                        break;
                    }
                }

                break;
            }
            case 4:
            {
                printf("\npress 1 for delete first node");
                printf("\npress 2 for delete last node");
                printf("\npress 3 for delete any position\n");
                scanf("%d", &d);
                switch (d) {
                    case 1:
                    {
                        d_delete_beginning(d_start);
                        break;
                    }
                    case 2:
                    {
                        d_delete_last_node(d_start);
                        break;
                    }
                    case 3:
                    {
                        d_delete_any_position(d_start);
                        break;
                    }
                    default:
                    {
                        printf("\n sorry! wrong choice, Try again\n");
                        break;
                    }
                }

                break;
            }
            case 5:
            {
                printf("\npress 1 for update beginning position");
                printf("\npress 2 for update last position");
                printf("\npress 3 for update any position\n");
                scanf("%d", &u);
                switch (u) {
                    case 1:
                    {
                        d_update_beginning(d_start);
                        break;
                    }
                    case 2:
                    {
                        d_update_last(d_start);
                        break;
                    }
                    case 3:
                    {
                        d_update_any_position(d_start);
                        break;
                    }
                    default:
                    {
                        printf("\n sorry! wrong choice, Try again\n");
                        break;
                    }
                }

                break;
            }
            case 6:
            {
                d_sort_data(d_start);
                break;
            }
            case 7:
            {
                d_search(d_start);
                break;
            }
                /*case 99:
                {
                clrscr();
                break;
                }
                case 0:
                {
                exit(1);
                }*/
            default:
            {
                printf("\n sorry! worng choice\n");
                break;
            }
        }
    }
    //getch();
    return 0;
}

void d_node_create() {
    struct double_link *ptr, *p;
    int n;
    printf("\n How many node create:\n");
    scanf("%d", &n);
    d_start = '\0';
    while (n > 0) {
        ptr = (struct double_link*) malloc((sizeof (struct double_link*)));
        ptr->raddr = '\0';
        ptr->laddr = '\0';
        printf("\n Enter data:\n");
        scanf("%d", &ptr->data);
        if (d_start == '\0') {
            d_start = ptr;
            p = d_start;
        } else {
            p->raddr = ptr;
            ptr->laddr = p;
            p = ptr;
        }

        n--;
    }


}

void d_display(struct double_link *head) {
    if (head == '\0')
        printf("\n sorry node is not created\n");
    else {
        printf("\n your entered data:\n\n\t");
        while (head->raddr != '\0') {
            printf("%d->", head->data);
            head = head->raddr;
        }
        printf("%d", head->data);
    }
}

void d_insert_beginning(struct double_link *head) {
    struct double_link *ptr;
    ptr = (struct double_link*) malloc((sizeof (struct double_link*)));
    if (ptr == '\0')
        printf("\n memory can not allocated\n");
    else {
        ptr->raddr = '\0';
        ptr->laddr = '\0';
        printf("\n Enter data:\n");
        scanf("%d", &ptr->data);
        if (head == '\0') {
            d_start = ptr;
        } else {
            ptr->laddr = '\0';
            ptr->raddr = head;
            head->laddr = ptr;
            d_start = ptr;
        }
        printf("\n Data inserted\n");
    }
}

void d_delete_beginning(struct double_link *head) {
    if (head == NULL)
        printf("\n sorry! node is not created\n");
    else if (head->raddr == NULL) {
        free(head);
        d_start = NULL;
        printf("\n First node is deleted\n");
    } else {
        d_start = head->raddr;
        d_start->laddr = NULL;
        free(head);
        printf("\n First node is deleted\n");
    }
}

void d_delete_last_node(struct double_link *head) {
    struct double_link *p;
    if (head == NULL)
        printf("\n sorry! node is not created\n");
    else if (head->raddr == NULL) {
        free(head);
        d_start = NULL;
        printf("\n Last node is deleted\n");
    } else {
        while (head->raddr != NULL)
            head = head->raddr;

        p = head->laddr;
        p->raddr = NULL;
        free(head);
        printf("\n Last node is deleted\n");

    }
}

void d_insert_last(struct double_link *head) {
    struct double_link *ptr;


    if (head == NULL)
        d_insert_beginning(d_start);
    else {
        ptr = (struct double_link*) malloc((sizeof (struct double_link*)));
        ptr->raddr = NULL;
        ptr->laddr = NULL;
        printf("\n Enter data:\n");
        scanf("%d", &ptr->data);
        if (ptr == '\0')
            printf("\n memory can not allocated\n");
        else {
            while (head->raddr != NULL)
                head = head->raddr;
            head->raddr = ptr;
            ptr->laddr = head;
            printf("\n Last node is inserted\n");

        }
    }


}

void d_insert_any_position(struct double_link *head) {
    int n, c = 0, i;
    struct double_link *ptr, *temp, *p;
    temp = head;
    while (head != NULL) {
        head = head->raddr;
        c++;
    }

    printf("\n Enter position for data insert\n");
    scanf("%d", &n);
    if (n == 1)
        d_insert_beginning(d_start);
    else if (n < 0 || n > c + 1)
        printf("\n Invalid position,Try again\n");
    else {
        for (i = 1; i < n - 1; i++)
            temp = temp->raddr;
        p = temp->raddr;
        ptr = (struct double_link*) malloc((sizeof (struct double_link*)));
        ptr->raddr = NULL;
        ptr->laddr = NULL;
        printf("\n Enter data:\n");
        scanf("%d", &ptr->data);
        if (ptr == '\0')
            printf("\n memory can not allocated\n");
        else {
            temp->raddr = ptr;
            ptr->laddr = temp;
            ptr->raddr = p;
            printf("\n Data is inserted\n");

        }
    }
}

void d_delete_any_position(struct double_link *head) {
    int n, c = 0, i;
    struct double_link *ptr, *temp, *p;
    temp = head;
    while (head != NULL) {
        head = head->raddr;
        c++;
    }

    printf("\n Enter position for data delete\n");
    scanf("%d", &n);
    if (n == 1)
        d_delete_beginning(d_start);
    else if (n < 0 || n > c)
        printf("\n Invalid position,Try again\n");
    else if (n == c)
        d_delete_last_node(d_start);
    else {
        for (i = 1; i < n; i++)
            temp = temp->raddr;
        p = temp->raddr;
        p = temp->raddr;
        ptr = temp->laddr;
        p->laddr = ptr;
        ptr->raddr = p;
        free(temp);
        printf("\n %d No. data is Deleted\n", n);
    }
}

void d_update_beginning(struct double_link *head) {
    if (head == NULL)
        printf("\n sorry! node is not created\n");
    else {
        printf("\n Enter data for first node update\n");
        scanf("%d", &head->data);
        printf("\n Updated\n");
    }
}

void d_update_last(struct double_link *head) {
    if (head == NULL)
        printf("\n sorry! node is not created\n");
    else {
        while (head->raddr != NULL)
            head = head->raddr;
        printf("\n Enter data for last node update\n");
        scanf("%d", &head->data);
        printf("\n Updated\n");

    }
}

void d_update_any_position(struct double_link *head) {
    int n, c = 0, i;
    struct double_link *ptr, *temp, *p;
    temp = head;
    while (head != NULL) {
        head = head->raddr;
        c++;
    }

    printf("\n Enter position for data Update\n");
    scanf("%d", &n);
    if (n < 0 || n > c)
        printf("\n Invalid position,Try again\n");
    else if (n == 1)
        d_update_beginning(d_start);
    else {
        for (i = 1; i < n; i++)
            temp = temp->raddr;
        printf("\n Enter data update\n");
        scanf("%d", &temp->data);
        printf("\n %d No. position is Updated\n", n);
    }
}

void d_sort_data(struct double_link *head) {
    int t;
    struct double_link *hi, *hj;
    hi = head;
    hj = head;
    if (head == NULL)
        d_display(d_start);
    else {
        while (hi->raddr != NULL) {
            hj = head;
            while (hj->raddr != NULL) {
                if (hj->data > hj->raddr->data) {
                    t = hj->data;
                    hj->data = hj->raddr->data;
                    hj->raddr->data = t;
                }
                hj = hj->raddr;
            }
            hi = hi->raddr;
        }
        d_display(d_start);
    }
}

void d_search(struct double_link *head) {
    int n, c = 1, f;
    if (head == NULL)
        printf("\n sorry! node is not created\n");

    else {
        printf("\n Enter item for searching:\n");
        scanf("%d", &n);

        while (head != NULL) {
            if (head->data == n) {
                f = 1;
                break;
            } else
                f = 0;
            head = head->raddr;
            c++;
        }


        if (f == 1)
            printf("\n Data %d is found following %d position\n", head->data, c);
        else
            printf("\n sorry item is not found\n");
    }
}
