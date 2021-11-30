string counterGame(long n) {
    bitset<64> myBit = n; bool louise=true;
    cout<<myBit<<endl;
    while(true){
        int ideal=0; int firstpos=0;
        for(int i=63; i>-1; i--){
            if(myBit[i]==1){
                if(ideal==0){
                    firstpos=i;
                    cout<<"FP:"<<firstpos<<endl;
                }
                ideal++;
                cout<<"Ideal: "<<ideal<<endl;
            }
        }
        if(ideal==1){
            cout<<"Ideal"<<endl;
            if(firstpos%2==0){
                if(louise){return "Richard";}
                else{return "Louise";}
            } else {
                if(louise){return "Louise";}
                else{return "Richard";}
            }
        } else {
            myBit.flip(firstpos);
            louise=!louise;
        }
        cout<<"myBit: "<<myBit<<endl<<endl;
    }
}