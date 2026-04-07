#include <stdio.h>
#include <stdint.h>

#define CHIP8_MEMORY_SIZE	4096
#define CHIP8_DISPLAY_WIDTH	64
#define CHIP8_DISPLAY_HEIGHT	32
#define V_REGISTER_COUNT	16
#define STACK_DEPTH		16
#define CHIP8_KEY_COUNT		16


int main() {
	typedef struct Chip8State{
		int a;
		int b;
	};
	printf("Hello, World!");
	return 0;
}

#include <stdio.h>

int main() {
	lab7_t4();
}
void lab7_t4() {
	int n;
	printf("Введите размер массива: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Размер массива должен быть положительным числом.\n");
		return 1;
	}

	int arr[n];

	printf("Введите %d элементов массива:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int max_index = 0, min_index = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[max_index]) {
			max_index = i;
		}
		if (arr[i] < arr[min_index]) {
			min_index = i;
		}
	}

	int temp = arr[max_index];
	arr[max_index] = arr[min_index];
	arr[min_index] = temp;

	printf("Изменённый массив:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

#include <stdio.h>

int main() {
	lab7_t5();
}
void lab7_t5() {
	int array[15];
	int i;

	int positive = 0;
	int negative = 0;
	int zero = 0;


	printf("Введите 15 элементов массива:\n");
	for (int i = 0; i < 15; i++) {
		scanf("%d", &array[i]);
	}


	for (int i = 0; i < 15; i++) {
		if (array[i] > 0) {
			positive++;
		}
		else if (array[i] < 0) {
			negative++;
		}
		else {
			zero++;
		}
	}


	printf("\nРезультаты подсчёта:\n");
	printf("Количество положительных элементов: %d\n", positive);
	printf("Количество отрицательных элементов: %d\n", negative);
	printf("Количество нулевых элементов: %d\n", zero);

	return 0;
}

#include <stdio.h>

#define ROWS 4
#define COLS 4

int main() {
	lab7_t6();
}
void lab7_t6() {
	int matrix[ROWS][COLS];
	int count = 0;

	printf("Введите элементы матрицы 4x4 (по строкам):\n");
	for (int i = 0; i < ROWS; i++) {
		printf("Строка %d: ", i + 1);
		for (int j = 0; j < COLS; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (matrix[i][j] > 0) {
				count++;
			}
		}
	}

	printf("\nМатрица:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\nКоличество элементов, больших нуля: %d\n", count);

	return 0;
}

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
	lab9_t3();
}
void lab9_t3() {
	char text[MAX_LENGTH];

	printf("Введите текст: ");
	fgets(text, MAX_LENGTH, stdin);


	text[strcspn(text, "\n")] = '\0';

	printf("Результат: ");

	for (int i = 0; text[i] != '\0'; i++) {
		if (isalpha(text[i])) {

			char upper_char = toupper(text[i]);

			int position = upper_char - 'A' + 1;
			printf("%d", position);


			if (text[i + 1] != '\0' && isalpha(text[i + 1])) {
				printf(" ");
			}
		}
		else {

			printf("%c", text[i]);
		}
	}
	printf("\n");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_INPUT_LENGTH 1000

int main() {
	lab9_t10();
}
void lab9_t10() {
	char input[MAX_INPUT_LENGTH];
	char words[MAX_WORDS][MAX_WORD_LENGTH];
	int word_count = 0;

	char target_char;
	int k;
	int result_count = 0;


	printf("Введите текст (не более %d символов):\n", MAX_INPUT_LENGTH - 1);
	fgets(input, MAX_INPUT_LENGTH, stdin);


	input[strcspn(input, "\n")] = '\0';


	printf("Введите искомый символ: ");
	scanf("%c", &target_char);
	getchar();


	printf("Введите количество повторений символа (k): ");
	scanf("%d", &k);


	char *token = strtok(input, " \t\n.,;:!?\"()[]{}");
	while (token != NULL && word_count < MAX_WORDS) {
		strncpy(words[word_count], token, MAX_WORD_LENGTH - 1);
		words[word_count][MAX_WORD_LENGTH - 1] = '\0';
		word_count++;
		token = strtok(NULL, " \t\n.,;:!?\"()[]{}");
	}


	for (int i = 0; i < word_count; i++) {
		int char_count = 0;


		for (int j = 0; words[i][j] != '\0'; j++) {
			if (words[i][j] == target_char) {
				char_count++;
			}
		}


		if (char_count == k) {
			result_count++;
		}
	}

	// Вывод результата
	printf("\nРезультат:\n");
	printf("Символ '%c' встречается ровно %d раз в %d словах.\n", target_char, k, result_count);

	if (result_count > 0) {
		printf("Слова, удовлетворяющие условию:\n");
		for (int i = 0; i < word_count; i++) {
			int char_count = 0;
			for (int j = 0; words[i][j] != '\0'; j++) {
				if (words[i][j] == target_char) {
					char_count++;
				}
			}
			if (char_count == k) {
				printf("  - %s\n", words[i]);
			}
		}
	}

	return 0;
}


