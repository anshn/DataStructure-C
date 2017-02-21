/* Double ended queue or dequeue */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int element;
   struct node *next;
   struct node *prev;
}d_node;

/*Print the elements of the dequeue */
void print_elements(d_node *head){
    d_node *cur = head;
    if( head == NULL )
    	printf("Queue is empty\n");
    else
    	printf("Elements of the dequeue are: ");
    while(cur != NULL){
         printf("%d ", cur->element);
         cur = cur->next;
    }
    printf("\n");
}

/* This will add to the tail of the queue*/
void push_back(d_node **tail, d_node **head, int data){
     d_node *cur;
     if(*tail == NULL || *head == NULL){
          (*tail) = malloc(sizeof(d_node));
          (*tail)->element = data;
          (*tail)->next = NULL;
          (*tail)->prev = NULL;
           *head = *tail;
     }
     else{
          cur = malloc(sizeof(d_node));
          cur->element = data;
          cur->prev = *tail;
          cur->next = NULL;
          (*tail)->next = cur;
          *tail = cur;
     }
     print_elements(*head);
}

/* This will add at the front of the queue */
void push_front(d_node **head, d_node **tail, int data){
     d_node *cur; 
     if(*head == NULL){
           (*head) = malloc(sizeof(d_node));
           (*head)->element = data;
           (*head)->prev = NULL;
           (*head)->next = NULL;
            *tail = *head;
     }
     else{
          cur = malloc(sizeof(d_node));
          cur->element = data;
          cur->prev = NULL;
          cur->next = *head;
          *head = cur;
     }
     print_elements(*head);
}

/*Remove elements from the tail of the queue*/
void pop_back(d_node **tail, d_node **head){
     d_node *temp;
     if(*tail == NULL){
            printf("Queue is empty\n");
     }
     else{
            printf("Deleting the last element :%d\n",(*tail)->element);
            if((*tail)->prev == NULL ){
		free(*tail);
                *tail = NULL;
                *head = NULL;
            }
	    else{
     	    	temp = (*tail)->prev;
            	temp->next = NULL;
		free(*tail);
            	*tail = temp;
           }
     }
}

/*Remove elements from the front or head of the queue*/
void pop_front(d_node **head){
     d_node *temp;
     if(*head == NULL){
            printf("Queue is empty\n");
     }
     else{
            printf("Deleting the first element :%d\n",(*head)->element);
            if((*head)->next == NULL){
		 free(*head);
                 *head = NULL;
            }
            else{
		temp = *head;
     	    	*head = (*head)->next;
            	(*head)->prev = NULL;
		free(temp);
            }
     }
}

int main(){
    d_node *head = NULL; 
    d_node *tail = NULL; 

    int ch=0;
    int num;
    do{
       printf("1.Enter element at the front:\n");
       printf("2.Enter element at the back:\n");
       printf("3.Remove element at the front:\n");
       printf("4.Remove element at the back:\n");
       printf("5.Print the elements of the list:\n");
       printf("6. Exit\n");

       scanf("%d", &ch);
       switch(ch){
           case 1:printf("Enter the value:\n");
                  scanf("%d", &num);
                  push_front(&head, &tail, num);
                  break;
           case 2:printf("Enter the value:\n");
                  scanf("%d", &num);
                  push_back(&tail, &head, num);
                  break;
           case 3:pop_front(&head);
                  break;
           case 4:pop_back(&tail, &head);
                  break;
           case 5:print_elements(head);
                  break;
           default: break;
       }
    }while(ch != 6);
    return 0;
}
