#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool comp (int64_t a, int64_t b) {
    return a > b;
}
int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), comp);

//    for (int i = 0; i < n; ++i) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
    cout << max(a[0] * a[1], a[a.size() - 1] * a[a.size() - 2]);

    return 0;
}