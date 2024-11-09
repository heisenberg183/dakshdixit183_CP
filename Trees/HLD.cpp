/*Daksh Dixit*/
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 1000000007;
// const int mod = 998244353;
#define inf 1000000000000000005
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define ff first
#define ss second
#define yes cout << "YES" <<endl
#define no cout << "NO" <<endl
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define print(x) cout<<x<<"\n"
#define fr(i,a,b) for(int i = a; i < b; i++)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define has_bits(bit_mask, x) ((bit_mask) & (1ULL << (x)))
#define turn_on_bit(bit_mask, x) (bit_mask |= (1ULL << (x)))
#define turn_off_bit(bit_mask, x) (bit_mask &= (~( 1ULL << (x))))
#define smallest_on_bit(bit_mask) (__builtin_ctzll(int)((bit_mask) & (~(bit_mask))))
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //greater<int> for descending set, also less_equal<int> which is ascending multiset 
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
//DEBUG
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" = "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(ordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
int MSB(int n){return 63-__builtin_clzll(n);}
int getIthbit(int n, int i){return ( n & ( 1 << i) ) == 0 ? 0 : 1;}
void setIthBit(int &n, int i){ n = n | (1 << i);}
void clearIthBit(int &n, int i){ n = n & ( ~(1 << i));}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int pwr(int a, int b) {a %= mod; int res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a){int arr[3];extendgcd(a, mod, arr); if(arr[2]!=1){return -1;}arr[0] =(arr[0]%mod + mod)%mod ;return arr[0];} //Modulo Inverse Exist only if gcd(a,m)=1;
int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
int mminvprime(int a){int ans = pwr(a, mod - 2); ans = (ans%mod+mod)%mod; return ans;} //If a,m are Coprime
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
bool revsort(int a, int b) {return a > b;}
pair<int,vector<int>> to_vector(int num){ string num_string = to_string(num); int sz = num_string.size(); vector<int> res(sz); for(int i=0;i<sz;i++){res[i] = num_string[i]-'0';}return mkp(sz,res);}
void google(int t) {cout << "Case #" << t << ": ";}
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_div(int a, int b) {a = a % mod; b = b % mod; return (mod_mul(a, mminvprime(b)) + mod) % mod;}  //only for prime m
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
// If this gives TLE copy approach from CSES Path Queries 2

vector<vi> edges;
// No need to change anything here
struct BinaryLifting {
	int n;
	int maxLog;
	int maxRequirement;
	vector<vector<int>> parent;
	vector<int> logValues;
	bool precomputedLogs = false;
	BinaryLifting(int n1, int requirement, int root) {
		n = n1;
		parent.resize(n);
		maxLog = log2(requirement + 1);
		maxRequirement = requirement;
		for (int i = 0; i < n; i++) {
			parent[i].resize(maxLog + 1);
			for (int j = 0; j <= maxLog; j++) {
				parent[i][j] = -1;
			}
		}
		fillParentTable(root);
		if (maxRequirement <= 1000000ll)
			precomputeLogs();
	}
	BinaryLifting() {}
	void fillParentTable(int root) {
		vector<bool> visited(n);
		dfsBinaryLifting(root, visited);
		int intermediate = -1;
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; j < n; j++) {
				intermediate = parent[j][i - 1];
				if (intermediate != -1) {
					parent[j][i] = parent[intermediate][i - 1];
				}
			}
		}
	}
	void dfsBinaryLifting(int root, vector<bool> &visited) {
		visited[root] = true;
		for (auto i : edges[root]) {
			if (!visited[i]) {
				parent[i][0] = root;
				dfsBinaryLifting(i, visited);
			}
		}
	}
	void precomputeLogs() {
		precomputedLogs = true;
		logValues.resize(maxRequirement + 1);
		logValues[1] = 0;
		for (int i = 2; i <= maxRequirement; i++) {
			logValues[i] = logValues[i / 2] + 1;
		}
	}
	int kthParent(int start, int k) {
		int a = start;
		while (k > 0) {
			int x = getLog(k);
			a = parent[a][x];
			if (a == -1)
				return a;
			k -= (1 << x);
		}
		return a;
	}
	int getLog(int x) {
		return precomputedLogs ? logValues[x] : log2(x);
	}
};
 
// No need to change anything here
struct LCA {
	int n;
	BinaryLifting *bl_object;
	vector<int> level;
	LCA(int n1, int root, BinaryLifting *bl) {
		n = n1;
		bl_object = bl;
		level.resize(n);
		dfsLCA(root, -1);
	}
	LCA() {}
	void dfsLCA(int root, int parent) {
		for (auto i : edges[root]) {
			if (i != parent) {
				level[i] = level[root] + 1;
				dfsLCA(i, root);
			}
		}
	}
	int getLCA(int a, int b) {
		if (level[a] > level[b]) {
			swap(a, b);
		}
		b = bl_object->kthParent(b, level[b] - level[a]);
		if (a == b)
			return a;
		for (int i = bl_object->maxLog; i >= 0; i--) {
			int parent1 = bl_object->parent[a][i];
			int parent2 = bl_object->parent[b][i];
			if (parent2 != parent1 && parent1 != -1 && parent2 != -1) {
				a = parent1;
				b = parent2;
			}
		}
		return bl_object->parent[a][0];
	}
};
 
 
template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<int> arr; // type may change
	int n;
	SegTree(int a_len, vector<int> &a) { // change if type updated
		arr = a;
		n = a_len;
		tree.resize(4 * n); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	SegTree() {}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, int val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};
 
struct Node1 {
	int val; // may change
	Node1() { // Identity element
		val = -inf;	// may change
	}
	Node1(int p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = max(l.val, r.val);  // may change
	}
};
 
struct Update1 {
	int val; // may change
	Update1(int p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};
 
 
template<typename Node, typename Update>
struct HLD {
	int n;
	int rootHere;
	vector<int> big_child;
	vector<int> subtree_sum;
	vector<int> chain;
	vector<int> label;
	vector<int> values;
	SegTree<Node, Update> s1;
	LCA *lca_object;
	BinaryLifting *bl_object;
	HLD(int n1, int root1, vector<int> &values1, LCA *lca) {
		n = n1;
		lca_object = lca;
		bl_object = lca->bl_object;
		rootHere = root1;
		big_child.resize(n);
		subtree_sum.resize(n);
		label.resize(n);
		chain.resize(n);
		values = values1;
		dfsPrecompute(rootHere, -1);
		int label_time = 0;
		dfsLabels(rootHere, -1, label_time);
		for (int i = 0; i < n; i++)
			chain[i] = i;
		dfsChains(rootHere, -1);
		s1 = SegTree<Node, Update>(n, values);
		for (int i = 0; i < n; i++) {
			s1.make_update(label[i], values[i]);
		}
		// debugHLD();
	}
	void dfsPrecompute(int root, int parent) {
		subtree_sum[root] = 1;
		big_child[root] = -1;
		int biggest = -1;
		for (auto i : edges[root]) {
			if (i != parent) {
				dfsPrecompute(i, root);
				subtree_sum[root] += subtree_sum[i];
				if (subtree_sum[i] > biggest) {
					big_child[root] = i;
					biggest = subtree_sum[i];
				}
			}
		}
	}
	void dfsLabels(int root, int parent, int &label_time) {
		label[root] = label_time++;
		if (big_child[root] != -1)
			dfsLabels(big_child[root], root, label_time);
		for (auto i : edges[root])
			if (i != parent && i != big_child[root])
				dfsLabels(i, root, label_time);
	}
	void dfsChains(int root, int parent) {
		if (big_child[root] != -1)
			chain[big_child[root]] = chain[root];
		for (auto i : edges[root])
			if (i != parent)
				dfsChains(i, root);
	}
	void debugHLD() {
		debug(big_child);
		debug(subtree_sum);
		debug(chain);
		debug(label);
		debug(values);
	}
	Node queryChain(int here, int toReach) {
		Node val = Node(0);
		int top;
		while (lca_object->level[here] > lca_object->level[toReach]) {
			top = chain[here];
			if (lca_object->level[top] <= lca_object->level[toReach])
				top = bl_object->kthParent(here, lca_object->level[here] - lca_object->level[toReach] - 1);
			Node a1 = val;
			Node a2 = s1.make_query(label[top], label[here]);
			val.merge(a1, a2);
			here = bl_object->parent[top][0];
		}
		return val;
	}
	int findAnswer(int u, int v) {
		int lca = lca_object->getLCA(u, v);
		Node n1 = queryChain(u, lca);
		Node n2 = queryChain(v, lca);
		Node merged;
		merged.merge(n1, n2);
		Node n3 = Node(s1.make_query(label[lca], label[lca]));
		Node ans;
		ans.merge(merged, n3);
		return ans.val;
	}
	void makeUpdateatIndex(int u, int val) {
		s1.make_update(label[u], val);
	}
};
 
// Change accordingly for edge weights instead of node values
void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> values(n);
	for (int i = 0; i < n; i++)
		cin >> values[i];
    edges.clear();edges.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a - 1].pb(b - 1);
		edges[b - 1].pb(a - 1);
	}
	BinaryLifting bl_object = BinaryLifting(n, n, 0);
	LCA lca_object = LCA(n,0, &bl_object);
	HLD<Node1, Update1> hld = HLD<Node1, Update1>(n,0, values, &lca_object);
    hld.debugHLD();
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			hld.makeUpdateatIndex(b - 1, c);
		} else {
			cout << hld.findAnswer(b - 1, c - 1) << " ";
		}
	}
}
 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
signed main(){
    fast;
    auto start1 = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE
    // freopen("shell.in", "r", stdin);
    // freopen("shell.out", "w", stdout);
    // #endif
    int t=1;
    // cin>>t; 
    for(int i=1;i<=t;i++){
        //google(i);
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/