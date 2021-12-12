#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<long long> fishies(9);
    string s;
    while (getline(cin, s, ',')) {
    	int x = stoi(s);
    	fishies[x]++;
    }
    int days = 256;
    for (int i = 0; i < days; i++) {
    	vector<long long> newFishies(9);
    	newFishies[8] = fishies[0];
    	newFishies[6] = fishies[0];
    	for (int i = 1; i < 9; i++) {
    		newFishies[i-1] += fishies[i];
    	}
    	fishies = newFishies;
    }
    cout << accumulate(fishies.begin(), fishies.end(), 0LL) << endl;

	return 0;
}