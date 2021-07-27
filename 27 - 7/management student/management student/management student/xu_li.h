/*
************************************************************************
************************************************************************
@ Quản lý điểm sinh viên:
	- Danh sách môn học: MAMH, TENMH, STCLT, STCTH
	- Danh sách lớp: MALOP, TENLOP, Năm nhập học, con trỏ
		->con trỏ sẻ trỏ đến danh sách sinh viên thuộc lớp đó.
	- Danh sách sinh viên: MASV, HO, TEN, PHAI, SODT, con trỏ
		->con trỏ sẻ trỏ đến danh sách điểm các môn của sinh viên đó
	- Danh sách điểm: MAMH, LAN, DIEM

@ Chương trình có các chức năng sau:
	-> Nhập lớp
	-> Nhập sinh viên của lớp
	-> Xuất danh sách sinh viên theo niên khóa
	-> Xuất DSSV của 1 lớp theo thứ tự alphabet tăng dần của tên + họ
	-> Nhập môn học
	-> Xuất DS môn học
	-> Nhập điểm
	-> Xuất bảng điểm môn học của 1 lớp theo 1 lần thi
	-> Phiếu điểm in bảng điểm môn học của 1 sinh viên có mã bất kỳ

@ Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các
điều kiện khi nhập làm dữ liệu bị sai.
************************************************************************
************************************************************************
*/

#pragma once
#include "load_file.h"
#include<iostream>
using namespace std;

/***************************************************/
/***************************************************/
void xuat_ds_lop(list_lop& ds_lop);
void nhap_lop_moi(list_lop& ds_lop);
int kt_ma_lop(list_lop ds_lop, string a);
void nhap_sv(list_lop &ds_lop);
void xuat_ds_sv_mot_lop(sinh_vien* pHead);
void xuat_ds_sv(list_lop ds_lop);
void nhap_mon_hoc(ds_mon_hoc& ds_mh);
void xuat_ds_mon_hoc(ds_mon_hoc ds_mh);
void xuat_ds_sv_theo_nam(list_lop ds_lop);
sinh_vien* kt_ma_sinh_vien(list_lop ds_lop, string ma_sv);
bool kt_ma_mh(ds_mon_hoc ds_mh, string ma_mh);
void nhap_1_diem(ds_mon_hoc ds_mh, score* a);
void nhap_diem(list_lop ds_lop, ds_mon_hoc ds_mh);
void xuat_ds_diem_1sv(list_lop ds_lop);
void xuat_ds_diem_1lop(list_lop ds_lop);
/***************************************************/
/***************************************************/

void menu()
{
	// khai báo biến trước khi load file
	list_lop ds_lop;
	list_sv ds_sv;
	ds_mon_hoc ds_mh;
	// load file trước khi thực hiện các chức năng
	load_file_DSLop(ds_lop);
	load_file_DSSinhVien(ds_lop);
	load_file_DSMonHoc(ds_mh);
	load_file_DSDiem(ds_lop);

	while (true)
	{
		system("cls");
		cout << "\n\n\t\t//==============// MENU //==============//" << endl;
		cout << "\n\t1.  Enter information of class" << endl;
		cout << "\n\t2.  Show list of classes" << endl;
		cout << "\n\t3.  Enter information of student" << endl;
		cout << "\n\t4.  Show list of students based on year" << endl;
		cout << "\n\t5.  Show list of student in a class" << endl;
		cout << "\n\t6.  Enter a subject" << endl;
		cout << "\n\t7.  Show list of subjects" << endl;
		cout << "\n\t8.  Enter scores" << endl;
		cout << "\n\t9.  Show a list of students' scores in a class by one test " << endl;
		cout << "\n\t10. Show a list of any student" << endl;
		cout << "\n\t0.  Exit program" << endl;
		cout << "\n\t\t//======================================//" << endl;
		int luachon;
		cout << "\nEnter your option: "; cin >> luachon;
		switch (luachon)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			nhap_lop_moi(ds_lop);
			system("pause");
			break;
		}
		case 2:
		{
			xuat_ds_lop(ds_lop);
			system("pause");
			break;
		}
		case 3:
		{
			nhap_sv(ds_lop);
			system("pause");
			break;
		}
		case 4:
		{
			xuat_ds_sv_theo_nam(ds_lop);
			system("pause");
			break;
		}
		case 5:
		{
			xuat_ds_sv(ds_lop);
			system("pause");
			break;
		}
		case 6:
		{
			nhap_mon_hoc(ds_mh);
			system("pause");
			break;
		}
		case 7:
		{
			xuat_ds_mon_hoc(ds_mh);
			system("pause");
			break;
		}
		case 8:
		{
			nhap_diem(ds_lop, ds_mh);
			system("pause");
			break;
		}
		case 9:
		{
			xuat_ds_diem_1lop(ds_lop);
			system("pause");
			break;
		}
		case 10:
		{
			xuat_ds_diem_1sv(ds_lop);
			system("pause");
			break;
		}
		}
	}
}

// hàm nhập thông tin cho 1 lớp mới
void nhap_lop_moi(list_lop& ds_lop)
{
	int n;
	cout << "number of classes to import:: "; cin >> n;

	for (int i = 0; i < n; i++) // nhập thông tin cho một lớp theo số lượng lớp cần nhập
	{
		lop x;
		cin.ignore();
		cout << "//====== ENTER INFORMATION OF NEW CLASS " << i + 1 << " ======//" << endl;
		cout << "Enter code of class: "; getline(cin, x.ma_lop);
		cout << "Enter name of class: "; getline(cin, x.ten_lop);
		cout << "enter school year: "; cin >> x.nam_nhap_hoc;
		ds_lop.ds[ds_lop.sl] = x; // thêm lớp x vừa nhập vào cuối danh sách
		ds_lop.sl++;
	}
}

// hàm xuất danh sách lớp 
void xuat_ds_lop(list_lop& ds_lop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		cout << "\t\t============= Class " << i + 1 << " =============" << endl;
		cout << "Code of class: " << ds_lop.ds[i].ma_lop << endl;
		cout << "Name of class: " << ds_lop.ds[i].ten_lop << endl;
		cout << "School year: " << ds_lop.ds[i].nam_nhap_hoc << endl;
	}
}

// hàm kiểm tra mã lớp do người dùng nhập
int kt_ma_lop(list_lop ds_lop, string a)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds[i].ma_lop == a)
		{
			return i;
		}
	}
	return -1;
}


// hàm nhập thông tin sinh viên mới vào 1 lớp
// --> nhập mã lớp cần thêm sv -> kiểm tra mã lớp nếu mã lớp tồn tại thì nhập sv vào ds sv
void nhap_sv(list_lop &ds_lop)
{
	cin.ignore();
	string a; // khai báo biến dùng để lưu mã lớp người dùng nhập vào
	cout << "Enter code of class: ";
	getline(cin, a);
	int vt = kt_ma_lop(ds_lop, a);
	// kiểm tra xem mã lớp người dùng nhập có tồn tại hay k
	if (vt == -1)
	{
		cout << "This class doesn't exist" << endl;
	}
	else
	{
		// nhập số lượng sinh viên cần thêm
		int n;
		cout << "Enter the number of students to add: "; cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			// thêm sinh viên vào danh sách
			sinh_vien* p = khoi_tao_sv();
			// lưu dữ liệu load được từ file vào sinh_vien p
			cout << "//====== ENTER INFORMATION OF NEW STUDENT " << i + 1 << " ======//" << endl;
			cout << "Enter code of student: "; getline(cin, p->ma_sv);
			cout << "Enter last name: "; getline(cin, p->ho);
			cout << "Enter first name: "; getline(cin, p->ten);
			cout << "Enter gender: "; getline(cin, p->gioi_tinh);
			cout << "Enter phone number: "; getline(cin, p->sdt);
			them_sv_vao_ds(ds_lop.ds[vt].ds_sinh_vien, p);

		}
	}
}

// hàm xuất danh sách sinh viên của 1 lớp
void xuat_ds_sv(list_lop ds_lop)
{
	cin.ignore();
	string a; // khai báo biến dùng để lưu mã lớp người dùng nhập vào
	cout << "Enter code of class: ";
	getline(cin, a);
	int vt = kt_ma_lop(ds_lop, a);
	if (vt == -1)
	{
		cout << "This class doesn't exist" << endl;
	}
	else
	{
		// xuất ra danh sách sinh viên của 1 lớp
		xuat_ds_sv_mot_lop(ds_lop.ds[vt].ds_sinh_vien.pHead);
	}
}

// hàm xuất danh sách sinh viên của 1 lớp
void xuat_ds_sv_mot_lop(sinh_vien* pHead)
{
	int i = 1;
	for (sinh_vien* k = pHead; k != NULL; k = k->pNext)
	{
		cout << "\t\t============ STUDENT " << i << " ============" << endl;
		cout << "Code of student: " << k->ma_sv << endl;
		cout << "Last name: " << k->ho << endl;
		cout << "First name: " << k->ten << endl;
		cout << "Gender: " << k->gioi_tinh << endl;
		cout << "Phone number: " << k->sdt << endl;
		i++;
	}
}

// hàm nhập môn học mới vào danh sách
void nhap_mon_hoc(ds_mon_hoc& ds_mh)
{
	int n;
	cout << "Enter the number of subjects to add: "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		mon_hoc a;
		cin.ignore();
		cout << "//====== ENTER INFORMATION OF SUBJECT " << i + 1 << " ======//" << endl;
		cout << "Enter code of subject: "; getline(cin, a.ma_monhoc);
		cout << "Enter name of subject: "; getline(cin, a.ten_monhoc);
		cout << "Enter number of credit for theory: "; cin >> a.so_tc_LT;
		cout << "Enter number of credit for practice: "; cin >> a.so_tc_TH;
		ds_mh.ds[ds_mh.sl] = a;
		ds_mh.sl++;
	}
}

// hàm xuất danh sách các môn học
void xuat_ds_mon_hoc(ds_mon_hoc ds_mh)
{
	cout << "In list have: " << ds_mh.sl << " subjects" << endl;
	for (int i = 0; i < ds_mh.sl; i++)
	{
		cout << "\t\t========== SUBJECT " << i + 1 << " ==========" << endl;
		cout << "Code of subject: " << ds_mh.ds[i].ma_monhoc << endl;
		cout << "Name of subject: " << ds_mh.ds[i].ten_monhoc << endl;
		cout << "Number of credit for theory: " << ds_mh.ds[i].so_tc_LT << endl;
		cout << "Number of credit for practice: " << ds_mh.ds[i].so_tc_TH << endl;
	}
}

// hàm xuất danh sách sinh viên có cùng năm nhập học
void xuat_ds_sv_theo_nam(list_lop ds_lop)
{
	int n;
	cout << "School year: "; cin >> n;
	cin.ignore();
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds[i].nam_nhap_hoc == n)
		{
			xuat_ds_sv_mot_lop(ds_lop.ds[i].ds_sinh_vien.pHead);
		}
	}
}

// hàm kiểm tra mã sinh viên có tồn tại hay k
sinh_vien* kt_ma_sinh_vien(list_lop ds_lop, string ma_sv)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (sinh_vien* k = ds_lop.ds[i].ds_sinh_vien.pHead; k != NULL; k = k->pNext)
		{
			if (k->ma_sv == ma_sv)
			{
				return k;
			}
		}
	}
	return NULL;
}

// hàm kiểm tra mã môn học
bool kt_ma_mh(ds_mon_hoc ds_mh, string ma_mh)
{
	for (int i = 0; i < ds_mh.sl; i++)
	{
		if (ds_mh.ds[i].ma_monhoc == ma_mh)
		{
			return true;
		}
	}
	return false;
}

// hàm nhập 1 điểm cho 1 sinh viên
void nhap_1_diem(ds_mon_hoc ds_mh, score* a)
{
	// nhập 1 điểm vào danh sách điểm --> nhập mã môn học + nhập số lần thi + nhập số điểm
	// kiểm tra mã môn học nếu đúng thì cho nhập tiếp số lần thì và số điểm
	cin.ignore();
	bool kt;
	do
	{
		cout << "Enter code of subject: "; getline(cin, a->ma_monhoc);
		kt = kt_ma_mh(ds_mh, a->ma_monhoc);
		if (kt == false)
		{
			cout << "This code doesn't exits, Please enter again." << endl;
		}
	} while (kt == false);
	cout << "enter the number of times: "; cin >> a->lan_thi;
	cout << "Enter score: "; cin >> a->score;
}

// hàm nhập nhiều điểm cho 1 sinh viên
void nhap_diem(list_lop ds_lop, ds_mon_hoc ds_mh)
{
	string a;
	cin.ignore();
	cout << "Enter the student code to enter the score: "; getline(cin, a);
	sinh_vien* p = kt_ma_sinh_vien(ds_lop, a);
	if (p == NULL)
	{
		cout << "Student code doesn't exist" << endl;
		system("pause");
	}
	else
	{
		int n;
		//cin.ignore();
		cout << "Enter the number of points to add: "; cin >> n;
		for (int i = 0; i < n; i++)
		{
			// thêm điểm vào danh sách
			score* a = khoi_tao_diem();
			cout << "//====== ENTER INFORMATION OF SCORE " << i + 1 << " ======//" << endl;
			nhap_1_diem(ds_mh, a);
			them_1diem_vao_ds(p->ds_diem, a);
		}
	}
}

// hàm xuất danh sách điểm của 1 sinh viên dựa vào mã sinh viên
void xuat_ds_diem_1sv(list_lop ds_lop)
{
	string a;
	cin.ignore();
	cout << "Enter the student code to see the score: "; getline(cin, a);
	sinh_vien* temp = kt_ma_sinh_vien(ds_lop, a);
	if (temp == NULL)
	{
		cout << "Student code doesn't exist" << endl;
	}
	else
	{
		cout << "List of scores are: \n";
		for (score* k = temp->ds_diem.pHead; k != NULL; k = k->pNext)
		{
			cout << k->score << "  ";
		}
	}
}

// hàm xuất danh sách điểm của 1 lớp theo 1 lần thi
void xuat_ds_diem_1lop(list_lop ds_lop)
{
	string a;
	cin.ignore();
	cout << "Enter the class code to see the score:: "; getline(cin, a);
	// kiểm tra mã lớp nhập vào
	int kt = kt_ma_lop(ds_lop, a);
	if (kt == -1)
	{
		cout << "Class code doesn't exist" << endl;
	}
	else
	{
		cout << "\nThe number of points per test is: " << endl;
		for (sinh_vien* k = ds_lop.ds[kt].ds_sinh_vien.pHead; k != NULL; k = k->pNext)
		{
			for (score* d = k->ds_diem.pHead; d != NULL; d = d->pNext)
			{
				if (d->lan_thi == 1)
				{
					cout << d->score << "  ";
				}
			}

		}
		cout << endl;
	}
}