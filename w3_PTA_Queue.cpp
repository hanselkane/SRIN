string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    
    queue<int> qA;
    queue<int> qB;
    
    // Fill queue
    for(int i=0; i<A.size(); i++){
        qA.push(A[i]);
        qB.push(B[i]);
    }
    
    for(int i=0; i<A.size(); i++){
        if(qA.front()+qB.front()<k){return "NO";}
        qA.pop(); qB.pop();
    }
    return "YES";
}