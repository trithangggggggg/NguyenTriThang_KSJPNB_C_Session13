#include <stdio.h>

void inputarray(int array[100][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

void printarray(int array[100][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void printcorners(int array[100][100], int rows, int cols) {
    printf("Cac phan tu o goc: \n");
    printf("%d %d\n", array[0][0], array[0][cols - 1]);
    printf("%d %d\n", array[rows - 1][0], array[rows - 1][cols - 1]);
}

void printborders(int array[100][100], int rows, int cols) {
    printf("Cac phan tu tren duong bien: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", array[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printdiagonals(int array[100][100], int rows, int cols) {
    printf("Cac phan tu tren duong cheo chinh va phu: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j || i + j == rows - 1) {
                printf("%d ", array[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int isprime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void printprimes(int array[100][100], int rows, int cols) {
    printf("Cac phan tu la so nguyen to: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isprime(array[i][j])) {
                printf("%d ", array[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int array[100][100];
    int choice;

    printf("Nhap so dong: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    do {
        printf("\nMENU\n");
        printf("1. Nhap phan tu cua mang\n");
        printf("2. In mang theo ma tran\n");
        printf("3. In cac phan tu o goc\n");
        printf("4. In cac phan tu tren duong bien\n");
        printf("5. In cac phan tu tren duong cheo chinh va phu\n");
        printf("6. In cac phan tu la so nguyen to\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputarray(array, rows, cols);
                break;
            case 2:
                printarray(array, rows, cols);
                break;
            case 3:
                printcorners(array, rows, cols);
                break;
            case 4:
                printborders(array, rows, cols);
                break;
            case 5:
                printdiagonals(array, rows, cols);
                break;
            case 6:
                printprimes(array, rows, cols);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai.\n");
        }
    } while (choice != 7);

    return 0;
}

