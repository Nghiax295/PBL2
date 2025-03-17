#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "Account.h"
#include "Menu.h"
#include "Function.h"
#include "LinkedList.h"
#include "Client.h"
#include "Admin.h"

class Rental_system : public admin, public client_function{
	public:
		bool login(string &);
		void login_system();
		void create_account();
		void update_data();
		void run_admin();
		void run_client(const string &);
};

bool Rental_system::login(string &id){
	List<client> account_list;
    account_list.load("user.txt");
    menu_login();
    string username, password, hidden;
    int x, y;
    moveCursor(0, 19);
	int n;
    while (true) {
    	get_x_y(x, y);
    	if (x >= 14 && x < 40 && y >= 15 && y < 17)
            return false;
        if(x >= 20 && x < 47 && y >=5 && y < 7){
        	moveCursor(22, 6); cout << "                        ";
            inputAtCursor(username, 22, 6);
		} else if(x >= 20 && x < 46 && y >= 8 && y < 10){
			moveCursor(22, 9); cout << "                        ";
           	moveCursor(22, 9);
           	char ch;
           	password = ""; hidden="";
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        		    if (!password.empty()) {
        		        password.erase(password.size() - 1);
        		        hidden.erase(hidden.size() - 1);
               			cout << "\b \b";
            		}
       			} else {
         		   password += ch;
         		   hidden += '*';
          		   cout << '*'; 
        		}
   			}
           	n=1;
		} else if (x >= 2 && x < 26 && y >= 12 && y < 14) {
            Node<client> *temp = account_list.get_head();
            while (temp != NULL) {
                if (temp->data.check_account(username, password)) {
                    id = temp->data.get_id();
                    return true;
                }
                temp = temp->next;
            }
            menu_login();
            moveCursor(10, 11);
            cout << "Sai thong tin dang nhap. Thu lai!";
            username.clear();
            password.clear();
        } else if (x >= 47 && x < 51 && y >= 8 && y < 10) {
        	if(n == 1){
        		moveCursor(22, 9); cout << password;
        		n=0;
			} else {
				moveCursor(22, 9); cout << hidden;
				n=1;
			}
		} else if (x >= 28 && x < 52 && y >= 12 && y < 14){
			foget_pass();
        }
        moveCursor(0, 19);
    }
}

void Rental_system::login_system(){
	int x, y;
    while(true){
    	//update_data();
    	menu_app();
    	get_x_y(x, y);
    	if(x >= 2 && x < 26 && y >= 9 && y < 11){
    		string id = "";
    		if(login(id)){
    			if(id != "ADMIN") run_client(id);	
    			else run_admin();
			}
		}else if(x >= 28 && x < 52 && y >= 9 && y < 11){
			create_account();
		} else if(x >= 16 && x < 39 && y >= 12 && y < 14){
			break;
		}
	}
	return;
}

void Rental_system::create_account(){
	menu_register();
	int x, y, n=1, n1, u, p;
	string id_client, name, id_card, dob, address, phone, email, user, pass, hidden;
	while(true){
		get_x_y(x, y);
		if(x >= 0 && x < 15 && y >= 4 && y < 6) return;
		else if(x >= 23 && x < 54 && y >= 10 && y < 12){
			moveCursor(55, 11); cout << "                     ";
			moveCursor(23, 11); cout << "                              ";
			inputAtCursor(name, 23, 11); 
			if(!check_name(name)){
				moveCursor(55, 11); cout << "Ten khong hop le.";
			} else convert_to_upper(name);
		} else if(x >= 23 && x < 54 && y >= 12 && y < 14) {
			moveCursor(55, 13); cout << "                   ";
			moveCursor(23, 13); cout << "                              ";
			inputAtCursor(id_card, 23, 13); 
			if(!check_cccd(id_card)){
				moveCursor(55, 13); cout << "CCCD gom 12 so.";
			}
		} else if(x >= 23 && x < 54 && y >= 14 && y < 16) {
			moveCursor(55, 15); cout <<"                           ";
			moveCursor(23, 15); cout << "                              ";
			inputAtCursor(dob, 23, 15);
			if(!check_dob(dob)){
				moveCursor(55, 15); cout <<"Ngay sinh khong hop le.";
			}
		} else if(x >= 23 && x < 54 && y >= 16 && y < 18) {
			moveCursor(55, 17); cout << "                          ";
			moveCursor(23, 17); cout << "                              ";
			inputAtCursor(address, 23, 17); 
			if(address.length() < 3){
				moveCursor(55, 17); cout << "Que quan khong hop le.";
			} else convert_to_upper(address);
		} else if(x >= 23 && x < 54 && y >= 18 && y < 20) {
			moveCursor(55, 19); cout << "                     ";
			moveCursor(23, 19); cout << "                              ";
			inputAtCursor(phone, 23, 19);
			if(!check_phone(phone)){
				moveCursor(55, 19); cout << "SDT khong hop le.";
			}
		} else if(x >= 23 && x < 54 && y >= 20 && y < 22) { 
			moveCursor(55, 21); cout << "                       ";
			moveCursor(23, 21); cout << "                              ";
			inputAtCursor(email, 23, 21);
			if(!check_email(email)){
				moveCursor(55, 21); cout << "Email khong hop le.";
			}
		} else if(x >= 23 && x < 54 && y >= 22 && y < 24){
			user = "";
			moveCursor(23, 23); cout << "                              ";
			moveCursor(55, 23); cout << "                                            ";                        
			u = 0; inputAtCursor(user, 23, 23);
			if(user.length() < 6 || user.length() > 12){
				moveCursor(55, 23); cout << "Ten nguoi dung tu 6-12 ki tu.";
			}
			if(!check_user(user)){
				moveCursor(55, 23); cout << "Ten nguoi dung khong chua ki tu dac biet.";
			} else u = 1;
		} else if(x >= 23 && x < 50 && y >= 24 && y < 26) {
			moveCursor(55, 25); cout << "                         ";
			moveCursor(23, 25); cout << "                          ";
			pass = ""; hidden = "";
			moveCursor(23, 25);
			char ch;
			int cnt=0;
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        		    if (!pass.empty()) {
        		    	cnt--;
        		        pass.erase(pass.size() - 1);
        		        hidden.erase(hidden.size() - 1);
               			cout << "\b \b";
           			}
       		 	} else {
         		   pass += ch; cnt++;
         		   hidden += '*';
          		   cout << '*'; 
        		}
   			}
   			if(cnt < 8 || cnt > 12) {
   				moveCursor(55, 25); cout << "Mat khau tu 8-12 ki tu.\n";
			} else {
				n1=1; p = 1;
			}
		} else if(x >= 50 && x < 54 && y >= 24 && y < 26) {
			if(n1 == 1){
        		moveCursor(23, 25); cout << pass; n1=0;
			} else {
				moveCursor(23, 25); cout << hidden; n1=1;
			}
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			bool c = false;
			List<account> acc_list;
			acc_list.load("user.txt");
			Node<account> *temp = acc_list.get_head();
			while(temp != NULL){
				if(temp->data.get_user() == user){
					c = true;
					break;
				}
				temp = temp->next;
			}
			if(c && n==1){
				moveCursor(55, 23); cout << "Ten nguoi dung da ton tai.";
			} else if(!u || !p){
				moveCursor(23, 23); cout << "                              ";
				moveCursor(23, 25); cout << "                         ";
				moveCursor(0, 27); cout << "Khong duoc de trong ten nguoi dung hoac mat khau.";
			} else if(n==1){
				List<client> client_list;
				client_list.load("user.txt");
				do{
					id_client = create_code("KH");
					if(!client_list.find_id("user.txt", id_client))
						break;
				} while(true);
				client new_client(id_client, user, pass, name, id_card, dob, address, phone, email);
				client_list.add(new_client);
				ofstream file_client("user.txt", ios::trunc);
				client_list.save(file_client);
				file_client.close();
				moveCursor(0, 27); cout << "                              ";
				moveCursor(0, 27); cout << "Tao tai khoan thanh cong.";	
				n--;
			}
		}
		moveCursor(0, 27);
	}
}

void Rental_system::update_data(){
	datetime time_now;
	time_now.time_now();
	time_t now = time_now.convert_time();
	List<contract> contract_list;
	contract_list.load("contract.txt");
	Node<contract> *ct = contract_list.get_head();
	
	time_t time;
	while(ct != NULL){
		if(ct->data.get_status() == "DANG THUE"){
			datetime dt = ct->data.get_return_date();
			time = dt.convert_time();
			if(now > time){
				ct->data.set_status("HOAN THANH");
				List<motorbike> motor_list;
				motor_list.load("motorbike.txt");
				Node<motorbike> *mt = motor_list.get_head();
				while(mt != NULL){
					if(mt->data.get_id() == ct->data.get_id_motor()){
						mt->data.set_status("TRONG");
						ofstream file_motor("motorbike.txt", ios::trunc);
						motor_list.save(file_motor);
						file_motor.close();
						break;
					}
					mt = mt->next;
				}
			}
		} else if(ct->data.get_status() == "DA DAT"){
			datetime dt = ct->data.get_rental_date();
			time = dt.convert_time();
			if(now > time){
				ct->data.set_status("DANG THUE");
				List<motorbike> motor_list;
				motor_list.load("motorbike.txt");
				Node<motorbike> *mt = motor_list.get_head();
				while(mt != NULL){
					if(mt->data.get_id() == ct->data.get_id_motor()){
						mt->data.set_status("DANG THUE");
						ofstream file_motor("motorbike.txt", ios::trunc);
						motor_list.save(file_motor);
						file_motor.close();
						break;
					}
					mt = mt->next;
				}
			}
		}
		ct = ct->next;
 	}
	ofstream file_contract("contract.txt", ios::trunc);
	contract_list.save(file_contract);
	file_contract.close();
}

void Rental_system::run_admin(){
	int x, y;
	while(true){	
		menu_admin();
		update_data();
		get_x_y(x, y);
		if(x >= 3 && x < 26 && y >= 4 && y < 6){
			update_data();
			client_manage();
		}
		else if(x >= 29 && x < 52 && y >= 4 && y < 6){
			update_data();
			motor_manage();
		}
		else if(x >= 3 && x < 26 && y >= 7 && y < 9){
			update_data();
			contract_manage();
		}
		else if(x >= 29 && x < 52 && y >= 7 && y < 9){
			update_data();
			int x, y;
			while(true){
				menu_statistic();
				get_x_y(x, y);
				if(x >= 13 && x < 42 && y >= 5 && y < 7){
					statistic_month();
				} else if(x >= 13 && x < 42 && y >= 8 && y < 10){
					statistic_quarter();
				} else if(x >= 13 && x < 42 && y >= 11 && y < 13){
					statistic_KTG();
				} else if(x >= 13 && x < 42 && y >= 14 && y < 16){
					statistic_motor();
				} else if(x >= 13 && x < 42 && y >= 17 && y < 19) {
					break;
				}
			}
		}
		else if(x >= 16 && x < 39 && y >= 10 && y < 12){
			system("cls");
			return;
		}
	}
}

void Rental_system::run_client(const string &id){
	int x, y;
	while(true){
		update_data();
		menu_client();
		get_x_y(x, y);
		if(x >= 13 && x < 42 && y >= 4 && y < 6){
			show_profile(id);
			go_back();
		} else if(x >= 13 && x < 42 && y >= 7 && y < 9){
			update_profile(id);
		} else if(x >= 13 && x < 42 && y >= 10 && y < 12){
			rental(id);
		} else if(x >= 13 && x < 42 && y >= 13 && y < 15){
			cancel_contract(id);
		} else if(x >= 13 && x < 42 && y >= 16 && y < 18){
			rental_history(id);
			go_back();
		} else if(x >= 13 && x < 42 && y >= 19 && y < 21){
			update_pass(id);
		} else if(x >= 13 && x < 42 && y >= 22 && y < 24){
    		system("cls");
			menu_app();
			break;
		}
		moveCursor(0, 29);
	}
}

#endif //SYSTEM_H
