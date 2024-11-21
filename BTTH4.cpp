
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// H�m ki?m tra s? c� ph?i l� d�y kh�ng gi?m hay kh�ng
int isNonDecreasing(int number) {
    int prevDigit = 10; // Gi� tri bat dau cho ph�p l� 10 (chu so truoc tat ca c�c chi so)
    
    while (number > 0) {
        int digit = number % 10;
        if (digit > prevDigit) {
            return 0; // Neu c� chu so nho hon chu so truoc d�, tra ve 0
        }
        prevDigit = digit;
        number /= 10;
    }
    
    return 1; // Neu tat ca chu so deu kh�ng giam, tra ve 1
}

int main() {
    char line[MAX_SIZE];
    int numbers[MAX_SIZE], count = 0;
    
    // �?c tat ca c�c so tu dau v�o
    printf("Nhap d�y so (ket th�c bang EOF):\n");
    while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            int num = 0;
            // Chuyen dai chuoi token th�nh so nguy�n
            for (int i = 0; token[i] != '\0'; i++) {
                if (isdigit(token[i])) {
                    num = num * 10 + (token[i] - '0');
                }
            }
            numbers[count++] = num;
            token = strtok(NULL, " \n");
        }
    }
    
    // M?ng d? d?m s? l?n xu?t hi?n c?a c�c s? kh�ng gi?m
    int freq[MAX_SIZE] = {0};
    
    // Duy?t qua t?ng s? trong m?ng numbers
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i])) {
            freq[numbers[i]]++;
        }
    }
    
    // In ra c�c s? kh�ng gi?m v� s? l?n xu?t hi?n
    printf("C�c s? kh�ng gi?m v� s? l?n xu?t hi?n:\n");
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i]) && freq[numbers[i]] > 0) {
            printf("S? %d xu?t hi?n %d l?n\n", numbers[i], freq[numbers[i]]);
            freq[numbers[i]] = 0; // �?m b?o ch? in m?t l?n
        }
    }

    return 0;
}
