#include <stdio.h>

// Case 1: Ham them gia tri cac phan tu
void addItem(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap gia tri phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// Case 2: Ham in ra cac phan tu trong mang
void printItems(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu [%d] co gia tri la %d\n", i, arr[i]);
    }
}

// Case 3: Ham chen phan tu vao vi tri chi dinh
void insertItem(int arr[], int *size, int pos, int value) {
    if (pos < 0 || pos > *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    printf("Da chen thanh cong!\n");
}

// Case 4: Ham sua phan tu o vi tri chi dinh
void updateItem(int arr[], int size, int pos, int value) {
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    arr[pos] = value;
    printf("Da sua thanh cong!\n");
}

// Case 5: Ham xoa phan tu o vi tri chi dinh
void deleteItem(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Da xoa thanh cong!\n");
}

// Case 6: Ham sap xep tang dan
void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Da sap xep tang dan!\n");
}

// Case 6: Ham sap xep giam dan
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Da sap xep giam dan!\n");
}

// Case 7: Ham tim kiem tuyen tinh
void linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Tim thay gia tri %d tai vi tri %d\n", value, i);
            return;
        }
    }
    printf("Khong tim thay gia tri %d\n", value);
}

// Case 7: Ham tim kiem nhi phan
void binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            printf("Tim thay gia tri %d tai vi tri %d\n", value, mid);
            return;
        }
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Khong tim thay gia tri %d\n", value);
}

int main() {
    int arr[100];
    int choose;
    int size = 0;

    do {
        printf("-----MENU-----\n");
        printf("1. Nhap so luong phan tu va gia tri\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Moi ban nhap lua chon: ");
        scanf("%d", &choose);

        switch (choose) {
        case 1: {
            printf("Nhap so luong phan tu: ");
            scanf("%d", &size);
            addItem(arr, size); // Goi case 1
            break;
        }
        case 2:
            printItems(arr, size); // Goi case 2
            break;
        case 3: {
            int pos, value;
            printf("Nhap vi tri can chen: ");
            scanf("%d", &pos);
            printf("Nhap gia tri can chen: ");
            scanf("%d", &value);
            insertItem(arr, &size, pos, value); // Goi case 3
            break;
        }
        case 4: {
            int pos, value;
            printf("Nhap vi tri can sua: ");
            scanf("%d", &pos);
            printf("Nhap gia tri moi: ");
            scanf("%d", &value);
            updateItem(arr, size, pos, value); // Goi case 4
            break;
        }
        case 5: {
            int pos;
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &pos);
            deleteItem(arr, &size, pos); // Goi case 5
            break;
        }
        case 6: {
            int sortChoice;
            printf("1. Sap xep tang dan\n");
            printf("2. Sap xep giam dan\n");
            printf("Nhap lua chon: ");
            scanf("%d", &sortChoice);
            if (sortChoice == 1)
                sortAscending(arr, size); // Goi case 6a
            else if (sortChoice == 2)
                sortDescending(arr, size); // Goi case 6b
            else
                printf("Lua chon khong hop le!\n");
            break;
        }
        case 7: {
            int searchChoice, value;
            printf("1. Tim kiem tuyen tinh\n");
            printf("2. Tim kiem nhi phan\n");
            printf("Nhap lua chon: ");
            scanf("%d", &searchChoice);
            printf("Nhap gia tri can tim: ");
            scanf("%d", &value);
            if (searchChoice == 1)
                linearSearch(arr, size, value); // Goi case 7a
            else if (searchChoice == 2) {
                sortAscending(arr, size); // Sap xep truoc khi tim kiem nhi phan
                binarySearch(arr, size, value); // Goi case 7b
            } else
                printf("Lua chon khong hop le!\n");
            break;
        }
        case 8:
            printf("Thoat chuong trinh!\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choose != 8);

    return 0;
}

