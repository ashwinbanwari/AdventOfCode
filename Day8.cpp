#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    int count = 0;
    while (getline(cin, line)) {
    	map<set<int>, int> m;
    	map<int, set<int>> mRev;
    	set<set<int>> possibles;
    	stringstream ss(line);
    	string tok;
    	while (ss >> tok) {
    		if (tok == "|") break;
    		possibles.insert(set<int>(tok.begin(), tok.end()));
    	}
    	for (const set<int>& s : possibles) {
    		if (s.size() == 2) {
    			m[s] = 1;
    			mRev[1] = s;
    		} else if (s.size() == 4) {
    			m[s] = 4;
    			mRev[4] = s;
    		} else if (s.size() == 3) {
    			m[s] = 7;
    			mRev[7] = s;
    		} else if (s.size() == 7) {
    			m[s] = 8;
    			mRev[8] = s;
    		}
    	}
    	for (const set<int>& s : possibles) {
    		if (s.size() == 6) {
    			set<int> one = mRev[1];
    			int a = *one.begin();
    			int b = *next(one.begin());
    			set<int> four = mRev[4];
    			auto it = four.begin();
    			int w = *it;
    			it++;
    			int x = *it;
    			it++;
    			int y = *it;
    			it++;
    			int z = *it;
    			if (s.count(a) + s.count(b) != 2) {
    				m[s] = 6;
    				mRev[6] = s;
    			} else if (s.count(w)+s.count(x)+s.count(y)+s.count(z) == 4) {
    				m[s] = 9;
    				mRev[9] = s;
    			} else {
    				m[s] = 0;
    				mRev[0] = s;
    			}
    		} else if (s.size() == 5) {
    			set<int> one = mRev[1];
    			int a = *one.begin();
    			int b = *next(one.begin());
    			set<int> four = mRev[4];
    			auto it = four.begin();
    			int w = *it;
    			it++;
    			int x = *it;
    			it++;
    			int y = *it;
    			it++;
    			int z = *it;
    			if (s.count(a)+s.count(b) == 2) {
    				m[s] = 3;
    				mRev[3] = s;
    			} else if (s.count(w)+s.count(x)+s.count(y)+s.count(z) == 3) {
    				m[s] = 5;
    				mRev[5] = s;
    			} else {
    				m[s] = 2;
    				mRev[2] = s;
    			}
    		}
    	}
    	string numero;
    	while (ss >> tok) {
    		set<int> thisNum(tok.begin(), tok.end());
    		numero += to_string(m[thisNum]);
    	}
    	count += stoi(numero);
    }
    cout << count << endl;



	return 0;
}