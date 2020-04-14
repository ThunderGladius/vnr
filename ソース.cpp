#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;



//fCALL関数
void fCALL(int &call) {
		cout << "CALLした数値を入力して下さい" << endl;
		cin >> call;
}



//fEAT関数
void fEAT(vector<vector<int>> &vec, int call) {
	int eat;
	//入力
	while (1) {
		cout << "EAT数を入力して下さい" << endl;
		cin >> eat;
		if (eat < 3) break;
		else cout << "再入力して下さい" << endl;
	}
	//第一分岐
	if(eat == 0){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				//1桁以上一致の除外
				if (call / 100 == a) vec.at(i).at(j) = 0;
				if ((call % 100) / 10 == b) vec.at(i).at(j) = 0;
				if ((call % 100) % 10 == c)vec.at(i).at(j) = 0;
			}
		}
	}
	//第二分岐
	if(eat == 1){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				//2桁以上一致の除外
				if ((call / 100 == a && (call % 100) / 10 == b)
					|| ((call % 100) / 10 == b && (call % 100) % 10 == c)
					|| ((call % 100) % 10 == c && call / 100 == a)) vec.at(i).at(j) = 0;
				//不一致の除外
				if (call / 100 != a && (call % 100) / 10 != b
					 && (call % 100) % 10 != c) vec.at(i).at(j) = 0;
			}
		}
	}
	//第三分岐
	if(eat == 2){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				//1桁一致の除外
				if (((call / 100 == a && (call % 100) / 10 != b) && ((call % 100) % 10 != c)) 
				 || ((call / 100 != a && (call % 100) / 10 == b) && ((call % 100) % 10 != c)) 
				 || ((call / 100 != a && (call % 100) / 10 != b) && ((call % 100) % 10 == c))) vec.at(i).at(j) = 0;

				//不一致の除外
				if (call / 100 != a && (call % 100) / 10 != b
					&& (call % 100) % 10 != c) vec.at(i).at(j) = 0;
			}
		}
		
	}
	//第四分岐
	if (eat == 3) cout << "You win!" << endl;
}


//fBITE関数
void fBITE(vector<vector<int>>& vec, int call) {
	int bite;
	//入力
	while (1) {
		cout << "BITE数を入力して下さい" << endl;
		cin >> bite;
		if (bite <= 3) break;
		else cout << "再入力して下さい" << endl;
	}
	//第一分岐ok
	if (bite == 0) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//callの各位
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				//1以上のbiteの除外
				if (ca == b || ca == c || cb == a || cb == c || cc == a || cc == b) vec.at(i).at(j) = 0;

			}
		}
	}
	//第二分岐
	if (bite == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//配列要素の各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//callの各位
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				if (((ca == b || ca == c) && (cb != a && cb != c) && (cc != a && cc != b )) ||
					((ca != b && ca != c) && (cb == a || cb == c) && (cc != a && cc != b)) ||
					((ca != b && ca != c) && (cb != a && cb != c) && (cc == a || cc == b)) ) {
				}
				else vec.at(i).at(j) = 0;

			}
		}
	}
	//第三分岐
	if (bite == 2) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//callの各位
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				if (((ca == b || ca == c) && (cb == a || cb == c) && (cc != a && cc != b)) ||
					((ca != b && ca != c) && (cb == a || cb == c) && (cc == a || cc == b)) ||
					((ca == b || ca == c) && (cb != a && cb != c) && (cc == a || cc == b))) {
				}
				else vec.at(i).at(j) = 0;
			}
		}

	}
	//第四分岐ok
	if (bite == 3) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				int a, b, c;//各位
				a = i, b = (vec.at(i).at(j) - 100 * i) / 10, c = (vec.at(i).at(j) - 100 * i) % 10;
				int ca, cb, cc;//callの各位
				ca = call / 100, cb = (call % 100) / 10, cc = (call % 100) % 10;

				//3bite以外の除外
				if ((ca == b && cb == c && cc == a) || (ca == c && cb == a && cc == b)) {
				}
				else vec.at(i).at(j) = 0;

			}
		}
	}

}



//main関数
int main() {
	//2次元配列vecを定義(10*100)
	vector<vector<int>> vec(10, vector<int>(100));
	int call = 0,pattern = 0;

	//vecに000~999を代入
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
			vec.at(i).at(j) = 100 * i + j;
		}
	}

	
	//重複の除外
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
			if(i == j/10 || j / 10 == j % 10 || j % 10 == i)/*各位重複判定*/{
				vec.at(i).at(j) = 0;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sort(vec.at(i).begin(), vec.at(i).end());
	}


	//以下ループ
	while (1) {
		pattern = 0;
		//CALL
		fCALL(call);
		//CALLされた数値を除外
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				if (vec.at(i).at(j) == call) vec.at(i).at(j) = 0;
			}
		}
		//EAT
		fEAT(vec, call);
		//BITE
		fBITE(vec, call);

		//出力
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

		//残りパターン数
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100 ; j++) {
				if (vec.at(i).at(j) != 0) pattern++;
			}
		}
		cout << "現在残り" << pattern << "通りです";
		cout << endl;
	}

}