#include <stdio.h>

int main() {
    lab7_t5();
}
void lab7_t5()
{
    #define SIZE 10

    
    int arr[SIZE] = {5, -3, 0, 8, -1, 0, 2, -7, 4, 0};
    
    int positive = 0;  // положительные
    int negative = 0;  // отрицательные
    int zero = 0;     // нулевые
    
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] < 0) {
            negative++;
        } else {
            zero++;
        }
    }
    
    printf("Количество положительных элементов: %d\n", positive);
    printf("Количество отрицательных элементов: %d\n", negative);
    printf("Количество нулевых элементов: %d\n", zero);
    
    return 0;
}


