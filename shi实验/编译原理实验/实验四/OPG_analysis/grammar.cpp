
#include "grammar.h"

struct stack_char {
	char a, b, c;
};

void OperatorGrammar::input_grammar() {
	std::cout << "请输入文法G的规则数" << std::endl;
	std::cin >> r;
	std::cout << "\n请输入文法G[s],形如(S->aS|bA)" << std::endl;
	for (int i = 0; i < r; i++) {
		std::cin >> grammar[i];
		first_vt[i][0] = 0;
		last_vt[i][0] = 0;
	}
}

int OperatorGrammar::legal_grammar() {
	for (int i = 0; i < r; i++) {
		// 首先判断非终结符是否合法
		if (grammar[i][0] < 'A' || grammar[i][0]> 'Z') {
			std::cout << "不是算符文法!" << std::endl;
			return -1;
		}
		for (int j = 3; grammar[i][j] != '\0'; j++) {
			if (grammar[i][j] >= 'A' && grammar[i][j] <= 'Z') {
				if (grammar[i][j + 1] >= 'A' && grammar[i][j + 1] <= 'Z') {
					std::cout << "不是算符文法!" << std::endl;
					return -1;
				}
			}
		}
	}
	std::cout << "该文法是算符文法" << std::endl;
	return 1;
}

void OperatorGrammar::char_terminator() {
	int k = 0;
	int flag = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 3; grammar[i][j] != '\0'; j++) {
			if ((grammar[i][j] < 'A' || grammar[i][j] > 'Z') && grammar[i][j] != '|') {
				for (int n = 0; n < k; n++) {
					if (grammar[i][j] == label[n]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					label[k] = grammar[i][j];
					k++;
				}
				flag = 0;
			}
		}
	}
	label[k] = '#';
	label[k + 1] = '\0';
	tchar_num = k + 1;
	std::cout << "\n该文法的非终结符集为:\n" << label << std::endl;
}

int OperatorGrammar::terminator(char c) {
	for (int i = 0; label[i] != '\0'; i++) {
		if (c == label[i]) {
			return i;
		}
	}
	return -1;
}

int OperatorGrammar::nterminator(char c) {
	for (int i = 0; i < r; i++) {
		if (c == grammar[i][0]) {
			return i;
		}
	}
	return -1;
}

void OperatorGrammar::trans_grammar() {
	int m = 0, n = 0;
	for (int i = 0; i < r; i++) {
		n = 0;
		for (int j = 0; grammar[i][j] != '\0'; j++) {
			if (grammar[i][j] != '|') {
				t_grammar[m][n] = grammar[i][j];
				n++;
			} else {
				t_grammar[m][n] = '\0';
				m++;
				n = 3;
				t_grammar[m][0] = grammar[i][0];
				t_grammar[m][1] = grammar[i][1];
				t_grammar[m][2] = grammar[i][2];
			}
		}
		t_grammar[m][n] = '\0';
		m++;
	}
	tr = m;
}

void OperatorGrammar::firstvt() {
	int k = 0;
	int t = -1;
	std::stack<stack_char> fstack;
	stack_char sc;
	stack_char stemp;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < tchar_num - 1; j++) {
			fflag[i][j] = 0;
		}
	}

	for (int i = 0; i < tr; i++) {
		// 检查是否需要给k + 1
		if (i > 0) {
			if (t_grammar[i][0] != t_grammar[i - 1][0]) {
				k++;
			}
		}
		for (int j = 3; t_grammar[i][j] != '\0'; j++) {
			t = terminator(t_grammar[i][j]);
			if (t != -1) {
				fflag[k][t] = 1;
				break;
			}
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < tchar_num - 1; j++) {
			if (fflag[i][j] == 1) {
				sc.a = grammar[i][0];
				sc.b = ',';
				sc.c = label[j];
				fstack.push(sc);
			}
		}
	}
	
	while (!fstack.empty()) {
		sc =  fstack.top();
		fstack.pop();
		for (int i = 0; i < tr; i++) {
			if (t_grammar[i][3] == sc.a) {
				for (int j = 0; j < r; j++) {
					if (t_grammar[i][0] == grammar[j][0]) {
						t = terminator(sc.c);
						if (t != -1) {
							if (fflag[j][t] == 0) {
								fflag[j][t] = 1;
								stemp.a = grammar[j][0];
								stemp.b = ',';
								stemp.c = label[t];
								fstack.push(stemp);
							}
						}
					}
				}
			}	
		}
	}

	std::cout << "\nFIRSTTV集合矩阵:\n";
	for (int i = 0; i < tchar_num - 1; i++) {
		std::cout << "  " << label[i];
	}
	std::cout << std::endl;

	for (int i = 0; i < r; i++) {
		std::cout << grammar[i][0] << " ";
		int l = 0;
		for (int j = 0; j < tchar_num - 1; j++) {
			std::cout << fflag[i][j] << "  ";
			if (fflag[i][j] == 1) {
				first_vt[i][l] = label[j];
				l++;
			}
		}
		first_vt[i][l] = '\0'; 
		std::cout << "\n";
	}
	for (int i = 0; i < r; i++) {
		std::cout << "FIRSTVT[" << grammar[i][0] << "]:";
		for (int j = 0; first_vt[i][j] != '\0'; j++) {
			std::cout << first_vt[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void OperatorGrammar::lastvt() {
	int k = 0;
	int t = -1;
	std::stack<stack_char> lstack;
	stack_char sc;
	stack_char stemp;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < tchar_num - 1; j++) {
			lflag[i][j] = 0;
		}
	}

	for (int i = 0; i < tr; i++) {
		if (i > 0) {
			if (t_grammar[i][0] != t_grammar[i - 1][0]) {
				k++;
			}
		}
		int j = 0;
		for (; t_grammar[i][j] != '\0'; j++) {
		}
		while (j >= 3) {

			// 若该字符为终结符则标志为对应label下标位置为1
			t = terminator(t_grammar[i][j]);
			if (t != -1) {
				lflag[k][t] = 1;
				break;
			}
			j--;			
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < tchar_num - 1; j++) {
			if (lflag[i][j] == 1) {
				sc.a = grammar[i][0];
				sc.b = ',';
				sc.c = label[j];
				lstack.push(sc);
			}
		}
	}
	
	while (!lstack.empty()) {
		sc =  lstack.top();
		lstack.pop();
		for (int i = 0; i < tr; i++) {
			int q = 0;
			for (; t_grammar[i][q] != '\0'; q++) {
			}
			if (t_grammar[i][q - 1] == sc.a) {
				for (int j = 0; j < r; j++) {
					if (t_grammar[i][0] == grammar[j][0]) {
						t = terminator(sc.c);
						if (t != -1) {
							if (lflag[j][t] == 0) {
								lflag[j][t] = 1;
								stemp.a = grammar[j][0];
								stemp.b = ',';
								stemp.c = label[t];
								lstack.push(stemp);
							}
						}
					}
				}
			}	
		}
	}

	std::cout << "\nLASTVT集合矩阵:\n";
	for (int i = 0; i < tchar_num - 1; i++) {
		std::cout << "  " << label[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < r; i++) {
		std::cout << grammar[i][0] << " ";
		int l = 0;
		for (int j = 0; j < tchar_num - 1; j++) {
			std::cout << lflag[i][j] << "  ";
			if (lflag[i][j] == 1) {
				last_vt[i][l] = label[j];
				l++;
			}
		}
		last_vt[i][l] = '\0'; 
		std::cout << "\n";
	}
	for (int i = 0; i < r; i++) {
		std::cout << "LASTVT[" << grammar[i][0] << "]:";
		for (int j = 0; last_vt[i][j] != '\0'; j++) {
			std::cout << last_vt[i][j] << " ";
		}
		std::cout << "\n";
	}	
}

int OperatorGrammar::table() {
	for (int i = 0; i < tchar_num; i++) {
		for (int j = 0; j < tchar_num; j++) {
			priority_array[i][j] = '0';
		}
	}
	t_grammar[tr][0] = '$';
	t_grammar[tr][1] = '-';
	t_grammar[tr][2] = '>';
	t_grammar[tr][3] = '#';
	t_grammar[tr][4] = grammar[0][0];
	t_grammar[tr][5] = '#';
	t_grammar[tr][6] = '\0';
	for (int i = 0; i < tr + 1; i++) {
		for (int j = 3; t_grammar[i][j] != '\0'; j++) {
			int t1 = -1, t2 = -1, t3 = -1, nt = -1;
			t1 = terminator(t_grammar[i][j]);
			if (t1 != -1) {
				// aa情况
				if (t_grammar[i][j + 1] != '\0') {
					t2 = terminator(t_grammar[i][j + 1]);
					if (t2 != -1) {
						if (priority_array[t1][t2] == '0' || priority_array[t1][t2] == '=') {
							priority_array[t1][t2] = '=';
						}
						else {
							std::cout << "优先关系出现冲突，该文法不是算符优先文法!" << std::endl;
							return -1;	
						}
					}
				}
				if (t_grammar[i][j + 1] != '\0' && t_grammar[i][j + 2] != '\0') {
					t2 = terminator(t_grammar[i][j + 2]);
					if (t2 != -1) {
						if (priority_array[t1][t2] == '0' || priority_array[t1][t2] == '=') {
							priority_array[t1][t2] = '=';
						}
						else {
							std::cout << "优先关系出现冲突，该文法不是算符优先文法!" << std::endl;
							return -1;	
						}
					}			
					
				}
				if (t_grammar[i][j + 1] != '\0') {
					nt = nterminator(t_grammar[i][j + 1]);
					if (nt != -1) {
						for (int h = 0; first_vt[nt][h] != '\0'; h++) {
							t3 = terminator(first_vt[nt][h]);
							if (t3 != -1) {
								if (priority_array[t1][t3] == '0' || priority_array[t1][t3] == '<') {
									priority_array[t1][t3] = '<';
								}									
								else {
									std::cout << "优先关系出现冲突，该文法不是算符优先文法!" << std::endl;
									return -1;	
								}
							}
						}
					}
				}
			} else {
				if (t_grammar[i][j + 1] != '\0') {
					t2 = terminator(t_grammar[i][j + 1]);
					if (t2 != -1) {
						nt = nterminator(t_grammar[i][j]);
						if (nt != -1) {
							for (int h = 0; last_vt[nt][h] != '\0'; h++) {
								t3 = terminator(last_vt[nt][h]);
								if (t3 != -1) {
									if (priority_array[t3][t2] == '0' || priority_array[t3][t2] == '>') {
										priority_array[t3][t2] = '>';
									}
									else {
										std::cout << "优先关系出现冲突，该文法不是算符优先文法!" << std::endl;
										return -1;	
									}								
								}
							}
						}
					}
				}
			}
		}
	}
	
	std::cout << "\n算符优先关系矩阵：\n ";
	for (int i = 0; i < tchar_num; i++) {
		std::cout << " " << label[i];
	}
	std::cout << "\n";
	for (int i = 0; i < tchar_num; i++) {
		std::cout << label[i] << " ";
		for (int j = 0; j < tchar_num; j++) {
			std::cout << priority_array[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 1;
}

void OperatorGrammar::print_stack(int j, int k, char *s)
{
	for (int i = j; i <= k; i++) {
		std::cout << s[i];
	}
	std::cout << "\t\t";
}

