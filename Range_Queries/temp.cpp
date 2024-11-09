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
