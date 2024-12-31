#include <stdio.h>
int nhapPhanTu(int n, int m, int maTran[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        printf("Nhap gia tri phan tu maTran[%d][%d]: ", i, j);
        scanf("%d", &maTran[i][j]);
        }
    }
    return 0;
}
int inPhanTuTheoMaTran(int n, int m, int maTran[n][m]) {
    printf("Gia tri cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int inPhanTuGoc(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu o goc:\n");
    printf("%d ", maTran[0][0]);
    printf("%d ", maTran[0][m - 1]);
    printf("%d ", maTran[n - 1][0]);
    printf("%d\n", maTran[n - 1][m - 1]);
    return 0;
}
int inDuongBien(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu tren duong bien:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        printf("%d ", maTran[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}
int inDuongCheo(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        if (i == j || i + j == m - 1) {
        printf("%d ", maTran[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
    }
    return 1;
}
int inSoNguyenTo(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        if (laSoNguyenTo(maTran[i][j])) {
        printf("%d ", maTran[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}
int main() {
    int n, m;
    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    int maTran[n][m];
    int luaChon;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapPhanTu(n, m, maTran);
                break;
            case 2:
                inPhanTuTheoMaTran(n, m, maTran);
                break;
            case 3:
                inPhanTuGoc(n, m, maTran);
                break;
            case 4:
                inDuongBien(n, m, maTran);
                break;
            case 5:
                inDuongCheo(n, m, maTran);
                break;
            case 6:
                inSoNguyenTo(n, m, maTran);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!.\n");
        }
    } while (luaChon != 7);

    return 0;
}

