/*
 * Author: Андрей Ляшук, группа 10
 */
#include <stdio.h>
#include <string.h>
#include "znak.h"
static int compare_dates(Date date1, Date date2) {
    if (date1.year != date2.year) {
        return date1.year - date2.year;
    }
    if (date1.month != date2.month) {
        return date1.month - date2.month;
    }
    return date1.day - date2.day;
}

int input_znak_array(ZNAK arr[], int size) {
    int count = 0;
    printf("Ввод данных для %d человек:\n", size);
    for (int i = 0; i < size; i++) {
        printf("\n--- Человек %d ---\n", i + 1);
        printf("Введите фамилию и имя: ");
        if (scanf(" %[^\n]", arr[i].name) != 1) {
            printf("Ошибка ввода имени. Прерывание.\n");
            break;
        }
        printf("Введите знак зодиака: ");
        if (scanf(" %[^\n]", arr[i].zodiac) != 1) {
            printf("Ошибка ввода знака зодиака. Прерывание.\n");
            break;
        }
        printf("Введите дату рождения (год месяц число): ");
        if (scanf("%d %d %d",
                  &arr[i].birth_date.year,
                  &arr[i].birth_date.month,
                  &arr[i].birth_date.day) != 3) {
            printf("Ошибка ввода даты. Прерывание.\n");
            break;
        }
        count++;
    }
    return count;
}

void sort_by_date(ZNAK arr[], int n) {
    for (int i = 1; i < n; i++) {
        ZNAK key = arr[i];
        int j = i - 1;
        while (j >= 0 && compare_dates(arr[j].birth_date, key.birth_date) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_znak(const ZNAK z) {
    printf("%s | Знак: %s | Дата рождения: %04d-%02d-%02d\n",
           z.name, z.zodiac,
           z.birth_date.year, z.birth_date.month, z.birth_date.day);
}

int print_by_zodiac(const ZNAK arr[], int n, const char zodiac[]) {
    int found = 0;
    printf("\nЛюди, родившиеся под знаком '%s':\n", zodiac);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].zodiac, zodiac) == 0) {
            print_znak(arr[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("Таких людей нет.\n");
    }
    return found;
}
