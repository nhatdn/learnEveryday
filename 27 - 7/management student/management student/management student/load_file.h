#pragma once
#include"ctdl.h"
#include<fstream>

void load_file_DSLop(list_lop& ds_lop)
{
	ifstream filein;
	filein.open("DSLop.txt", ios_base::in);

	while (filein.eof() != true)
	{
		// load dữ liệu của 1 lớp và lưu vào biến x
		lop x;
		getline(filein, x.ma_lop, ',');
		getline(filein, x.ten_lop, ',');
		filein >> x.nam_nhap_hoc;
		filein.ignore();

		// lưu dữ liệu của lớp x vừa load đượcc vào mảng ds_lop
		ds_lop.ds[ds_lop.sl] = x;
		ds_lop.sl++;
	}

	filein.close();
}

// hàm load file DSSinhVien
void load_file_DSSinhVien(list_lop& ds_lop)
{
	ifstream filein;
	filein.open("DSSinhVien.txt", ios_base::in);

	while (filein.eof() != true)
	{
		// duyệt qua từng lớp
		for (int i = 0; i < ds_lop.sl; i++)
		{
			// duyệt danh sách sinh viên củaa mỗi lớp
			int n;
			filein >> n;
			filein.ignore();
			for (int j = 0; j < n; j++)
			{
				sinh_vien* p = khoi_tao_sv();
				// lưu dữ liệu load đượcc từ file vào sinh_vien p
				getline(filein, p->ma_sv, ',');
				getline(filein, p->ho, ',');
				getline(filein, p->ten, ',');
				getline(filein, p->gioi_tinh, ',');
				getline(filein, p->sdt);
				// thêm sinh viên p vừa lưu vào danh sách sinh viên
				them_sv_vao_ds(ds_lop.ds[i].ds_sinh_vien, p);
			}
		}
	}

	filein.close();
}

// hàm load file DSMonHoc
void load_file_DSMonHoc(ds_mon_hoc& ds_mh)
{
	ifstream filein;
	filein.open("DSMonHoc.txt", ios_base::in);
	while (filein.eof() != true)
	{
		mon_hoc a;
		getline(filein, a.ma_monhoc, ',');
		getline(filein, a.ten_monhoc, ',');
		filein >> a.so_tc_LT;
		filein.ignore();
		filein >> a.so_tc_TH;
		filein.ignore();
		ds_mh.ds[ds_mh.sl] = a;
		ds_mh.sl++;
	}
	filein.close();
}

// hàm load file DSDiem
void load_file_DSDiem(list_lop ds_lop)
{
	ifstream filein;
	filein.open("DSDiem.txt", ios_base::in);
	while (filein.eof() != true)
	{
		for (int i = 0; i < ds_lop.sl; i++)
		{
			for (sinh_vien* k = ds_lop.ds[i].ds_sinh_vien.pHead; k != NULL; k = k->pNext)
			{
				int n;
				filein >> n;
				filein.ignore();
				for (int j = 0; j < n; j++)
				{
					score* a = khoi_tao_diem();
					getline(filein, a->ma_monhoc, ',');
					filein >> a->lan_thi;
					filein.ignore();
					filein >> a->score;
					filein.ignore();
					// thêm điểm vừa load được vào danh sách điểm
					them_1diem_vao_ds(k->ds_diem, a);
				}
			}
		}

	}
	filein.close();
}
