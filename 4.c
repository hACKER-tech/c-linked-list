/*Input:Number of inuts, and equvivalent number of integer inputs
  Output:printing all the elements of the linked list ,and printing all the even elements of the linked list
  Remarks:to access any element in a linked list we have to go through each and every node before to access it*/   
#include <stdio.h> 
#include<stdlib.h>  

/*Defining the user defined data type -structure
  data:stores the information inputed by user(integer)
  link:connects with the next node of a linked list*/
struct node 
{ 
    int data; 
    struct node* link; 
}; 

/*g_root:contains address of the first node of the linked list(g represent that it is a global variable*/
struct node*g_root;

/*linking various nodes to form a linked list*/
void linking()
{
    /*temporary:pointer which temporarily holds the address of new node to be added*/
    struct node* temporary;
    temporary=(struct node*)(malloc(sizeof(struct node)));

    /*scanning the elements into node*/    
    scanf("%d",&temporary->data);
    temporary->link=NULL;
    
    /*if g_root is NULL it means that the root is not pointing to anything,so the node is the first of the linked list*/
    /*hence assign the address in temporary to g_root*/
    if(g_root==NULL)
    {
        g_root=temporary;
    }
    
    /*if g_root!=NULL,it means there is a node already existing and hence we have to append a new node*/
    else
    {
        /*ptr:pointer declared for appending a new node*/
        struct node*ptr ;
        ptr=g_root;

        /*ptr would travel through entire linked list
          as it reaches the end we would replace the last node's link with new node's address.
          temporary pointer contains the information of the neww node's address*/
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temporary;
    }
}

/*printing the elemts of the linked list*/
void printing()
{
    /*temporary:stores the address of nodes and is replaced with next one after printing*/
    struct node*temporary;
    temporary=g_root;

    /*if temporary=NULL ,it means that it has reached the end of the linked list*/
    while(temporary!=NULL)
    {
        printf("%d-->",temporary->data);
        temporary=temporary->link;
    }
    printf("NULL\n");
}

/*function for deleting a node*/
void deletenode(int position)
{
    /*temporary:pointer declared for traversing over the linked list
     *stops when it finds an odd number*/
    struct node* temporary = g_root;
    
    /*if position !=1 it means that the node is not a root node*/
        if (position!=1)
	{
	        /*p:pointer declared and is used deleting a node
		 *i:declared for making the temporary pointer traverse through the linked list */	
		struct node* p;
                int i=1;

		/*when we find an odd number in between the temporary variable stops at that position
		 *to make temporary pointer reach there we are using a while loop */
                while(i<=position-2)
                {
                        temporary = temporary->link;
                        i += 1;
                }

		/*now we assign the pointer p to next node 
		 *we now assign temporary to the next of p
		 *now we free the pointer p which points to an odd data*/ 
                p=temporary->link;
                temporary->link=p->link;
                free(p);

	}
        else
	{
 
		/*if position equal 1 then it means that the node is a root
		 *we now shift the root node to the next one
		 *we have initiated temporary pointer to the previous root
		 *by freeing that we delete the node*/
		g_root = g_root->link;
                free(temporary);
        }
}    

/*main function*/
int main()
{
    /*num:stores the information of number of nodes of linked lists*/
    int num;

    /*scanning the value of num*/
    scanf("%d",&num);

    /*appending the new node*/
    int j = 0;
    while(j < num)
    {
	    linking();
	    j += 1;
    }
    struct node* temp = g_root;
    /*printing  the nodes of the linked list*/
    printing();

    /*calling delete function(deletes all nodes with odd data value)*/
    int i=1;
    while (temp!=NULL)
    {
	/*if the data is even we just have to proceed to the next node*/   
    	if (temp->data%2==0)
       	{
		temp=temp->link;
		i += 1;
        }

	/*if not we have to delete the node and proceed further*/
        else
	{
       		deletenode(i);
                temp=temp->link;
        }
   }
    /*printing all the nodes of the new linked list*/
    printing();
    return 0;
}
    
        
