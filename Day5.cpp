#include <bits/stdc++.h>

using namespace std;

pair<int, int> getPair(string& s) {
	stringstream ss(s);
	string a;
	string b;
	getline(ss, a, ',');
	getline(ss, b, ',');
	return make_pair(stoi(a), stoi(b));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<vector<int>> area(1000, vector<int>(1000));
	//auto area = new int[1000][1000]();
	vector<vector<int>> lines;
	string a, b;
	while (cin >> a) {
		cin >> b >> b;
		pair<int, int> point1 = getPair(a);
		pair<int, int> point2 = getPair(b);
		lines.push_back({point1.first, point1.second, point2.first, point2.second});
	}
	for (vector<int> line : lines) {
		if (line[0] == line[2]) {
			// horizontal
			int mini = min(line[1], line[3]);
			int maxi = max(line[1], line[3]);
			for (int i = mini; i <= maxi; i++) {
				area[line[0]][i]++;
			}
		} else if (line[1] == line[3]) {
			// vertical
			int mini = min(line[0], line[2]);
			int maxi = max(line[0], line[2]);
			for (int i = mini; i <= maxi; i++) {
				area[i][line[1]]++;
			}
		} else {
			int deltaX = (line[0] > line[2]) ? -1 : 1;
			int deltaY = (line[1] > line[3]) ? -1 : 1;
			for (int i = line[0], j = line[1]; i != line[2]+deltaX; i += deltaX, j+= deltaY) {
				area[i][j]++;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (area[i][j] >= 2) count++;
		}
	}
	cout << count << endl;

    

	return 0;
}