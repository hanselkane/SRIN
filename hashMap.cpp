struct Destination {
    string city;
    int price;
    
    Destination(string inCity, int inPrice){
        city=inCity;
        price=inPrice;
    }
    
    bool operator==(const Destination &d) const {
        return city == d.city && price == d.price;
    }
};

class MyHashFunction {
    public:
        int operator()(const Destination &d) const {
            return d.city.length();
        }
};

int lonelyinteger(vector<int> a) {
    unordered_map<Destination, int, MyHashFunction> um;
    
    Destination des1("Jakarta",5000);
    Destination des2("Bandung",3000);
    Destination des3("Bekasi",2000);
    
    um[des1]=2;
    um[des2]=1;
    um[des3]=2;
    
    //Count for profit
    int sum=0;
    for(auto &x:um){
        sum+=x.first.price*x.second;
    }
    
    cout<<"Total Profit: "<<sum<<endl;
    
    return 0;
}