#ifndef _MAIN_H_
#define _MAIN_H_

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int is_digit(char c);
void print_result(int *result, int len_r);
int str_len(char *str);
void *_calloc(unsigned int bytes, unsigned int size);
int *multiply(char *num1, char *num2);

#endif
