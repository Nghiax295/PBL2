#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"
#include "Function.h"
#include "Contract.h"
#include "Motorbike.h"
#include "ClientFunction.h"

class admin : public account{
	public:
		void client_manage();
		void contract_manage();
		void motor_manage();
		void statistic_month();
		void statistic_quarter();
		void statistic_KTG();
		void statistic_motor();
		void confirm_contract();
		void add_contract();
		void admin_cancel_contract();
};

void admin::client_manage(){
	int x, y;
	while(true){
		menu_admin1();
		get_x_y(x, y);
		if(x >= 13 && x <= 42 && y >= 5 && y <= 7){
			menu_client_list();
			List<client> client_list;
			client_list.load("user.txt");
			client_list.show_list();
			moveCursor(0, 9); cout << "            ";
			moveCursor(0, 0);
			go_back();
		} else if(x >= 13 && x <= 42 && y >= 8 && y <= 10){
			menu_search_client();
    		int x, y;
    		while(true){
    			get_x_y(x, y);
    			if(x >= 0 && x < 15 && y >= 4 && y < 6) {
    				system("cls");
    				break;
				} else if(x >= 15 && x < 54 && y >= 8 && y < 10){
					menu_search_client();
    				moveCursor(17, 9); cout << "                                    ";
    				moveCursor(17, 9);
    				string keyword;
    				getline(cin, keyword);
    				convert_to_upper(keyword);
    				if(keyword != ""){
    					client_function KH;
    					KH.search(keyword);
					}
				}	
			}
		} else if(x >= 13 && x < 42 && y >= 11 && y < 13){
			menu_client_renting();
			List<contract> ct_list;
			ct_list.load("contract.txt");
			Node<contract> *ct = ct_list.get_head();
    		while(ct != NULL){
    			if(ct->data.get_status() == "DANG THUE"){
    				List<client> cl_list;
    				cl_list.load("user.txt");
    				Node<client> *cl = cl_list.get_head();
    				while(cl != NULL){
    					if(cl->data.get_id() == ct->data.get_id_client()){
    						cl->data.show_list();
    						break;
						}
						cl = cl->next;
					}
				}
				ct = ct->next;
			}
    		go_back();
		} else if(x >= 13 && x < 42 && y >= 14 && y < 16){
			menu_admin();
			break;
		}
	}
}

void admin::contract_manage(){
	menu_admin3();
	int x, y;
	while(true){
		get_x_y(x, y);
		if(x >= 11 && x < 42 && y >= 5 && y < 7){
			confirm_contract();
		} else if(x >= 11 && x < 42 && y >= 8 && y < 10){
			menu_contract_complete();
    		bool c = false;
    		List<contract> contract_list;
			contract_list.load("contract.txt");
			Node<contract> *temp = contract_list.get_head();
			while(temp != NULL){
				if(temp->data.get_status() == "HOAN THANH"){
					temp->data.show_list();
					c = true;
				}	
				temp = temp->next;
			}
			if(!c){
				moveCursor(0, 8); cout << setfill(' ') << setw(110);
				moveCursor(0, 8); cout << "Khong co hop dong nao da hoan thanh.";
			}
			go_back();
			menu_admin3();
		} else if(x >= 11 && x < 42 && y >= 11 && y < 13){
			menu_contract_not_complate();
    		List<contract> contract_list;
			contract_list.load("contract.txt");
			Node<contract> *temp = contract_list.get_head();
			bool c = false;
			while(temp != NULL){
				if(temp->data.get_status() == "DANG THUE" || temp->data.get_status() == "DA DAT"){
					temp->data.show_list();
					c = true;
				}
				temp = temp->next;
			}
			if(!c){
				moveCursor(0, 12); cout << setfill(' ') << setw(110);
				moveCursor(0, 12); cout << "Khong co hop dong nao chua hoan thanh.";
			}
			go_back();
			menu_admin3();	
		} else if(x >= 11 && x < 42 && y >= 14 && y < 16){
			add_contract();
		} else if(x >= 11 && x < 42 && y >= 17 && y < 19){
			admin_cancel_contract();
		} else if(x >= 11 && x < 42 && y >= 20 && y < 22){
			menu_admin();
			break;
		}
	}
}

void admin::motor_manage(){
	int x, y;
	motorbike MT;
	while(true){
		//update_data();
		menu_admin2();
		get_x_y(x, y);
		if(x >= 13 && x < 42 && y >= 5 && y < 7){
			menu_motor_list();
			List<motorbike> motor_list;
			motor_list.load("motorbike.txt");
			motor_list.show_list();
			go_back();
		} else if(x >= 13 && x < 42 && y >= 8 && y < 10){
			menu_search_motor();
    		int x, y;
    		while(true){
    			get_x_y(x, y);
    			if(x >= 0 && x < 15 && y >= 4 && y < 6) {
    				system("cls");
    				break;
				} else if(x >= 15 && x < 54 && y >= 8 && y < 10){
					menu_search_motor();
    				moveCursor(17, 9); cout << "                                    ";
    				moveCursor(17, 9);
    				string keyword;
    				getline(cin, keyword);
    				convert_to_upper(keyword);
    				if(!MT.search(keyword)){
    					moveCursor(0, 12); cout << setfill(' ') << setw(100);
    					moveCursor(0, 12); cout << "Khong tim thay voi tu khoa: ";
						moveCursor(28, 12); cout << keyword << endl;
					}
				}	
			}
		} else if(x >= 13 && x < 42 && y >= 11 && y < 13){
			MT.edit_motor();
		} else if(x >= 13 && x < 42 && y >= 14 && y < 16){
			menu_delete_motor();
			List<motorbike> motor_list;
			motor_list.load("motorbike.txt");
			motor_list.show_list();
			int x, y, n=1;
    		string id_motor;
			bool c = false;
			while(true){
    			get_x_y(x, y);
    			if(x >= 0 && x < 15 && y >= 4 && y < 6){
    				system("cls");
    				break;
				} else if(x >= 16 && x < 54 && y >= 8 && y < 10){
					moveCursor(17, 9); cout << "                                    ";
					inputAtCursor(id_motor, 17, 9); convert_to_upper(id_motor); 
					c = true; moveCursor(0, 11);
					if(!motor_list.find_id("motorbike.txt", id_motor)){
						moveCursor(17, 9); cout << "Khong co ma xe tren";
						moveCursor(0, 11); c = false;
					}
				} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
					if(n==1 && c){
						menu_delete_motor();
						motor_list.delete_node("motorbike.txt", id_motor);
						moveCursor(17, 9); cout << "Da xoa thanh cong";
						moveCursor(0, 14); n--;
						List<motorbike> mt_list;
						mt_list.load("motorbike.txt");
						mt_list.show_list();
					}
					if(!c){
						moveCursor(17, 9); cout << "Nhap ma xe can xoa";
						moveCursor(0, 11);
					}
				}
			}
		} else if(x >= 13 && x < 42 && y >= 17 && y < 19){
			menu_add_motor();
    		int x, y, n=1, d=0;
    		string id_motor, brand, type, plate_number, color, status = "TRONG";
    		long price;
    		bool c = false;
    		while(true){
    			get_x_y(x, y);
    			if(x >= 0 && x < 15 && y >= 4 && y < 6){
    				system("cls");
    				break;
				} else if(x >= 17 && x < 54 && y >= 8 && y < 10){
					List<motorbike> mt_list;
					mt_list.load("motorbike.txt");
					do{
						id_motor = create_code("XM");
						if(!mt_list.find_id("motorbike.txt", id_motor))
							break;
					} while(true);
					moveCursor(19, 9); cout << id_motor;
				} else if(x >= 17 && x < 54 && y >= 10 && y < 12){
					inputAtCursor(brand, 19, 11); convert_to_upper(brand);
				} else if(x >= 17 && x < 54 && y >= 12 && y < 14) {
					inputAtCursor(type, 19, 13); convert_to_upper(type);
				} else if(x >= 17 && x < 54 && y >= 14 && y < 16){
					inputAtCursor(plate_number, 19, 15); convert_to_upper(plate_number);
				} else if(x >= 17 && x < 54 && y >= 16 && y < 18){
					inputAtCursor(color, 19, 17); convert_to_upper(color);
				} else if(x >= 17 && x < 54 && y >= 18 && y < 20){
					moveCursor(19, 19); cin >> price;
				} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
					if(brand == "" || type == "" || plate_number == "" || color == ""){
						moveCursor(0, 21); cout << "Ban chua nhap thong tin xe.";
					} else c = true;
					if(n==1 && c){
						motorbike new_motor(id_motor, brand, type, plate_number, color, price, status);
    					List<motorbike> motor_list;
						motor_list.load("motorbike.txt");
    					motor_list.add(new_motor);	
    					ofstream file("motorbike.txt", ios::trunc);
    					motor_list.save(file);
    					file.close(); n--; c = false;
    					moveCursor(0, 21); cout << "Da them xe may thanh cong. ";
					}
				}
			}
		} else if(x >= 13 && x < 42 && y >= 20 && y < 22){
			system("cls");
			menu_admin();
			return;
		}
		moveCursor(0, 21);
	}
}

void admin::statistic_month() {
	menu_statistic1();
    int x, y, year, m;
    datetime start, end;
    while (true) {
        get_x_y(x, y);
        if (x >= 0 && x < 15 && y >= 4 && y < 6) {
            menu_statistic();
            return;
        } else if (x >= 21 && x < 54 && y >= 7 && y < 9) {
        	menu_statistic1();
            moveCursor(55, 8); cout << "                      ";
            moveCursor(22, 8); cin >> year;
            start.set_time(1, 1, year, 0, 0);
            if (!start.check_time()) {
                moveCursor(55, 8); cout << "Nam khong hop le.";
                continue;
            }
            end.set_time(31, 12, year, 23, 59); 
            List<contract> ct_list;
            ct_list.load("contract.txt");
            
            int completed[12] = {0}, not_completed[12] = {0}, reserved[12] = {0};      
            long long revenue[12] = {0};

            Node<contract> *ct = ct_list.get_head();
            while (ct != NULL) {
                datetime rental_date = ct->data.get_rental_date();
                time_t rental_time = rental_date.convert_time();
                if (rental_time >= start.convert_time() && rental_time <= end.convert_time()) {
                    int month = rental_date.get_month() - 1;
                    if (ct->data.get_status() == "HOAN THANH") {
                        completed[month]++;
                        revenue[month] += ct->data.get_total_amount();
                    } else if (ct->data.get_status() == "DANG THUE") {
                        not_completed[month]++;
                    } else if (ct->data.get_status() == "DA DAT") {
                        reserved[month]++;
                    }
                }
                ct = ct->next; 
            }
            m=14;
            cout << "\n\n";
            cout << "+-------+------------+-----------------+--------+------------------+\n";
            cout << "| Thang | Hoan thanh | Chua hoan thanh | Da Dat | Doanh thu(HD HT) |\n";
            cout << "+-------+------------+-----------------+--------+------------------+\n";
            for (int i = 0; i < 12; i++) {
            	cout << "|       |            |                 |        |                  |\n";
            	moveCursor(4, m); cout << (i+1);
            	moveCursor(15, m); if(completed[i] != 0) cout << completed[i];
            	moveCursor(31, m); if(not_completed[i] != 0) cout << not_completed[i];
            	moveCursor(44, m); if(reserved[i] != 0) cout << reserved[i];
            	moveCursor(50, m); if(revenue[i] != 0) cout << revenue[i] << "vnd";
            	cout << "\n+-------+------------+-----------------+--------+------------------+\n";
            	m += 2;
        	}
        	moveCursor(0, 0);
    	}
	}
}

void admin::statistic_quarter() {
    menu_statistic2();
    int x, y, year, m;
    datetime start, end;
    while (true) {
        get_x_y(x, y);
        if (x >= 0 && x < 15 && y >= 4 && y < 6) {
            menu_statistic();
            return;
        } else if (x >= 21 && x < 54 && y >= 7 && y < 9) {
        	menu_statistic2();
            moveCursor(55, 8); cout << "                      ";
            moveCursor(22, 8); cin >> year;

            start.set_time(1, 1, year, 0, 0);
            if (!start.check_time()) {
                moveCursor(55, 8); cout << "Nam khong hop le.";
                continue;
            }
            end.set_time(31, 12, year, 23, 59);
            List<contract> ct_list;
            ct_list.load("contract.txt");

            int completed[4] = {0}, not_completed[4] = {0}, reserved[4] = {0};      
            long long revenue[4] = {0};

            Node<contract> *ct = ct_list.get_head();
            while (ct != NULL) {
                datetime rental_date = ct->data.get_rental_date();
                time_t rental_time = rental_date.convert_time();

                if (rental_time >= start.convert_time() && rental_time <= end.convert_time()) {
                    int month = rental_date.get_month();
                    int quarter = (month - 1) / 3;
                    if (ct->data.get_status() == "HOAN THANH") {
                        completed[quarter]++;
                        revenue[quarter] += ct->data.get_total_amount();
                    } else if (ct->data.get_status() == "DANG THUE") {
                        not_completed[quarter]++;
                    } else if (ct->data.get_status() == "DA DAT") {
                        reserved[quarter]++;
                    }
                }
                ct = ct->next;
            }
			m=14; 
            cout << "\n\n";
            cout << "+--------+------------+-----------------+--------+------------------+\n";
            cout << "|  Quy   | Hoan thanh | Chua hoan thanh | Da Dat | Doanh thu(HD HT) |\n";
            cout << "+--------+------------+-----------------+--------+------------------+\n";
            for (int i = 0; i < 4; i++) {
                cout << "|        |            |                 |        |                  |\n";
                moveCursor(4, m); cout << (i + 1);
                moveCursor(15, m); if (completed[i] != 0) cout << completed[i];
                moveCursor(31, m); if (not_completed[i] != 0) cout << not_completed[i];
                moveCursor(44, m); if (reserved[i] != 0) cout << reserved[i];
                moveCursor(50, m); if (revenue[i] != 0) cout << revenue[i] << "vnd";
                cout << "\n+--------+------------+-----------------+--------+------------------+\n";
                m += 2;
            }
            moveCursor(0, 0);
        }
    }
}

void admin::statistic_KTG(){
	menu_statistic3();
	int day1, month1, year1, day2, month2, year2, x, y;
	time_t time1, time2, time;
	datetime t1, t2;
	while(true){
		get_x_y(x, y);
		if(x >= 0 && x < 15 && y >= 4 && y < 6){
   			menu_statistic();
   			return;
		} else if(x >= 12 && x < 54 && y >= 7 && y < 9){
			label1:{
				moveCursor(13, 8); cin >> day1;
				moveCursor(16, 8); cin >> month1;
				moveCursor(19, 8); cin >> year1;
				t1.set_time(day1, month1, year1, 0, 0);
				if(!t1.check_time()){
					moveCursor(0, 10); cout << "Thoi gian khong hop le.";
					moveCursor(13, 8); cout << "  /  /      ";
					goto label1;
				} else {
					moveCursor(0, 10); cout << "                       ";
				}
			}
			
			time1 = t1.convert_time();
			label2:{
				moveCursor(40, 8); cin >> day2;
				moveCursor(43, 8); cin >> month2;
				moveCursor(46, 8); cin >> year2;
				t2.set_time(day2, month2, year2, 23, 59);
				time2 = t2.convert_time();
				if(!t2.check_time() || time2 < time1 ){
					moveCursor(0, 10); cout << "Thoi gian khong hop le.";
					moveCursor(40, 8); cout << "  /  /       ";
					goto label2;
				} else {
					moveCursor(0, 10); cout << "                       ";
				}
			}
			moveCursor(0, 10);
			List<contract> con_list;
    		con_list.load("contract.txt");
   			Node<contract> *ct = con_list.get_head();
    		long long total = 0;
   			int c = 0, c1 = 0, c2 = 0, c3 = 0;
			while(ct != NULL){
				time = ct->data.get_rental_date().convert_time();
				if(time >= time1 && time <= time2){
					c++;
					if(ct->data.get_status() == "HOAN THANH") {
						total += ct->data.get_total_amount();
						c1++;
					}
					else if(ct->data.get_status() == "DANG THUE") c2++;
					else if(ct->data.get_status() == "DA DAT") c3++;
				}
				ct = ct->next;
			}
			cout << "Trong khoang thoi gian tren:\n";
			cout << "\n\tCo tong cong " << c << " hop dong thue xe\n";
			cout << "\n\tCo " << c1 << " hop dong da hoan thanh\n";
			cout << "\n\tCo " << c2 << " hop dong dang trong qua trinh thue\n";
			cout << "\n\tCo " << c3 << " hop dong da dat truoc\n";
			cout << "\n\tDoanh thu tu cac hop dong da hoa thanh la: " << total << "vnd\n";
		}
	}
}

void admin::statistic_motor(){
	menu_statistic4();
	int arr[10];
	List<motorbike> motor_list;
	motor_list.load("motorbike.txt");
	Node<motorbike> *mt = motor_list.get_head();		
	int m = 0, m1 = 0;
	while(mt != NULL){
		m++;
		if(mt->data.get_status() == "TRONG") m1++;
		mt = mt->next;
	}
	cout << "\nThong ke ve xe may:\n";
	cout << "\n\tHien co " << m << " xe may trong kho\n";
	cout << "\n\tCo " << m - m1 << " xe may dang duoc thue\n";
	cout << "\n\tCo " << m1 << " xe may chua duoc thue\n";
	go_back();
}

void admin::confirm_contract(){
	menu_contract_confirm();
    List<contract> contract_list;
	contract_list.load("contract.txt");
	Node<contract> *temp = contract_list.get_head();
	bool ch = false;
	while(temp != NULL){
		if(temp->data.get_status() == "CHO XAC NHAN"){
			temp->data.show_list();
			ch = true;
		}
		temp = temp->next;
	}
	if(!ch){
		moveCursor(0, 12); cout << setfill(' ') << setw(110);
		moveCursor(0, 12); cout << "Khong co hop dong nao can xac nhan.";
	}
	cout << "\n";
	int x, y, n = 1; bool c2 = false;
	string id_ct;
	while(true){
		get_x_y(x, y);
		if(x >= 0 && x < 15 && y >= 4 && y < 6){
			menu_admin3();
			break;
		} else if(x >= 18 && x < 34 && y >= 4 && y < 6){
			if (n==1 && ch){
				temp = contract_list.get_head();
				while(temp != NULL){
					if(temp->data.get_status() == "CHO XAC NHAN")
						temp->data.set_status("DA DAT");
					temp = temp->next;
				}
				ofstream file_c("contract.txt", ios::trunc);
				contract_list.save(file_c);
				file_c.close();
				cout << "Da xac nhan cac hop dong tren.\n";
				n--;
			}
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			if(c2){
				bool c1 = false;
				temp = contract_list.get_head();
				while(temp != NULL){
					if(temp->data.get_id() == id_ct){
						if(temp->data.get_status() == "CHO XAC NHAN"){
							temp->data.set_status("DA DAT");
							ofstream file_c("contract.txt", ios::trunc);
							contract_list.save(file_c);
							file_c.close();
							moveCursor(55, 9); cout << "Xac nhan thanh cong hop dong: " << id_ct;
						}
						c1 = true; 
						break;
					}
					temp = temp->next;
				}
				if(!c1){
					moveCursor(55, 9); cout << "Khong tim thay ma hop dong: " << id_ct;
				}
				c2 = false;
			}
		} else if(x >= 16 && x < 54 && y >= 8 && y < 10) {
			moveCursor(55, 9); cout << "                                              ";
			moveCursor(17, 9); cout << "                                    ";
			inputAtCursor(id_ct, 17, 9); convert_to_upper(id_ct);
			c2 = true;
		}
	}
}

void admin::add_contract(){
	menu_add_contract();
	string id_contract, id_client, id_motor, status;
	int s_day, s_month, s_year, s_hour, s_minute;
   	int e_day, e_month, e_year, e_hour, e_minute;
   	int t_day, t_hour, t_minute;
   	long long total_amount = 0;
   	datetime s_time, e_time;
   	long price = 0;
   	time_t start, end;
   	List<motorbike> motor_list;
   	motor_list.load("motorbike.txt");
   	int x, y, n=1, n1=0, n2=0, n3=0, n4=0, n5=0;
   	while(true){
   		get_x_y(x, y);
   		if(x >= 0 && x < 15 && y >= 4 && y < 6){
   			menu_admin3();
   			return;
		} else if(x >= 20 && x < 54 && y >= 10 && y < 12){
			List<contract> contract_list;
			contract_list.load("contract.txt");
			do{
				n1=0;
				id_contract = create_code("HD");
				if(!contract_list.find_id("contract.txt", id_contract)){
					n1=1; break;
				}
					
			} while(true);
			moveCursor(20, 11); cout << id_contract;
		} else if(x >= 20 && x < 54 && y >= 12 && y < 14){
			n2 = 0;
			inputAtCursor(id_client, 20, 13);
			convert_to_upper(id_client);
			if(!check_cccd(id_client)){
				
			} else n2=1;
		} else if(x >= 20 && x < 54 && y >= 14 && y < 16){
			n3=0;
			moveCursor(55, 15); cout << "                              ";
			moveCursor(20, 15); cout << "                              ";
   			inputAtCursor(id_motor, 20, 15);
   			convert_to_upper(id_motor);
   			if(!motor_list.find_id("motorbike.txt", id_motor)){
   				moveCursor(55, 15); cout << "Khong tim thay ma xe may tren.";
			} else n3=1;
		} else if(x >= 20 && x < 54 && y >= 16 && y < 18){
			n4=0;
			moveCursor(20, 17); cout << "    /  /        |        :       ";
			moveCursor(55, 17); cout << "                       ";
			moveCursor(22, 17); cin >> s_day;
   			moveCursor(25, 17); cin >> s_month;
   			moveCursor(28, 17); cin >> s_year;
   			moveCursor(43, 17); cin >> s_hour;
   			moveCursor(46, 17); cin >> s_minute;
   			s_time.set_time(s_day, s_month, s_year, s_hour, s_minute);
   			if(!s_time.check_time()){
   				moveCursor(55, 17); cout << "Thoi gian khong hop le.";
			} else n4=1;
		} else if(x >= 20 && x < 54 && y >= 18 && y < 20){
			n5=0;
			moveCursor(55, 19); cout << "                       ";
			moveCursor(20, 19); cout << "    /  /        |        :       ";
			moveCursor(22, 19); cin >> e_day;
   			moveCursor(25, 19); cin >> e_month;
   			moveCursor(28, 19); cin >> e_year;
   			moveCursor(43, 19); cin >> e_hour;
   			moveCursor(46, 19); cin >> e_minute;
   			e_time.set_time(e_day, e_month, e_year, e_hour, e_minute);
   			start = s_time.convert_time();
   			end = e_time.convert_time();
   			if(!e_time.check_time() || end < start){
   				moveCursor(55, 19); cout << "Thoi gian khong hop le.";
			} else if(n4){
				time_t total_time = end - start;
    			t_day = total_time / 86400;
    			t_hour = (total_time % 86400) / 3600;
   				t_minute = (total_time % 3600) / 60; 
   				moveCursor(20, 21);
   				cout << t_day << " ngay " << t_hour << " gio " << t_minute << " phut"; 
				Node<motorbike> *mt = motor_list.get_head();
   				while(mt != NULL){
   					if(mt->data.get_id() == id_motor)
   						break;
   					mt = mt->next;
				}
				price = mt->data.get_price();
				total_amount = t_day*24*price + t_hour*price + (float)t_minute/60*price;
   				moveCursor(20, 23); cout << total_amount << "vnd";
   				status = "DA DAT";
   				n5=1;
			}
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			bool c = true;
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
			if(c && n && n1 && n2 && n3 && n4 && n5){
   				datetime rental_dt(s_day, s_month, s_year, s_hour, s_minute);
   				datetime return_dt(e_day, e_month, e_year, e_hour, e_minute);
   				contract ct(id_contract, id_client, id_motor, rental_dt, return_dt, total_amount, status);
   				List<contract> contract_list;
   				contract_list.load("contract.txt");
    			contract_list.add(ct);	
    			ofstream file("contract.txt", ios::trunc);
    			contract_list.save(file);
    			file.close();
    			moveCursor(0, 25); cout << "Them hop dong thanh cong.";
				n--;
    		}
    		if(!n1 && !n2 && !n3 && !n4 && !n5) {
    			moveCursor(0, 25); cout << "Nhan cac thong tin truoc khi xac nhan.";
			} else if(!c){
				moveCursor(0, 25); cout << "Khong the dat xe tu thoi gian tren.";
			}
		}
		moveCursor(0, 25);
	}
}

void admin::admin_cancel_contract(){
	menu_cancel_contract();
	List<contract> contract_list;
	contract_list.load("contract.txt");
	Node<contract> *temp = contract_list.get_head();
	bool c = false, c2 = false;
	while(temp != NULL){
		if(temp->data.get_status() == "CHO XAC NHAN" || temp->data.get_status() == "DA DAT"){
			temp->data.show_list();
			c = true;
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
			menu_admin3();
			return;	
		} else if(x >= 18 && x < 34 && y >= 4 && y < 6){ 
			if (n==1 && c){
				temp = contract_list.get_head();
				while(temp != NULL){
					if(temp->data.get_status() == "CHO XAC NHAN" || temp->data.get_status() == "DA DAT")
						contract_list.delete_node("contract.txt", temp->data.get_id());
					temp = temp->next;
				}
				cout << "Da huy cac hop dong tren.\n";
				n--; c = false;
			}
		} else if(x >= 38 && x < 54 && y >= 4 && y < 6){
			if(c2){
				bool c1 = false;
				temp = contract_list.get_head();
				while(temp != NULL){
					if(temp->data.get_id() == id_ct){
						if(temp->data.get_status() == "CHO XAC NHAN" || temp->data.get_status() == "DA DAT"){
							contract_list.delete_node("contract.txt", temp->data.get_id());
							moveCursor(55, 9); cout << "Huy thanh cong hop dong: " << id_ct;
						} else {
							moveCursor(55, 9); cout << "Khong the huy hop dong nay";
						}
						c1 = true; break;
					}
					temp = temp->next;
				}
				if(!c1){
					moveCursor(55, 9); cout << "Khong tim thay ma hop dong: " << id_ct;
				}
				c2 = false;
			}
		} else if(x >= 16 && x < 54 && y >= 8 && y < 10){
			moveCursor(55, 9); cout << "                                             ";
			moveCursor(17, 9); cout << "                                    ";
			inputAtCursor(id_ct, 17, 9); convert_to_upper(id_ct);
			c2 = true;
		}
		moveCursor(0, 11);
	}
}

#endif //ADMIN_H
