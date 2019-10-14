/*~~~~~~~~~~~~~~~~~~~~~~~*/
/*                       */
/*                       */
/*                       */
/*      ©raisinten       */
/*      Darshan Sen      */
/*                       */
/*                       */
/*                       */
/*~~~~~~~~~~~~~~~~~~~~~~~*/

#include<bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define pb push_back
#define ins insert
#define mp make_pair
#define len(s) s.length()
#define repii(i,l,r)	for(i = l; i <= r; ++i)
#define repin(i,l,r)	for(i = l; i <  r; ++i)
#define repdi(i,r,l)	for(i = r; i >= l; --i)
#define repdn(i,r,l)	for(i = r; i >  r; --i)
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(n,m) memset(n, m, sizeof(n))
#define pii pair<int, int >
#define pll pair<long long ,long long >
#define usuu unordered_set<unsigned >
#define usii unordered_set<int >
#define usll unordered_set<long long >
#define suu set<unsigned >
#define sii set<int >
#define sll set<long long >
#define vec vector
#define vuu vector<unsigned > 
#define vii vector<int > 
#define vbb vector<bool > 
#define vll vector<long long >
#define vlu vector<long long unsigned >
#define mll map<long long , long long >
#ifdef	_WIN32
#define gc	getchar
#else
#define gc	getchar_unlocked
#endif
#define ret return 0
#define what_is(x) cout << #x << " is: " << x << endl;

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MOD   1000000007
#define PI	  3.14159265358979323846

typedef long long   			ll;
typedef long long unsigned		llu;
typedef long double				ldo;
typedef double					db;

template <typename T>
void fs (T& x) {
	x ^= x;
	bool neg = false;
	register char ch = gc();
	while ((ch != '-') and (ch < '0' or ch > '9'))
		ch = gc();
	if (ch == '-') {
		neg = true;
		ch = gc();
	}
	for(; ch >= '0' and ch <= '9'; ch = gc())
		x = (x << 1) + (x << 3) + ch - 48;
	if (neg)
		x *= -1;
}

template <typename T>
void showc (T b, T e) {
	for (auto it = b; it != e; ++it)
		cout << (*it) << " ";
	cout << endl;
}

///////////////////////////////////////////////////////////


///////////////////FILL YOURSELF////////////////////////
#define NV 7
#define NE 10
const ll INF = INT_MAX;
int V[NV] = {
	0,
	INF,
	INF,
	INF,
	INF,
	INF,
	INF
};
int E[NE][3] = {
//	{S, E, W}
	{1, 2, 6},
	{1, 3, 5},
	{1, 4, 5},
	{2, 5, -1},
	{3, 2, -2},
	{3, 5, 1},
	{4, 3, -2},
	{4, 6, -1},
	{5, 7, 3},
	{6, 7, 3}
};
/////////////////END FILL YOURSELF//////////////////////

void BellmanFord (void ) {
	int i, j, k;
	repin (k, 1, NV) {
		repin (i, 0, NE) {
			V[E[i][1] - 1] = min(
				min (
					0LL + V[E[i][0] - 1] + E[i][2],
					INF
				),
				0LL + V[E[i][1] - 1]
			);
		}
	}
	repin (i, 0, NV)
		cout << i + 1 << "\t" << V[i] << endl;
}

int main()	{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	boost;

	BellmanFord();

	ret;
}
