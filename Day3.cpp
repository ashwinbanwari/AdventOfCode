#include <bits/stdc++.h>

using namespace std;

vector<int> getPopular(unordered_set<string> strs) {
	vector<int> ans(12);
	for (string s : strs) {
		for (int i = 0; i < s.size(); i++) {
    		ans[i] += (s[i] == '1') ? 1 : -1;
    	}
	}
	for (int& i : ans) {
    	if (i == 0) {
    		i = -1;
    	} else {
    		i = (i >= 0) ? 1 : 0;
    	}
    }
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//part 1
    /*string s;
    vector<int> ans(12);
    while (cin >> s) {
    	for (int i = 0; i < s.size(); i++) {
    		ans[i] += (s[i] == '1') ? 1 : -1;
    	}
    }
    s.clear();
    string v;
    for (int i = 0; i < ans.size(); i++) {
    	if (ans[i] >= 0) {
    		s.push_back('1');
    		v.push_back('0');
    	} else {
    		s.push_back('0');
    		v.push_back('1');
    	}
    }
    cout << stoi(s, nullptr, 2) * stoi(v, nullptr, 2); */

	vector<string> all;
	string s;
    while (cin >> s) {
    	all.push_back(s);
    }

    unordered_set<string> oxygenRatings(all.begin(), all.end());
    for (int i = 0; oxygenRatings.size() > 1; i++) {
    	unordered_set<string> newOxygenRatings;
    	vector<int> ans = getPopular(oxygenRatings);
    	for (string s : oxygenRatings) {
    		if ((ans[i] == -1 && s[i] == '1') || s[i]-'0' == ans[i]) {
    			newOxygenRatings.insert(s);
    		}
    	}
    	oxygenRatings = newOxygenRatings;
    	cerr << oxygenRatings.size() << endl;
    }
    cerr << *oxygenRatings.begin() << endl;

    unordered_set<string> co2Ratings(all.begin(), all.end());
    for (int i = 0; co2Ratings.size() > 1; i++) {
    	vector<int> ans = getPopular(co2Ratings);
    	unordered_set<string> newCo2Ratings;
    	for (string s : co2Ratings) {
    		if ((ans[i] == -1 && s[i] == '0') || s[i]-'0' == 1-ans[i]) {
    			newCo2Ratings.insert(s);
    		}
    	}
    	co2Ratings = newCo2Ratings;
    	cerr << co2Ratings.size() << endl;
    }
    cerr << *co2Ratings.begin() << endl;

    cout << stoi(*oxygenRatings.begin(), nullptr, 2) * stoi(*co2Ratings.begin(), nullptr, 2); 

	return 0;
}