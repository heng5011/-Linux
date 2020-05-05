#include<iostream>
//#include <curses.h>
#include<conio.h>
#include<stack>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
using namespace std;
int k, n;
int f;
int home_flag, end_flag;
int home_s, home_e;
int end_s, end_e;
int vis[100][100];
char a[100][100];
int map[100][100];
struct node {
	int x;
	int y;
};
void tishi() {
	cout<<"↑ ↓ ← → 控制移动"<<endl;
	cout<<"Home设起点,END设终点,ENTER加墙,Del删墙"<<endl; 
	cout<<"按F9演示， ESC退出"<<endl;
}
void out_chengse() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"●"<<" ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void out_red() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"■ ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void out_green() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"●"<<" ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
} 
void zhuanhua() {
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < n;++j) {
			if(a[i][j] == '#') {
				map[i][j] = 2;
			} else if(a[i][j] == '.') {
				map[i][j] = 0;
			} 
		}
	}
}
void pass(int X,int Y) {	
	map[X][Y] = 1;
	if(X == end_s && Y == end_e) {
		f = 1;//防止输出两次ans 
		system("cls");
		cout<<"Path found!"<<endl;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				if(i == home_s && j == home_e) {
					out_chengse();
				} else if(i == end_s && j == end_e) {
					out_green();
				} else if(map[i][j] == 0)
					printf(".  ");
				else if(map[i][j] == 1)
					cout<<"○ ";
				else
					out_red();
			}
			cout<<endl<<endl;
		}
		return;
	}
	if(map[X+1][Y]==0)
		pass(X+1,Y);
	if(map[X-1][Y]==0)
		pass(X-1,Y);
	if(map[X][Y+1]==0)
		pass(X,Y+1);
	if(map[X][Y-1]==0)
		pass(X,Y-1);
	map[X][Y] = 0;         //恢复复原来状态
}

int ans(int x, int y) {
	memset(vis,0,sizeof(vis));
	stack <node> q;
	node now, end, next;
	now.x = home_s;
	now.y = home_e;
	end.x = end_s;
	end.y = end_e;
	q.push(now);
	while(!q.empty() ) {
		vis[now.x ][now.y ] = 1;
		if(now.x == end.x && now.y == end.y ) {
			f = 1;//防止输出两次ans 
			cout<<"Path found!"<<endl;
			memset(vis,0,sizeof(vis));
			while(!q.empty() ) {
				now = q.top() ;
				vis[now.x ][now.y ] = 1;
				q.pop() ;
			}
			for(int i = 0;i < n;++i) {
				for(int j = 0;j < n;++j) {
					if(vis[i][j]) {
						if(i == home_s && j == home_e) {
							out_chengse();
						} else if(i == end_s && j == end_e) {
							out_green();
						} else {
							cout<<"○ ";
						}
					} else if(a[i][j] == '#'){
						out_red();
					} else {
						cout<<a[i][j]<<"  ";
					}
				}
				cout<<endl<<endl;
			}
			return 1;
		}
		next = now;
		next.y++;
		if(next.y < n && next.y > 0 && a[next.x ][next.y] != '#' && !vis[next.x ][next.y ]) {
			now = next;
			vis[now.x ][now.y ] = 1;
			q.push(now);
			continue; 
		}   
		next = now;
		next.x ++;
		if(next.x < n && next.x > 0 && a[next.x ][next.y ] != '#' && !vis[next.x ][next.y ]) {
			now = next;
			vis[now.x ][now.y ] = 1;
			q.push(now);
			continue; 
		} 
		next = now;
		next.y --;
		if(next.y < n && next.y > 0 && a[next.x ][next.y ] != '#' && !vis[next.x ][next.y ]) {
			now = next;
			vis[now.x ][now.y ] = 1;
			q.push(now);
			continue; 
		}	 
		next = now;
		next.x --;
		if(next.x < n && next.x > 0 && a[next.x ][next.y] != '#' && !vis[next.x ][next.y ]) {
			now = next;
			vis[now.x ][now.y ] = 1;
			q.push(now);
			continue; 
		} 
		now = q.top();
		q.pop() ;
	} 
	system("cls");
	memset(a,'.',sizeof(char) * 10000);
	home_flag = 0;
	end_flag = 0;
	cout<<"Path not found!"<<endl;
	return 0;
}
int main() {
	cout<<"请输入迷宫大小（N*N）："; 
	scanf("%d",&n);
	int i;
	char c;
	int x = 0, y = 0;
	memset(a,'.',sizeof(char) * 10000);
	a[0][0] = 1;
	system("cls");
	tishi(); 
	for(i = 0;i < n;++i) {
		for(int j = 0;j < n;++j) {
			cout<<a[i][j]<<"  ";
		}
		cout<<endl<<endl;
	}
	while(1) {    
		c = getch();
		switch(c) {
			case -32:
				c = getch();
				if(k) { //保证走过去之后原先的有墙的话还有墙 
					a[x][y] = '#';
				}
				k = 0;
				switch(c) { 
					case 83:       //删除墙 del键 
						a[x][y] = '.';
						break;
					case 79:       //设置起点 Home键 
						if(!end_flag) {
							a[x][y] = '0';
							end_flag++;
							end_s = x;
							end_e = y;
						}
						break;
					case 72:      //向上移动  ↑键 
						if(x - 1 >= 0 && x - 1 < n) {
							f = 0;
							if(a[x-1][y] == '#') {
								k = 1;
							}
							if(a[x][y] == '#') {
								a[x][y] = '#';
							} else {
								a[x][y] = '.';
							}	
							a[--x][y] = 1;			
						}
						break;
					case 80:    //向下移动  ↓键 
						if(x + 1 >= 0 && x + 1 < n ) {
							f = 0;
							if(a[x+1][y] == '#') {
								k = 1;
							}
							if(a[x][y] == '#') {
								a[x][y] = '#';
							} else {
								a[x][y] = '.';
							}
							a[++x][y] = 1;
						}
						break;
					case 75:   //向左移动  ←键 
						if(y - 1 >= 0 && y - 1 < n ) {
							f = 0;
							if(a[x][y-1] == '#') {
								k = 1;
							}
							if(a[x][y] == '#') {
								a[x][y] = '#';
							} else {
								a[x][y] = '.';
							}
							a[x][--y] = 1;	
						}
						break;
					case 71:  // 设置终点 END键 
						if(!home_flag) {
						a[x][y] = '*';
						home_flag++;
						home_s = x;
						home_e = y;
						}
						break;
					case 77:  //想右移动   →键 
						if(y + 1 >= 0 && y + 1 < n ) {
							f = 0;
							if(a[x][y+1] == '#') {
								k = 1;
							}
							if(a[x][y] == '#') {
								a[x][y] = '#';
							} else {
								a[x][y] = '.';
							}
							a[x][++y] = 1;
						}
						break;
			
				}
				break;
			default:
				if(c == 13) {  //设置墙 enter键 
					a[x][y] = '#';
				} else if(c == 27) { //Esc 退出 
					return 1;
				} else {  //F9 开始演示 
					if(!home_flag) {
						system("cls");
						cout<<"Error: You must set Stratplace."<<endl;
						system("pause");
					}
					if(!end_flag) {
						system("cls");
						cout<<"Error: You must set Endlace."<<endl;
						system("pause");
					}
					if(home_flag && end_flag && f == 0) {
						memset(map,0,sizeof(map));
						zhuanhua();
						pass(home_s, home_e);
						system("pause");
					}  
				}
				break;
		}
		if(home_flag) { //  保持起点不被掩盖 
			a[home_s][home_e] = '*';
		}
		if(end_flag) { //  同理 
			a[end_s][end_e] = '0';
		}
		system("cls");
		tishi(); 
		for(i = 0;i < n;++i) {
			for(int j = 0;j < n;++j) {
				if(a[i][j] == '*') {
					out_chengse();
				} else if(a[i][j] == '0'){
					out_green();
				} else if(a[i][j] == '#'){
					out_red();
				} else {  
					cout<<a[i][j]<<"  ";
				}	
			}
			cout<<endl<<endl;
		}
	}
	return 0;
}
