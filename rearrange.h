void InitializeDeck(vector<Card>& OD){
    int VALUE=1, TYPE=1;
    for(int i=0; i<52; i++)
    {
        OD.push_back(Card(VALUE,TYPE));
        TYPE++;
        if(TYPE==5)
        {
            TYPE=1;
            VALUE++;
        }
    }
}

void Shuffle(vector<Card>& Deck, vector<Card> I){
    int n;
    cout<<"\nType random number to shuffle: ";cin>>n;
    int randomNumber, cardLeft=52;
    /*
    Have an original deck I:
    Choose randon number 'r', pick that r-th card and put it on top of the deck 
    */
    for(int i=0;i<52;i++)
    {
        randomNumber=(int)(n*abs(rand()%1000))%cardLeft;
        Deck.push_back(I[randomNumber]);
        I.erase(I.begin()+randomNumber);
        cardLeft--;
    }
    int i=0;
        cout<<"\n\t\t\t\t\t      [?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    while(i<8)
    {
        cout<<"\n\t\t\t\t\t     [[[?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t    [[[[[?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t   [?][[[[?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t  [?]]][[[[?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t [?]]]] [[[[?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t [[?]]] [[[?]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t [[[?]] [[?]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t  [[?]]][[?]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t   [[?]][?]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t    [?][?]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t     [?]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t      [?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        i++;
    }
    cout<<"\n\t\t\t\t\t      [?]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t     [?]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t    [?]]]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t   [?]]]]]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t  [?]]]]]]]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t [?]]]]]]]]]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t[?]]]]]]]]]]]]]    ";std::this_thread::sleep_for(std::chrono::milliseconds(50));cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

vector<Card> RearrangeDefault(vector<Card>& Hand){
    vector<Card> OriginalDeck; 
    InitializeDeck(OriginalDeck);

    vector<Card> decoy=Hand;
    Hand.clear();
    
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<decoy.size();j++)
        {
            if(decoy[j].GetValue()==OriginalDeck[i].GetValue()&&decoy[j].GetType()==OriginalDeck[i].GetType())
            {
                Hand.push_back(decoy[j]);
                decoy.erase(decoy.begin()+j);
                break;
            }
        }
    }
    return Hand;
}

vector<Card> RearrangeThirteen(vector<Card>& Hand){
    if(Hand.size()==0) return Hand;

    vector<Card> OriginalDeck; 
    InitializeDeck(OriginalDeck);
    for(int i=0;i<8;i++)
    {
        OriginalDeck.push_back(OriginalDeck[0]);
        OriginalDeck.erase(OriginalDeck.begin());
    }

    vector<Card> decoy=Hand;
    Hand.clear();
    
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<decoy.size();j++)
        {
            if(decoy[j].GetValue()==OriginalDeck[i].GetValue()&&decoy[j].GetType()==OriginalDeck[i].GetType())
            {
                Hand.push_back(decoy[j]);
                decoy.erase(decoy.begin()+j);
                break;
            }
        }
    }
    return Hand;
}