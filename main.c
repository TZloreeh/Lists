// I used repl.it to compile it
//Lorenzo Eccher 2019-11-25 


#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


typedef struct lista *ELEMENTO;

struct lista{
int ID; 
char control; 
int weight; 
int *next; 
}; 

void menu(){
  printf("\n\n\nWhat do you want to do?"); 
  printf("\n[1] Add manually a node to the list"); 
  printf("\n[2] Add N random nodes to the list ");
  printf("\n[3] Print the current list");
  printf("\n[4] Print the average of the weights");
  printf("\n[5] Print maximun, minimum and defferences");

  printf("\n[0] Exit\n> ");
}

int generateID(){

  int ID;

  ID =(rand() % ((2001 + 1) - 999) + 999);

  return ID; 
}

char generateChar(){
  char alpabet[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
  int generatore = 26; 
  int cont;

  cont =rand()%26; 
  

  return alpabet[cont]; 

}

int generateWeight(){
  int ret; 

  ret=(rand() % ((81 + 1) - 39) + 39);

  while(ret == 48 || ret == 60 || ret == 70){

    ret=(rand() % ((81 + 1) - 39) + 39);
  }

  return ret; 

}

 void newNode(ELEMENTO *head, int ID, char control, int weight){

   ELEMENTO temp; 

   temp = malloc(sizeof(ELEMENTO)); 

   if(temp != NULL){ 

     temp->ID=ID;
     temp->control=control; 
     temp->weight=weight;

    temp->next=*head; 
    *head=temp;
   }



}

void printList(ELEMENTO head)
{
  ELEMENTO temp=head;

  if(temp == NULL){
    printf("\n\nThe list is empty,  fill it!");
  }
  else
  {
    while(temp != NULL)
  { 
    printf("\n\nElement\t%d\t%d\t%d", temp->ID,temp->weight, temp->control); 
    temp=temp->next;  

  }
  }
   
  
}

float average(head){

 float average=0, i=0; 
 int sum=0; 

 ELEMENTO temp=head;

 if(temp == NULL)
 {
      
   printf("\n\nThe list is empty,  fill it!");


 }
 else 
 {
   while(temp != NULL)
  { 
    sum = sum +  temp->weight; 
    i++; 
    temp=temp->next; 

  }
  

  average=sum/i; 

   

 }
   
  

  return average; 

}

void clear(){
  system("clear"); 
}

void MaxMin(head){
  ELEMENTO temp=head;
  int max=1, min=999;

  if(temp == NULL){
    printf("\n\nThe list is empty,  fill it!");
  }
  else
  {
    while(temp != NULL)
  { 
    if(temp->weight > max){
      max=temp->weight;

    } 

    if(temp->weight < min)
    {
      min=temp->weight; 
    }
    
    
    temp=temp->next;
      

  }
  
  printf("\n\nThe max weight is %d", max); 
  printf("\n\nThe min weight is %d", min); 
  printf("\n\nThe weight difference between max an min is %d", (max-min)); 
  

  }

  
}






int main(void) {

  srand(time(NULL)); 
  ELEMENTO head = NULL; 
  int choice;
  int ID, weight; 
  char control;
  int i, times;  

  system("clear"); 
  
  /*//test
  for(int i=0; i<10; i++ ){

    printf("\n\n%d", generateID()); 
    printf("\n%c", generateChar()); 
    printf("\n%d", generateWeight()); 
  }
  */

  //inizio richieste programma
  printf("\nHi, welcome to my program! ");
  
  do{
  
   menu();
   scanf("%d", &choice); 
   clear(); 

   switch(choice){

   case 0: 
        clear(); 
        break; 


   case 1: 
        
        clear(); 
        printf("\nInsert an integer ID [1000 - 2000]\n> "); 
        scanf("%d", &ID);
        printf("\nInsert an integer weight [40 - 80 (musn't type 48,60,70)]\n> "); 
        scanf("%d", &weight); 
        printf("Insert an alphabet char\n> "); 
        scanf("%c", &control); 
        break; 


   case 2:


        printf("\nHow many random nodes do u want?\n> ");
        scanf("%d", &times); 
        for(i=0; i<times; i++)
        {
          newNode(&head, generateID(), generateChar(), generateWeight());
        }
        break; 

   case 3: 
        printList(head); 
        break; 
    
   case 4: 
        printf("\nThe average of total weitghts is: %.2f", average(head)); 
        break; 

   case 5: 
        MaxMin(head); 
        break; 


   default: 
         break; 

       
   }



  }while(choice != 0); 


  printf("\n\nexit success"); 




  return 0;
}