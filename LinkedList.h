#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class Node{
	public:
		T data;
		Node *next;
		Node(T data);
}; 

template <typename T>
class List{
	private:
		Node<T> *head;
	public:
		List();
		~List();
		
		void load(const string &filename);
		void save(ofstream &file);
		
		Node<T> *get_head() const;
		
		void add(const T &new_data);
		void delete_node(const string &filename, const string &id);
		void show_list() const;
		bool find_id(const string &filename, const string &id);
};

template <typename T>
Node<T> :: Node(T data) : data(data), next(NULL){}

template <typename T>
List<T> :: List() : head(NULL){}

template <typename T>
List<T> :: ~List(){
	Node<T> *current = head;
	while(current != NULL){
		Node<T> *temp = current->next;
		delete current;
		current = temp;
	}
}


template <typename T>
void List<T> :: load(const string &filename){
	ifstream file(filename.c_str());
	
	if(!file.is_open()){
		cout << "Mo tep khong thanh cong.\n";
		return;
	}
	T new_data;
	while(true){
		new_data.load_from_file(file);
		if(file.eof()) break;
		add(new_data);
	}
	
	file.close();
}

template <typename T>
void List<T> :: save(ofstream &file){
	if(!file.is_open()){
		cout << "Mo tep khong thanh cong.\n";
		return;
	}
	
	Node<T> *temp = head;
	while(temp != NULL){
		temp->data.save_to_file(file);
		temp = temp->next;
	}
}


template <typename T>
Node<T>* List<T> :: get_head() const{
	return head;
}


template <typename T>
void List<T> :: add(const T &new_data){
	Node<T> *new_node  = new Node<T>(new_data);
	if(head == NULL)
		head = new_node;
	else {
		Node<T> *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

template <typename T>
void List<T>::delete_node(const string &filename, const string &id) {
    List<T> list;
    list.load(filename);

    Node<T> *temp = list.get_head();
    Node<T> *prev = NULL;
    
    while (temp != NULL && temp->data.get_id() != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            list.head = temp->next;
        else
            prev->next = temp->next;
        delete temp;
    } else	return;

    ofstream file(filename.c_str(), ios::trunc);
    list.save(file);
    file.close();
}

template <typename T>
void List<T> :: show_list() const{
	if(head == NULL){
		cout << "Danh sach rong.\n";
		return;
	}
	
	Node<T> *temp = head;
	while(temp != NULL){
		temp->data.show_list();
		temp = temp->next;
	}
}

template <typename T>
bool List<T> :: find_id(const string &filename, const string &id){
	List<T> list;
	list.load(filename);
	Node<T> *temp = list.get_head();
	while(temp != NULL){
		if(temp->data.get_id() == id)
			return true;
		temp = temp->next;
	}
	return false;
}

#endif //LINKEDLIST_H
