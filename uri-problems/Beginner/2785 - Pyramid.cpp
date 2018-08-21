#include <iostream>
#include <vector>

using namespace std;

int sum = 0;
vector<vector<int> > mtrx;
vector<int> cache; // cache[i] = guarda a soma até aquela linha (não a soma da linha isolada)

void solve(int i, int j, int qntd, int max) {

	int aux = 0;
	// cout << "mtrx[" << i << "][" << j << "] = " << mtrx[i][j] << endl;
	for (int j1 = j; j1 < j + qntd; j1++) {
		aux += mtrx[i][j1];
	}

	// cout << "aux: " << aux << endl;
	if (cache[i-1] + aux < cache[i]) {
		// cout << "cache i-1: " << cache[i-1] << " cache i: " << cache[i] << endl;
		cache[i] = cache[i-1] + aux;
	}

	if (i == 0) {
		cout << j << endl;
		return;
	}

	solve(i-1, j, qntd-1, max);
	solve(i-1, j+1, qntd-1, max);
}

int main() {

	int n;
	cin >> n;

	mtrx.assign(n, vector<int>(n));
	cache.assign(n, 99999);
	cache.at(n-1) = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mtrx[i][j];
		}
	}

	for (int j = 0; j < n; j++) {
		cache[n-1] += mtrx[n-1][j];
	}
	solve(n-2, 0, n-1, n);
	solve(n-2, 1, n-1, n);

	for (auto x : cache) {
		// cout << x << endl;
	}


	return 0;
}
