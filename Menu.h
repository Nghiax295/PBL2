#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>

using namespace std;

void menu_app(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                                                    |\n";
    cout << "|    Thuc hien:                                      |\n";
    cout << "|      SV1: Nguyen Si Nghia    102230308   23T_DT3   |\n";
    cout << "|      SV2: Nguyen Xuan Tinh   102230325   23T_DT3   |\n";
    cout << "|    Huong dan:        GV: Nguyen Van Hieu           |\n";
    cout << "+----------------------------------------------------+\n";
    cout << "| +----------------------+  +----------------------+ |\n";
    cout << "| |       Dang nhap      |  |    Tao tai khoan     | |\n";
    cout << "| +----------------------+  +----------------------+ |\n";
	cout << "|              +----------------------+              |\n";
    cout << "|              |        Thoat         |              |\n";
    cout << "|              +----------------------+              |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_login(){
	system("cls");
    cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                 Dang nhap he thong                 |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                   +-------------------------+      |\n";
   	cout << "|  Ten nguoi dung   |                         |      |\n";
   	cout << "|                   +-------------------------+      |\n";
   	cout << "|                   +-------------------------+---+  |\n";
   	cout << "|     Mat khau      |                         | O |  |\n";
   	cout << "|                   +-------------------------+---+  |\n";
   	cout << "|                                                    |\n";
   	cout << "| +----------------------+  +----------------------+ |\n";
    cout << "| |       Dang nhap      |  |    Quen mat khau     | |\n";
    cout << "| +----------------------+  +----------------------+ |\n";
   	cout << "|             +------------------------+             |\n";
   	cout << "|             |        Quay lai        |             |\n";
   	cout << "|             +------------------------+             |\n";
 	cout << "+----------------------------------------------------+\n";
}

void menu_update_pass(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
  	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Doi mat khau                    |\n";
   	cout << "+--------------+----------------------+--------------+\n";
   	cout << "|   Quay lai   |                      |   Xac nhan   |\n";
   	cout << "+--------------+                      +--------------+\n\n";
   	cout << "+-------------------+--------------------------------+\n";
   	cout << "|  Ten nguoi dung   |                                |\n";
   	cout << "+-------------------+----------------------------+---+\n";
   	cout << "| Nhap mat khau cu  |                            | O |\n";
   	cout << "+-------------------+----------------------------+---+\n";
   	cout << "| Nhap mat khau moi |                            | O |\n";
   	cout << "+-------------------+----------------------------+---+\n";
   	cout << "| Nhap lai mat khau |                            | O |\n";
    cout << "+-------------------+----------------------------+---+\n";
}

void menu_register() {
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                  Dang ky tai khoan                 |\n";
    cout << "+--------------+----------------------+--------------+\n";
    cout << "|   Quay lai   |                      |    Dang ky   |\n";
   	cout << "+--------------+                      +--------------+\n\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                   Nhap thong tin                   |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "|      Ho va ten     |                               |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "| So CCCD (Passport) |                               |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "|      Ngay sinh     |                               |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "|      Que quan      |                               |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "|    So dien thoai   |                               |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "|        Email       |                               |\n";
   	cout << "+--------------------+-------------------------------+\n";
   	cout << "|   Ten nguoi dung   |                               |\n";
   	cout << "+--------------------+---------------------------+---+\n";
   	cout << "|      Mat khau      |                           | O |\n";
   	cout << "+--------------------+---------------------------+---+\n";
   	
}

void menu_forget_pass(){
	system("cls");
    cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Quen mat khau                   |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n\n";
	cout << "+--------------------+-------------------------------+\n";
    cout << "| Nhap ma khach hang |                               |\n";
    cout << "+--------------------+---------------------------+---+\n";
    cout << "| Nhap mat khau moi  |                           | O |\n";
    cout << "+--------------------+---------------------------+---+\n";
    cout << "| Xac nhan mat khau  |                           | O |\n";
    cout << "+--------------------+---------------------------+---+\n";
    cout << "Nhap ma CAPTCHA: \n";
    cout << "+--------------------+          +--------------------+\n";
    cout << "|                    |          |      Xac nhan      |\n";
    cout << "+--------------------+          +--------------------+\n";
}

void menu_admin(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                      XIN CHAO                      |\n";
    cout << "| +----------------------+  +----------------------+ |\n";
    cout << "| |  Quan ly khach hang  |  |    Quan ly xe may    | |\n";
    cout << "| +----------------------+  +----------------------+ |\n";
    cout << "| +----------------------+  +----------------------+ |\n";
    cout << "| |       Hop dong       |  |       Thong ke       | |\n";
    cout << "| +----------------------+  +----------------------+ |\n";
    cout << "|              +----------------------+              |\n";
    cout << "|              |       Dang xuat      |              |\n";
    cout << "|              +----------------------+              |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_admin1(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                  Quan ly khach hang                |\n";
    cout << "+----------------------------------------------------+\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |    Danh sach khach hang    |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |     Tim kiem khach hang    |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |   Khach hang dang thue xe  |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |          Quay lai          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_client_list(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                 Danh sach khach hang               |\n";
   	cout << "+------------+---------------------------------------+\n";	
   	cout << "|  Quay lai  |\n";
   	cout << "+------------+\n";
   	cout << left << setw(16) << "\nMa khach hang" 
		 << left << setw(20) << "Ho va ten"
		 << left << setw(15) << "So CCCD"
		 << left << setw(15) << "Ngay sinh"
		 << left << setw(15) << "Que quan"
		 << left << setw(15) << "SDT"
		 << "Email\n";
}

void menu_client_renting(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|               Khach hang dang thue xe              |\n";
   	cout << "+------------+---------------------------------------+\n";
   	cout << "|  Quay lai  |\n";
   	cout << "+------------+\n"; 
   	cout << left << setw(16) << "\nMa khach hang" 
		 << left << setw(20) << "Ho va ten"
		 << left << setw(15) << "So CCCD"
		 << left << setw(15) << "Ngay sinh"
		 << left << setw(15) << "Que quan"
		 << left << setw(15) << "SDT"
		 << "Email\n\n";
}

void menu_admin2(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                  Quan ly xe may                    |\n";
    cout << "+----------------------------------------------------+\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |      Danh sach xe may      |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |      Tim kiem xe may       |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |    Sua thong tin xe may    |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |         Xoa xe may         |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |        Them xe may         |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |          Quay lai          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_motor_list(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                   Danh sach xe may                 |\n";
    cout << "+------------+---------------------------------------+\n";
   	cout << "|  Quay lai  |\n";
   	cout << "+------------+\n";
   	cout << left << setw(16) << "\nMa xe may" 
		 << left << setw(15) << "Hang xe"
		 << left << setw(15) << "Loai xe"
		 << left << setw(15) << "Bien so xe"
		 << left << setw(15) << "Mau xe"
		 << left << setw(15) << "Gia thue 1h"
		 << "Tinh trang\n\n";
}

void menu_add_motor(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                     Them xe may                    |\n";
   	cout << "+--------------+----------------------+--------------+\n";
   	cout << "|   Quay lai   |                      |   Them xe    |\n";
   	cout << "+--------------+                      +--------------+\n\n";
   	cout << "+----------------+-----------------------------------+\n";
   	cout << "|    Ma xe may   |                                   |\n";
   	cout << "+----------------+-----------------------------------+\n";
   	cout << "|    Hang xe     |                                   |\n";
   	cout << "+----------------+-----------------------------------+\n";
   	cout << "|    Loai xe     |                                   |\n";
   	cout << "+----------------+-----------------------------------+\n";
   	cout << "|   Bien so xe   |                                   |\n";
   	cout << "+----------------+-----------------------------------+\n";
   	cout << "|     Mau xe     |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
   	cout << "| Gia thue 1 gio |                                   |\n";
   	cout << "+----------------+-----------------------------------+\n";
}

void menu_delete_motor(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
    cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                     Xoa xe may                     |\n";
   	cout << "+--------------+----------------------+--------------+\n";
   	cout << "|   Quay lai   |                      |    Xoa xe    |\n";
   	cout << "+--------------+                      +--------------+\n\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|  Nhap ma xe  |                                     |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << left << setw(16) << "\nMa xe may" 
		 << left << setw(15) << "Hang xe"
		 << left << setw(15) << "Loai xe"
		 << left << setw(15) << "Bien so xe"
		 << left << setw(15) << "Mau xe"
		 << left << setw(15) << "Gia thue 1h"
		 << "Tinh trang\n\n";
}

void menu_search_motor(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
    cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|              Tim kiem thong tin xe may             |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "| Nhap tu khoa |                                     |\n";
   	cout << "+--------------+-------------------------------------+\n";
}

void menu_search_client(){
	system("cls");
    cout << "+----------------------------------------------------+\n";
    cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|           Tim kiem thong tin khach hang            |\n";
    cout << "+--------------+-------------------------------------+\n";
    cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n\n";
    cout << "+--------------+-------------------------------------+\n";
    cout << "| Nhap tu khoa |                                     |\n";
    cout << "+--------------+-------------------------------------+\n";
}

void menu_admin3(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                  Quan ly hop dong                  |\n";
    cout << "+----------------------------------------------------+\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |   Hop dong cho xac nhan    |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |   Hop dong da hoan thanh   |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |  Hop dong chua hoan thanh  |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |       Them hop dong        |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |        Huy hop dong        |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |          Quay lai          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_contract_confirm(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
    cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|          Danh sach hop dong cho xac nhan           |\n";
    cout << "+--------------+---+--------------+---+--------------+\n";
    cout << "|   Quay lai   |   | Xac nhan het |   |   Xac nhan   |\n";
    cout << "+--------------+   +--------------+   +--------------+\n\n";
    cout << "+--------------+-------------------------------------+\n";
   	cout << "| Ma hop dong  |                                     |\n";
   	cout << "+--------------+-------------------------------------+\n\n";
    cout << left << setw(15) << "Ma hop dong"
    	 << left << setw(15) << "Ma khach hang"
    	 << left << setw(15) << "Ma xe may"
    	 << left << setw(19) << "Thoi gian dat"
    	 << left << setw(19) << "Thoi gian tra"
    	 << left << setw(15) << "Tong chi phi"
    	 << "Trang thai\n\n";
}

void menu_contract_complete(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
    cout << "+----------------------------------------------------+\n";
   	cout << "|          Danh sach hop dong da hoan thanh          |\n";
   	cout << "+------------+---------------------------------------+\n";
   	cout << "|  Quay lai  |\n";
   	cout << "+------------+\n\n";
   	cout << left << setw(15) << "Ma hop dong"
   		 << left << setw(15) << "Ma khach hang"
   		 << left << setw(15) << "Ma xe may"
   		 << left << setw(19) << "Thoi gian dat"
   		 << left << setw(19) << "Thoi gian tra"
   		 << left << setw(15) << "Tong chi phi"
   		 << "Trang thai\n\n";
}

void menu_contract_not_complate(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|         Danh sach hop dong chua hoan thanh         |\n";
   	cout << "+------------+---------------------------------------+\n";
   	cout << "|  Quay lai  |\n";
   	cout << "+------------+\n\n";
   	cout << left << setw(15) << "Ma hop dong"
   		 << left << setw(15) << "Ma khach hang"
   		 << left << setw(15) << "Ma xe may"
   		 << left << setw(19) << "Thoi gian dat"
   		 << left << setw(19) << "Thoi gian tra"
   		 << left << setw(15) << "Tong chi phi"
   		 << "Trang thai\n\n";
}

void menu_admin4(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                      Thong ke                      |\n";
    cout << "+----------------------------------------------------+\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |         Doanh thu          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |    Tinh trang hop dong     |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |     Tinh trang xe may      |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |          Quay lai          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_client(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
    cout << "|                 XIN CHAO QUY KHACH                 |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |     Thong tin ca nhan      |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |   Sua thong tin ca nhan    |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |  Tim kiem va Dat thue xe   |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |        Huy hop dong        |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |      Lich su thue xe       |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |        Doi mat khau        |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |         Dang xuat          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_profile(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                  Thong tin ca nhan                 |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n\n";
   	cout << "+--------------------+-------------------------------+\n";
    cout << "|   Ma khach hang    |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|     Ho va ten      |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|      So CCCD       |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|      Ngay sinh     |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|      Que quan      |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|   So dien thoai    |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|       Email        |                               |\n";
    cout << "+--------------------+-------------------------------+\n";	
} 

void menu_edit_client(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                Sua thong tin ca nhan               |\n";
   	cout << "+--------------+----------------------+--------------+\n";
   	cout << "|   Quay lai   |                      |   Xac nhan   |\n";
    cout << "+--------------+                      +--------------+\n\n";
    cout << "+----------------------------------------------------+\n";
    cout << "|               Nhap thong tin can sua               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|   Ma khach hang    |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|     Ho va ten      |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|      So CCCD       |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|      Ngay sinh     |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|      Que quan      |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|   So dien thoai    |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
    cout << "|       Email        |                               |\n";
    cout << "+--------------------+-------------------------------+\n";
}

void menu_rental_history(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
    cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Lich su thue xe                 |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n\n";
   	cout << left << setw(15) << "Ma hop dong"
   		 << left << setw(15) << "Ma khach hang"
   		 << left << setw(15) << "Ma xe may"
   		 << left << setw(19) << "Thoi gian dat"
   		 << left << setw(19) << "Thoi gian tra"
   		 << left << setw(15) << "Tong chi phi"
   		 << "Trang thai\n\n";
}

void menu_edit_motor(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
    cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                Sua thong tin xe may                |\n";
   	cout << "+--------------+----------------------+--------------+\n";
   	cout << "|   Quay lai   |                      |   Xac nhan   |\n";
    cout << "+--------------+                      +--------------+\n\n";
    cout << "+------------------------+---------------------------+\n";
    cout << "| Nhap ma xe may can sua |                           |\n";
    cout << "+------------------------+---------------------------+\n";
    cout << "|               Nhap thong tin can sua               |\n";
    cout << "+----------------+-----------------------------------+\n";
    cout << "|    Hang xe     |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
    cout << "|    Loai xe     |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
    cout << "|   Bien so xe   |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
    cout << "|     Mau xe     |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
    cout << "| Gia thue 1 gio |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
    cout << "|   Trang thai   |                                   |\n";
    cout << "+----------------+-----------------------------------+\n";
}

void menu_rental(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|               Tim kiem va Dat thue xe              |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Nhap thong tin                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|    Ma xe may    |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|   Ngay/Gio dat  |     /  /        |        :       |\n";
   	cout << "+-----------------+----------------------------------+\n";
  	cout << "|   Ngay/Gio tra  |     /  /        |        :       |\n"; 
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "| Tong thoi gian  |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|   Tong chi phi  |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|  Xac nhan dat   |\n";
   	cout << "+-----------------+\n\n";
   	cout << "Tim kiem xe may\n";
   	cout << "+-----------------+----------------------------------+\n";
    cout << "|  Nhap tu khoa   |                                  |\n";
    cout << "+-----------------+----------------------------------+\n";
}

void menu_cancel_contract(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Huy hop dong                    |\n";
   	cout << "+--------------+---+--------------+---+--------------+\n";
   	cout << "|   Quay lai   |   |  Huy tat ca  |   | Xac nhan huy |\n";
    cout << "+--------------+   +--------------+   +--------------+\n\n";
    cout << "+--------------+-------------------------------------+\n";
   	cout << "| Ma hop dong  |                                     |\n";
   	cout << "+--------------+-------------------------------------+\n\n";
    cout << left << setw(15) << "Ma hop dong"
   		 << left << setw(15) << "Ma khach hang"
   		 << left << setw(15) << "Ma xe may"
   		 << left << setw(19) << "Thoi gian dat"
   		 << left << setw(19) << "Thoi gian tra"
   		 << left << setw(15) << "Tong chi phi"
   		 << "Trang thai\n\n";
}

void menu_statistic(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                       Thong ke                     |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|           +----------------------------+           |\n";
    cout << "|           |       Theo tung thang      |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |        Theo tung quy       |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |    Theo khoang thoi gian   |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |       Thong ke xe may      |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "|           |          Quay lai          |           |\n";
    cout << "|           +----------------------------+           |\n";
    cout << "+----------------------------------------------------+\n";
}

void menu_statistic1(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|              Thong ke theo tung thang              |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n";
	cout << "+-------------------+--------------------------------+\n";
	cout << "| Nhap nam thong ke |                                |\n";
	cout << "+-------------------+--------------------------------+\n";
}

void menu_statistic2(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|               Thong ke theo tung quy               |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n";
	cout << "+-------------------+--------------------------------+\n";
	cout << "| Nhap nam thong ke |                                |\n";
	cout << "+-------------------+--------------------------------+\n";
}

void menu_statistic3(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|           Thong ke theo khoang thoi gian           |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n";
	cout << "+---------+---------------+----------+---------------+\n";
	cout << "| Tu ngay |    /  /       | Den ngay |    /  /       |\n";
	cout << "+---------+---------------+----------+---------------+\n";
}

void menu_statistic4(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                 Thong ke ve xe may                 |\n";
   	cout << "+--------------+-------------------------------------+\n";
   	cout << "|   Quay lai   |\n";
   	cout << "+--------------+\n";
}

void menu_add_contract(){
	system("cls");
	cout << "+----------------------------------------------------+\n";
   	cout << "|   PBL2: XAY DUNG UNG DUNG HO TRO CHO THUE XE MAY   |\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Them hop dong                   |\n";
   	cout << "+--------------+----------------------+--------------+\n";
   	cout << "|   Quay lai   |                      |   Xac nhan   |\n";
    cout << "+--------------+                      +--------------+\n\n";
   	cout << "+----------------------------------------------------+\n";
   	cout << "|                    Nhap thong tin                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|   Ma hop dong   |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|      CCCD       |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|    Ma xe may    |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|   Ngay/Gio dat  |     /  /        |        :       |\n";
   	cout << "+-----------------+----------------------------------+\n";
  	cout << "|   Ngay/Gio tra  |     /  /        |        :       |\n"; 
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "| Tong thoi gian  |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
   	cout << "|   Tong chi phi  |                                  |\n";
   	cout << "+-----------------+----------------------------------+\n";
}

#endif //MENU_H
