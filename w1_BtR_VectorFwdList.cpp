vector<int> breakingRecords(forward_list<int> scores) {
    int max=*scores.begin(); int min=*scores.begin(); int counter[2]={0};
    
    forward_list<int>::iterator i = scores.begin();
    
    while(i != scores.end()){
        if(max<*i){
            max=*i;
            counter[0]+=1;
        } else if (*i<min) {
            min=*i;
            counter[1]+=1;
        }
        advance(i, 1);
    }
    vector<int> result;
    result.push_back(counter[0]); 
    result.push_back(counter[1]);
    return result;
}