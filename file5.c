#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* head = NULL;

void insert_at_beginning();
void insert_at_end();
void insert_at_randomPosition();
void display();
void delete_at_beginning();
void delete_at_end();
void delete_at_randomPosition();

int count_nodes() {
    int count = 0;
    struct Node* new = head;
    while (new != NULL) {
        count++;
        new = new->link;
    }
    printf("No of nodes are %d\n", count);
    return count;
}

int main() {
    int choice = 0;
    while (choice != 9) {
        mainmenu:printf("**********MAIN MENU*************\n 1.INSERT AT BEGINNING \n 2.INSERT AT END \n 3.INSERT AT RANDOM POSITION \n 4.DISPLAY \n 5.COUNT \n 6.DELETE AT BEGINNING \n 7.DELETE AT END \n 8.DELETE AT RANDOM POSITION \n 9.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_randomPosition();
                break;
            case 4:
                display();
                break;
            case 5:
                count_nodes();
                break;
            case 6:
                delete_at_beginning();
                break;
            case 7:
                delete_at_end();
                break;
            case 8:
                delete_at_randomPosition();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}


void
insert_at_beginning ()
{
  int value;
  printf ("enter a value to insert");
  scanf ("%d", &value);
  struct Node *new = (struct Node *) malloc (sizeof (struct Node));
  if (new == NULL) {
        printf("Memory allocation failed\n");
        //return;
    }
  new->data = value;
  //head->link = NULL;
  new->link = head;
  head= new;
  printf ("NODE INSERTED AT BEGINNING");
}

void insert_at_end(){
    int value;
    printf ("enter a value to insert");
    scanf ("%d", &value);
    struct Node *new = (struct Node *) malloc (sizeof (struct Node));
    struct Node *temp;
    if (new == NULL)
    {
      printf ("failed");
      return;
    }
    temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    new->data=value;
    temp->link=new;
    new->link=NULL;
    }
void insert_at_randomPosition() {
    int value;
    printf("Enter a value to insert: ");
    scanf("%d", &value);

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = value;
    new->link = NULL;

    int position;
    printf("Enter the position to insert a value: ");
    scanf("%d", &position);

    if (position < 0) {
        printf("Invalid position\n");
        free(new);
        return;
    }

    if (position == 0) {
        new->link = head;
        head = new;
        printf("Node inserted at position 0\n");
        return;
    }

    struct Node *temp = head;
    int i;

    for (i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(new);
        return;
    }

    new->link = temp->link;
    temp->link = new;

    printf("Node inserted at position %d\n", position); // Correctly display the position
}



void display()
{
  struct Node *temp;
  if (head == NULL)
    {
      printf ("list is empty");
      return;
    }
    temp = head;
    printf("Linked List: ");
      while (temp != NULL)
	{
	  printf ("->%d", temp->data);
	  temp = temp->link;
	}

    printf("\n");

}
// Function to delete a node from the beginning of the linked list
void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->link;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end of the linked list
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    if (prev != NULL) {
        prev->link = NULL;
    } else {
        // Only one node in the list
        head = NULL;
    }

    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete a node from a random position in the linked list
void delete_at_randomPosition() {
    int position;
    printf("Enter the position to delete a node: ");
    scanf("%d", &position);

    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        delete_at_beginning();
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    int current_position = 0;

    while (temp != NULL && current_position < position) {
        prev = temp;
        temp = temp->link;
        current_position++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}


