#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//Lop tai khoan
class account{
	private:
		string username; //PK
		string password;
		string id; //role
	public:
		account();
		account(string, string , string);
		
		void load_from_file(ifstream &);
		void save_to_file(ofstream &);
		
		string get_id() const;
		string get_user() const;	
		string get_pass() const;
		
		void set_pass(const string &);
		
		bool check_account(const string &, const string &);
}; 

account::account() : id(""), username(""), password("") {} 

account::account(string id, string username, string password) : 
	id(id), username(username), password(password){} 


void account::load_from_file(ifstream &file){
	getline(file, id, '|');
	getline(file, username, '|');
	getline(file, password, '|');
}

void account::save_to_file(ofstream &file){
	file << id << "|"
		 << username << "|"
		 << password << "|";
}


string account::get_id() const{
	return id;
}

string account::get_user() const {
	return username;
}

string account::get_pass() const{
	return password;
}


void account::set_pass(const string &new_pass){
	password = new_pass;
}


bool account::check_account(const string &input_user, const string &input_pass){
	return (username == input_user && password == input_pass);
}

#endif //ACCOUNT_H
