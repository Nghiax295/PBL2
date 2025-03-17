#ifndef FUNCTION_H
#define FUNCTION_H

#include <windows.h>
#include <cctype>
#include <ctime>
#include <sstream>
#include <set>
#include "Datetime.h"

string create_code(const string &str);
string create_captcha();
void get_x_y(int &x, int &y);
void moveCursor(int x, int y);
void inputAtCursor(string &input, int cursorX, int cursorY);
bool go_back();
void convert_to_upper(string &input);
bool check_name(const string& input);
bool check_cccd(const string &input);
bool check_phone(const string &input);
bool check_dob(const string& input);
bool check_user(const string &input);


string create_code(const string &str) {
    const int codeLength = 7;
    string code = "";
    code += str;
    for (int i = 0; i < codeLength; ++i) {
        int randomDigit = rand() % 10;
        	ostringstream oss;
			oss << randomDigit;
			string s = oss.str();
        code += s;
    }
    return code;
}

string create_captcha() {
    string captcha;
    string characters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 6; ++i) {
        int randomIndex = rand() % characters.size();
        captcha += characters[randomIndex];
    }
    return captcha;
}

void get_x_y(int &x, int &y) {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    DWORD events;
    INPUT_RECORD inputRecord;
    bool isLeftButtonPressed = false;
    while (true) {
        ReadConsoleInput(hInput, &inputRecord, 1, &events);
        if (inputRecord.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;
            if (mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && !isLeftButtonPressed) {
                isLeftButtonPressed = true;
                x = mouseEvent.dwMousePosition.X;
                y = mouseEvent.dwMousePosition.Y;
            } else if (mouseEvent.dwButtonState == 0 && isLeftButtonPressed) {
                FlushConsoleInputBuffer(hInput);
                SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
                break;
            }
        }
    }
}

void moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void inputAtCursor(string &input, int cursorX, int cursorY) {
    moveCursor(cursorX, cursorY);
    getline(cin, input);
    moveCursor(cursorX, cursorY);
    cout << input;
}

bool go_back(){
	int x, y;
	while(true){
		get_x_y(x, y);
		if(x >= 0 && x < 15 && y >= 4 && y < 6){
			system("cls");
			return true;
		}
	}
}

void convert_to_upper(string &input){
	for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - ('a' - 'A');
        }
    }
}

bool check_name(const string& input){
	for(int i = 0; i < input.length(); i++)
		if(!isalpha(input[i]) && input[i] != ' ') return false;
	return true;
}

bool check_cccd(const string &input){
	if(input.length() != 12) return false;
	for(int i = 0; i < input.length(); i++)
		if(!isdigit(input[i])) return false;
	return true;
} 

bool check_dob(const string& input){
	istringstream ss(input);
    int day, month, year;
    char ch1, ch2;
    ss >> day >> ch1 >> month >> ch2 >> year;
    if (ss.fail() || ch1 != '/' || ch2 != '/') return false;
    datetime dt(day, month, year, 0, 0);
    return dt.check_time();
}

bool check_phone(const string &input){
	if(input.length() != 10 || input[0] != '0') return false;
	for(int i = 0; i < input.length(); i++)
		if(!isdigit(input[i])) return false;
	return true;
}

bool check_user(const string &input){
	for(int i = 0; i < input.length(); i++)
		if(!isalpha(input[i]) && !isdigit(input[i])) return false;
	return true;
}

bool check_email(const string& input) {
    size_t atPos = input.find('@');
    size_t dotPos = input.rfind(".com");

    if (atPos == std::string::npos || dotPos == std::string::npos || atPos >= dotPos) {
        return false;
    }

    std::string domain = input.substr(atPos + 1);
    if (domain != "gmail.com") {
        return false;
    }

    std::string localPart = input.substr(0, atPos);
    if (localPart.empty()) {
        return false; 
    }

    for (size_t i = 0; i < localPart.size(); ++i) {
        char c = localPart[i];
        if (!(isalnum(c) || c == '.' || c == '_' || c == '+' || c == '-')) {
            return false;
        }
    }

    return true; 
}

#endif //FUNCTION_H
