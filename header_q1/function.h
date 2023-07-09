#include <stdio.h>
#include "str.h"
#include "struct.h"
#ifndef FUNCTION_H
#define FUNCTION_H


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

#endif