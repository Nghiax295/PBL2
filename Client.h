#ifndef CLIENT_H
#define CLIENT_H

#include <sstream>
#include <limits>
#include <iomanip>
#include <conio.h>
#include "Account.h"
#include "Motorbike.h"
#include "Contract.h"
#include "Function.h"

using namespace std;

//Lop khach hang
class client : public account{
    private:
		string name;
		string id_card;
		string date_of_birth;
		string address;
		string phone_number;
		string email;
    public:
    	client();
    	client(string, string, string, string, string, string, string, string, string);
    	
        void load_from_file(ifstream &);
        void save_to_file(ofstream &);
        
        string get_id() const;
        string get_name() const;
        string get_id_card() const;
        string get_dob() const;
        string get_address() const;
        string get_phone() const;
        string get_email() const;
        
        void set_name(const string &);
        void set_id_card(const string &);
        void set_dob(const string &);
        void set_address(const string &);
        void set_phone(const string &);
        void set_email(const string &);
        
        void show_list();
        void search(const string &);
}; 

client::client(){}

client::client(string id_client, string user, string pass, string name, string id_card, string dob,
	string address, string phone, string email) : 
	account(id_client, user, pass), name(name), id_card(id_card), date_of_birth(dob),
	address(address), phone_number(phone), email(email){}


void client::load_from_file(ifstream &file) {
	account::load_from_file(file);
	getline(file, name, '|');
	getline(file, id_card, '|');
	getline(file, date_of_birth, '|');
	getline(file, address, '|');
	getline(file, phone_number, '|');
	getline(file, email);
}

void client::save_to_file(ofstream &file) {
	account::save_to_file(file);
	file << name << "|"
		 << id_card << "|"
	     << date_of_birth << "|"
	     << address << "|"
	     << phone_number << "|"
	     << email << "\n";
}


string client::get_id() const{
	return account::get_id();
}

string client::get_name() const{
	return name;
}

string client::get_id_card() const{
	return id_card;
}

string client::get_dob() const{
	return date_of_birth;
}

string client::get_address() const{
	return address;
}

string client::get_phone() const{
	return phone_number;
}

string client::get_email() const{
	return email;
}


void client::set_name(const string &new_name){
	name = new_name;
}

void client::set_id_card(const string &new_id){
	id_card = new_id;
}

void client::set_dob(const string &new_dob){
	date_of_birth = new_dob;
}

void client::set_address(const string &new_address){
	address = new_address;
}

void client::set_phone(const string &new_phone){
	phone_number = new_phone;
}

void client::set_email(const string &new_email){
	email = new_email;
}


void client::show_list(){
	cout << left << setw(15) << get_id()
		 << left << setw(20) << name
		 << left << setw(15) << id_card
		 << left << setw(15) << date_of_birth
		 << left << setw(15) << address
		 << left << setw(15) << phone_number
		 << left << setw(20) << email << endl;
}

void client::search(const string &keyword){
	List<client> client_list;
    client_list.load("user.txt");
    Node<client>* temp = client_list.get_head();
    bool found = false;
    cout << "\n";
    cout << left << setw(16) << "\nMa khach hang" 
		 << left << setw(20) << "Ho va ten"
		 << left << setw(15) << "So CCCD"
		 << left << setw(15) << "Ngay sinh"
		 << left << setw(15) << "Que quan"
		 << left << setw(15) << "SDT"
		 << "Email\n\n"; 
    while (temp != NULL) { 
        if (temp->data.get_name().find(keyword) != string::npos ||
            temp->data.get_address().find(keyword) != string::npos ||
            temp->data.get_phone().find(keyword) != string::npos) {
            	if(temp->data.get_id() != "ADMIN"){
            		temp->data.show_list();
            		found = true;
				}	
        }
        temp = temp->next;
    }
    
    if (!found){
    	moveCursor(0, 12); cout << setfill(' ') << setw(110);
    	moveCursor(0, 12); cout << "Khong tim thay voi tu khoa: ";
		moveCursor(28, 12); cout << keyword << endl;
	}
}

#endif //CLIENT_H
