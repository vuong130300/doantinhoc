#include"Header.h" 
int main() {
	NODELOAIHANGHOA list, dshh;
	NODEHANGHOA list1,dshh1;
	LoaiHH lhh;
	HANGHOA hh;
	int  se;
	
	
	do {
		Menu();
		cout << "Lua chon : " << endl;
		cin >> se;
		switch (se) {
		case 1: {
			add_first(list, lhh);


			break;
		}
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		
		case 10:
			return 0;
		default:
			cout << endl << "Ban nhap khong hop le. Hay nhap lai." << endl;
			break;
		}

	} while (1);
	return 0;

	system("pause");

	
	
}