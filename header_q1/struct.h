#ifndef STRUCT_H
#define STRUCT_H
struct BOOK
{
    char title[100][30];
    char auth[100][30];
    char publ[100][30];
    int borrowed[100];
    int book_number;
};

#endif