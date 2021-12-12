#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int h = 0, v = 0, aim = 0;
    string w;
    while (cin >> w) {
    	int x;
    	cin >> x;
    	switch(w[0]) {
    		case 'f':
    			h += x;
    			v += aim * x;
    			break;
    		case 'u':
    			aim -= x;
    			break;
    		default:
    			aim += x;
    			break;
    	}
    }
    cout << h*v << endl;



	return 0;
}