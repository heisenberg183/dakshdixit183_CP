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
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //greater<int> for descending set, also less_equal<int> which is ascending multiset
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
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(ordered_set v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
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

//Segment Trees Consist of 2 points in each node vector<node>, vector<update> 
//node stores the value we want to query and update stores the update we need to make when called

struct node
{
	int sum;
	node(){
        //1.Identity Element :- the element I such that merge(x,I) = x (for all x)
        sum=0;  
    }
	node(int val){
        //2. Value of Leaf Nodes  
		this->sum=val;
	}

    // 3.Store the thing you wanna query
	void merge(const node &l,const node &r){
		sum = l.sum+r.sum;   //Change 3
	}
};


struct update
{   //Current Update Values
	int v;
	update(){
        //4. Identity Transformation :- the element I such that combine(x,I) = x (for all x)
        v=0;
    }
	update(int val){ 
        //5. Value of Leaaf Nodes
		this->v = val;
	}
	//6.Combine the current update with the other update
    //Other update is passed as parameter to this update and this update values are updated]
	void combine(update &other,const int32_t &tl,const int32_t &tr){
		v += other.v; // Change 6
		// you can be sure that the "other" is newer than current
	}

	//7.Store the correct information in the node x
    //What the Node will store after applying the current update
	void apply(node &x,const int32_t &tl,const int32_t &tr){
		x.sum += (tr-tl+1)*v;
	}
};

template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}
	
	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}
	
	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
	
	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}
	
	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};


void solve(){
    int n,m;
    cin>>n>>m;
    segtree<node,update> st(n);
    vi arr(n,0);
    st.build(arr);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int l,r,val;
            cin>>l>>r>>val;
            r--;
            st.rupd(l,r,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            r--;
            cout<<st.query(l,r).sum<<endl;
        }
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
signed main(){
    fast;
    auto start1 = high_resolution_clock::now();
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

