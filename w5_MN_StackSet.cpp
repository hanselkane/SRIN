vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    set<int> result; 
    stack<int> stArr;
    
    for(int i=arr.size()-1; i>=0; i--){
        stArr.push(arr[i]);
    }

    int a=0;
    for(int b=0; b<brr.size(); b++){
        if(stArr.top()==brr[b]){
            stArr.pop();
        } else if (stArr.top()>brr[b]){
            result.insert(brr[b]);
        }
    }
    
    vector<int> finale;
    for(auto &x: result){
        finale.push_back(x);
    }
    
    return finale;
}