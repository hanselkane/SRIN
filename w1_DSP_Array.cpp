int divisibleSumPairs(int n, int k, vector<int> ar) {
    int numpair=0;
    int cont [k] = {0};
    
    for(int &el:ar){
        numpair+=cont[(k-el%k)%k];
        cont[el%k]++;
    }
    
    return numpair;
}