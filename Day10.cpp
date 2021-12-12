#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    vector<string> lines;
    while (cin >> s) {
    	lines.push_back(s);
    }
    unordered_map<char, char> closing{{'(', ')'}, {'<', '>'}, {'{', '}'}, {'[',']'}};
    unordered_map<char, int> value{{')',1}, {']',2}, {'}', 3}, {'>', 4}};
    //long long res = 0;
    vector<long long> scores;
    for (string s : lines) {
    	cerr << s << s << endl;
    	stack<char> stk;
    	bool good = true;
    	for (char c : s) {
    		if (closing.find(c)==closing.end()) {
    			if (stk.top() != c) {
    				//res += value[c];
    				good = false;
    				break;
    			} else {
    				stk.pop();
    			}
    		} else {
    			stk.push(closing[c]);
    		}
    	}
    	if (good) {
    		long long res = 0;
    		while (!stk.empty()) {
    			cerr << stk.size() << endl;
    			char c = stk.top();
    			res *= 5;
    			res += value[c];
    			stk.pop();
    		}
    		scores.push_back(res);
    	}
    }
    sort(scores.begin(), scores.end());

    cout << scores[scores.size() / 2] << endl;

	return 0;
}