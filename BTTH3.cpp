
#include <stdio.h>

// H�m in d�y so
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// H�m thuc hien thuat to�n sap xep dai truc tiep
void bubbleSort(int arr[], int n) {
    printf("D�y ban d?u: ");
    printArray(arr, n);
    
    for (int i = 0; i < n - 1; i++) { // L?p qua c�c v�ng
        printf("Bu?c %d:\n", i + 1);
        int swapped = 0; // �e kiem tra c� dai hay kh�ng
        
        for (int j = 0; j < n - i - 1; j++) { // So s�nh tung cap
            if (arr[j] > arr[j + 1]) { // �ai neu kh�ng d�ng th? t?
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printArray(arr, n); // In trang th�i sau moi buoc
        
        // Neu kh�ng c� so dai n�o?, d�y d� sap xep xong
        if (!swapped) {
            printf("Kh�ng c� ho�n vi, d�y d� sap xep.\n");
            break;
        }
    }
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Nhap c�c phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("D�y d� sap xep: ");
    printArray(arr, n);
    
    return 0;
}

