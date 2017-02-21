#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node_c;
void print_elements(node_c **front, node_c **rear){
        node_c *cur= *front;
        node_c *temp = NULL;
	if( *front == NULL){
		printf("Queue is empty\n");
		return;
	}
        printf("Values of the circular queue: ");
	while(cur != temp){
 		printf("%d ",cur->data);	
                cur = cur->next;
		temp = *front;
        }
	printf("\n");
}
/* Insert elements in the queue */
void insert_elements(node_c **front, node_c **rear, int num){
	node_c *cur = NULL;
	cur = malloc(sizeof(node_c));
	cur->data = num;
        if(*front == NULL){
		*front = cur;
        }else{
		(*rear)->next = cur;
	}
	*rear = cur;
	(*rear)->next = *front;
	print_elements(front, rear);
}

void remove_elements(node_c **front, node_c **rear){
	node_c *temp;
	if(*front == NULL){
		printf("Queue is empty\n");	
	}
	if(*front == *rear){
		printf("Deleting the only element %d\n", (*front)->data);
		free(*front);
		*front = *rear = NULL;
	}
        else{
		printf("Deleting the front element %d\n", (*front)->data);
		temp = *front;
		*front = (*front)->next;
		(*rear)->next = *front;
		free(temp);
	}
}

int main(){
        node_c *front = NULL;
        node_c *rear = NULL;
        int ch;
        int num;

        printf("Enter a choice:\n");
        do{
        	printf("1.Enter element to the circular queue:\n");
       		printf("2.Remove element from the circular queue:\n");
       		printf("3.Print the elements of the circular queue:\n");
       		printf("4. Exit\n");

       		scanf("%d", &ch);
       		switch(ch){
           		case 1: printf("Enter the value:\n");
                  		scanf("%d", &num);
                  		insert_elements(&front, &rear, num);
                  		break;
           		case 2: remove_elements(&front, &rear);
                  		break;
           		case 3:print_elements(&front, &rear);
                  		break;
			case 4:break;
                        default: printf("Wrong choice!!! Enter a valid choice\n");
				 break;
 		}
	}while(ch!=4);
	return 0;
}
