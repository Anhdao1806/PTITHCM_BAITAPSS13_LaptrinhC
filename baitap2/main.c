
#include<stdio.h>
int UCLN ( int a , int b ){
    while ( b !=0){
        int n = b;
        b = a % b ;
        a = n ;
    }
    return a;
}
int main (){
    int a, b ;
    printf ("Nhap so a :");
    scanf ( "%d",&a);
    printf ("Nhap so b :");
    scanf ( "%d",&b);
    int  uocChungLonNhat = UCLN ( a,b);
    printf ("Uoc chung lon nhat cua %d và %d là : %d\n", a,b,uocChungLonNhat);
    return 0;
}
