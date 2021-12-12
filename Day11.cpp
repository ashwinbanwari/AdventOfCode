#include <bits/stdc++.h>

using namespace std;

long long DFS(int i, int j, vector<vector<int>>& octos, vector<vector<bool>>& flashed) {
	int N = octos.size();
	int M = octos[0].size();
	if (i < 0 || i >= N || j < 0 || j >= M || flashed[i][j] || octos[i][j] <= 9) {
		return 0;
	}
	int ans = 1;
	flashed[i][j] = 1;
	vector<pair<int, int>> mods = {{1, 0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1},{-1,1}};
	for (auto& p : mods) {
		int a = i+p.first;
		int b = j+p.second;
		if (!(a < 0 || a >= N || b < 0 || b >= M)) octos[a][b]++;
		ans += DFS(a, b, octos, flashed);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<vector<int>> octos;
    string s;
    while (cin >> s) {
    	octos.push_back(vector<int>());
    	for (char c : s) {
    		octos.back().push_back(c-'0');
    	}
    }
    int N = octos.size();
    int M = octos[0].size();
    int iter = 100;
    long long res = 0;
    int i;
    for (i = 1;; i++) {
    	vector<vector<bool>> flashed(N, vector<bool>(M, 0));
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			octos[i][j]++;
    		}
    	}
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			DFS(i, j, octos, flashed);
    		}
    	}
    	int numFlashed = 0;
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			if (flashed[i][j]) {
    				numFlashed++;
    				octos[i][j] = 0;
    			}
    		}
    	}
    	if (numFlashed == N*M) {
    		break;
    	}
    }
    cout << i << endl;
	return 0;
}