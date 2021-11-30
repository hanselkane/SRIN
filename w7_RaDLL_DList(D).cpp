void printer(DoublyLinkedListNode* ll){
    for(; ll!=nullptr; ll=ll->next){
        cout<<ll->data<<", ";
    }
    cout<<endl;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    // printer(llist);
    if(llist==nullptr||llist->next==nullptr){
        return llist;
    }
    llist->prev=llist->next;
    llist->next=nullptr;
    llist=llist->prev;
    
    DoublyLinkedListNode* r;
    for(; llist!=nullptr; llist=llist->prev){
        if(llist->next==nullptr){
            r=llist;
        }
        swap(llist->next,llist->prev);
        // cout<<llist->data<<", ";
    }
    // printer(llist);
    return r;
}