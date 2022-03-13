#include<stdio.h>
#include<stdlib.h>
struct SinhVien
{
	char ten[20];
	char ma[10];
	int namsinh;
	float dtb;
	int songaynghi;
};

void NhapMang(struct SinhVien a[], int n);
void XuatMang(struct SinhVien a[], int n);
void XuatSV(struct SinhVien a[], int  n);

void NhapMang(struct SinhVien a[], int n){
	
	do{
		printf("Cho biet so Sinh vien: ");
		scanf("%d", &n);
	} while (n <= 0);
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("Thong tin Sinh vien thu %d la: \n", i);
		printf("Ten: \n");
		fflush(stdin);
		gets(a[i].ten);
		printf("Ma so: \n");
		fflush(stdin);
		gets(a[i].ma);
		printf("Nam sinh :\n");
		scanf("%d", &a[i].namsinh);
		printf("Diem Trung Binh: \n");
		scanf("%f", &a[i].dtb);
		printf("So ngay nghi: \n");
		scanf("%d", &a[i].songaynghi);
	}
}
void XuatMang(struct SinhVien a[], int n){
	printf("Ten\t\t   Ma\t\t NamSinh\t DTB\t \tSoNgayNghi");
	int i;
	for (i = 1; i <= n; i++){
		printf("\n%s  %s \t %d \t\t %f \t%d\n", a[i].ten,a[i].ma, a[i].namsinh, a[i].dtb, a[i].songaynghi);
	}
}
void main(){
	struct SinhVien A[100];
	int N;
	NhapMang(A, N);
	XuatMang(A, N);
	getch();
}
