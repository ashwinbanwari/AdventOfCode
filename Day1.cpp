#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// part 1
    /*int ans = 0;
    int last = INT_MAX;
    int x;
    while (cin >> x) {
    	if (x > last) ans++;
    	last = x;
    }
    cout << ans << endl;*/

    // part 2
    int ans = 0;
  	vector<int> input;
  	int x;
  	while (cin >> x) {
  		input.push_back(x);
  	}
  	for (int i = 3; i < input.size(); i++) {
  		if (input[i] > input[i-3]) ans++;
  	}
  	cout << ans << endl;

	return 0;
}