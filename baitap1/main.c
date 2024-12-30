
#include <stdio.h>
int taoMaTran(int Hang, int Cot, int maTran[Hang][Cot]) {
    printf("Nhap cac phan tu cua ma tran (%dx%d):\n", Hang, Cot);
    for (int hang = 0; hang < Hang; hang++) {
        for (int cot = 0; cot < Cot; cot++) {
        printf("Nhap phan tu [%d][%d]: ", hang, cot);
        scanf("%d", &maTran[hang][cot]);
        }
    }
    return 1;
}
int inMaTran(int Hang, int Cot, int maTran[Hang][Cot]) {
    printf("Ma tran vua nhap:\n");
    for (int hang = 0; hang < Hang; hang++) {
        for (int cot = 0; cot < Cot; cot++) {
        printf("%d ", maTran[hang][cot]);
        }
        printf("\n");
    }
    return 1;
}
int main (){
    int Hang , Cot;
    printf ("Nhap so hang :");
    scanf ("%d",&Hang);
    printf ("Nhap so cot :");
    scanf ("%d",&Cot);
    int maTran[Hang][Cot];
    if (taoMaTran(Hang,Cot,maTran)){
        inMaTran(Hang,Cot,maTran);
    }
    return 0;
}
