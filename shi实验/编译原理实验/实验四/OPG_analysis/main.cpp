/*************************************************************************
	> File Name: yyyyyyy.c
	> Author: kwh
	> Mail:
	> Created Time: 2019年11月12日 星期二 19时08分56秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grammar.h"
using namespace std;

#define MAXSIZE 64
#define NN -10

typedef char datatype;
typedef struct {
	datatype data[MAXSIZE];
	int top;
} seqstack;
seqstack OPR;
seqstack OPT;
char *p;
int  matrix[7][7] = {
    {NN,-1,-1,-1,-1,NN,1},
	{NN,1,-1,-1,-1,1,1},
	{NN,1,1,-1,-1,1,1},
    {1,1,1,NN,NN,1,1},
    {NN,-1,-1,-1,-1,0,NN},
    {NN,1,1,NN,NN,1,1},
    {-1,NN,NN,-1,NN,NN,0}};

int row,line;
int count=1;
int compare (char m, char n) {
	switch (m) {
		case '=': row = 0; break;
		case '+': row = 1; break;
		case '*': row = 2; break;
		case 'i': row = 3; break;
		case '(': row = 4; break;
		case ')': row = 5; break;
		case '$': row = 6; break;
		default:  return -100; break;
	}
	switch(n) {
		case '=': line = 0; break;
		case '+': line = 1; break;
		case '*': line = 2; break;
		case 'i': line = 3; break;
		case '(': line = 4; break;
		case ')': line = 5; break;
		case '$': line = 6; break;
		default: return -100; break;
	}
	return matrix[row][line];
}

void OPRsetnull () {
	OPR.top=-1;
}

int OPRempty () {
	if (OPR.top >= 0)
		return 0;
	else
		return 1;
}

void OPRpush (char x) {
	if(OPR.top == MAXSIZE - 1)
	printf("上溢!");
	else {
	OPR.top++;
	OPR.data[OPR.top] = x;
	}
}

datatype OPRpop () {
	if (OPRempty()) {
		printf("下溢！");
    return -1;
} else {
		OPR.top--;
		return (OPR.data[OPR.top + 1]);
	}
}

datatype OPRtop () {
	if (OPRempty()) {
		return -1;
	} else return(OPR.data[OPR.top]);
}

void OPTsetnull () {
	OPT.top = -1;
}

int OPTempty () {
	if(OPT.top >= 0)
		return 0;
	else
		return 1;
}

void OPTpush (char x) {
	if(OPT.top == MAXSIZE - 1)
		printf("上溢!");
	else {
		OPT.top++;
		OPT.data[OPT.top] = x;
	}
}

datatype OPTpop () {
	if(OPTempty()) {
		printf("下溢！");return -1;
	} else {
		OPT.top--;
		return(OPT.data[OPT.top+1]);
	}
}

datatype OPTtop () {
	if(OPTempty()) {
		return -1;
	} else return(OPT.data[OPT.top]);
}

void output(char opt, char op1, char op2, int num) {
	if(op1 == 'i' && op2 == 'i') printf("(%c,%c,%c,t%d)\n", opt, op1, op2, num);
	if(op1 != 'i' && op2 == 'i') printf("(%c,t%d,%c,t%d)\n",opt, op1, op2, num);
	if(op2 != 'i' && op1 == 'i') printf("(%c,%c,t%d,t%d)\n", opt, op1, op2, num);
	if(op1 != 'i' && op2 != 'i') printf("(%c,t%d,t%d,t%d)\n", opt, op1, op2, num);
}

void test() {
	OPRsetnull();
	OPTsetnull();
	char ch[]="$i=i*(i*(i+i))*i$";
	printf("\n\n分析语句:");
	printf("%s\n", ch);
	p = ch;
	char opt;
	char op1, op2;
	if(*p == '$') OPTpush(*p);
	p++;
	while(*p != '$') {
	    if(*p == 'i') OPRpush(*p);
		    else {
			    opt = OPTtop();
		    P: switch(compare(opt, *p)) {
				case -1:  OPTpush(*p); break;
				case NN:  break;
			    case 0:  OPTpop(); break;
			    case 1:	op1=OPRpop();
						op2=OPRpop();
					    output(opt, op1, op2, count);
						OPRpush(count);
						count++;
						opt = OPTpop();
						opt = OPTtop();
						goto P; break;
		        }
		    }
		p++;
	}
	while (!OPTempty() && !OPRempty() && (OPTtop() != '$')) {
        op1 = OPRpop();
		op2 = OPRpop();
		opt = OPTpop();
		if (opt != '='){
			output(opt, op1, op2, count);
			OPRpush((count));count++;
		}
		if(opt == '=') printf("(%c,t%d, ,i)\n", opt, count - 1);
	}
}

int main() {
    OperatorGrammar opg;
	opg.input_grammar();
	if (opg.legal_grammar() == -1) {
		return -1;
	}
	opg.char_terminator();
	opg.trans_grammar();
	opg.firstvt();
	opg.lastvt();
	if(opg.table() == -1) {
		return -1;
	}

	test();
    return 0;
}


