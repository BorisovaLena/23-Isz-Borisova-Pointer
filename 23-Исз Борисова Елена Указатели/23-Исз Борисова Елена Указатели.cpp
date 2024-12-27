#include <iostream>
#include <malloc.h>

void input_one_dimensional_array(int* array, int size) //ввод одномерного массива
{
    for (int i = 0; i < size; i++)
    {
        printf("Введите элемент [%d] = ", i);
        scanf_s("%d", (array + i));
    }
}
void print_one_dimensional_array(int* array, int size) //вывод одномерного массива
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }
}

void input_two_dimensional_array(int* array, int n, int m) //ввод двумерного массива
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Введите элемент [%d][%d] = ", i, j);
            scanf_s("%d", (array + i * m + j));
        }
    }
}

void print_two_dimensional_array(int* array, int n, int m) //вывод двумерного массива
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(array + i * m + j));
        }
        printf("\n");
    }
}

int sum_data(int* array, int size) //вычисление суммы элементов массива
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }
    return sum;
}

int main() {
    system("chcp 1251>null");

    printf("Задание 1 (а): Создать одномерный числовой массив, заполнить его, вывести значения на экран (памать под массив должна быть выделена динамически).\n");
    int size = 0;
    printf("Введите размер массива: \n");
    scanf_s("%d", &size);
    int* array_A = (int*)malloc(size * sizeof(int));
    input_one_dimensional_array(array_A, size);
    print_one_dimensional_array(array_A, size);
    free(array_A);

    printf("\n");

    printf("Задание 1 (б): Создать двумерный числовой массив, заполнить его, вывести значения на экран (памать под массив должна быть выделена динамически).\n");
    int n, m = 0;
    printf("Введите количество строк: ");
    scanf_s("%d", &n);
    printf("Введите количество столбцов: ");
    scanf_s("%d", &m);
    int* array_B = (int*)malloc(n * m * sizeof(int));
    input_two_dimensional_array(array_B, n, m);
    print_two_dimensional_array(array_B, n, m);
    free(array_B);

    printf("\n");

    printf("Задание 1 (в): Создать строку (массив символов), заполнить его, вывести значения на экран (памать под массив должна быть выделена динамически).\n");
    int count = 0;
    printf("Введите количество символов: ");
    scanf_s("%d", &count);
    char* str = (char*)malloc(sizeof(char) * count + 2);
    while (getchar() != '\n');
    for (int i = 0; i < count; i++)
    {
        scanf_s("%c", &str[i]);
    }
    str[count] = '\0';
    printf("Введенная строка: %s \n", str);
    free(str);


    printf("\n");

    printf("Задание 2: Вычислить сумму элементов массива, не используя переменные с индексом.\n");
    size = 0;
    printf("Введите размер массива: ");
    scanf_s("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));
    input_one_dimensional_array(array, size);
    print_one_dimensional_array(array, size);
    int sum = sum_data(array, size);
    printf("\nСумма элементов массива равна %d", sum);

    free(array);

    return 0;
}
