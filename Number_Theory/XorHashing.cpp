// Converts an array to a random mapping then we can use this mapping for random xor hashing where if xor of range equal then range equal.
// Without this hashing if xor(1,2) = xor(3) so we cant say xor of range equal then range equal, but with this assumption is mostly true.

map<unsigned long long, unsigned long long> mapping;
set<unsigned long long> used = {0};
for (auto &c : arr){
    unsigned long long random;
    if (!mapping.count(c)){
        do{
            random = getRandomNumber(0,N);
        }while (used.count(random));
        used.insert(random);
        mapping[c] = random;
    }else{
        random = mapping[c];
    }
    c = random;
}