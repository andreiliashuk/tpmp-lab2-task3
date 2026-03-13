/*
 * Author: Андрей Ляшук, группа 10
 */
#ifndef ZNAK_H
#define ZNAK_H
typedef struct {
    int year;   /* Year (e.g., 1990) */
    int month;  /* Month (1-12) */
    int day;    /* Day (1-31) */
} Date;

/*
 * ZNAK structure containing personal information and zodiac sign.
 */
typedef struct {
    char name[50];        /* Full name (surname and first name) */
    char zodiac[20];      /* Zodiac sign */
    Date birth_date;      /* Birth date */
} ZNAK;

/*
 * Function: input_znak_array
 *   Reads data from keyboard into an array of ZNAK structures.
 *   arr: array of ZNAK structures
 *   size: maximum number of elements to read
 *   returns: number of successfully read elements
 */
int input_znak_array(ZNAK arr[], int size);

/*
 * Function: sort_by_date
 *   Sorts ZNAK array by birth date in ascending order.
 *
 *   arr: array to sort
 *   n: number of elements in the array
 */
void sort_by_date(ZNAK arr[], int n);

/*
 * Function: print_by_zodiac
 *   Prints information about people with given zodiac sign.
 *   arr: array of ZNAK structures
 *   n: number of elements in the array
 *   zodiac: zodiac sign to search for
 *   returns: number of found people
 */
int print_by_zodiac(const ZNAK arr[], int n, const char zodiac[]);

/*
 * Function: print_znak
 *   Prints a single ZNAK structure.
 *   z: structure to print
 */
void print_znak(const ZNAK z);

#endif /* ZNAK_H */
