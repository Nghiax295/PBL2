#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include "Datetime.h"

using namespace std;

class contract{
	private:
		string id_contract;
		string id_client;
		string id_motor; 
		datetime rental_date;
		datetime return_date;
		long long total_amount;
		string status;
	public:
		contract();
		contract(string, string, string, datetime, datetime, long long, string);
		
		void load_from_file(ifstream &);
		void save_to_file(ofstream &);
		
		string get_id() const;
		string get_id_client() const;
		string get_id_motor() const;
		datetime get_rental_date() const;
		datetime get_return_date() const;
		long long get_total_amount();
		string get_status() const;
		
		void set_status(const string &);
		
		void show_list();
};

contract::contract(){}

contract::contract(string id_contract, string id_client, string id_motor,
   datetime start, datetime end, long long total_amount, string status) :
    id_contract(id_contract), id_client(id_client), id_motor(id_motor), 
	rental_date(start), return_date(end), total_amount(total_amount), 
	status(status){}

void contract::load_from_file(ifstream &file){
	getline(file, id_contract, '|');
	getline(file, id_client, '|');
	getline(file, id_motor, '|');
	rental_date.load_from_file(file);
	return_date.load_from_file(file);
	file >> total_amount;
	file.ignore(numeric_limits<streamsize>::max(), '|');
	getline(file, status);
}

void contract::save_to_file(ofstream &file){
	file << id_contract << "|"
		 << id_client << "|"
		 << id_motor << "|";
	rental_date.save_to_file(file);
	return_date.save_to_file(file);
	file << total_amount << "|"
	     << status << "\n";
}


string contract::get_id() const{
	return id_contract;
}

string contract::get_id_client() const {
	return id_client;
}

string contract::get_id_motor() const{
	return id_motor;
}

datetime contract::get_rental_date() const{
	return rental_date;
}

datetime contract::get_return_date() const{
	return return_date;
}

long long contract::get_total_amount(){
	return total_amount;
}

string contract::get_status() const{
	return status;
}


void contract::set_status(const string &new_status){
	status = new_status;
}


void contract::show_list(){
	cout << left << setw(15) << id_contract
		 << left << setw(15) << id_client
		 << left << setw(15) << id_motor;
	rental_date.show_datetime();
	return_date.show_datetime();
	cout << left << setw(15) << total_amount
		 << status << "\n";
}

#endif //CONTRACT_H
