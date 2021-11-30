struct MyComparator {
    bool operator()(pair<string,int> const& a, pair<string,int> const& b){
        return (a.second>b.second);
    }
};

void plusMinus(vector<int> arr) {
    priority_queue<pair<string,int>, vector<pair<string,int>>, MyComparator> pq;
    pq.push({"John",2});
    pq.push({"Erica",7});
    pq.push({"Kusuma",5});
    pq.push({"Thomas",1});
    
    for(; !pq.empty(); pq.pop()){
        cout<<pq.top().first<<", ";
    }
}