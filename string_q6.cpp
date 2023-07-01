/*도서 관리 프로그램을 만들어봅시다. 프로그램에는 다음과 같은 기능들이 구현되어 있어야 합니다. (난이도 : 上)

책을 새로 추가하는 기능 (책의 총 개수는 100 권이라 하자. 이 때, 각 책의 정보는 제목, 저자의 이름, 출판사로 한다)

책의 제목을 검색하면 그 책의 정보가 나와야 한다.

위와 마찬가지로 저자, 출판사 검색 기능이 있어야 한다.

책을 빌리는 기능.

책을 반납하는 기능*/
#include <stdio.h>

int add(char *p, char *q, char *r, int *s, int a);
int borrow(char (*p)[30], char *q, int (*r)[2]);
int restore(char (*p)[30], char *q, int (*r)[2]);
int search(char (*p)[30], char (*q)[30], char (*r)[30], int (*s)[2]);

int compare(char *a, char *b);

int main(){
    int program; // 1: add, 2: search, 3: borrow, 4: restore, 0: terminate
    char book_title[100][30];
    char book_author[100][30];
    char book_publisher[100][30];
    int book_exist[100][2]; // 책 추가된 순서와 빌림여부: 책 빌렸으면 1 안 빌렸으면 0.
    int i = 0;
    char name[30];
    printf(" What do you want to do? \n1. add \n2. search \n3. borrow \n4. restore \n0. terminate \n>> :  ");
    scanf("%d", &program);
    while(program){

        switch (program)
        {
        case 1: //add
            add(book_title[i], book_author[i], book_publisher[i], book_exist[i], i);
            i++;
            break; 
        case 2: //search
            search(book_title, book_author, book_publisher, book_exist);
            break;
        case 3: //borrow
            printf("Write book name that you want to borrow : ");
            scanf("%s", name);
            borrow(book_title, name, book_exist);
            break;
        case 4: //restore
            printf("Write book name that you want to restore : ");
            scanf("%s", name);
            restore(book_title, name, book_exist);
            break;    
        default:
            printf("Please enter the exact number \n");
            break;
        
        }
        printf(" What do you want to do ? \n1. add \n2. search \n3. borrow \n4. restore \n0. terminate \n>> : ");
        scanf("%d", &program);
    }
    printf("The program is terminated.\n");
    return 0;
}
int add(char *p, char *q, char *r, int *s, int a){
    printf("book_%d\n",(a+1));
    *s = (a+1); // 책 번호 작성.
    *(s+1) = 0; // 안 빌린 상태.
    printf("What is the title of book : \n");
    scanf("%s", p); 

    printf("What is the author of book : \n");
    scanf("%s", q);

    printf("What is the publisher of book : \n");
    scanf("%s", r);
    return 0;
}
int search(char (*p)[30], char (*q)[30], char (*r)[30], int (*s)[2]){
    int find;
    int i, j;
    char name[30];
    printf("What do you search about the book ?\n 1. Title  2. Author   3. Publisher \n>> :");
    scanf("%d", &find);
    printf("\nThe name is : ");
    scanf("%s", name);
    switch (find)
    {
    case 1: //Find for title
        printf(" Author, Publisher, Borrowing status \n: ");
        for(i = 0; i < 100; i++){
            if (compare(name, p[i]) == 1){
                printf("%s, %s, %d \n", q[i], r[i], s[i][1]);
            }
        }
        printf("\n");
        break;
    case 2: //Find for Author
        printf(" Title, Publisher, Borrowing status \n: ");
        for(i = 0; i < 100; i++){
            if (compare(name, q[i]) == 1){
                printf("%s, %s, %d \n", p[i], r[i], s[i][1]);
            }
        }
        printf("\n");
        break;
    case 3: // Find for Fublisher
        printf(" Title, Author, Borrowing status \n: ");
        for(i = 0; i < 100; i++){
            if (compare(name, r[i]) == 1){
                printf("%s, %s, %d \n", p[i], q[i], s[i][1]);
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
int borrow(char (*p)[30], char *q, int (*r)[2]){ // p : book_title, q : name, 
    for(int i = 0; i < 100; i++){
        if (compare(q, p[i]) == 1){
            r[i][1] = 1;;
        }
    }
    return 0;
}
int restore(char (*p)[30], char *q, int (*r)[2]){
    for(int i = 0; i < 100; i++){
        if (compare(q, p[i]) == 1){
            r[i][1] = 0;;
        }
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