#include <stdio.h>

int add(char *book_title, char *book_author, char *book_publisher, int *borrowed, int num);
int borrow(char (*book_title)[30], int *borrowed);
int restore(char (*book_title)[30], int *borrowdd);
int search(char (*book_title)[30], char (*book_author)[30], char (*book_publisher)[30], int *borrowed);

int compare(char *a, char *b);
int similar(char *a, char *b); // 찾고 싶은 대상, 피 검색어

int main(){
    int program; // 1: add, 2: search, 3: borrow, 4: restore, 0: terminate
    int book_number = 0;  // 총 책 개수는 : total book number  =  book_number + 1
    char book_title[100][30];
    char book_author[100][30];
    char book_publisher[100][30];
    int borrowed[100]; // 책 추가된 순서와 빌림여부: 책 빌렸으면 1 안 빌렸으면 0.

    printf(" What do you want to do? \nChoice[1]. add \nChoice[2]. search \nChoice[3]. borrow \nChoice[4]. restore \nChoice[0]. terminate \n>> :  ");
    scanf("%d", &program);
    while(program){

        switch (program)
        {
        case 1: //add
            add(book_title[book_number], book_author[book_number], book_publisher[book_number], borrowed, book_number);
            book_number++;
            break; 
        case 2: //search
            search(book_title, book_author, book_publisher, borrowed);
            break;
        case 3: //borrow
            borrow(book_title, borrowed);
            break;
        case 4: //restore
            restore(book_title, borrowed);
            break;    
        default:
            printf("Please enter the exact number \n");
            break;
        
        }
        printf(" What do you want to do? \nChoice[1]. add \nChoice[2]. search \nChoice[3]. borrow \nChoice[4]. restore \nChoice[0]. terminate \n>> :  ");
        scanf("%d", &program);
    }
    printf("We management %d_books.\n", book_number);
    printf("The program is terminated.\n");
    return 0;
}



int add(char *book_title, char *book_author, char *book_publisher, int *borrowed, int num){
    printf("book_%d\n",(num+1)); // 책 번호
    *(borrowed+num) = 0; // 안 빌린 상태.
    printf("What is the title of book : \n");
    scanf("%s", book_title); 

    printf("What is the author of book : \n");
    scanf("%s", book_author);

    printf("What is the publisher of book : \n");
    scanf("%s", book_publisher);

    printf("Success! \n");
    return 0;
}
int borrow(char (*book_title)[30], int *borrowed){
    char name[30];
    int num;
    int find; // How way do you find the book

    printf("How do you find the book both book_title(#1) and book number(#2) : ");
    scanf("%d", &find);
    if(find == 1){
        printf("Enter book name that you want to borrow : ");
        scanf("%s", name);
        for(int i = 0; i < 100; i++){
            if (compare(name, book_title[i]) == 1){
                if(borrowed[i] == 1){
                    printf("\nAlready borrowed.\n");
                    return 0;
                }
                borrowed[i] = 1;
                printf("Success! \n");
            }
        }
    }else if(find == 2){
        printf("Enter the book number : ");
        scanf("%d", &num);
        if(borrowed[num - 1] == 1){
            printf("Already borrowed.\n");
            return 0;
        }
        borrowed[num - 1] = 1;
        printf("Success! \n");
    }
    
    return 0;
}
int restore(char (*book_title)[30], int *borrowed){
    char name[30];
    int num;
    int find;

    printf("How do you find the book both book_title(#1) and book number(#2) : ");
    scanf("%d", &find);
    if(find == 1){
        printf("Enter book name that you want to restore : ");
        scanf("%s", name);
        for(int i = 0; i < 100; i++){
            if (compare(name, book_title[i]) == 1){
                borrowed[i] = 0;;
            }
        }
    }else if(find == 2){
        printf("Enter the book number : ");
        scanf("%d", &num);
        borrowed[num - 1] = 0;
    }
    return 0;
}
int search(char (*book_title)[30], char (*book_author)[30], char (*book_publisher)[30], int *borrowed){
    int find;
    int i;
    char name[30];
    printf("What do you search about the book ?\n 1. Title  2. Author   3. Publisher \n>> :");
    scanf("%d", &find);
    printf("\nThe name of book is : ");
    scanf("%s", name);
    switch (find)
    {
    case 1: //Find for title
        for(i = 0; i < 100; i++){
            if(similar(name, book_title[i]) == 1){
                printf("Contaning word is : %s \n", book_title[i]);
            }
        }
        printf("\n");
        for(i = 0; i < 100; i++){
            if (compare(name, book_title[i]) == 1){
                printf("%d_book : Author, Publisher, Borrowing status \n: ", i+1);
                printf(">> %s, %s, %d \n", book_author[i], book_publisher[i], borrowed[i]);
            }
        }
        printf("\n");
        break;
    case 2: //Find for Author
        for(i = 0; i < 100; i++){
            if (compare(name, book_author[i]) == 1){
                printf("\n The information of book_%d : Title, Publisher, Borrowing status \n: ", i+1);
                printf(">> %s, %s, %d \n", book_title[i], book_publisher[i], borrowed[i]);
            }
        }
        printf("\n");
        break;
    case 3: // Find for Fublisher
        for(i = 0; i < 100; i++){
            if (compare(name, book_publisher[i]) == 1){
                printf("%d_book : Title, Author, Borrowing status \n: ", i+1);
                printf(">> %s, %s, %d \n", book_title[i], book_author[i], borrowed[i]);
            }
        }
        printf("\n");
        break;
    default:
        printf("That information is not correct \n");
        break;
    }
    return 0;
}

int compare(char *a, char *b){
    
    while(*a){
        if(*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    if(*b == 0) return 1;  // 0대신 '\0' 또는 (char)NULL을 쓸 수도 있다.

    return 0;
}
int similar(char *a, char *b){ // a 찾고 싶은 단어, b 검색대상.  //있으면 1 없으면 0
    while(*a){
        if(*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}