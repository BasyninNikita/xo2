#include <iostream>
#include <sstream>
using namespace std;
char win;int vyhod;int x;
void tablica(char *mass) {
	cout << "   1   2   3   4   5" << endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "a| " << mass[0] << " | " << mass[1] << " | " << mass[2] << " | " << mass[3] << " | " << mass[4] << " | "<< endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "b| " << mass[5] << " | " << mass[6] << " | " << mass[7] << " | " << mass[8] << " | " << mass[9] << " | "<< endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "c| " << mass[10] << " | " << mass[11] << " | " << mass[12] << " | " << mass[13] << " | " << mass[14] << " | "<< endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "d| " << mass[15] << " | " << mass[16] << " | " << mass[17] << " | " << mass[18] << " | " << mass[19] << " | "<< endl;
	cout << " +---+---+---+---+---+" << endl;	
	cout << "e| " << mass[20] << " | " << mass[21] << " | " << mass[22] << " | " << mass[23] << " | " << mass[24] << " | "<< endl;
	cout << " +---+---+---+---+---+" << endl;
}
void vozmhody(char op, char *mass) {
	int k = 0;
	for (int i = 0; i < 25; i++) {
		if (!(mass[i] == 'X' || mass[i] == 'O')) {
			if (i < 5) {
				cout << ++k << ".mark cell a" << i + 1 << " as " << op << endl;
			}
			if (i>4 && i<10) {
				cout << ++k << ".mark cell b" << i - 4 << " as " << op << endl;
			}
			if (i>9 && i<15) {
				cout << ++k << ".mark cell c" << i - 9 << " as " << op << endl;
			}
			if (i>14 && i<20) {
				cout << ++k << ".mark cell d" << i - 14 << " as " << op << endl;
			}			
			if (i>19) {
				cout << ++k << ".mark cell e" << i - 19 << " as " << op << endl;
			}
		}
	}
	cout << ++k << ". quit" << endl;
	vyhod = k;
}
int hod(int move, char op, char *mass) {
	int cell;
	string string;
	getline(cin, string);
	istringstream stream(string);
	stream >> cell;
	while (cell < 1 || cell >(27 - move)) {
		cout << endl << "You can not use this move. Enter another move" << endl;
		getline(cin, string);
		istringstream stream(string);
		stream >> cell;
	}
	int k = 0;
	for (int i = 0; i < 25; i++){
		if (mass[i] == ' ') {
			k++;
		}
		if (k == cell) {
			mass[i] = op;
			tablica(mass);
			return 0;
			}
	}
	if (cell == vyhod) {
		cout << "game over((" << endl;
		x = vyhod;
		return -1;
	}
	return 0;
}
char proverka(char *mass) {
	
	for (int i = 0; i < 4; i++) {
		if ((mass[i] == mass[i + 5] && mass[i + 10] == mass[i + 15]&& mass[i + 15] == mass[i + 20]) && mass[i] != ' ') {
			return mass[i];
		}
	}
	for (int i = 0; i < 21; i+=5) {
		if ((mass[i ] == mass[i + 1] && mass[i + 1] == mass[i + 2]&& mass[i + 2] == mass[i + 3]&& mass[i + 4] == mass[i + 4]) && mass[i] != ' ') {
			return mass[i];;
		}
	}
		if ((mass[0] == mass[6] && mass[6] == mass[12]&& mass[12] == mass[18]&& mass[18] == mass[24]) && mass[2] != ' ')  {
			return mass[0];
		}
		if((mass[4] == mass[8] && mass[8] == mass[12]&& mass[12] == mass[16]&& mass[16] == mass[20]) && mass[0] != ' ') {
			return mass[4];
			}
	return ' ';
}
int main() {
	char mass[25] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char op;
	tablica(mass);
	for (int move = 1; move <= 25; move++) {
		if (move % 2) {
			op = 'X';
			vozmhody(op, mass);
			hod(move, op, mass);
		}
		else {
			op = 'O';
			vozmhody(op, mass);
			hod(move, op, mass);
		}
		if (vyhod == x) {
			return -1;
		}
		if (move >= 9) {
			proverka(mass);
			char  win = proverka(mass);
				cout << win<<" win" << endl;
				return -1;
			}
			if (move == 9 && win != 'X' && win != 'O') {
				cout << "nichya" << endl;
				return -1;
			}
	}
	if (vyhod ==x) {
		return -1;
	}
}
