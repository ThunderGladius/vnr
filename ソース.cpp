#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;



//fCALL�֐�
void fCALL(int &call) {
		cout << "CALL�������l����͂��ĉ�����" << endl;
		cin >> call;
}



//fEAT�֐�
void fEAT(vector<vector<int>> &vec, int call) {
	int eat;
	//����
	while (1) {
		cout << "EAT������͂��ĉ�����" << endl;
		cin >> eat;
		if (eat < 3) break;
		else cout << "�ē��͂��ĉ�����" << endl;
	}
	//��ꕪ��
	if(eat == 0){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				//1���ȏ��v�̏��O
				if (call / 100 == a) vec.at(i).at(j) = 0;
				if ((call % 100) / 10 == b) vec.at(i).at(j) = 0;
				if ((call % 100) % 10 == c)vec.at(i).at(j) = 0;
			}
		}
	}
	//��񕪊�
	if(eat == 1){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				//2���ȏ��v�̏��O
				if ((call / 100 == a && (call % 100) / 10 == b)
					|| ((call % 100) / 10 == b && (call % 100) % 10 == c)
					|| ((call % 100) % 10 == c && call / 100 == a)) vec.at(i).at(j) = 0;
				//�s��v�̏��O
				if (call / 100 != a && (call % 100) / 10 != b
					 && (call % 100) % 10 != c) vec.at(i).at(j) = 0;
			}
		}
	}
	//��O����
	if(eat == 2){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				//1����v�̏��O
				if (((call / 100 == a && (call % 100) / 10 != b) && ((call % 100) % 10 != c)) 
				 || ((call / 100 != a && (call % 100) / 10 == b) && ((call % 100) % 10 != c)) 
				 || ((call / 100 != a && (call % 100) / 10 != b) && ((call % 100) % 10 == c))) vec.at(i).at(j) = 0;

				//�s��v�̏��O
				if (call / 100 != a && (call % 100) / 10 != b
					&& (call % 100) % 10 != c) vec.at(i).at(j) = 0;
			}
		}
		
	}
	//��l����
	if (eat == 3) cout << "You win!" << endl;
}


//fBITE�֐�
void fBITE(vector<vector<int>>& vec, int call) {
	int bite;
	//����
	while (1) {
		cout << "BITE������͂��ĉ�����" << endl;
		cin >> bite;
		if (bite < 3) break;
		else cout << "�ē��͂��ĉ�����" << endl;
	}
	//��ꕪ��
	if (bite == 0) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//call�̊e��
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				//1�ȏ��bite�̏��O
				if (ca == b || ca == c || cb == a || cb == c || cc == a || cc == b) vec.at(i).at(j) = 0;

			}
		}
	}
	//��񕪊�
	if (bite == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//call�̊e��
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				//2�ȏ��bite�̏��O
				if ((ca == b && cb == a) || (ca == b && cb == c) || (ca == b && cc == a) ||
					(ca == c && cb == a) || (ca == c && cc == a) || (ca == c && cc == b) ||
					(cb == a && ca == b) || (cb == a && ca == c) || (cb == a && cc == b) ||
					(cb == c && ca == b) || (cb == c && cc == a) || (cb == c && cc == b) ||
					(cc == a && ca == b) || (cc == a && ca == c) || (cc == a && cb == c) ||
					(cc == b && ca == c) || (cc == b && cb == a) || (cc == b && cb == c) ) {
					vec.at(i).at(j) = 0;
				}

				//0bite�̏��O
				if ((ca != b || ca != c) && (cb != a || cb != c) && (cc != a || cc != b)) {
					vec.at(i).at(j) = 0;
				}

			}
		}
	}
	//��O����
	if (bite == 2) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//call�̊e��
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				//3bite�̏��O
				if ((ca == b && cb == c && cc == a) || (ca == c && cb == a && cc == b)) {
					vec.at(i).at(j) = 0;
				}

				//1bite�̏��O
				if (((ca == b || ca == c) && (cb != a || cb != c) && (cc != a || cc != b)) ||
					((ca != b || ca != c) && (cb == a || cb == c) && (cc != a || cc != b)) ||
					((ca != b || ca != c) && (cb != a || cb != c) && (cc == a || cc == b))) {
					vec.at(i).at(j) = 0;
				}
				//0bite�̏��O
				if ((ca != b || ca != c) && (cb != a || cb != c) && (cc != a || cc != b)) {
					vec.at(i).at(j) = 0;
				}
			}
		}

	}
	//��l����
	if (bite == 3) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//�e��
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//call�̊e��
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				//3bite�ȊO�̏��O
				if ((ca == b && cb == c && cc == a) || (ca == c && cb == a && cc == b)) {
				}
				else vec.at(i).at(j) = 0;

			}
		}
	}

}



//main�֐�
int main() {
	//2�����z��vec���`(10*100)
	vector<vector<int>> vec(10, vector<int>(100));
	int call = 0;

	//vec��000~999����
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
			vec.at(i).at(j) = 100 * i + j;
		}
	}

	
	//�d���̏��O
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
			if(i == j/10 || j / 10 == j % 10 || j % 10 == i)/*�e�ʏd������*/{
				vec.at(i).at(j) = 0;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sort(vec.at(i).begin(), vec.at(i).end());
	}


	//�ȉ����[�v
	while (1) {
		//CALL
		fCALL(call);
		//EAT
		fEAT(vec, call);
		//BITE
		fBITE(vec, call);

		//�o�̓e�X�g
		system("cls");
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				if (vec.at(i).at(j) != 0) {
					if (vec.at(i).at(j) < 100) {
						cout << "0";
					}
					cout << vec.at(i).at(j) << " ";
				}
			}
		}
		cout << endl;
	}

}