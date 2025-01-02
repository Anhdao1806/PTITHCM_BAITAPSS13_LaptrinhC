#include <stdio.h>
#define MAX 100
int nhapMang(int mang[]) {
    int soPhanTu;
    printf("Nhap so phan tu: ");
    scanf("%d", &soPhanTu);
    printf("Nhap gia tri cac phan tu:\n");
    for (int i = 0; i < soPhanTu; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
    return soPhanTu;
}
int inMang(int mang[], int soPhanTu) {
    if (soPhanTu == 0) {
        printf("Mang rong!\n");
    } else {
        printf("Gia tri cac phan tu trong mang:\n");
        for (int i = 0; i < soPhanTu; i++) {
            printf("%d ", mang[i]);
        }
        printf("\n");
    }
    return soPhanTu;
}
int themPhanTu(int mang[], int soPhanTu) {
    int viTri, giaTri;
    printf("Nhap vi tri muon them: ");
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > soPhanTu) {
        printf("Vi tri khong hop le!\n");
        return soPhanTu;
    }
    printf("Nhap gia tri cua phan tu: ");
    scanf("%d", &giaTri);

    for (int i = soPhanTu; i > viTri; i--) mang[i] = mang[i - 1];
    mang[viTri] = giaTri;
    return soPhanTu + 1;
}
int suaPhanTu(int mang[], int soPhanTu) {
    int viTri, giaTri;
    printf("Nhap vi tri muon sua: ");
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= soPhanTu) {
        printf("Vi tri khong hop le!\n");
        return soPhanTu;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTri);
    mang[viTri] = giaTri;
    return soPhanTu;
}
int xoaPhanTu(int mang[], int soPhanTu) {
    int viTri;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= soPhanTu) {
        printf("Vi tri khong hop le!\n");
        return soPhanTu;
    }
    for (int i = viTri; i < soPhanTu - 1; i++) mang[i] = mang[i + 1];
    return soPhanTu - 1;
}
int sapXep(int mang[], int soPhanTu, int chon) {
    int temp;
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if ((chon == 1 && mang[i] < mang[j]) || (chon == 2 && mang[i] > mang[j])) {
                temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
    return soPhanTu;
}
int timKiemTuyenTinh(int mang[], int soPhanTu, int giaTri) {
    for (int i = 0; i < soPhanTu; i++) {
        if (mang[i] == giaTri) {
            return i;
        }
    }
    return -1;
}
int timKiemNhiPhan(int mang[], int soPhanTu, int giaTri) {
    int trai = 0, phai = soPhanTu - 1;
    while (trai <= phai) {
        int giua = (trai + phai) / 2;
        if (mang[giua] == giaTri) {
            return giua;
        }
        if (mang[giua] < giaTri) {
            trai = giua + 1;
        } else {
            phai = giua - 1;
        }
    }
    return -1;
}
int main() {
    int mang[MAX], soPhanTu = 0, chon, giaTri, viTri;
    while (1) {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. Them mot phan tu\n");
        printf("4. Sua mot phan tu\n");
        printf("5. Xoa mot phan tu\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                soPhanTu = nhapMang(mang);
                break;
            case 2:
                soPhanTu = inMang(mang, soPhanTu);
                break;
            case 3:
                soPhanTu = themPhanTu(mang, soPhanTu);
                break;
            case 4:
                soPhanTu = suaPhanTu(mang, soPhanTu);
                break;
            case 5:
                soPhanTu = xoaPhanTu(mang, soPhanTu);
                break;
            case 6:
                printf("1. Sap xep giam dan\n");
                printf("2. Sap xep tang dan\n");
                printf("Chon chuc nang: ");
                scanf("%d", &chon);
                soPhanTu = sapXep(mang, soPhanTu, chon);
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &giaTri);
                printf("1. Tim kiem tuyen tinh\n");
                printf("2. Tim kiem nhi phan\n");
                printf("Chon chuc nang: ");
                scanf("%d", &chon);
                if (chon == 1) viTri = timKiemTuyenTinh(mang, soPhanTu, giaTri);
                else if (chon == 2) viTri = timKiemNhiPhan(mang, soPhanTu, giaTri);
                if (viTri != -1) {
                    printf("Tim thay tai vi tri %d\n", viTri);
                } else {
                    printf("Khong tim thay\n");
                }
                break;
            case 8:
                return 0;
            default:
                printf("Chuc nang khong hop le!\n");
        }
    }
    return 0;
}

