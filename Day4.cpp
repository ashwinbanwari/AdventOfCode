#include <bits/stdc++.h>

using namespace std;

bool solved(vector<vector<int>> bits) {
	for (int i = 0; i < 5; i++) {
		bool good1 = 1;
		bool good2 = 1;
		for (int j = 0; j < 5; j++) {
			good1 &= bits[i][j];
			good2 &= bits[j][i];
		}
		if (good1 || good2) return true;
	}
	return false;
}

int solvedAt(vector<vector<int>>& board, vector<int>& nums) {
	vector<vector<int>> bits(5, vector<int>(5, 0));
	for (int k = 0; k < nums.size(); k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i][j] == nums[k]) {
					bits[i][j] = 1;
				}
			}
		}
		if (solved(bits)) return k+1;
	}
	return INT_MAX;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string line1;
    getline(cin, line1);
    stringstream ss(line1);
    string s;
    vector<int> order;
    while (getline(ss, s, ',')) {
    	cerr << s << endl;
    	order.push_back(stoi(s));
    }
    vector<vector<vector<int>>> boards;
    int i = 25;
    int x;
    while (cin >> x) {
    	if (i==25) {
    		boards.push_back(vector<vector<int>>(5,vector<int>(5)));
    		i=0;
    	}
    	boards.back()[i/5][i%5]=x;
    	i++;
    }
    int maxSolvedAt = 0;
    vector<vector<int>>* bestBoard;
    for (vector<vector<int>>& board : boards) {
    	int timeTaken = solvedAt(board, order);
    	cerr << "timeTaken: " << timeTaken << endl;
    	if (timeTaken > maxSolvedAt) {
    		maxSolvedAt = timeTaken;
    		bestBoard = &board;
    	}
    }
    vector<vector<int>>& ansBoard = *bestBoard;
    unordered_set<int> numsCalled (order.begin(), order.begin() + maxSolvedAt);
    int sum = 0;
    for (int i = 0; i < 5; i++) {
    	for (int j = 0; j < 5; j++) {
    		if (numsCalled.find(ansBoard[i][j]) == numsCalled.end()) {
    			sum += ansBoard[i][j];
    		}
    	}
    }
    int lastNum = order[maxSolvedAt-1];
    cerr << sum << " * " << lastNum << endl;
    cout << sum * lastNum << endl;

	return 0;
}