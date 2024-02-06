#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("./libcalc.so", RTLD_LAZY); // Загрузка динамической библиотеки
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    int choice = 0;
    int num1, num2, result;

    int (*add)(int, int);
    int (*sub)(int, int);
    int (*mul)(int, int);
    int (*div)(int, int);

    add = dlsym(handle, "addition");  // Получение указателей на функции из динамической библиотеки
    sub = dlsym(handle, "subtraction");
    mul = dlsym(handle, "multiplication");
    div = dlsym(handle, "division");

    do {
        printf("\nВыберите операцию:\n");
        printf("1) Сложение\n");
        printf("2) Вычитание\n");
        printf("3) Умножение\n");
        printf("4) Деление\n");
        printf("5) Выход\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nВведите первое число: ");
                scanf("%d", &num1);
                printf("\nВведите второе число: ");
                scanf("%d", &num2);
                result = add(num1, num2);
                printf("\nРезультат: %d\n", result);
                break;
            case 2:
                printf("\nВведите первое число: ");
                scanf("%d", &num1);
                printf("\nВведите второе число: ");
                scanf("%d", &num2);
                result = sub(num1, num2);
                printf("\nРезультат: %d\n", result);
                break;
            case 3:
                printf("\nВведите первое число: ");
                scanf("%d", &num1);
                printf("\nВведите второе число: ");
                scanf("%d", &num2);
                result = mul(num1, num2);
                printf("\nРезультат: %d\n", result);
                break;
            case 4:
                printf("\nВведите первое число: ");
                scanf("%d", &num1);
                printf("\nВведите второе число: ");
                scanf("%d", &num2);
                result = div(num1, num2);
                printf("\nРезультат: %d\n", result);
                break;
            case 5:
                printf("Программа завершена.\n");
                break;
            default:
                printf("Неправильный выбор операции.\n");
        }
    } while (choice != 5);


    dlclose(handle);  // Закрытие динамической библиотеки

    return 0;
}

