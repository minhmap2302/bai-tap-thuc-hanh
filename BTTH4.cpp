
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Hàm ki?m tra s? có ph?i là dãy không gi?m hay không
int isNonDecreasing(int number) {
    int prevDigit = 10; // Giá tri bat dau cho phép là 10 (chu so truoc tat ca các chi so)
    
    while (number > 0) {
        int digit = number % 10;
        if (digit > prevDigit) {
            return 0; // Neu có chu so nho hon chu so truoc dó, tra ve 0
        }
        prevDigit = digit;
        number /= 10;
    }
    
    return 1; // Neu tat ca chu so deu không giam, tra ve 1
}

int main() {
    char line[MAX_SIZE];
    int numbers[MAX_SIZE], count = 0;
    
    // Ð?c tat ca các so tu dau vào
    printf("Nhap dãy so (ket thúc bang EOF):\n");
    while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            int num = 0;
            // Chuyen dai chuoi token thành so nguyên
            for (int i = 0; token[i] != '\0'; i++) {
                if (isdigit(token[i])) {
                    num = num * 10 + (token[i] - '0');
                }
            }
            numbers[count++] = num;
            token = strtok(NULL, " \n");
        }
    }
    
    // M?ng d? d?m s? l?n xu?t hi?n c?a các s? không gi?m
    int freq[MAX_SIZE] = {0};
    
    // Duy?t qua t?ng s? trong m?ng numbers
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i])) {
            freq[numbers[i]]++;
        }
    }
    
    // In ra các s? không gi?m và s? l?n xu?t hi?n
    printf("Các s? không gi?m và s? l?n xu?t hi?n:\n");
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i]) && freq[numbers[i]] > 0) {
            printf("S? %d xu?t hi?n %d l?n\n", numbers[i], freq[numbers[i]]);
            freq[numbers[i]] = 0; // Ð?m b?o ch? in m?t l?n
        }
    }

    return 0;
}
