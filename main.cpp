#pragma optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using si = long long;
using ui = unsigned long long;
using flt = long double;
using ch = char;
using str = string;
template<class T>
using vec = vector<T>;

ifstream in{"input.txt"};
ofstream out{"output.txt"};

// vettori salvati di tutto le combinazioni di denaro (rimuoverlo dappertutto per ottimizzare)
stack<vec<si>> vettori;

si calc(vec<si>& stanze, si i) {
	sort(stanze.begin(), stanze.end());
	while (i<stanze.size() && stanze[i]==0) ++i;
	vettori.push(stanze);
	if(i>=stanze.size()-1) return 0;

	bool finished = false;
	for(int p = i; p != stanze.size()-1; ++p) {
		if (stanze[p] == stanze[p+1]) {
			stanze[p]--;
			stanze[p+1]++;
			finished = true;
			break;
		}
	}
	
	if (!finished) {
		stanze[i]--;
		stanze[i+1]++;
	}
	return 1 + calc(stanze, i);
}

int main() {
	si N;
	cin >> N;

	vec<si> stanze;
	stanze.resize(N, 1);
	cout << calc(stanze, 0) << endl;

	// SCOMMENTARE PER FAR SCRIVERE TUTTE LE POSSIBILITÀ (potrebbe metterci tanto)
	/*while(!vettori.empty()) {
		for (auto st = vettori.top().rbegin(); st != vettori.top().rend(); ++st)
			cout << *st << " ";
		cout << endl;
		vettori.pop();
	}*/
}