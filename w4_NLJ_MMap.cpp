string kangaroo(int x1, int v1, int x2, int v2) {
    multimap<int, int> instance;
    // vector<int> a={1,2,34,4};
    // partition(a.begin(), a.end(),[](int i){return i % 2 == 0;});
    
    for(int t=0; t<10001; t++){
        x1+=v1;
        x2+=v2;
        instance.emplace(x1,x2);
    }
    
    multimap <int, int> :: iterator itr;
    for(itr=instance.begin(); itr!=instance.end(); itr++){
        if(itr->first==itr->second){
            return "YES";
        }
    }
    
    return "NO";
}