#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include"string.h"
#include<string>


using namespace std;
typedef struct NODEHH* NODEHANGHOA;
typedef struct NODELH* NODELOAIHANGHOA;
struct HANGHOA {
	char maHH[10];
	char tenHH[30];
	int soluong;
	int dongia;
};
struct NODEHH {
	HANGHOA data1;
	NODEHANGHOA link;
};
struct LoaiHH {
	char maloai[10];
	char tenloai[30];
	NODEHANGHOA hh;
};
struct NODELH {
	LoaiHH data;
	NODELOAIHANGHOA link;
};


void init(NODELOAIHANGHOA& list);
//--------------------------------------------------------
void init1(NODEHANGHOA & list1);
//--------------------------------------------------------
int empty(NODELOAIHANGHOA list);
//--------------------------------------------------------
int empty1(NODEHANGHOA list1);
//--------------------------------------------------------
NODELOAIHANGHOA creat_node(LoaiHH lhh);
//--------------------------------------------------------
NODEHANGHOA creat_node1(HANGHOA hh);
//--------------------------------------------------------
void read_List(NODELOAIHANGHOA& list); //nhap danh sach loai hang hoa
//--------------------------------------------------------
void read_List1(NODEHANGHOA& list1); //nhap danh sach hang hoa
//-----------------------------------------------------------
void print_List(NODELOAIHANGHOA list);//xuat danh sach loai hang hoa
//-----------------------------------------------------------
void print_List1(NODEHANGHOA list1);//xuat danh sach hang hoa
//--------------------------------------------------------
bool check_code(NODELOAIHANGHOA& list, char* ma); //kiểm tra trùng mã loại hàng hóa
//--------------------------------------------------------
bool check_code(NODEHANGHOA& list1, char* ma1);   //kiểm tra trùng mã hàng hóa
//--------------------------------------------------------
NODELOAIHANGHOA add_first(NODELOAIHANGHOA& list, LoaiHH lhh); //hàm thêm đầu loại hh
//--------------------------------------------------------
NODEHANGHOA add_first1(NODEHANGHOA& list1, HANGHOA hh); //hàm thêm đầu
//--------------------------------------------------------
void delete_loaiHH_MaHH(NODELOAIHANGHOA& list, LoaiHH lhh);//hàm xóa hàng hóa theo mã loại hàng hóa
//------------------------------------------------------
void delete_HH_MaHH(NODEHANGHOA& list1, HANGHOA hh);//hàm xóa hàng hóa theo mã hàng hóa
//--------------------------------------------------------
void fix_loaiHH(NODELOAIHANGHOA& list, LoaiHH lhh);
//---------------------------------------------------------
void fix_HH(NODEHANGHOA& list1, HANGHOA hh);//hàm sửa
//--------------------------------------------------------
NODELOAIHANGHOA tim_type_HH_maHH(NODELOAIHANGHOA list, LoaiHH lhh);//hàm tìm loại hàng hóa theo mã hàng hóa
//--------------------------------------------------------
NODEHANGHOA tim_HH_maHH(NODEHANGHOA list1, HANGHOA hh);//hàm tìm hàng hóa theo mã hàng hóa
//--------------------------------------------------------
void read_File(ifstream &file_name, HANGHOA &hh);//hàm đọc file 
//---------------------------------------------------------
void write_file(char* file_name);//hàm ghi file
//--------------------------------------------------------
void Menu();



