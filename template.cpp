#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int INF = 1e9;

/*
 * This function is ceil() but uses interger divison to avoid dealing with
 * floating points and precision error.
 * @param a Numerator.
 * @param b Denomerator.
 * @return a whole number
 * Source: https://codeforces.com/blog/entry/121968
 */
ll divceil(ll a, ll b) { return a / b + (a % b > 0); }
ll divfloor(ll a, ll b) { return a / b - (a % b < 0); }

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

void solve() {}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
