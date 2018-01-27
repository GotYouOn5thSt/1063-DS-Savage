#include <iostream>

using namespace std;


int main() {

	int  i = 0, j = 0, k = 1;
	int Nums[15][15];

	for (i = 0; i<15; i++) {
		for (j = 0; j<15; j++) {
			Nums[i][j] = k;
			k++;
		}
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << Nums[j][i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
