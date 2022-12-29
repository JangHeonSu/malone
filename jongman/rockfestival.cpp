#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;

	cin >> c;

	for (int i = 0; i < c; i++)
	{
		double l, n, a,min=111111;
		vector<int> v;
		cin >> n >> l;
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			v.push_back(a);
		}

		while (l <= n)
		{
			a = 0;
			for (int j = 0; j < l; j++)
			{
				a += v[j];
			}
			if(min>a/l)
				min = a/l;

			for (int j = 1; j < n - (l - 1); j++)
			{
				a = 0;
				for (int k = j; k < j + l; k++)
				{
					a += v[k];
				}
				if (min > a/l)
					min = a/l;
			}
			l++;
		}
		cout << fixed;
		cout.precision(9);
		cout << min <<'\n';
	}

	return 0;
}
