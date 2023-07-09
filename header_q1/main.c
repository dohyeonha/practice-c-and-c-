/*(이전에 만든)도서 관리 프로그램을만들되,구조체를 이용해 봅시다. 또한 register_book 과 같은 함수를 이용하여 책을 등록해봅시다.*/
#include <stdio.h>
#include "function.h"
// #include "str.h"
#include "struct.h"

// int add(struct BOOK *book, int num);
// int borrow(struct BOOK *book);
// int restore(struct BOOK *book);
// int search(struct BOOK *book);

// int compare(char *a, char *b);
// int similar(char *a, char *b); // 찾고 싶은 대상, 피 검색어


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