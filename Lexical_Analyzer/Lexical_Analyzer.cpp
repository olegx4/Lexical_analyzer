#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<regex>
#include<stack>


using namespace std;

void thisIs(string input){
	regex constant("\\d+");
	regex keyword("MOV|mov|xchg");
	regex separator(",|;| ");

	if (regex_match(input, constant))
		cout << "is constant\n";
	else if(regex_match(input, keyword))
		cout << "is operator\n";
	else if (regex_match(input, separator))
		cout << "is separator\n";
	else
		cout << "smth new\n";
}
//int isKeyword(char buffer[]) {
//	char keywords[32][10] = { "MOV", "" };
//	int i, flag = 0;
//
//	for (i = 0; i < 32; ++i) {
//		if (strcmp(keywords[i], buffer) == 0) {
//			flag = 1;
//			break;
//		}
//	}
//
//	return flag;
//}

//int isRegistry(char buffer[]) {
//	char keywords[32][10] = { "MOV", "" };
//	int i, flag = 0;
//
//	for (i = 0; i < 32; ++i) {
//		if (strcmp(keywords[i], buffer) == 0) {
//			flag = 1;
//			break;
//		}
//	}
//
//	return flag;
//}

void main() {
	while (1) {
		string NewString;
		cin >> NewString;
		thisIs(NewString);
	}
	/*char ch, buffer[15], operators[] = "+-* /=";
	ifstream fin("program.txt");
	int i, j = 0;

	if (!fin.is_open()) {
		cout << "error while opening the file\n";
		exit(0);
	}

	while (!fin.eof()) {
		ch = fin.get();

		for (i = 0; i < 6; ++i) {
			if (ch == operators[i])
				cout << ch << " is operator\n";
		}

		if (isalnum(ch)) {
			buffer[j++] = ch;
		}
		else if ((ch == ' ' || ch == '\n') && (j != 0)) {
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1)
				cout << buffer << " is keyword\n";
			else
				cout << buffer << " is indentifier\n";
		}

	}

	fin.close();

	return 0;
	*/
}