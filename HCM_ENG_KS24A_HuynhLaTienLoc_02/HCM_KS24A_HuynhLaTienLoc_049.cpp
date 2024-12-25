#include <stdio.h>
#include <stdbool.h>

void nhapmang(int arr[], int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienthimang(int arr[], int n) {
    printf("Cac gia tri cua mang: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    printf("\n");
}

int demphantuchan(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int timgiatrilonthuhai(int arr[], int n) {
    int first = arr[0], second = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

void themphantudaumang(int arr[], int *n, int value) {
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
}

void xoaphantutaivitri(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sapxepgiamdanbubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100];  
    int n = 0, c;

    do {
        printf("==MENU==\n");
        printf("1. Nhap so phan tu va gia tri trong mang\n");
        printf("2. In ra gia tri trong mang\n");
        printf("3. Dem so luong phan tu chan trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao dau mang\n");
        printf("6. Xoa mot phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Insertion Sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary Search)\n");
        printf("9. In ra cac so nguyen to trong mang va binh phuong cua chung\n");
        printf("10. Sap xep mang theo thu tu giam dan (Bubble Sort)\n");
        printf("11. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                nhapmang(arr, &n);
                break;
            case 2:
                hienthimang(arr, n);
                break;
            case 3:
                printf("So luong phan tu chan trong mang: %d\n", demPhanTuChan(arr, n));
                break;
            case 4:
                printf("Gia tri lon thu hai trong mang: %d\n", timgiatrilonthuhai(arr, n));
                break;
            case 5:
                int value;
                printf("Nhap gia tri can them vao dau mang: ");
                scanf("%d", &value);
                themphantudaumang(arr, &n, value);
                break;
            case 6:
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                xoaphantutaivitri(arr, &n, pos);
                break;
            case 10:
                sapxepgiamdanbubbleSort(arr, n);
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (c != 11);

    return 0;
}

