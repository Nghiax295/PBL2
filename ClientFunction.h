#ifndef CLIENTFUNCTION_H
#define CLIENTFUNCTION_H

#include "Client.h"

class client_function : public client{
	public:
		void show_profile(const string &);
		void update_profile(const string &);
        void search_motor();
        void rental(const string &);
        void cancel_contract(const string &);
        void rental_history(const string &);
        void update_pass(const string &);
        void foget_pass(); 
};

void client_function::show_profile(const string &id){
	menu_profile();
	List<client> client_list;
   	client_list.load("user.txt");
   	Node<client> *temp = client_list.get_head();
   	while(temp != NULL){
   		if(temp->data.get_id() == id){
   			moveCursor(23, 9); cout << temp->data.get_id();
   			moveCursor(23, 11); cout << temp->data.get_name();
   			moveCursor(23, 13); cout << temp->data.get_id_card();
   			moveCursor(23, 15); cout << temp->data.get_dob(); 
   			moveCursor(23, 17); cout << temp->data.get_address();
   			moveCursor(23, 19); cout << temp->data.get_phone();
   			moveCursor(23, 21); cout << temp->data.get_email();
   			break;
		}
		temp = temp->next;
	}
}

void client_function::search_motor(){
   	moveCursor(20, 26); cout << "                                 ";
   	moveCursor(20, 26);
   	string keyword;
   	getline(cin, keyword);
   	convert_to_upper(keyword);
   	motorbike MT;
   	if(!MT.search(keyword)){
   		moveCursor(0, 29); cout << setfill(' ') << setw(100);
   		moveCursor(0, 29); cout << "Khong tim thay voi tu khoa: ";
		moveCursor(28, 29); cout << keyword << endl;
	}
}

void client_function::foget_pass(){
	menu_forget_pass();
   	string id_client, pass1, pass2, captcha1, captcha2, hidden1, hidden2;
   	int x, y, n1, n2;
   	while(true){
   		get_x_y(x, y);
   		if(x >= 0 && x < 15 && y >= 4 && y < 6){
   			menu_login();
   			return;
		} else if(x >= 22 && x < 54 && y >= 8 && y < 10){
			moveCursor(23, 9); cout << "                              ";
			inputAtCursor(id_client, 23, 9); convert_to_upper(id_client);
		} else if(x >= 22 && x < 50 && y >= 10 && y < 12) {
			moveCursor(55, 11); cout << "                         ";
			moveCursor(23, 11); cout << "                          ";
			moveCursor(23, 11);
			pass1=""; hidden1="";
			char ch; 
			int cnt=0;
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        			cnt--;
        		    if (!pass1.empty()) {
        		        pass1.erase(pass1.size() - 1);
        		        hidden1.erase(hidden1.size() - 1);
               			cout << "\b \b";
            		}
       		 	} else {
         		   pass1 += ch; cnt++;
         		   hidden1 += '*';
          		   cout << '*'; 
        		}
   			}
   			if(cnt < 8 || cnt > 12) {
   				moveCursor(55, 11); cout << "Mat khau tu 8-12 ki tu.\n";
			} else n1=1;
		} else if(x >= 22 && x < 50 && y >= 12 && y < 14) {
			moveCursor(55, 13); cout << "                         ";
			moveCursor(23, 13); cout << "                          ";
			pass2=""; hidden2="";
			moveCursor(23, 13);
			char ch;
			int cnt=0;
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        		    if (!pass2.empty()) {
        		    	cnt--;
        		        pass2.erase(pass2.size() - 1);
        		        hidden2.erase(hidden2.size() - 1);
               			cout << "\b \b";
            		}
       		 	} else {
         		   pass2 += ch; cnt++;
         		   hidden2 += '*';
          		   cout << '*'; 
        		}
   			}
   			if(cnt < 8 || cnt > 12) {
   				moveCursor(55, 13); cout << "Mat khau tu 8-12 ki tu.\n";	
			} else n2=1;
		} else if(x >= 50 && x < 54 && y >= 10 && y < 12) {
			if(n1 == 1){
        		moveCursor(23, 11); cout << pass1; n1=0;
			} else {
				moveCursor(23, 11); cout << hidden1; n1=1;
			}
		} else if(x >= 50 && x < 54 && y >= 12 && y < 14) {
			if(n2 == 1){
        		moveCursor(23, 13); cout << pass2; n2=0;
			} else {
				moveCursor(23, 13); cout << hidden2; n2=1;
			}
		} else if(x >= 0 && x < 22 && y >= 16 && y < 18) {
			captcha1 = create_captcha();
			moveCursor(17, 15); cout << captcha1;
			moveCursor(4, 17); cout << "        ";
			inputAtCursor(captcha2, 5, 17);
		} else if(x >= 32 && x < 54 && y >= 16 && y < 18){
			List<client> client_list;
			if(!client_list.find_id("user.txt", id_client)) {
				moveCursor(0, 20); cout << "                                   ";
				moveCursor(0, 20); cout << "Ma khach hang khong dung.\n";
			} else if(pass1 != pass2){
				moveCursor(0, 20); cout << "                                   ";
				moveCursor(0, 20); cout << "Mat khau moi khong trung nhau.\n";
			} else if(captcha1 != captcha2){
				moveCursor(0, 20); cout << "                                   ";
				moveCursor(0, 20); cout << "Nhap sai ma CAPTCHA.\n";
			} else {
				moveCursor(0, 20); cout << "                                   ";
				moveCursor(0, 20); cout << "Da doi duoc mat khau.\n";
				client_list.load("user.txt");
				Node<client> *temp = client_list.get_head();
				while(temp != NULL){
					if(temp->data.get_id() == id_client){
						temp->data.set_pass(pass1);
						ofstream file("user.txt", ios::trunc);
        				client_list.save(file);
        				file.close();
        				break;
					}
					temp = temp->next;
				}
			}
		}
		moveCursor(0, 19);
	}
}

void client_function::update_pass(const string &id){
	menu_update_pass();
   	string pass1, pass2, pass3, hidden1, hidden2, hidden3;
   	int n1, n2, n3;
   	List<client> acc_list;
   	acc_list.load("user.txt");
   	Node<client> *temp = acc_list.get_head();
   	while(temp != NULL){
   		if(temp->data.get_id() == id)
   			break;
   		temp = temp->next;
	}
	moveCursor(22, 9); cout << temp->data.get_user();
	moveCursor(0, 17);
   	int x, y, n=1;
   	bool c = false;
   	while(true){
   		get_x_y(x, y);
   		if(x >= 0 && x < 15 && y >= 4 && y < 6){
   			system("cls");
   			return;
		} else if(x >= 21 && x < 50 && y >= 10 && y < 12){
			moveCursor(55, 11); cout << "                           ";
   			moveCursor(22, 11); cout << "                           ";
           	moveCursor(22, 11);
           	char ch;
           	pass1 = ""; hidden1="";
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        		    if (!pass1.empty()) {
        		        pass1.erase(pass1.size() - 1);
        		        hidden1.erase(hidden1.size() - 1);
               			cout << "\b \b";
            		}
       			} else {
         		   pass1 += ch;
         		   hidden1 += '*';
          		   cout << '*'; 
        		}
   			}
           	n1=1;
   		} else if(x >= 50 && x < 54 && y >= 10 && y < 12){
   			if(n1 == 1){
        		moveCursor(22, 11); cout << pass1; n1=0;
			} else {
				moveCursor(22, 11); cout << hidden1; n1=1;
			}
		} else if(x >= 21 && x < 50 && y >= 12 && y < 14){
			moveCursor(55, 13); cout << "                               ";
			moveCursor(55, 15); cout << "                               ";
   			moveCursor(22, 13); cout << "                           ";
           	moveCursor(22, 13);
           	char ch;
           	int cnt=0;
           	pass2 = ""; hidden2="";
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        		    if (!pass2.empty()) {
        		    	cnt--;
        		        pass2.erase(pass2.size() - 1);
        		        hidden2.erase(hidden2.size() - 1);
               			cout << "\b \b";
            		}
       			} else {
         		   pass2 += ch; cnt++;
         		   hidden2 += '*';
          		   cout << '*'; 
        		}
   			}
           	if(cnt < 8 || cnt > 12){
   				moveCursor(55, 13); cout << "Mat khau tu 8-12 ki tu.";
			} else n2=1;
		} else if(x >= 50 && x < 54 && y >= 12 && y < 14){
			if(n2 == 1){
        		moveCursor(22, 13); cout << pass2; n2=0;
			} else {
				moveCursor(22, 13); cout << hidden2; n2=1;
			}
		} else if(x >= 21 && x < 50 && y >= 14 && y < 16){
			moveCursor(55, 15); cout << "                               ";
			moveCursor(22, 15); cout << "                           ";
           	moveCursor(22, 15);
           	char ch;
           	int cnt=0;
           	pass3 = ""; hidden3="";
    		while (true) {
        		ch = _getch();
        		if (ch == '\r') {
        		    cout << endl;
        		    break;
        		} else if (ch == '\b') {
        		    if (!pass3.empty()) {
        		    	cnt--;
        		        pass3.erase(pass3.size() - 1);
        		        hidden3.erase(hidden3.size() - 1);
               			cout << "\b \b";
            		}
       			} else {
         		   pass3 += ch; cnt++;
         		   hidden3 += '*';
          		   cout << '*'; 
        		}
   			}
           	if(cnt < 8 || cnt > 12){
   				moveCursor(55, 15); cout << "Mat khau tu 8-12 ki tu.";
			} else n3=1;
		} else if(x >= 50 && x < 54 && y >= 14 && y < 16){
			if(n3 == 1){
        		moveCursor(22, 15); cout << pass3; n3=0;
			} else {
				moveCursor(22, 15); cout << hidden3; n3=1;
			}
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6) {
			if (pass1 == "" || pass2 == "" || pass3 == "") {
				moveCursor(0, 17); cout << "Nhap cac thong tin truoc khi xac nhan.";
			} else if(temp->data.get_pass() != pass1){
				moveCursor(55, 11); cout << "Mat khau cu khong dung.";
			} else if(pass2 != pass3){
				moveCursor(55, 15); cout << "Mat khau moi khong trung nhau.";
				
			} else {
				c = true; n=1;
			}
			if(n==1 && c){
				moveCursor(0, 17); cout << "                                      ";
        		moveCursor(0, 17); cout << "Doi mat khau thanh cong.";
        		temp->data.set_pass(pass2);
        		ofstream file("user.txt", ios::trunc);
        		acc_list.save(file);
        		file.close();
        		n--; c = false;
			}
			
		}
		moveCursor(0, 17);
	}
}

void client_function::update_profile(const string &id){
	menu_edit_client();
    List<client> client_list;
   	client_list.load("user.txt");
   	Node<client> *temp = client_list.get_head();
   	string new_name, new_id_card, new_dob, new_address, new_phone, new_email;
   	while(temp != NULL){
   		if(temp->data.get_id() == id){
   			new_name = temp->data.get_name();
   			new_id_card = temp->data.get_id_card();
   			new_dob = temp->data.get_dob(); 
   			new_address = temp->data.get_address();
   			new_phone = temp->data.get_phone();
   			new_email = temp->data.get_email();
   			moveCursor(23, 11); cout << temp->data.get_id();
   			moveCursor(23, 13); cout << new_name;
   			moveCursor(23, 15); cout << new_id_card;
   			moveCursor(23, 17); cout << new_dob;
   			moveCursor(23, 19); cout << new_address;
   			moveCursor(23, 21); cout << new_phone;
   			moveCursor(23, 23); cout << new_email;
   			break;
		}
		temp = temp->next;
	}
	moveCursor(0, 25);
    int x, y;
    int n1, n2, n3, n4, n5, n6;
    while(true){
    	get_x_y(x, y);
    	if(x >= 0 && x < 15 && y >= 4 && y < 6){
    		system("cls");
    		return;
		} else if(x >= 23 && x < 54 && y >= 10 && y < 12){
			moveCursor(0, 25); cout << "Khong the sua ma khach hang.";
		} else if(x >= 23 && x < 54 && y >= 12 && y < 14){
			moveCursor(55, 13); cout << "                     ";
			moveCursor(23, 13); cout << "                              ";
			n1 = 0; inputAtCursor(new_name, 23, 13); 
			if(!check_name(new_name)){
				moveCursor(55, 13); cout << "Ten khong hop le.";
			} else {
				n1 = 1; convert_to_upper(new_name);
			}
		} else if(x >= 23 && x < 54 && y >= 14 && y < 16){
			moveCursor(55, 15); cout << "                   ";
			moveCursor(23, 15); cout << "                              ";
			n2 = 0; inputAtCursor(new_id_card, 23, 15);
			if(!check_cccd(new_id_card)){
				moveCursor(55, 15); cout << "CCCD gom 12 so.";
			} else n2 = 1;
		} else if(x >= 23 && x < 54 && y >= 16 && y < 18){
			moveCursor(55, 17); cout << "                           ";
			moveCursor(23, 17); cout << "                              ";
			n3= 0; inputAtCursor(new_dob, 23, 17);
			if(!check_dob(new_dob)){
				moveCursor(55, 17); cout << "Ngay sinh khong hop le.";
			} else n3 =1;
		} else if(x >= 23 && x < 54 && y >= 18 && y < 20){
			moveCursor(23, 19); cout << "                              ";
			n4 = 0; inputAtCursor(new_address, 23, 19); 
			if(new_address.length() < 3){
				moveCursor(55, 19); cout << "Que quan khong hop le.";
			} else {
				n4 = 1; convert_to_upper(new_address);
			}
		} else if(x >= 23 && x < 54 && y >= 20 && y < 22){
			moveCursor(55, 21); cout << "                     ";
			moveCursor(23, 21); cout << "                              ";
			n5 = 0; inputAtCursor(new_phone, 23, 21);
			if(!check_phone(new_phone)){
				moveCursor(55, 21); cout << "SDT khong hop le.";
			} else n5 = 1;
		} else if(x >= 23 && x < 54 && y >= 22 && y < 24){
			moveCursor(55, 2); cout << "                       ";
			moveCursor(23, 23); cout << "                              ";
			n6 = 0; inputAtCursor(new_email, 23, 23); 
			if(new_email.length() > 10) n6 = 1;
			if(!check_email(new_email)){
				moveCursor(55, 2); cout << "Email khong hop le.";
			} else n6 = 1;
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			if(!n1 && !n2 && !n3 && !n4 && !n5 && !n6) {
				moveCursor(0, 25); cout << "Nhap cac thong tin truoc khi xac nhan.";
			} else {
				List<client> client_list;
				client_list.load("user.txt");
				Node<client> *temp = client_list.get_head();
				while(temp != NULL){
					if(temp->data.get_id() == id){
						temp->data.set_name(new_name);
						temp->data.set_id_card(new_id_card);
						temp->data.set_dob(new_dob);
						temp->data.set_address(new_address);
						temp->data.set_phone(new_phone);
						temp->data.set_email(new_email);
						n1 = n2 = n3 = n4 = n5 = n6 = 0;
						break;
					}
					temp = temp->next;
				}
				ofstream file("user.txt", ios::trunc);
				client_list.save(file);
				file.close();
				moveCursor(0, 25); cout << "                                      ";
				moveCursor(0, 25); cout << "Da cap nhat thong tin\n";
			}
		} 
		moveCursor(0, 25);
	}
}

void client_function::rental(const string &id){
	menu_rental();
   	string id_motor = "", status = "", id_contract = "";
   	int s_day, s_month, s_year, s_hour, s_minute;
   	int e_day, e_month, e_year, e_hour, e_minute;
   	int t_day, t_hour, t_minute;
   	long long total_amount = 0;
   	long price = 0;
   	List<motorbike> motor_list;
   	motor_list.load("motorbike.txt");
   	datetime s_time, e_time, n_time;
   	time_t start, end;
   	int x, y, n=1, n1=0, n2=0, n3=0;
   	while(true){
   		get_x_y(x, y);
   		if(x >= 0 && x < 15 && y >= 4 && y < 6){
   			menu_client();
   			return;
		} else if(x >= 20 && x < 54 && y >= 10 && y < 12){
			n1=0;
			moveCursor(0, 23); cout << "                                        ";
			moveCursor(55, 11); cout << "                              ";
			moveCursor(20, 11); cout << "                              ";
   			inputAtCursor(id_motor, 20, 11);
   			convert_to_upper(id_motor);
   			if(!motor_list.find_id("motorbike.txt", id_motor)){
   				moveCursor(55, 11); cout << "Khong tim thay ma xe may tren.";
			} else {
				Node<motorbike> *mt = motor_list.get_head();
   				while(mt != NULL){
   					if(mt->data.get_id() == id_motor)
   						break;
   					mt = mt->next;
				}
				price = mt->data.get_price(); n1=1;
			}
			if(n3 && n1){
				total_amount = t_day*24*price + t_hour*price + (float)t_minute/60*price;
   				moveCursor(20, 19); cout << total_amount << " vnd";
			}
		} else if(x >= 20 && x < 54 && y >= 12 && y < 14){
			n2=0;
			moveCursor(0, 23); cout << "                                        ";
			moveCursor(20, 13); cout << "    /  /        |        :       ";
			moveCursor(55, 13); cout << "                                 ";
			moveCursor(22, 13); cin >> s_day;
   			moveCursor(25, 13); cin >> s_month;
   			moveCursor(28, 13); cin >> s_year;
   			moveCursor(43, 13); cin >> s_hour;
   			moveCursor(46, 13); cin >> s_minute;
   			s_time.set_time(s_day, s_month, s_year, s_hour, s_minute);
   			n_time.time_now();
   			if(!s_time.check_time()){
   				moveCursor(55, 13); cout << "Thoi gian khong hop le.";
			} else if(s_time.convert_time() - n_time.convert_time() > 30*24*60*60){
				moveCursor(55, 13); cout << "Dat truoc khong qua 1 thang.";
			} else n2=1;
		} else if(x >= 20 && x < 54 && y >= 14 && y < 16){
			n3=0;
			moveCursor(0, 23); cout << "                                        ";
			moveCursor(55, 15); cout << "                                     ";
			moveCursor(20, 15); cout << "    /  /        |        :       ";
			moveCursor(22, 15); cin >> e_day;
   			moveCursor(25, 15); cin >> e_month;
   			moveCursor(28, 15); cin >> e_year;
   			moveCursor(43, 15); cin >> e_hour;
   			moveCursor(46, 15); cin >> e_minute;
   			e_time.set_time(e_day, e_month, e_year, e_hour, e_minute);
   			start = s_time.convert_time();
   			end = e_time.convert_time();
   			if(!e_time.check_time() || end < start){
   				moveCursor(55, 15); cout << "Thoi gian khong hop le.";
			} else if(end - start > 14*24*60*60){
				moveCursor(55, 15); cout << "Thoi gian thue khong qua 2 tuan.";
			} else if(n2){
				time_t total_time = end - start;
    			t_day = total_time / 86400;
    			t_hour = (total_time % 86400) / 3600;
   				t_minute = (total_time % 3600) / 60; 
   				moveCursor(20, 17);
   				cout << t_day << " ngay " << t_hour << " gio " << t_minute << " phut"; 
   				n3=1;
				if(n1 && n3){
					total_amount = t_day*24*price + t_hour*price + (float)t_minute/60*price;
   					moveCursor(20, 19); cout << total_amount << " vnd";
				}
			}
		} else if(x >= 0 && x < 19 && y >= 20 && y < 22){
			bool c = true; status = "CHO XAC NHAN"; 
			List<contract> contract_list;
			contract_list.load("contract.txt");
			Node<contract> *ct = contract_list.get_head();
			while(ct != NULL){
				if(ct->data.get_id_motor() == id_motor){
					time_t tg = ct->data.get_return_date().convert_time();
					if(tg > start){
						c = false; 
						break;
					}
				}
				ct = ct->next;
			}
			if(c && n && n1 && n2 && n3){
				do{
					id_contract = create_code("HD");
					if(!contract_list.find_id("contract.txt", id_contract))
						break;
				} while(true);
   				contract ct(id_contract, id, id_motor, s_time, e_time, total_amount, status);
    			contract_list.add(ct);	
    			ofstream file("contract.txt", ios::trunc);
    			contract_list.save(file);
    			file.close();
    			moveCursor(0, 23); cout << "Da dat thue xe, vui long cho phan hoi.";
				n--;
    		}
    		if(!n1 || !n2 || !n3) {
    			moveCursor(0, 23); cout << "Nhap cac thong tin truoc khi dat xe.";
			} else if(!c){
				moveCursor(0, 23); cout << "Khong the dat xe tu thoi gian tren."; 
			}
		} else if(x >= 20 && x < 54 && y >= 25 && y < 27){
			menu_rental();
			search_motor();
		}
		moveCursor(0, 23);
	}
}

void client_function::cancel_contract(const string &id){
	menu_cancel_contract();
	List<contract> contract_list;
	contract_list.load("contract.txt");
	Node<contract> *temp = contract_list.get_head();
	bool c = false, c2 = false;
	while(temp != NULL){
		if(temp->data.get_id_client() == id){
			if(temp->data.get_status() == "CHO XAC NHAN" || temp->data.get_status() == "DA DAT"){
				temp->data.show_list();
				c = true;
			}
		}
		temp = temp->next;
	}
	if(!c){
		moveCursor(0, 12); cout << setfill(' ') << setw(110);
		moveCursor(0, 12); cout << "Khong co hop dong nao dang cho.";
	}
	string id_ct;
	cout << "\n";
	int x, y, n=1;
	while(true){
		get_x_y(x, y);
		if(x >= 0 && x < 15 && y >= 4 && y < 6){
			menu_client();
			return;	
		} else if(x >= 18 && x < 34 && y >= 4 && y < 6){ 
			if (n==1 && c){
				temp = contract_list.get_head();
				while(temp != NULL){
					if(temp->data.get_id_client() == id){
						if(temp->data.get_status() == "CHO XAC NHAN" || temp->data.get_status() == "DA DAT"){
							contract_list.delete_node("contract.txt", temp->data.get_id());
						}
					}
					temp = temp->next;
				}
				moveCursor(55, 9); cout << "Da huy cac hop dong tren.\n";
				n--; c = false;
			}
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			if(c2){
				bool c1 = false;
				List<contract> ct_list;
				ct_list.load("contract.txt");
				Node<contract> *ct = ct_list.get_head();
				while(ct != NULL){
					if(ct->data.get_id() == id_ct){
						if(ct->data.get_status() == "CHO XAC NHAN" || temp->data.get_status() == "DA DAT"){
							ct_list.delete_node("contract.txt", ct->data.get_id());
							cout << "Huy thanh cong hop dong: " << id_ct;
						} else {
							moveCursor(55, 9); cout << "Khong the huy hop dong nay.";
						}
						c1 = true; break;
					}
					ct = ct->next;
				}
				if(!c1){
					moveCursor(55, 9); cout << "Khong tim thay ma hop dong: " << id_ct;
				}
				c2 = false;
			}
		} else if(x >= 16 && x < 54 && y >= 8 && y < 10){
			moveCursor(55, 9); cout << "                                          ";
			moveCursor(17, 9); cout << "                                    ";
			inputAtCursor(id_ct, 17, 9); convert_to_upper(id_ct);
			c2 = true;
		}
		moveCursor(0, 11);
	}
}

void client_function::rental_history(const string &id){
	menu_rental_history();
   	bool c = false;
   	List<contract> contract_list;
   	contract_list.load("contract.txt");
   	Node<contract> *temp = contract_list.get_head();
   	while(temp != NULL){
   		if(temp->data.get_id_client() == id){
   			if(temp->data.get_status() == "HOAN THANH" || temp->data.get_status() == "DANG THUE"){
   				temp->data.show_list();
   				c = true;
			}		
		}
   		temp = temp->next;		
	}
	if(!c) {
		moveCursor(0, 8); cout << setfill(' ') << setw(110);
		moveCursor(0, 8); cout << "Quy khach chua co lich su thue xe.";
	}
}

#endif //CLIENTFUNCTION_H
