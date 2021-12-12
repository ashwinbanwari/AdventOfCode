#include <bits/stdc++.h>

using namespace std;

bool lowPoint(int i, int j, vector<vector<int>>& heatMap) {
	vector<pair<int, int>> mods = {{1,0},{0,1},{-1,0},{0,-1}};
	for (auto& p : mods) {
		int a = i+p.first;
		int b = j+p.second;
		if (a >= 0 && a < heatMap.size() && b >= 0 &&  b < heatMap[0].size()) {
			if (heatMap[i][j] >= heatMap[a][b]) {
				return false;
			}
		}
	}
	return true;
}

int DFS (int i, int j, vector<vector<int>> heatMap, vector<vector<int>>& seen) {
	if (!(i >= 0 && i < heatMap.size() && j >= 0 && j < heatMap[0].size()) || seen[i][j] || heatMap[i][j] == 9) {
		return 0;
	}
	seen[i][j] = 1;
	int ans = 1;
	vector<pair<int, int>> mods = {{1,0},{0,1},{-1,0},{0,-1}};
	for (auto &p : mods) {
		ans += DFS(i+p.first, j+p.second, heatMap, seen);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<vector<int>> heatMap;
    string ln;
    while (cin >> ln) {
    	heatMap.push_back(vector<int>());
    	for (char c : ln) {
    		heatMap.back().push_back(c-'0');
    	}
    }
    vector<int> largests;
    for (int i = 0; i < heatMap.size(); i++) {
    	for (int j = 0; j < heatMap[0].size(); j++) {
    		if (lowPoint(i, j, heatMap)) {
    			vector<vector<int>> seen(heatMap.size(), vector<int>(heatMap[0].size(), 0));
    			largests.push_back(DFS(i, j, heatMap, seen));
    		}
    	}
    }
    sort(largests.begin(), largests.end());
    if (largests.size() < 3) {
    	cout << -1 << endl;
    }
    cerr << largests.size() << endl;
    for (auto it = largests.begin(); it != largests.end(); it++) {
    	cerr << *it << endl;
    }
    cout << accumulate(largests.end()-3, largests.end(), 1, multiplies<int>()) << endl;


	return 0;
}