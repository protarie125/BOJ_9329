#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int n, m;
		cin >> n >> m;

		auto group = map<int, int>{};
		for (auto g = 1; g <= m; ++g) {
			group[g] = -1;
		}

		auto value = map<int, ll>{};
		for (auto i = 0; i < n; ++i) {
			int k;
			cin >> k;

			while (0 < (k--)) {
				int p;
				cin >> p;

				group[p] = i;
			}

			cin >> value[i];
		}

		auto prs = vi(n, -1);
		for (auto j = 1; j <= m; ++j) {
			int ns;
			cin >> ns;

			const auto g = group[j];
			if (g < 0) {
				continue;
			}

			if (prs[g] < 0) {
				prs[g] = ns;
			}
			else {
				prs[g] = min(prs[g], ns);
			}
		}

		auto ans = ll{ 0 };
		for (auto i = 0; i < n; ++i) {
			if (0 < prs[i]) {
				ans += value[i] * prs[i];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}