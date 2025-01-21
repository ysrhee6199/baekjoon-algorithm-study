#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll cnt;

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<ll> primes;
    for (ll i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    // 투 포인터 방식으로 연속된 소수의 합 계산
    ll start = 0, end = 0, sum = 0;
    while (true) {
        if(sum>=n) sum -= primes[start++];
        else if(end == primes.size()) break;
        else sum += primes[end++];
        if(sum == n) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
