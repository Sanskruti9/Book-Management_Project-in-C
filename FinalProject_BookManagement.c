#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Book {
	int bookId;
	char bookName[20];
	char author[20];
	char category[20];         
	double price;
	float rating;
	
}Book;
int count = 0;

//function declarations
void addBook(Book*,int*);
void displayBook(Book*);
int searchBy_BookID(Book*,int);
void searchBy_BookName(Book*);
void searchBook(Book*);
void removeBook(Book*);
void updateBook(Book*);
void authorBooks(Book*);
void categoryBooks(Book*);
void sortBooks(Book*);
void topBooks(Book*);


//function definations
void addBook(Book* bArr,int* size)  {
	int n;
	printf("\nHow many books you want to add: ");
	scanf("%d", &n);
	
	if((*size - count) < n)  {
		printf("\nBook Array is full now, it should be increase by %d\n", n);
		bArr = (Book*)realloc(bArr, *size + (n-(*size - count)));
	}
	
	for(int i = count;i < n+count; i++)  {

		printf("Enter Book Id: ");
		scanf("%d", &bArr[i].bookId);
		printf("Enter Name of Book: ");
		fflush(stdin);
		gets(bArr[i].bookName);
		printf("Enter Author Name of book: ");
		fflush(stdin);
		gets(bArr[i].author);
		printf("Enter category of book: ");
		fflush(stdin);
		gets(bArr[i].category);
		printf("Enter price of book: ");
		scanf("%lf", &bArr[i].price);
		printf("Enter rating of book: ");
		scanf("%f", &bArr[i].rating);
		
		printf("\n");
		printf("Book Added Successfully.\n\n");	
		
	}
	count = n+count;
}

void displayBook(Book* bArr) {
    if(count == 0) {
        printf("\nLibrary is empty, add books first\n");
        return;
    }

    // Print table headers
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-20s | %-15s | %-10s | %-8s | %-6s |\n", 
           "Book ID", "Book Name", "Author", "Category", "Price", "Rating");
    printf("--------------------------------------------------------------------------------------\n");

    // Loop through the book array and print each book's details in a table format
    for(int i = 0; i < count; i++) {
        printf("| %-8d | %-20s | %-15s | %-10s | %-8.2lf | %-6.1f |\n", 
               bArr[i].bookId, bArr[i].bookName, bArr[i].author, bArr[i].category, bArr[i].price, bArr[i].rating);
    }
    printf("--------------------------------------------------------------------------------------\n");
}


int searchBy_BookID(Book* bArr,int Id)  {
        if(count==0)
        {
            printf("\nLibrary is empty, add book first\n");
            return -1;
        }   
        
        
	    for(int i=0;i <= count; i++)   {
	    	if(bArr[i].bookId==Id)  {
		        return i;
	        }	    
	    } 
		printf("\nBook Not Found\n");
		return -1;
		     
}
void searchBy_BookName(Book* bArr)  {
        if(count==0)
        {
            printf("\nLibrary is empty, add book first\n");
            return;
        }
    
        char Name[20];
	    printf("Enter the Book Name you want to search: ");
	    fflush(stdin);
        gets(Name);
        
        int flag = 0;
	    for(int i=0;i <= count; i++)  {
		  if(strcasecmp(bArr[i].bookName,Name)==0)  {
		     printf("\nBook Found\n");
		     // Print table headers
             printf("\n--------------------------------------------------------------------------------------\n");
             printf("| %-8s | %-20s | %-15s | %-10s | %-8s | %-6s |\n", 
                "Book ID", "Book Name", "Author", "Category", "Price", "Rating");
             printf("--------------------------------------------------------------------------------------\n");

            // Loop through the book array and print each book's details in a table format
            //for(int i = 0; i < count; i++) {
                printf("| %-8d | %-20s | %-15s | %-10s | %-8.2lf | %-6.1f |\n", 
                 bArr[i].bookId, bArr[i].bookName, bArr[i].author, bArr[i].category, bArr[i].price, bArr[i].rating);
            //}
            printf("--------------------------------------------------------------------------------------\n");
            printf("\n");
		     /*
		     printf("\nBook Id: %d", bArr[i].bookId);
	         printf("\nBook Name: %s", bArr[i].bookName);
		     printf("\nAuthor: %s",bArr[i].author);
		     printf("\nCategory: %s", bArr[i].category);
		     printf("\nPrice: %.2lf", bArr[i].price);
		     printf("\nRating: %.1f", bArr[i].rating);
		    
		     printf("\n");
		     */
	       }
	       	      
	    }
		printf("\nBook Not Found\n");  	
}

void searchBook(Book* bArr)  {
	if(count==0)
    {
       printf("\nLibrary is empty, add book first\n");
       return;
    }
    
	int choice;
	
	printf("How you want to search book by Id or Name: \n");
	printf("press 1 if you want search book by BookId\n");
	printf("press 2 if you want search book by BookName\n");
	scanf("%d", &choice);
	
	if(choice==1)  {
		int Id;
	    printf("Enter the Book ID you want to search: ");
	    scanf("%d", &Id);
	    
		int i = searchBy_BookID(bArr,Id);
		if(i!=-1)  {
			// Print table headers
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("| %-8s | %-20s | %-15s | %-10s | %-8s | %-6s |\n", 
           "Book ID", "Book Name", "Author", "Category", "Price", "Rating");
        printf("--------------------------------------------------------------------------------------\n");

        // Loop through the book array and print each book's details in a table format
        //for(int i = 0; i < count; i++) {
             printf("| %-8d | %-20s | %-15s | %-10s | %-8.2lf | %-6.1f |\n", 
               bArr[i].bookId, bArr[i].bookName, bArr[i].author, bArr[i].category, bArr[i].price, bArr[i].rating);
        //}
        printf("--------------------------------------------------------------------------------------\n");
        printf("\n");
	    }
		
    }
	else if(choice==2)  {
		searchBy_BookName(bArr);
	} 
	else {
		printf("Invalid Choice!\n");
	}	
}

void removeBook(Book* bArr)   {
	if(count==0)
    {
       printf("\nLibrary is empty, add book first\n");
       return;
    }
    
	int Id;
	printf("Enter Book ID of the Book that you want to remove: ");
	scanf("%d", &Id);
	
	int index = searchBy_BookID(bArr, Id);
	
	if(index>=0)  {
		for(int i = index; i < count-1; i++)  {
			bArr[i]=bArr[i+1];
		}
		count--;
		printf("\nBook Removed Successfully.\n");
		return ;
	}
	printf("Book Not Found\n");	
}
void updateBook(Book* bArr)  {
	if(count==0)
    {
       printf("\nLibrary is empty, add book first\n");
       return;
    }
    
	int Id;
	printf("Enter Book ID of the Book that you want to update: ");
	scanf("%d", &Id);
	
	int index = searchBy_BookID(bArr, Id);
	
	if(index>=0)  {
		
		printf("\nEnter new price: ");
		scanf("%lf", &bArr[index].price);
		printf("\nEnter new rating: ");
		scanf("%f", &bArr[index].rating);
		
		printf("\nBook Updated Successfully.\n");
		
	}
	else {
		printf("Book Not Found\n");	
	}
}

void authorBooks(Book* bArr) {
    if (count == 0) {
        printf("\nLibrary is empty, add a book first\n");
        return;
    }

    char authorName[20];
    printf("Enter Author Name: ");
    fflush(stdin);
    gets(authorName);

    int flag = 0; // Flag to check if any books are found

    // Print table headers before the loop
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-20s | %-15s | %-10s | %-8s | %-6s |\n", 
           "Book ID", "Book Name", "Author", "Category", "Price", "Rating");
    printf("--------------------------------------------------------------------------------------\n");

    // Loop through the book array and check for matching author names
    for (int i = 0; i < count; i++) {
        if (strcasecmp(bArr[i].author, authorName) == 0) {
            // Print each matching book's details
            printf("| %-8d | %-20s | %-15s | %-10s | %-8.2lf | %-6.1f |\n", 
                   bArr[i].bookId, bArr[i].bookName, bArr[i].author, bArr[i].category, bArr[i].price, bArr[i].rating);
            flag = 1; // Book found
        }
    }

    // If no books are found, print a message
    if (flag == 0) {
        printf("\nNo books found for the given author.\n");
    }

    printf("--------------------------------------------------------------------------------------\n");
}

void categoryBooks(Book* bArr) {
    if (count == 0) {
        printf("\nLibrary is empty, add a book first\n");
        return;
    }

    char category[20];
    printf("Enter Category Name: ");
    fflush(stdin);
    gets(category);

    int flag = 0; // Flag to check if any books are found

    // Print table headers before the loop
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-20s | %-15s | %-10s | %-8s | %-6s |\n", 
           "Book ID", "Book Name", "Author", "Category", "Price", "Rating");
    printf("--------------------------------------------------------------------------------------\n");

    // Loop through the book array and check for matching categories
    for (int i = 0; i < count; i++) {
        if (strcasecmp(bArr[i].category, category) == 0) {
            // Print each matching book's details
            printf("| %-8d | %-20s | %-15s | %-10s | %-8.2lf | %-6.1f |\n", 
                   bArr[i].bookId, bArr[i].bookName, bArr[i].author, bArr[i].category, bArr[i].price, bArr[i].rating);
            flag = 1; // Book found
        }
    }

    // If no books are found, print a message
    if (flag == 0) {
        printf("\nNo books found for the given category.\n");
    }

    printf("--------------------------------------------------------------------------------------\n");
}

void sortBooks(Book* bArr)
{
    int i,j,ch;    
   
    Book temp_bArr[count];
    Book temp;
    if(count==0)
    {
       printf("\nLibrary is empty, add book first\n");
       return;
    }
    for(i=0;i<count;i++)
    {
        temp_bArr[i]=bArr[i];
    }
    printf("\nEnter how you want sort Books\n");
         printf("1) By price\n");
         printf("2) By rating\n");
         printf("Enter choice:");
         scanf("%d",&ch);
         if(ch==1)
         {
            printf("\n1) Higest to Lowest\n");
            printf("2) Lowest to Highest\n");
            printf("Enter choice:");
            scanf("%d",&ch);
            if(ch==1)
            {
              for(i=0;i<count;i++)
              {    
                for(j=i+1;j<count;j++)
                { 
                   //printf("%d",count);
                   if(temp_bArr[j].price>temp_bArr[i].price)
                   {
                      temp=temp_bArr[i];
                      temp_bArr[i]=temp_bArr[j];
                      temp_bArr[j]=temp;       
                   }
                }
              }
              displayBook(temp_bArr); 
            }
            else if(ch==2)
            {
              for(i=0;i<count;i++)
              {      
               for(j=i+1;j<count;j++)
               { 
                  if(temp_bArr[j].price<temp_bArr[i].price)
                  {
                      temp=temp_bArr[i];
                      temp_bArr[i]=temp_bArr[j];
                      temp_bArr[j]=temp;       
                  }
               }
              }
              displayBook(temp_bArr);
            }
         }
         else if(ch==2)
         {
            printf("\n1) Highest to Lowest\n");
            printf("2) Lowest to Highest\n");
            printf("Enter choice:");
            scanf("%d",&ch);
            if(ch==1)
            {
              for(i=0;i<count;i++)
              {  
                for(j=i+1;j<count;j++)
                { 
                  // printf("%d",count);
                  if(temp_bArr[j].rating > temp_bArr[i].rating)
                  {
                      temp=temp_bArr[i];
                      temp_bArr[i]=temp_bArr[j];
                      temp_bArr[j]=temp;       
                  }
                }
              }
              displayBook(temp_bArr);
            }
            else if(ch==2)
            {
              for(i=0;i<count;i++)
              {
               for(j=i+1;j<count;j++)
               { 
                  if(temp_bArr[j].rating < temp_bArr[i].rating)
                  {
                      temp=temp_bArr[i];
                      temp_bArr[i]=temp_bArr[j];
                      temp_bArr[j]=temp;        
                  }
               }
              }
              displayBook(temp_bArr);
            }
         }
}

void topBooks(Book* bArr)
{
    int i,j,ch,newCount=3;
    Book temp_bArr[newCount];
    Book temp;
    if(count==0)
    {
       printf("\nLibrary is empty, add book first\n");
       return;
    }
    
    for(i=0;i<count;i++)
    {
        temp_bArr[i]=bArr[i];
    }
    printf("\n\nEnter how you want top 3 Book\n");
    printf("1)on the basis of price\n");
    printf("2)on the basis of rating\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    printf("\nTop books:\n");
    
    if(ch==1)
    {
        for(i=0;i<count;i++)
        { 
            for(j=i+1;j<count;j++)
            { 
                if(temp_bArr[j].price>temp_bArr[i].price)
                {
                    temp=temp_bArr[i];
                    temp_bArr[i]=temp_bArr[j];
                    temp_bArr[j]=temp;       
                }
            }
        }
        displayBook(temp_bArr);
    }
    else if(ch==2)
    {
        for(i=0;i<count;i++)
        {   
            for(j=i+1;j<count;j++)
            { 
                if(temp_bArr[j].rating>temp_bArr[i].rating)
                {
                    temp=temp_bArr[i];
                    temp_bArr[i]=temp_bArr[j];
                    temp_bArr[j]=temp;       
                }
            }
        }
        displayBook(temp_bArr);
    } 
}

void main()  {
	int size = 2;
	Book* bArr = (Book*)malloc(sizeof(Book)*size);
    
    int choice;
    do {
    	
       printf("\n****Hello, Welcome to The Book Management System!****\n\n");
       printf(" 1) Press 1 for Add Books\n");
       printf(" 2) Press 2 for Display All Books\n");
       printf(" 3) Press 3 for Search Books\n");
       printf(" 4) Press 4 for Remove Books\n");
       printf(" 5) Press 5 for Update Books data\n");
       printf(" 6) Press 6 for Display List of specific Author's Books\n");
       printf(" 7) Press 7 for Display List of specific Category's Books\n");
       printf(" 8) Press 8 for Display Sorted Books\n");
       printf(" 9) Press 9 for Display Top 3 Books\n");
       printf(" 10) Press 10 for Exit\n");
       
       printf("\n");
	   
	   printf("\nEnter your choice: ");
       scanf("%d", &choice);
	   
	   switch(choice)  {
		case 1:
			addBook(bArr, &size);          //function call
			break;
		case 2:
			displayBook(bArr);
			break;
		case 3:
			searchBook(bArr);
			break;
		case 4:
			removeBook(bArr);
			break;
		case 5:
			updateBook(bArr);
			break;
		case 6:
			authorBooks(bArr);
			break;
		case 7:
			categoryBooks(bArr);
			break;
		case 8:
			sortBooks(bArr);
			break;
		case 9:
			topBooks(bArr);
			break;
		case 10:
		    return ; 
		default:
			printf("\nInvalid Choice, Please Enter valid choice!\n");
	    }	
	}
	while(choice != 0);
}
