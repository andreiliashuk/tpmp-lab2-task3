/*
 * Author: Андрей Ляшук, группа 10
 */
#ifndef ZNAK_H
#define ZNAK_H
typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[50];
    char zodiac[20];
    Date birth_date;
} ZNAK;


int input_znak_array(ZNAK arr[], int size);

void sort_by_date(ZNAK arr[], int  n);
int print_by_zodiac(const ZNAK arr[], int n, const char zodiac[]);

void print_znak(const ZNAK z);

#endif 
