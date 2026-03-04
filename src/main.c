#include <stdio.h>
#include "znak.h"

#define MAX_PEOPLE 10

int main() {
    ZNAK people[MAX_PEOPLE];
    int count;
    char search_zodiac[20];
    
    printf(" Программа для работы со структурой ZNAK (Вариант 8) \n");
    count = input_znak_array(people, MAX_PEOPLE);
    
    if (count == 0) {
        printf("Нет данных для обработки. Завершение программы.\n");
        return 1;
    }
    printf("\n Введённые данные (%d человек) \n", count);
    for (int i = 0; i < count; i++) {
        print_znak(people[i]);
    }
    sort_by_date(people, count);
    printf("\n Данные, упорядоченные по дате рождения \n");
    for (int i = 0; i < count; i++) {
        print_znak(people[i]);
    }
    printf("\n Поиск по знаку зодиака \n");
    printf("Введите знак зодиака для поиска: ");
    scanf(" %[^\n]", search_zodiac);
    print_by_zodiac(people, count, search_zodiac);
    return 0;
}
