#include <bits/stdc++.h>
using namespace std;

bool isPermutationSubstring(const string &p, const string &h) {
    int n = p.size(), m = h.size();
    if (n > m) return false;

    vector<int> freq_p(26, 0), freq_window(26, 0);
    for (char c : p) freq_p[c - 'a']++;

    for (int i = 0; i < m; ++i) {
        freq_window[h[i] - 'a']++;
        if (i >= n) freq_window[h[i - n] - 'a']--;
        if (i >= n - 1 && freq_window == freq_p) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string p, h;
        cin >> p >> h;
        cout << (isPermutationSubstring(p, h) ? "YES" : "NO") << '\n';
    }
    return 0;
}
