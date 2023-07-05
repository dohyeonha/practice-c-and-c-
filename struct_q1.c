/*(이전에 만든)도서 관리 프로그램을만들되,구조체를 이용해 봅시다. 또한 register_book 과 같은 함수를 이용하여 책을 등록해봅시다.*/
#include <stdio.h>

struct BOOK
{
    char title[100][30];
    char auth[100][30];
    char publ[100][30];
    int borrowed[100];
    int book_number;
};

int add(struct BOOK *book, int num);
int borrow(struct BOOK *book);
int restore(struct BOOK *book);
int search(struct BOOK *book);

int compare(char *a, char *b);
int similar(char *a, char *b); // 찾고 싶은 대상, 피 검색어


int main(){
    int program;
    int book_number = 0;
    struct BOOK book;
    
    printf(" What do you want to do? \nChoice[1]. add \nChoice[2]. search \nChoice[3]. borrow \nChoice[4]. restore \nChoice[0]. terminate \n>> :  ");
    scanf("%d", &program);
    while(program){

        switch (program)
        {
        case 1: //add
            add(&book, book_number);
            
            book_number++;
            break; 
        case 2: //search
            search(&book);
            break;
        case 3: //borrow
            borrow(&book);
            break;
        case 4: //restore
            restore(&book);
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
int add(struct BOOK *book, int num){

    printf("book_%d\n",(num+1)); // 책 번호
    book->book_number = num + 1;
    book->borrowed[num] = 0; // 안 빌린 상태.
    printf("What is the title of book : \n");
    scanf("%s", book->title[num]); 

    printf("What is the author of book : \n");
    scanf("%s", book->auth[num]);

    printf("What is the publisher of book : \n");
    scanf("%s", book->publ[num]);

    printf("Success! \n");
    return 0;
}
int search(struct BOOK *book){
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
            if(similar(name, book->title[i]) == 1){
                printf("Contaning word is : %s \n", book->title[i]);
            }
        }
        printf("\n");
        for(i = 0; i < 100; i++){
            if (compare(name, book->title[i]) == 1){
                printf("%d_book : Author, Publisher, Borrowing status \n: ", i+1);
                printf(">> %s, %s, %d \n", book->auth[i], book->publ[i], book->borrowed[i]);
            }
        }
        printf("\n");
        break;
    case 2: //Find for Author
        for(i = 0; i < 100; i++){
            if (compare(name, book->auth[i]) == 1){
                printf("\n The information of book_%d : Title, Publisher, Borrowing status \n: ", i+1);
                printf(">> %s, %s, %d \n", book->title[i], book->publ[i], book->borrowed[i]);
            }
        }
        printf("\n");
        break;
    case 3: // Find for Fublisher
        for(i = 0; i < 100; i++){
            if (compare(name, book->publ[i]) == 1){
                printf("%d_book : Title, Author, Borrowing status \n: ", i+1);
                printf(">> %s, %s, %d \n", book->title[i], book->auth[i], book->borrowed[i]);
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
int borrow(struct BOOK *book){
    char name[30];
    int num;
    int find; // How way do you find the book

    printf("How do you find the book both book_title(#1) and book number(#2) : ");
    scanf("%d", &find);
    if(find == 1){
        printf("Enter book name that you want to borrow : ");
        scanf("%s", name);
        for(int i = 0; i < 100; i++){
            if (compare(name, book->title[i]) == 1){
                if(book->borrowed[i] == 1){
                    printf("\nAlready borrowed.\n");
                    return 0;
                }
                book->borrowed[i] = 1;
                printf("Success! \n");
            }
        }
    }else if(find == 2){
        printf("Enter the book number : ");
        scanf("%d", &num);
        if(book->borrowed[num - 1] == 1){
            printf("Already borrowed.\n");
            return 0;
        }
        book->borrowed[num - 1] = 1;
        printf("Success! \n");
    }
    
    return 0;
}
int restore(struct BOOK *book){
    char name[30];
    int num;
    int find;

    printf("How do you find the book both book_title(#1) and book number(#2) : ");
    scanf("%d", &find);
    if(find == 1){
        printf("Enter book name that you want to restore : ");
        scanf("%s", name);
        for(int i = 0; i < 100; i++){
            if (compare(name, book->title[i]) == 1){
                book->borrowed[i] = 0;;
            }
        }
    }else if(find == 2){
        printf("Enter the book number : ");
        scanf("%d", &num);
        book->borrowed[num - 1] = 0;
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