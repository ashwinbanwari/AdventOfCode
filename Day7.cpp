#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> nums;
    string num;
    while (getline(cin, num, ',')) {
    	nums.push_back(stoi(num));
    }
    double mean = accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
    cerr << mean << endl;
    int goal = lround(mean);
    int res = INT_MAX;
    for (int i = goal-1; i <= goal; i++) {
    	int currres = 0;
    	for (int n : nums) {
    		int val = abs(n-i);
	    	currres += (val * (val+1) / 2);
	    }
	    res = min(currres, res);
    }
    
    cout << res << endl;
	return 0;
}