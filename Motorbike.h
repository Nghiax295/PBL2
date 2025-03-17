#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;

//Lop xe may
class motorbike{
	private:
		string id_motor; //PK
		string brand;
		string type;
		string plate_number;
		string color;
		long price;
		string status;
	public:
		motorbike();
		motorbike(string, string, string, string, string, long, string);
		
		void load_from_file(ifstream &);
		void save_to_file(ofstream &);
		
		string get_id() const;
		string get_brand() const;
		string get_type() const;
		string get_plate_number() const;
		string get_color() const;
		long get_price();
		string get_status() const;
		
		void set_brand(const string &);
		void set_type(const string &);
		void set_plate_number(const string &);
		void set_color(const string &);
		void set_price(long);
		void set_status(const string &);
		
		void show_list();
		void edit_motor();
		bool search(const string &);
};

motorbike::motorbike() : id_motor(""), brand(""), type(""),
	plate_number(""), color(""), price(0), status(""){}

motorbike::motorbike(string id_motor, string brand, string type,
	string plate_number, string color, long price, string status) :
	id_motor(id_motor), brand(brand), type(type), price(price),
	plate_number(plate_number), color(color), status(status){}


void motorbike::load_from_file(ifstream &file) {
	getline(file, id_motor, '|');
	getline(file, brand, '|');
	getline(file,type, '|');
	getline(file, plate_number, '|');
	getline(file, color, '|');
	file >> price;
	file.ignore(numeric_limits<streamsize>::max(), '|');
	getline(file, status);
}

void motorbike::save_to_file(ofstream &file) {
	file << id_motor << "|"
	     << brand << "|"
	     << type << "|"
	     << plate_number << "|"
	     << color << "|"
	     << price << "|"
	     << status << "\n";
}


string motorbike::get_id() const{
	return id_motor;
}

string motorbike::get_brand() const{
	return brand;
}

string motorbike::get_type() const{
	return type;
}

string motorbike::get_plate_number() const{
	return plate_number;
}

string motorbike::get_color() const{
	return color;
}

long motorbike::get_price(){
	return price;
}

string motorbike::get_status() const{
	return status;
}


void motorbike::set_brand(const string &new_brand){
	brand = new_brand;
}

void motorbike::set_type(const string &new_type){
	type = new_type;
}

void motorbike::set_plate_number(const string &new_plate_number){
	plate_number = new_plate_number;
}

void motorbike::set_color(const string &new_color){
	color = new_color;
}

void motorbike::set_price(long new_price){
	price = new_price;
}

void motorbike::set_status(const string &new_status){
	status = new_status;
}


void motorbike::show_list() {
	cout << left << setw(15) << id_motor
	     << left << setw(15) << brand
	     << left << setw(15) << type
	     << left << setw(15) << plate_number
	     << left << setw(15) << color
	     << left << setw(15) << price
		 << status << "\n";
}

void motorbike::edit_motor(){
	menu_edit_motor();
    int x, y, n=1;
    bool c = false, c1 = false;
    string id_motor, brand, type, plate_number, color, status;
    long price;
    while(true){
    	get_x_y(x, y);
    	if(x >= 0 && x < 15 && y >= 4 && y < 6){
    		system("cls");
    		return;
		} else if(x >= 25 && x < 54 && y >= 8 && y < 10){
			moveCursor(27, 9); cout << "                          ";
			inputAtCursor(id_motor, 27, 9); convert_to_upper(id_motor);
			moveCursor(0, 25);
			List<motorbike> mt_list;
			mt_list.load("motorbike.txt");
			Node<motorbike> *mt = mt_list.get_head();
			while(mt != NULL){
				if(mt->data.get_id() == id_motor){
					moveCursor(19, 13); cout << mt->data.get_brand();
					moveCursor(19, 15); cout << mt->data.get_type();
					moveCursor(19, 17); cout << mt->data.get_plate_number();
					moveCursor(19, 19); cout << mt->data.get_color();
					moveCursor(19, 21); cout << mt->data.get_price();
					moveCursor(19, 23); cout << mt->data.get_status();
					c1 = true;
					break;
				}
				mt = mt->next;
			}
			moveCursor(0, 25);
			if(!c1) {
				moveCursor(0, 25); cout << "Khong co xe voi ma tren.";
			}
		} else if(x >= 17 && x < 54 && y >= 12 && y < 14){
			if(!c1) {
				moveCursor(0, 25); cout << "Chua nhap ma xe may.";
				continue;
			}
			moveCursor(19, 13); cout << "                                 ";
			inputAtCursor(brand ,19, 13); convert_to_upper(brand);
			c = true; moveCursor(0, 25);
		} else if(x >= 17 && x < 54 && y >= 14 && y < 16) {
			if(!c1) {
				moveCursor(0, 25); cout << "Chua nhap ma xe may.";
				continue;
			}
			moveCursor(19, 15); cout << "                                 ";
			inputAtCursor(type ,19, 15); convert_to_upper(type);
			c = true; moveCursor(0, 25);
		} else if(x >= 17 && x < 54 && y >= 16 && y < 18) {
			if(!c1) {
				moveCursor(0, 25); cout << "Chua nhap ma xe may.";
				continue;
			}
			moveCursor(19, 17); cout << "                                 ";
			inputAtCursor(plate_number ,19, 17); convert_to_upper(plate_number);
			c = true; moveCursor(0, 25);
		} else if(x >= 17 && x < 54 && y >= 18 && y < 20) {
			if(!c1) {
				moveCursor(0, 25); cout << "Chua nhap ma xe may.";
				continue;
			}
			moveCursor(19, 19); cout << "                                 ";
			inputAtCursor(color ,19, 19); convert_to_upper(color);
			c = true; moveCursor(0, 25);
		} else if(x >= 17 && x < 54 && y >= 20 && y < 22) {
			if(!c1) {
				moveCursor(0, 25); cout << "Chua nhap ma xe may.";
				continue;
			}
			moveCursor(19, 21); cout << "                                 ";
			moveCursor(19, 21); cin >> price;
			c = true; moveCursor(0, 25);
		} else if(x >= 17 && x < 54 && y >= 22 && y < 24) {
			if(!c1) {
				moveCursor(0, 25); cout << "Chua nhap ma xe may.";
				continue;
			}
			moveCursor(19, 23); cout << "                                 ";
			moveCursor(55, 23); cout << "(\"TRONG\" , \"DANG THUE\")";
			inputAtCursor(status, 19, 23); convert_to_upper(status);
			c = true; moveCursor(0, 25);
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			if(n == 1 || c){
				List<motorbike> mt_list;
				mt_list.load("motorbike.txt");
				Node<motorbike> *temp = mt_list.get_head();
				while(temp != NULL){
					if(temp->data.get_id() == id_motor){
						if(brand != "") temp->data.set_brand(brand);
						if(type != "") temp->data.set_type(type);
						if(plate_number != "") temp->data.set_plate_number(plate_number);
						if(color != "") temp->data.set_color(color);
						if(price) temp->data.set_price(price);
						if(status == "TRONG" || status == "DANG THUE") temp->data.set_status(status);
						break;
					}
					temp = temp->next;
				}
				ofstream file("motorbike.txt", ios::trunc);
				mt_list.save(file);
				file.close();
				moveCursor(0, 25); cout << "                                      ";
				moveCursor(0, 25); cout << "Da cap nhat thong tin\n";
				n--;
			} 
			if(!c) {
				moveCursor(0, 25); cout << "Nhap cac thong tin truoc khi xac nhan.";
			}
		}
	}
}

bool motorbike::search(const string &keyword){
	List<motorbike> motor_list;
    motor_list.load("motorbike.txt");
    Node<motorbike>* temp = motor_list.get_head();
    bool found = false;
    cout << "\n";
    cout << left << setw(16) << "\nMa xe may"
         << left << setw(15) << "Hang xe"
         << left << setw(15) << "Loai xe"
         << left << setw(15) << "Bien so xe"
         << left << setw(15) << "Mau xe"
         << left << setw(15) << "Gia thue 1h"
         << "Tinh trang\n\n";
    if(keyword == "") return found;
    while (temp != NULL) {
        if (temp->data.get_id().find(keyword) != string::npos ||
            temp->data.get_brand().find(keyword) != string::npos ||
            temp->data.get_type().find(keyword) != string::npos ||
            temp->data.get_plate_number().find(keyword) != string::npos ||
            temp->data.get_color().find(keyword) != string::npos) {
        	temp->data.show_list();
            found = true;
        }
        temp = temp->next;
    }
    return found;
}

#endif //MOTORBIKE_H
