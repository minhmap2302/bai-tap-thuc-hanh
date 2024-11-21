
#include <stdio.h>

// Hàm in dãy so
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm thuc hien thuat toán sap xep dai truc tiep
void bubbleSort(int arr[], int n) {
    printf("Dãy ban d?u: ");
    printArray(arr, n);
    
    for (int i = 0; i < n - 1; i++) { // L?p qua các vòng
        printf("Bu?c %d:\n", i + 1);
        int swapped = 0; // Ðe kiem tra có dai hay không
        
        for (int j = 0; j < n - i - 1; j++) { // So sánh tung cap
            if (arr[j] > arr[j + 1]) { // Ðai neu không dúng th? t?
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printArray(arr, n); // In trang thái sau moi buoc
        
        // Neu không có so dai nào?, dãy dã sap xep xong
        if (!swapped) {
            printf("Không có hoán vi, dãy dã sap xep.\n");
            break;
        }
    }
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Nhap các phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("Dãy dã sap xep: ");
    printArray(arr, n);
    
    return 0;
}

