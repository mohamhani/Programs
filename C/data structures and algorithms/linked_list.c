#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(struct Node** head_ptr, int data)
{
    struct Node* node_ptr = (struct Node*)malloc(sizeof(struct Node));
    node_ptr->data = data;
    node_ptr->next = NULL;

    if(*head_ptr != NULL)
    {
        node_ptr->next = *head_ptr;
    }
    *head_ptr = node_ptr;
}

void display(struct Node* node_ptr)
{
    printf("list is: ");
    while(node_ptr != NULL)
    {
        printf(" %d", node_ptr->data);
        node_ptr = node_ptr->next;
    }
    printf("\n");
}

/*
* Generating a random number between 1 to 99  
*/
int generateRandomNumber()
{
    int random = rand() %100 + 1;

    return random;
}

int main(int argc, const char *argv[])
{
    struct Node* head = NULL;
    int size, number;
    printf("Enter the size of the linked_list: ");
    scanf("%d",&size);

    for(int i = 0; i < size; i++)
    {
        number = generateRandomNumber();
        insert(&head, number);
    }

    display(head);
    

}