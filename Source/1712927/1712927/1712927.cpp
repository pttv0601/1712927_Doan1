#include <stdio.h>
#include <wchar.h>
#include "stdafx.h"
#include <fcntl.h>
#include <io.h>
#include<string.h>;
#pragma warning(disable:4996)
struct Sinhvien
{
	wchar_t mssv[11];
	wchar_t hovaten[100];
	wchar_t email[100];
	wchar_t khoa[31];
	int nienkhoa;
	wchar_t ngaysinh[11];
	wchar_t hinh[100];
	wchar_t mota[1000];
	wchar_t sothich1[1000];
	wchar_t sothich2[1000];
};

void seek(FILE* fp, wchar_t c)
{
	long temp = 0;
	wchar_t c1;
	fseek(fp, -1L, SEEK_CUR);
	if (fgetwc(fp) == c)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	fseek(fp, -2L, SEEK_CUR);
	if (fgetwc(fp) == c)
	{
		fseek(fp, -2L, SEEK_CUR);
		return;
	}
	fseek(fp, 1L, SEEK_CUR);
	for (int i = 0; i >= 0; i++)
	{
		c1 = fgetwc(fp);
		if (c1 == c)
		{
			fseek(fp, -temp, SEEK_CUR);
			break;
		}
		else
		{
			temp++;
			fseek(fp, -temp, SEEK_CUR);
		}
	}
}
void fileinput(FILE* fp, Sinhvien &a, int& count)
{
	wchar_t temp1[1000];
	wchar_t temp2[1000];
	wchar_t c;
	int dem1 = 0;
	int dem2 = 0;
	count = 0;
	fgetwc(fp);
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.mssv);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^,],", &a.mssv);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.hovaten);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^,],", &a.hovaten);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.email);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^,],", &a.email);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.khoa);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^,],", &a.khoa);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%d", &a.nienkhoa);
		fseek(fp, 2L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%d", &a.nienkhoa);
		fseek(fp, 1L, SEEK_CUR);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.ngaysinh);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^,],", &a.ngaysinh);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.hinh);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^,],", &a.hinh);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.mota);
		if (fgetwc(fp) == 44)
		{
			count++;
		}
	}
	else
	{
		seek(fp, c);
		for (int i = 0; i >= 0; i++)
		{
			temp1[i] = fgetwc(fp);
			if (temp1[i] == 44 || temp1[i] == 10)
			{
				if (temp1[i] == 44)
				{
					temp1[i] = '\0';
					count++;
					break;
				}
				if (temp1[i] == 10)
				{
					temp1[i] = '\0';
					break;
				}
			}
			dem1++;
		}
		for (int i = 0; i <= dem1; i++)
		{
			a.mota[i] = temp1[i];
		}
	}

	if (count == 0)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.sothich1);
		if (fgetwc(fp) == 44)
		{
			count++;
		}
	}
	else
	{
		seek(fp, c);
		for (int i = 0; i >= 0; i++)
		{
			temp2[i] = fgetwc(fp);
			if (temp2[i] == 44 || temp2[i] == 10)
			{
				if (temp2[i] == 44)
				{
					temp2[i] = '\0';
					count++;
					break;
				}
				if (temp2[i] == 10)
				{
					temp2[i] = '\0';
					break;
				}
			}
			dem2++;
		}
		for (int i = 0; i <= dem2; i++)
		{
			a.sothich1[i] = temp2[i];
		}
	}
	if (count == 1)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.sothich2);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		seek(fp, c);
		fwscanf(fp, L"%[^\n]", &a.sothich2);
	}
}
void fileoutput(Sinhvien* a, int i, int* sothich)
{
	wchar_t b[50];
	wchar_t c[] = L".htm";
	wcscpy(b, a[i].mssv);
	wcscat(b, c);
	FILE* x = _wfopen(b, L"w, ccs= UTF-8");
	if (x != NULL)
	{
		fwprintf(x, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(x, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(x, L"	<head>\n");
		fwprintf(x, L"		<meta http-equiv=\"Content - Type\" content=\"text/html; charset = utf - 8\" />\n");
		fwprintf(x, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
		fwprintf(x, L"		<title>HCMUS - %ls</title>\n", a[i].hovaten);
		fwprintf(x, L"	</head>\n");
		fwprintf(x, L"	<body>\n");
		fwprintf(x, L"		<div class=\"Layout_container\">\n");
		fwprintf(x, L"			<!-- Begin Layout Banner Region -->\n");
		fwprintf(x, L"			<div class=\"Layout_Banner\" >\n");
		fwprintf(x, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(x, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"			<!-- End Layout Banner Region -->\n");
		fwprintf(x, L"			<!-- Begin Layout MainContents Region -->\n");
		fwprintf(x, L"			<div class=\"Layout_MainContents\">\n");
		fwprintf(x, L"				<!-- Begin Below Banner Region -->\n");
		fwprintf(x, L"				<div class=\"Personal_Main_Information\">\n");
		fwprintf(x, L"					<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(x, L"					<div class=\"Personal_Location\">\n");
		fwprintf(x, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(x, L"						<span class=\"Personal_FullName\">%ls - %s</span>\n", a[i].hovaten, a[i].mssv);
		fwprintf(x, L"						<div class=\"Personal_Department\">Khoa %ls</div>\n", a[i].khoa);
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"						<div class=\"Personal_Phone\">\n");
		fwprintf(x, L"							Email: %ls\n", a[i].email);
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"					<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(x, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
		fwprintf(x, L"						<img src=\"%s\" class=\"Personal_Hinhcanhan\" />\n", a[i].hinh);
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"				<!-- End Below Banner Region -->\n");
		fwprintf(x, L"				<!-- Begin MainContents Region -->\n");
		fwprintf(x, L"				<div class=\"MainContain\">\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"					<!-- Begin Top Region -->\n");
		fwprintf(x, L"					<div class=\"MainContain_Top\">\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(x, L"						<div>\n");
		fwprintf(x, L"							 <ul class=\"TextInList\">\n");
		fwprintf(x, L"								<li>Họ và tên: %ls</li>\n", a[i].hovaten);
		fwprintf(x, L"								<li>MSSV: %ls</li>\n", a[i].mssv);
		fwprintf(x, L"								<li>Sinh viên khoa %ls</li>\n", a[i].khoa);
		fwprintf(x, L"								<li>Ngày sinh: %ls</li>\n", a[i].ngaysinh);
		fwprintf(x, L"								<li>Email: %ls</li>\n", a[i].email);
		fwprintf(x, L"							</ul>\n");
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(x, L"						<div>\n");
		fwprintf(x, L"							<ul class=\"TextInList\">\n");
		if (sothich[i] == 0)
		{
			fwprintf(x, L"								<li>Không có sở thích nào.\n</li>\n");
		}
		if (sothich[i] == 1)
		{
			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
		}
		else if (sothich[i] == 2)
		{

			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich2);
		}
		fwprintf(x, L"							</ul>\n");
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
		fwprintf(x, L"						<div class=\"Description\">\n");
		fwprintf(x, L"							%ls.\n", a[i].mota);
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"			<!-- Begin Layout Footer -->\n");
		fwprintf(x, L"			<div class=\"Layout_Footer\">\n");
		fwprintf(x, L"				<div class=\"divCopyright\">\n");
		fwprintf(x, L"					<br />\n");
		fwprintf(x, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
		fwprintf(x, L"					<br />\n");
		fwprintf(x, L"					@2018</br>\n");
		fwprintf(x, L"					Đồ án giữa kỳ</br>\n");
		fwprintf(x, L"				Kỹ thuật lập trình</br>\n");
		fwprintf(x, L"				TH2018/04</br>\n");
		fwprintf(x, L"				1712927 - Phạm Thị Tuyết Vy</br>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"			<!-- End Layout Footer -->\n");
		fwprintf(x, L"		</div>\n");
		fwprintf(x, L"	</body>\n");
		fwprintf(x, L"</html>\n");
		fwprintf(x, L"\n");
		wprintf(L" ->Đã xuất file %ls.\n", b, i + 1);
	}
	fclose(x);
}

void info(Sinhvien* b, int n, int* sothich)
{

	wprintf(L"	Thông tin sinh viên %d\n", n);
	wprintf(L"Mã số sinh viên: %ls\n", b[n - 1].mssv);
	wprintf(L"Họ và tên: %ls\n", b[n - 1].hovaten);
	wprintf(L"Sinh viên khoa: %ls\n", b[n - 1].khoa);
	wprintf(L"Khóa học: %d\n", b[n - 1].nienkhoa);
	wprintf(L"Ngày sinh: %ls\n", b[n - 1].ngaysinh);
	wprintf(L"Link hình ảnh: %ls\n", b[n - 1].hinh);
	wprintf(L"Mô tả: %ls\n", b[n - 1].mota);
	wprintf(L"Email: %ls\n", b[n - 1].email);
	if (sothich[n - 1] == 0)
	{
		wprintf(L"Sở thích 1: không.\n");
		wprintf(L"Sở thích 2: không.\n");
	}
	if (sothich[n - 1] == 1)
	{
		wprintf(L"Sở thích 1: %ls\n", b[n - 1].sothich1);
		wprintf(L"Sở thích 2: không.\n");
	}
	if (sothich[n - 1] == 2)
	{
		wprintf(L"Sở thích 1: %ls\n", b[n - 1].sothich1);
		wprintf(L"Sở thích 2: %ls\n", b[n - 1].sothich2);
	}
	wprintf(L"...................................\n");
}
void xuat(Sinhvien* a, int sodong, int& n, int* sothich)
{
	wprintf(L"Nhập số thứ tự sinh viên cần xuất profile page, nhập -1 để xuất tất cả, nhập -2 để thoát: ");
	do
	{
		wscanf(L"%d", &n);
		if (n<-2 || n>sodong || n==0)
		{
			wprintf(L"Nhập sai: ");
			continue;
		}
		if (n == -1)
		{
			for (int i = 0; i < sodong; i++)
			{
				fileoutput(a, i, sothich);
			}
			wprintf(L"Vui lòng nhập tiếp: ");
			continue;
		}
		if (n == -2)
		{
			return;
		}
		fileoutput(a, n - 1, sothich);
		wprintf(L"Vui lòng nhập tiếp: ");
	} while (1);
}
int line(FILE* fp)
{
	int temp = 0;
	wchar_t c[1000];
	for (int i = 1; i > 0; i++)
	{
		if (fwscanf(fp, L"%[^\n]\n", c) != EOF)
		{
			temp++;
		}
		else return temp;
	}
}
void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);
	Sinhvien a;
	Sinhvien *b = NULL;
	int* sothich = NULL;
	int count;
	FILE* fp = _wfopen(L"SV.csv", L"rt, ccs= UTF-8");
	if (fp == NULL)
	{
		wprintf(L"Có lỗi khi mở file.\n");
		return;
	}
	int n = line(fp);
	b = new Sinhvien[n];
	sothich = new int[n];
	rewind(fp);
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		fileinput(fp, a, count);
		b[i - 1] = a;
		sothich[i - 1] = count;

	}
	for (int i = 1; i <= n; i++)
	{
		info(b, i, sothich);
	}
	int p;
	xuat(b, n, p, sothich);
	delete[]b;
	delete[]sothich;
	fclose(fp);
}
