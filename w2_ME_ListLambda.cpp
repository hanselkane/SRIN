int marsExploration(string s) {
    list<char> theChar;
    // Copy string'chars to doubly linked list
    for(int i=0; i<s.length(); i++){
        theChar.push_back(s[i]);
    }    
    
    int i=0; int counter=0;
    for_each(theChar.begin(), theChar.end(), [&i,&counter](char &c){
        if(i==0){if(c!='S'){counter++;}}
        if(i==1){if(c!='O'){counter++;}}
        if(i==2){if(c!='S'){counter++;}}
        i++;
        if(i==3){i=0;}
    });

    return counter;
}