int sockMerchant(int n, vector<int> ar) {
    int current=0; int quant=0;
    while(ar.size()!=0){
        // First of all, lets take 1
        current=ar[0];
        ar.erase(ar.begin());
        // Check
        sort(ar.begin(),ar.end(),greater<int>());
        if(binary_search(ar.begin(),ar.end(),current,greater<int>())){
        for(int j=0; j<ar.size(); j++){
            if(ar[j]==current){
                quant++;
                ar.erase(ar.begin()+j);
                break;
            }
        }}
    }
    return quant;
}