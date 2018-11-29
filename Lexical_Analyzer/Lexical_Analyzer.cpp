#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<String>
#include<ctype.h>
#include<regex>
#include<stack>
#include <cstdlib>
#include <bitset>

using namespace std;

stack<string> mystack;

void isRegister(int &lexemnumber, string input) {
	cmatch result;
	regex Keyword("mov|MOV|xchg");
	regex Register("(ax|bx|dx|bp|eax|ebx|edx|ebp|esp|esi|edi|eflags|eip|cs|ds|es|fs|gs|ss|ecx)");
	if (regex_match(input, Register)) {
		mystack.push(input);
		cout << "lexem:\t" << lexemnumber++ << "\t" << input << " is register\t" << &mystack.top() << "\n";
	}
	else if (!regex_search(input.c_str(), result, Keyword))
	{
		mystack.push(input);
		cout << "lexem:\t" << lexemnumber++ << "\t" << input << " is variable\t" << &mystack.top() << "\n";
	}
}

void isKeyWord(int linenumber, int &lexemnumber, string input, bool &flag) {
	cmatch result;
	regex Keyword("mov|MOV|xchg");
	if (regex_search(input.c_str(), result, Keyword)) {
		cout << "Line : " << linenumber << endl;
		flag = true;
		for (int i = 0; i < result.size(); i++) {
			mystack.push(result[i]);
			cout << "lexem:\t" << lexemnumber++ << "\t" << result[i] << " is keyword\t" << &mystack.top() << "\n";
		}
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
				{
					cout << "lexem:\t" << lexemnumber++ << "\t" << str[i] << " is separator\n";
				}
				else if (isdigit(str[i])) {
					while (isdigit(str[i])) {
						buffer += str[i];
						i++;
					}
					i--;
					int digit = stoi(buffer);
					mystack.push(buffer);
					cout << "lexem:\t" << lexemnumber++ << "\t" << bitset<8>(digit) << " is digit\t" << &mystack.top() << "\n";;
					buffer.erase();
				}
				else if (isalpha(str[i])) {
					while (isalpha(str[i])) {
						buffer += str[i];
						i++;
					}
					if (!buffer.empty()) {
						i--;
						isRegister(lexemnumber, buffer);
						buffer.erase();
					}
				}
			}
		}
		flag = false;
		linenumber++;
	}

	while (!mystack.empty()) {
		mystack.pop();
	}
	fin.close();
}