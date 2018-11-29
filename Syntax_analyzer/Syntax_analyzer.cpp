#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<String>
#include<ctype.h>
#include<regex>
#include<stack> //for adress
#include <cstdlib>
#include <map>
using namespace std;



void isRegister( string input) {
	cmatch result;
	regex Register("(ax|bx|dx|bp|eax|ebx|edx|ebp|esp|esi|edi|eflags|eip|cs|ds|es|fs|gs|ss)");
	if (regex_match(input, Register)) {
		cout << "lexem:\t" << "\t" << input << " is register\n";
	}
}

void main() {
	map<string, int> lexemsPriority{ {"*",1},{ "/",1 },{ "+",2 }, { "-",2 },{ ">", 3}, { "<", 3 }, { ">=", 3 },{ "<=", 3 } };
	string str = "";
	string buffer = "";
	ifstream fin("program.txt");
	stack<char> lexemsAcc;
	bool flag = false;
	int linenumber = 1;

	if (!fin.is_open()) {
		cout << "error while opening the file\n";
		exit(0);
	}

	while (getline(fin, str)) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
			{
				lexemsAcc.push(str[i]);
			}
			else if (isalpha(str[i])) {
				lexemsAcc.push(str[i]);
			}
			else if (isalpha(str[i])) {
				lexemsAcc.push(str[i]);
			}
		}
		linenumber++;
	}
	fin.close();
}