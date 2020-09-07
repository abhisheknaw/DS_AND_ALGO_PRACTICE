#include <bits/stdc++.h>
using namespace std;

int main() 
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		int answer = 0;

		string chair;
		cin >> chair;

		for (int i = 0; i < n;) {
			if (chair[i] == '0') {
				int end = i + 1;
				for (int j = end; j < n; j++) {
					if (chair[j] == '0') {
						end = j + 1;
					}
					else {
						break;
					}
				}
				int empty = end - i;
			}
		}
	}


	return 0;
}