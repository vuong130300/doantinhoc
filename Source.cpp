#include"Header.h"
#include <list>
//--------------------------------------------------------
void init(NODELOAIHANGHOA& list)
{
	list = NULL;
}
//--------------------------------------------------------
void init1(NODEHANGHOA& list1)
{
	list1 = NULL;
}
//--------------------------------------------------------
int empty(NODELOAIHANGHOA list)
{
	return(list == NULL ? 1 : 0);
}
//--------------------------------------------------------
int empty1(NODEHANGHOA list1)
{
	return(list1 == NULL ? 1 : 0);
}
//--------------------------------------------------------
NODELOAIHANGHOA creat_node(LoaiHH lhh)
{
	NODELOAIHANGHOA p;
	p = new NODELH;
	p->data = lhh;
	p->link = NULL;
	return p;
}
//--------------------------------------------------------
NODEHANGHOA creat_node1(HANGHOA hh)
{
	NODEHANGHOA p1;
	p1 = new NODEHH;
	p1->data1 = hh;
	p1->link = NULL;
	return p1;
}
//--------------------------------------------------------
void read_List(NODELOAIHANGHOA& list)			 //nhap danh sach loai hang hoa
{
	init(list);
	LoaiHH lhh;
	do
	{
		cout << "\nNhap MaSV(thoat 0):";
		cin.getline(lhh.maloai, 10);
		while (check_code(list, lhh.maloai))
		{
			cout << "\nMa so hang hoa bi trung";
			cout << "\n Nhap lai ma so hh:";
			cin.getline(lhh.maloai, 10);
		}
		if (strcmp(lhh.maloai, "0") == 0)
			break;
		cout << "\nNhap ten loai hang hoa:";
		cin.getline(lhh.tenloai, 20);
		
		add_first(list, lhh);
	} while (1);
}
//--------------------------------------------------------
void read_List1(NODEHANGHOA& list1)			 //nhap danh sach hang hoa
{
	init1(list1);
	HANGHOA hh;
	do
	{
		cout << "\nNhap ma hang hoa(thoat 0):";
		cin.getline(hh.maHH, 10);
		while (check_code(list1, hh.maHH))
		{
			cout << "\nMa so hang hoa bi trung";
			cout << "\n Nhap lai ma so hh:";
			cin.getline(hh.maHH, 10);
		}
		if (strcmp(hh.maHH, "0") == 0)
			break;
		cout << "\nNhap ten hang hoa:";
		cin.getline(hh.tenHH, 20);
		cout << "/nNhap sp luong hang hoa:";
		cin >> hh.soluong;
		cout << "/nNhap don gia cho hang hoa:";
		cin >> hh.dongia;

		add_first1(list1, hh);		
	} while (1);
}
//-----------------------------------------------------------
void print_List(NODELOAIHANGHOA list)	//xuat danh sach loai hang hoa
{
	cout << setw(0) << "MALHH" << setw(15) << "TEN LHH" << setw(20) << endl;
	while (list != NULL)
	{
		cout << setw(0) << list->data.maloai << setw(15) << list->data.tenloai << setw(20) << endl;
		list = list->link;
	}
}
//-----------------------------------------------------------
void print_List1(NODEHANGHOA list1)//xuat danh sach hang hoa
{
	cout << setw(0) << "MAHH" << setw(15) << "TEN HH" << setw(20) << "So luong"<< setw(25) <<"Don Gia "<< endl;
	while (list1 != NULL)
	{
		cout << setw(0) << list1->data1.maHH << setw(15) << list1->data1.tenHH << setw(20) << list1->data1.soluong<<setw(25)<<list1->data1.dongia << endl;
		list1 = list1->link;
	}
}
//--------------------------------------------------------
bool check_code(NODELOAIHANGHOA& list, char* ma) //kiểm tra trùng mã loại hàng hóa
{
	NODELOAIHANGHOA p = list;
	while (p != NULL)
	{
		if (strcmp(p->data.maloai, ma) == 0)
			return true;
		p = p->link;
	}
	return false;
}
//--------------------------------------------------------
bool check_code(NODEHANGHOA& list1, char* ma1)   //kiểm tra trùng mã hàng hóa
{
	NODEHANGHOA p1 = list1;
	while (p1 != NULL)
	{
		if (strcmp(p1->data1.maHH, ma1) == 0)
			return true;
		p1 = p1->link;
	}
	return false;
}
//--------------------------------------------------------
NODELOAIHANGHOA add_first(NODELOAIHANGHOA& list, LoaiHH lhh) //hàm thêm đầu loại hh
{
	NODELOAIHANGHOA p;
	p = creat_node(lhh);
	p->link = list;
	list = p;
	return p;
}
//--------------------------------------------------------
NODEHANGHOA add_first1(NODEHANGHOA& list1, HANGHOA hh) //hàm thêm đầu
{
	NODEHANGHOA p1;
	p1 = creat_node1(hh);
	p1->link = list1;
	list1 = p1;
	return p1;
}
//--------------------------------------------------------
void delete_loaiHH_MaHH(NODELOAIHANGHOA& list, LoaiHH lhh) //hàm xóa hàng hóa theo mã loại hàng hóa
{
	if (strcmp(list->data.maloai, lhh.maloai) == 0)
	{
		NODELOAIHANGHOA p = list;
		list = list->link;
		delete p;
	}
	else
	{
		NODELOAIHANGHOA p, before;
		p = list;
		before = list;
		while (p != NULL && strcmp(p->data.maloai, lhh.maloai) != 0)
		{
			before = p;
			p = p->link;
		}
		if (p != NULL)
		{
			before->link = p->link;
			delete p;
		}
	}
}

//------------------------------------------------------
void delete_HH_MaHH(NODEHANGHOA& list1, HANGHOA hh) //hàm xóa hàng hóa theo mã hàng hóa
{
	if (strcmp(list1->data1.maHH, hh.maHH) == 0)
	{
		NODEHANGHOA p1 = list1;
		list1 = list1->link;
		delete p1;
	}
	else
	{
		NODEHANGHOA p1, before1;
		p1 = list1;
		before1 = list1;
		while (p1 != NULL && strcmp(p1->data1.maHH, hh.maHH) != 0)
		{
			before1 = p1;
			p1 = p1->link;
		}
		if (p1 != NULL)
		{
			before1->link = p1->link;
			delete p1;
		}
	}
}
//--------------------------------------------------------
void fix_loaiHH(NODELOAIHANGHOA & list, LoaiHH lhh);
//---------------------------------------------------------
void fix_HH(NODEHANGHOA& list1, HANGHOA hh);//hàm sửa
//--------------------------------------------------------
NODELOAIHANGHOA tim_type_HH_maHH(NODELOAIHANGHOA list, LoaiHH lhh) //hàm tìm hàng hóa theo mã loại hàng hóa
{
	NODELOAIHANGHOA p = list;
	while (p != NULL)
	{
		if (p->data.maloai == lhh.maloai)
			return p;
		p = p->link;
	}
	return p;

}
//--------------------------------------------------------
NODEHANGHOA tim_HH_maHH(NODEHANGHOA list1, HANGHOA hh) //hàm tìm hàng hóa theo mã hàng hóa
{
	NODEHANGHOA p1 = list1;
	while (p1 != NULL)
	{
		if (p1->data1.maHH == hh.maHH)
			return p1;
		p1 = p1->link;
	}
	return p1;
}
//--------------------------------------------------------
void read_File(ifstream& file_name, HANGHOA& hh);//hàm đọc file 

//---------------------------------------------------------
void write_file(char* file_name);//hàm ghi file
//--------------------------------------------------------



//---------------------------------------------------------
void Menu()
{
	cout << " " << endl;
	cout << endl << "MENU" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Ban hay chon mot trong cac lua chon sau: " << endl << endl;
	cout << "1. Them loai hang hoa voa danh sach" << endl;
	cout << "2. Them hang hoa vao danh sach" << endl;
	cout << "3. xoa loai hang hoa theo ma loai hang hoa " << endl;
	cout << "4. xoa hang hoa theo ma hang hoa" << endl;
	cout << "5. sua loai hang hoa" << endl;
	cout << "6. sua hang hoa" << endl;
	
	cout << "7. Thoat" << endl;

}