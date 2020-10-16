/*
1. Họ và tên: Lê Danh Vũ
2. Mã số sinh viên: 2001181427
3. Lớp: 09DHTH4
4. Phòng: A102; Tiết học: 10-12
5. Nội dung: Buổi 1 (Mảng 1 chiều)
*/
//--------------------------------------------------------------------------------
//Khai báo thư viện và hằng (nếu có)
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
//--------------------------------------------------------------------------------
//Khai báo các hàm con
void menu();
void thucthi();
void taoMangChan(int a[], int &n);
void xuatMang(int a[], int n);
void taoMangChanLeXenKe(int a[], int &n);
void lietKePTChuSoDauLe(int a[], int n);
void ptCucTriVaTong(int a[], int n);
void hoanVi(int &a, int &b);
void xoaSoChanThuHai(int a[], int &n);
void lietKePTXuatHienNhieuNhat(int a[], int n);
void nhapMang(int a[], int &n);
void sapXepChanTangVaLeGiam(int a[], int n);
//--------------------------------------------------------------------------------
//Hàm main
void main()
{
	menu();
	thucthi();
	getch();
}
//Hàm menu
void menu()
{
	printf("---------MOI BAN CHON 1 CHUC NANG DE THUC HIEN---------");
	printf("\n1. Tao mang toan chan");
	printf("\n2. Tao mang chan le xen ke");
	printf("\n3. Liet ke phan tu co chu so dau la so le");
	printf("\n4. Xuat cac phan tu cuc tri cua mang va tinh tong chung");
	printf("\n5. Sap xep so chan tang dan, so le giam dan");
	printf("\n6. Xoa so chan thu 2 trong mang tu dau day");
	printf("\n7. Xuat cac phan tu xuat hien nhieu nhat trong mang");
	printf("\n8. Xuat cac phan tu co so lan xuat hien it nhat trong mang");
	printf("\n9. Dem so lan xuat hien cua cac phan tu trong mang");
	printf("\n10. Tim day con giam dai nhat trong mang");
	printf("\n11. Them vao day so x ngay truoc so le nho nhat");
	printf("\n12. Tim so nho thu 2 trong mang");
	printf("\n0. Thoat chuong trinh\n");
}
//Hàm thực thi
void thucthi()
{
	int a[MAXSIZE], s, n = 0;
	while(true)
	{
		printf("\n\nChon chuc nang: ");
		scanf_s("%d",&s);
		switch(s)
		{
		case 1:
			taoMangChan(a, n);
			xuatMang(a, n);
			break;
		case 2:
			taoMangChanLeXenKe(a, n);
			xuatMang(a, n);
			break;
		case 3:
			printf("\nCac chu so dau co chu so le la: ");
			lietKePTChuSoDauLe(a, n);
			break;
		case 4:
			printf("\nLiet ke cuc tri va tong cua chung: ");
			ptCucTriVaTong(a, n);
			break;
		case 5:
			printf("\nMang sau khi sap xep chan tang dan _ le giam dan\n");
			sapXepChanTangVaLeGiam(a, n);
			xuatMang(a, n);
			break;
		case 6:
			xoaSoChanThuHai(a,n);
			xuatMang(a,n);
			break;
		case 7:
			nhapMang(a,n);
			xuatMang(a,n);
			printf("\nMang b[]: ");
			lietKePTXuatHienNhieuNhat(a,n);
			break;
		case 0:
			exit(0);
		}
	}
}
//Hàm nhập mảng
void nhapMang(int a[], int &n)
{
	printf("\nNhap so luong phan tu: ");
	scanf_s("%d",&n);
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri a[%d]: ",i);
		scanf_s("%d",&a[i]);
	}
}
//Hàm tạo mảng chẵn
void taoMangChan(int a[], int &n)
{
	do
	{
		printf("Nhap so luong phan tu trong mang (>=15): ");
		scanf("%d", &n);
	}while(n < 15);

	for (int i = 0; i < n; i++)
	{
		do
		{
			a[i] = rand() % (MAXSIZE + 1);
		}while(a[i] % 2 != 0);
	}
}
//Hàm xuất mảng
void xuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%4d",a[i]);
}
//Hàm tạo mảng chẵn lẻ xen kẽ
void taoMangChanLeXenKe(int a[], int &n)
{
	do
	{
		printf("Nhap so luong phan tu trong mang (>=15): ");
		scanf("%d", &n);
	}while(n < 15);

	a[0] = rand() % MAXSIZE;
	for (int i = 1; i < n; i++)
	{
		do
		{
			a[i] = rand() % MAXSIZE;
		}while((a[i] + a[i-1]) % 2 == 0);
	}
}
//Hàm xuất các phần tử đầu có chữ số lẻ
void lietKePTChuSoDauLe(int a[], int n)
{
	for(int i = 0; i < n; i++)	
	{
		int chuSoDau = a[i] / 10;
		if(chuSoDau % 2 != 0)
			printf("%4d",a[i]);
	}
}
//Hàm xuất các phần tử cực trị và tính tổng chúng
void ptCucTriVaTong(int a[], int n)
{
	int tong = 0;
	if(a[0] > a[1] || a[0] < a[1])
	{
		printf("%4d",a[0]);
		tong += a[0];
	}
	if(a[n-1] < a[n-2] || a[n-1] > a[n-2])
	{
		printf("%4d",a[n-1]);
		tong += a[n-1];
	}
	for(int i = 1; i < n - 1; i++)
	{
		if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1]))
		{
			tong += a[i];
			printf("%4d",a[i]);
		}
	}
	printf("\nTong cuc tri: %d",tong);
}
//Hàm hoán vị
void hoanVi(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}

//Hàm sắp xếp chẵn tăng
void sapXepChanTang(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j])
				hoanVi(a[i], a[j]);
}
//Hàm sắp xếp lẻ giảm
void sapXepLeGiam(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] % 2 != 0 && a[j] % 2 != 0 && a[i] < a[j])
				hoanVi(a[i], a[j]);
}

//Hàm sắp xếp chẵn tăng dần và lẻ giảm dần
void sapXepChanTangVaLeGiam(int a[], int n)
{
	/*int chan[MAXSIZE], le[MAXSIZE];
	int c = 0, l = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			chan[c] = a[i];
			c++;
		}
		if(a[i] % 2 != 0)
		{
			le[l] = a[i];
			l++;
		}
	}
	c = c-1;
	l = l-1;
	

	sapXepChanTang(chan, c);
	sapXepLeGiam(le, l);
	for(int i = 0; i < c; i++)
		printf("%4d", chan[i]);
	for(int i = 0; i < l; l++)
		printf("%4d", le[i]);*/
	for(int i = 0; i < n-1 ; i++)
		
		for(int j = i + 1; j < n; j++)
			if( a[i]>a[j] && a[i]%2!=0&& a[j] % 2 != 0)
				
				hoanVi(a[i], a[j]);
}

//Hàm xóa số chẵn thứ 2 trong mãng
void xoaSoChanThuHai(int a[], int &n)
{
	int dem = 0, viTri = -1;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
			dem++;
		if(dem == 2)
		{
			viTri = i;
			break;
		}
	}
	if(viTri == -1)
	{
		printf("\nMang khong co so chan thu hai");
		return;
	}
	for(int i = viTri; i < n - 1; i++)
		a[i] = a[i+1];
	n--;
}

//Hàm tìm phần tử trong một mảng
int timPT(int a[], int n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return 1;
	return 0;
}
//Hàm xuất các phần tử xuất hiện nhiều nhất trong mảng
void lietKePTXuatHienNhieuNhat(int a[], int n)
{
	int b[MAXSIZE], c[MAXSIZE];
}