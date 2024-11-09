struct st{
public:
    vi s,smin = {LLONG_MAX},smax = {LLONG_MIN};

    void push(int x){
        s.pb(x);
        smin.pb(min(smin.back(),x));
        smax.pb(max(smax.back(),x));
    }

    int pop(){
        int res = s.back();
        s.ppb();
        smin.ppb();
        smax.ppb();
        return res;
    }

    bool empty(){
        return s.empty();
    }
 
    int minval(){
        return smin.back();
    }

    int maxval(){
        return smax.back();
    }
};

st s1,s2;
//Here add and remove operations are like queue push ans pop we implemented it just by using 2 stacks
//This is min max queue that will give the max and minvalues that are inserted inside the queue
auto add = [&](int x){
    s2.push(x);
};

auto remove = [&](){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
};

auto good = [&](){
    int mn = min(s1.minval(),s2.minval());
    int mx = max(s1.maxval(),s2.maxval());
    return mx-mn<=k;
};