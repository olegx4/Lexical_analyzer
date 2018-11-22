#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<String>
#include<ctype.h>
#include<regex>
#include<stack> //for adress

using namespace std;

void isRegister(int &lexemnumber, string input) {
	cmatch result;
	regex Register("(ax|bx|dx|bp|eax|ebx|edx|ebp|esp|esi|edi|eflags|eip|cs|ds|es|fs|gs|ss)");
	if (regex_match(input, Register)) {
		cout << "lexem:\t" << lexemnumber++ << "\t" << input << " is register\n";
	}
}

void isKeyWord(int linenumber, int &lexemnumber, string input, bool &flag) {
	cmatch result;
	regex Keyword("mov|MOV");
	if (regex_search(input.c_str(), result, Keyword)) {
		cout << "Line : " << linenumber << endl;
		flag = true;
		for (int i = 0; i < result.size(); i++)
			cout << "lexem:\t" << lexemnumber++ << "\t" << result[i] << " is keyword\n";
	}
}


void main() {

	string str = "";
	string buffer = "";
	ifstream fin("program.txt");
	bool flag = false;
	int linenumber = 1, lexemnumber = 1;

	if (!fin.is_open()) {
		cout << "error while opening the file\n";
		exit(0);
	}

	while (getline(fin, str)) {
		isKeyWord(linenumber, lexemnumber, str, flag);
		if (flag) {
			for (int i = 0; i < str.length(); i++) {
				if (ispunct(str[i]) && buffer.empty())
					cout << "lexem:\t" << lexemnumber++ << "\t" << str[i] << " is separator\n";
				else if (isdigit(str[i])) {
					while (isdigit(str[i])) {
						buffer += str[i];
						i++;
					}
					cout << "lexem:\t" << lexemnumber++ << "\t" << buffer << " is digit\n";
					buffer.clear();
				}
				else if (isalpha(str[i])) {
					while (isalpha(str[i])) {
						buffer += str[i];
						i++;
					}
					if (!buffer.empty()) {
						isRegister(lexemnumber, buffer);
						buffer.clear();
					}

				}

			}
		}
		flag = false;
		linenumber++;
	}
	fin.close();
}