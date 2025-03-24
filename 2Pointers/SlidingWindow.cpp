//General Method
void tempSolve(){
    int ans,val;
    for(int i=0;i<n;i++){
        int j = i-k;
        add(i);
        if(j>=0){
            remove(j);
        }
        if(i>=k-1){
            update(val,ans);
        }
    }
}

//Logic of Variable Size Sliding Window
for(int r=0,l=0;r<n;r++){
    add(arr[r]);
    while(!good()){
        remove();
        l++;
    }
    update(ans);
}