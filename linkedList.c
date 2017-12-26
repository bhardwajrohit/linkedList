/*
   FILE          : linkedList.c
   PROGRAMMER    : Rohit Bhardwaj
   DESCRIPTION   : This program uses a linked list to hold and print a list of words of up to 30 characters, 
                   one per line. When new word is inserted it follows a comma and the position in the list where
				   the word should be inserted(for e.g : word , 2). When the user enters '$' on a line by itself, 
				   the program will stop taking new words.

*/
// Header Files
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	
//structure
	typedef struct list
	{
	char data[30];             //character array that will take words of up to 30 characters 
	struct list *link;         //Pointer(link) that will points to next node in the linked list                                  
	}listNode;
	
//Global Variables
	listNode *currentNode=NULL,*head=NULL,*newNode=NULL,*tempNode=NULL; 
	
	
//Function Prototypes
	void createNode();
	void insertNode();
	void displayList();
	
//Here the Main Function starts
int main()
{
	char n;
	printf("press\n(1)To Create Node\n(2)To Insert Node\n($)To Display & Stop\n");
	while(1)
	{
		scanf("%c",&n);
	    
		if(n=='1')
		{
            createNode();       //Calling the function createNode()
			printf("press\n(1)To Create Node\n(2)To Insert Node\n($)To Display & Stop\n");
		}
	
		if(n=='2')
		{
			insertNode();      //Calling the function insertNode()
			printf("press\n(1)To Create Node\n(2)To Insert Node\n($)To Display & Stop\n");
		}

		if(n=='$')
		{
			displayList();     //Calling the function displayList()
			break;
		}	
	}
}
	
// FUNCTION      : createNode()
// DESCRIPTION   : The function create nodes in the linked list                
// PARAMETERS    : none
// RETURNS       : nothing	
void createNode()
{
	int i;
	printf("Enter the word: ");	
	if(head == NULL)
	 {
	  currentNode = (listNode *)malloc(sizeof(listNode));      //creating a node by allocating the memory to the structure
	  scanf("%s",&currentNode->data);
	  currentNode->link = NULL;                               //Assigning the address of next node, since no next node exists, a NULL is assigned                                
	  head = currentNode;
	 }
	
	else
	 {
	  newNode = (listNode *)malloc(sizeof(listNode));        //creating a node by allocating the memory to the structure
	  scanf("%s",&newNode ->data);
	  newNode ->link = NULL;
	  currentNode->link = newNode;                            //Linking the newly created node (newNode) with the previous                     
	  currentNode = currentNode->link;                        //Assigning  the address of next node(newNode) to previous node                                        
	 }
	
}
	
	
// FUNCTION     : insertNode()
// DESCRIPTION  : The function inserts node in the linked list                
// PARAMETERS   : none
// RETURNS      : nothing	
void insertNode()
{
   //Local Variables
   int count = 0, position = 0, i = 0;                                             
   char comma;
   
   tempNode = (listNode *)malloc(sizeof(listNode));           //creating a node by allocating the memory to the structure                                                                     
   newNode = (listNode *)malloc(sizeof(listNode));
   newNode ->link = NULL;
   printf("Enter the word and position where in the list the word should be inserted:\n");
   scanf("%s %c %d", &newNode->data, &comma, &position);

   /*This will keep track of the number of nodes in the linked list*/
   for(currentNode=head; currentNode!=NULL; currentNode=currentNode->link)
	{
      count++;                                                //Each time a node is created it will increment                                 
    }

   /*If comma is not inserted the word will be inserted at the end of the list*/
   if (comma != ',')
	{
		for(currentNode=head; currentNode!=NULL; currentNode=currentNode->link)
	
		{ 
			tempNode = currentNode;                            //store the currentNode in  temperory node
			tempNode ->link = newNode;                         //Link the inserted node with the previous Node(newNode)
			newNode->link = NULL;
		}
	}

   /* Insert the Node at the First Position if position=1*/
   if(position == 1)
	{
	  newNode->link = head;                                     //Assigning the address of new node in the head
	  head = newNode;
	}
	
   /*Insert the node at the end if position=count(End Position)*/
	else if(position == count)
	{
		for(currentNode=head; currentNode!=NULL; currentNode=currentNode->link)	
		{
			tempNode = currentNode;                              //currentNode as temperory node
			tempNode->link = newNode;                            //Link the inserted node with the previous Node(tempNode)                                     
			newNode->link = NULL;
		}
	}
	
	/* Insert the node in the position between head and tail*/
	else if(1 < position < count)
	{
	  position = position-1;                                     //actual position where the node should inserted will be n-1
	  
	  for(currentNode = head; currentNode != NULL; currentNode = currentNode->link)
	  {
      	i++;
	    if(i == position)
	     {
	       newNode->link = currentNode->link;
	       currentNode->link = newNode;                           //Saving the link of current Node in the new Node                                   
	       currentNode = newNode;
	     }
	   }
	 }
}
	
// FUNCTION       : displayList()
// DESCRIPTION    : It will display and end the linked list if '$' sign is inserted in
//                  the linked list                
// PARAMETERS     : none
// RETURNS        : nothing
	
void displayList()
 {
   for(currentNode = head; currentNode != NULL; currentNode = currentNode->link)
	{
	  printf("%s\n",currentNode->data);    //Print the whole linked list
	}
 }
