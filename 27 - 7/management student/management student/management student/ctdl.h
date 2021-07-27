#pragma once
/*
************************************************************************************************************************************************
- Danh sách môn học: MAMH, TENMH, STCLT, STCTH
- Danh sách lớp: MALOP, TENLOP, Năm nhập học, con trỏ
	->con trỏ sẻ trỏ đến danh sách sinh viên thuộc lớp đó.
- Danh sách sinh viên: MASV, HO, TEN, PHAI, SODT, con trỏ
	->con trỏ sẻ trỏ đến danh sách điểm các môn của sinh viên đó
- Danh sách điểm: MAMH, LAN, DIEM

- struct môn học : mã môn học, tên môn học, số tc lý thuyết, số tc thực hành
- struct danh sách các môn học : mảng 1 chiều chứa các môn học và số lượng môn học có trong mảng
- struct điểm của 1 môn học : mã môn học, lần thi, số điểm, con trỏ pNext liên kết với số điểm khác trong danh sách điểm
- struct danh sách điểm của 1 môn học : 2 con trỏ pHead và pTail quản lý danh sách
- struct sinh viên : mã sv, họ, tên, giới tính, số điện thoại, danh sách điểm, con trỏ pNext liên kết với các sv khác trong danh sách sv của 1 lớp
- struct danh sách sinh viên : 2 con trỏ pHead và pTail quản lý danh sách
- struct lớp : mã lớp, tên lớp, năm nhập học, danh sách sinh viên của lớp
- struct danh sách lớp : mảng 1 chiều chứa các lớp và số lượng lớp có trong mảng
************************************************************************************************************************************************
*/
#include<string>
#include<iostream>
using namespace std;
#define MAX 100
using namespace std;

typedef struct MON_HOC
{
	string ma_monhoc;
	string ten_monhoc;
	int so_tc_LT = 0;
	int so_tc_TH = 0;
} mon_hoc;

struct DANH_SACH_MON_HOC
{
	mon_hoc ds[MAX];
	int sl = 0;
};
typedef struct DANH_SACH_MON_HOC ds_mon_hoc;

typedef struct SCORE
{
	string ma_monhoc;
	int lan_thi = 0;
	float score = 0;
	SCORE* pNext = NULL;
} score;

struct LIST_SCORE
{
	score* pHead = NULL;
	score* pTail = NULL;
};
typedef struct LIST_SCORE list_score;

typedef struct SINH_VIEN
{
	string ma_sv;
	string ho;
	string ten;
	string gioi_tinh;
	string sdt;
	list_score ds_diem;
	SINH_VIEN* pNext = NULL;
} sinh_vien;

struct LIST_SINH_VIEN
{
	sinh_vien* pHead = NULL;
	sinh_vien* pTail = NULL;
};
typedef struct LIST_SINH_VIEN list_sv;

typedef struct LOP
{
	string ma_lop;
	string ten_lop;
	int nam_nhap_hoc;
	list_sv ds_sinh_vien;
}lop;

typedef struct LIST_LOP
{
	lop ds[MAX];
	int sl = 0;
}list_lop;

// hàm khởi tạo 1 đối tượng sinh viên mới
// --> dùng trong load_file.h
sinh_vien* khoi_tao_sv()
{
	sinh_vien* p = new sinh_vien;
	p->pNext = NULL;
	return p;
}

// hàm thêm 1 sinh viên vào trong danh sách sinh viên của 1 lớp
// --> dùng trong load_file.h
void them_sv_vao_ds(list_sv& ds_sv, sinh_vien*p)
{
	// trường hợp danh sách rỗng --> pHead = NULL --> thêm vào đầu
	if (ds_sv.pHead == NULL)
	{
		ds_sv.pHead = p;
		ds_sv.pTail = p;
	}
	else // thêm sinh viên mới vào cuối danh sách --> pTail = p
	{
		ds_sv.pTail->pNext = p;
		ds_sv.pTail = p;
	}
}

// hàm khởi tạo 1 điểm mới
score* khoi_tao_diem()
{
	score* p = new score;
	p->pNext = NULL;
	return p;
}

// hàm thêm điểm vào danh sách điểm
void them_1diem_vao_ds(list_score& ds_diem, score* a)
{
	if (ds_diem.pHead == NULL)
	{
		ds_diem.pHead = a;
		ds_diem.pTail = a;
	}
	else
	{
		ds_diem.pTail->pNext = a;
		ds_diem.pTail = a;
	}
}