
//SHOW TABLE
void ShowTableThirteen(vector<Card> Table, Player Players[], int i){

                        //---TABLE------------
    string  line1,      //  name0       name1
            line2,      //  [][][]       [][]
            line5l,     //  ... - Cards - (space)
            line5r,     //  (space) - Cards - ...
            line6,      //  (not use yet)
            line3,      //  []       [][][][]
            line4;      //  name3       name2
                        //--------------------

    string name0, name1, name2, name3;

    if(Players[0].Finished==true)
    {
        name0+=Players[0].name;
        name0+=" (Finished)";
    }
    else if(Players[0].InRound==false)
    {
        name0+=Players[0].name;
        name0+=" (Passed)";
    }
    else
    {
        name0+=Players[0].name;
    }

    if(Players[1].Finished==true)
    {
        name1+="(Finished) ";
        name1+=Players[1].name;
    }
    else if(Players[1].InRound==false)
    {
        name1+="(Passed) ";
        name1+=Players[1].name;
    }
    else 
    {
        name1+=Players[1].name;
    }

    if(Players[2].Finished==true)
    {
        name2+="(Finished) ";
        name2+=Players[2].name;
    }
    else if(Players[2].InRound==false)
    {
        name2+="(Passed) ";
        name2+=Players[2].name;
    }
    else
    {
        name2+=Players[2].name;
    }

    if(Players[3].Finished==true)
    {
        name3+=Players[3].name;
        name3+=" (Finished)";
    }
    else if(Players[3].InRound==false)
    {   
        name3+=Players[3].name;
        name3+=" (Passed)";
    }
    else
    {
        name3+=Players[3].name;
    }

    string hand[4];
    for(int i=0;i<4;i++)
    {   
        for(int j=0;j<Players[i].Hand.size();j++)
        {
            hand[i]+="[]";
        }
    }
    
    line1+=hand[0];
    for(int i=0;i<126-hand[0].size()-hand[1].size();i++)
    {
        line1+=" ";
    }
    line1+=hand[1];

    switch(i)
    {
        case(0):
        {
            line2+="< YOUR TURN >";
            for(int i=0;i<126-13;i++)
            {
                line2+=" ";
            }
            for(int i=0;i<126;i++)
            {
                line3+=" ";
            }
        } break;
        case(1):
        {
            for(int i=0;i<126-13;i++)
            {
                line2+=" ";
            }
            line2+="< YOUR TURN >";
            for(int i=0;i<126;i++)
            {
                line3+=" ";
            }
        } break;
        case(2):
        {
            for(int i=0;i<126;i++)
            {
                line2+=" ";
            }
            for(int i=0;i<126-13;i++)
            {
                line3+=" ";
            }
            line3+="< YOUR TURN >";
        } break;
        case(3):
        {
            for(int i=0;i<126;i++)
            {
                line2+=" ";
            }
            line3+="< YOUR TURN >";
            for(int i=0;i<126-13;i++)
            {
                line3+=" ";
            }
        } break;
    }

    line4+=hand[3];
    for(int i=0;i<126-hand[2].size()-hand[3].size();i++)
    {
        line4+=" ";
    }
    line4+=hand[2];

    for(int i=0;i<(126+4-7*Table.size())/2-4;i++)
    {
        line5r+=" ";
    }
    line5l=line5r+"   "; 
    if(Table[Table.size()-1].GetValue()!=0) 
    {
        line5l+=" ";
        if(Table.size()==1) line5r+=" ";
    }

    cout<<"\n-----TABLE----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|"<<setw(126/2)<<left<<name0<<setw(126/2)<<right<<name1<<"|";
    cout<<"\n|"<<line1<<"|";
    cout<<"\n|                                                                                                                              |";
    cout<<"\n|"<<line2<<"|";
    cout<<"\n|                                                                                                                              |";

    cout<<"\n|"<<line5l;
    for(int i=0;i<Table.size();i++)
        {
            Table[i].SymbolShow();
            cout<<"    ";
        }
    cout<<line5r<<"|";
    //cout<<"\n|"<<line6<<"|";

    cout<<"\n|                                                                                                                              |";
    cout<<"\n|"<<line3<<"|";
    cout<<"\n|                                                                                                                              |";
    cout<<"\n|"<<line4<<"|";
    cout<<"\n|"<<setw(126/2)<<left<<name3<<setw(126/2)<<right<<name2<<"|";
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------------";
}

int CheckWinImm(vector<Card> Hand){
    int COUNT[14]={};
    int DOUBLES=0, STRAIGHT=0;
    int FIVESTRAIGHTDOUBLE=0;
    int BLACKS=0, REDS=0;

    for(int i=0;i<13;i++)
    {
        COUNT[Hand[i].GetValue()]++;

        if(Hand[i].GetType()==1 || Hand[i].GetType()==2)
        BLACKS++;
        if(Hand[i].GetType()==3 || Hand[i].GetType()==4)
        REDS++;
    }

    for(int i=1;i<14;i++)
    {
        if(COUNT[i]!=0 && i!=2)
        STRAIGHT++;

        if(COUNT[i]==2 && COUNT[i]==3)
        DOUBLES++;

        if(COUNT[i]==4)
        DOUBLES+=2;
    }

    //CHECK 5 STRAIGHT DOUBLE
    for(int i=3;i<11;i++)
    {
        if(COUNT[i]>=2)
        {
            FIVESTRAIGHTDOUBLE++;
            if(FIVESTRAIGHTDOUBLE==5)
                return 5;

            continue;
        }
        FIVESTRAIGHTDOUBLE=0;
    }

    if(COUNT[2]==4)
    return 1;
    if(DOUBLES==6)
    return 2;
    if(STRAIGHT==12)
    return 3;
    if(REDS==13 || BLACKS==13)
    return 4;


    return 0;
}

//GAME THIRTEEN
string PlayThirteen(vector<Card> Deck){
    Player Players[4];
    int WinImm[4]; //WIN IMMEDIATELY

    cout<<"\n- Playing Thirteen -\n";
    
    cin.ignore();
    cout<<"\nName of the players:\n";
    cout<<"Player 1: ";getline(cin,Players[0].name);
    cout<<"Player 2: ";getline(cin,Players[1].name);
    cout<<"Player 3: ";getline(cin,Players[2].name);
    cout<<"Player 4: ";getline(cin,Players[3].name);

    // int N;
    // cout<<"How many players? ";cin>>N;
    string namelength[4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<Players[i].name.size();j++)
        {
            namelength[i]+=" ";
        }
    }
    
    cout<<"\n\n------------------------------!!!! INSTRUCTIONS !!!!------------------------------";
    cout<<"\n\nType the number under each of your cards to choose/unchoose it";
    cout<<"\n\nWhen you have done choosing the cards to play, type '-1' to play the chosen cards";
    cout<<"\n\nIf you want to skip/pass, type '0'";
    cout<<"\n\nHAVE FUN!\n\n";
    cout<<"\n\n----------------------------------------------------------------------------------";

    //GIVE CARDS FROM DECK TO PLAYERS
    for(int i=0;i<52;i++)
    {
        if(i%4==1){
            Players[1].Hand.push_back(Deck[i]);
        }else if(i%4==2){
            Players[2].Hand.push_back(Deck[i]);
        }else if(i%4==3){
            Players[3].Hand.push_back(Deck[i]);
        }else if(i%4==0){
            Players[0].Hand.push_back(Deck[i]);
        }
    }

    RearrangeThirteen(Players[0].Hand);
    RearrangeThirteen(Players[1].Hand);
    RearrangeThirteen(Players[2].Hand);
    RearrangeThirteen(Players[3].Hand);

    
    if(CheckWinImm(Players[0].Hand)>0 || CheckWinImm(Players[1].Hand)>0 || CheckWinImm(Players[2].Hand) || CheckWinImm(Players[3].Hand)>0)
    {
        cout<<"\n\n!!!!IMMIDIATELY WINNNN!!!!";
        cout<<"\n\nInitial cards:   "<<Players[0].name<<"    "<<Players[1].name<<"    "<<Players[2].name<<"    "<<Players[3].name<<endl;
        for(int i=0;i<13;i++)
        {
            cout<<"              "<<namelength[0];
            Players[0].Hand[i].SymbolShow();cout<<" "<<namelength[1];
            Players[1].Hand[i].SymbolShow();cout<<" "<<namelength[2];
            Players[2].Hand[i].SymbolShow();cout<<" "<<namelength[3];
            Players[3].Hand[i].SymbolShow();
            cout<<endl;
        }
        return 0;
    }

    //JUST SAVE THE INITIAL HANDS
    vector<Card> InitialHand0, InitialHand1, InitialHand2, InitialHand3;
    for(int i=0;i<13;i++)
    {
        InitialHand0.push_back(Players[0].Hand[i]);
        InitialHand1.push_back(Players[1].Hand[i]);
        InitialHand2.push_back(Players[2].Hand[i]);
        InitialHand3.push_back(Players[3].Hand[i]);
    }

    //HAVE 3♠︎ (OR PRIORITIZED)
    int first;
    //CHECK IF HAVE 3♠︎
    for(int i=0;i<13;i++)
    {
        if(Players[0].Hand[i].GetValue()==3&&Players[0].Hand[i].GetType()==1)
        {
            first=0;
            break;
        }
        if(Players[1].Hand[i].GetValue()==3&&Players[1].Hand[i].GetType()==1)
        {
            first=1;
            break;
        }
        if(Players[2].Hand[i].GetValue()==3&&Players[2].Hand[i].GetType()==1)
        {
            first=2;
            break;
        }
        if(Players[3].Hand[i].GetValue()==3&&Players[3].Hand[i].GetType()==1)
        {
            first=3;
            break;
        }
    }

    vector<Card> Table;
    vector<Card> TableHistory;
    vector<string> PlayerMoveHistory;

    Table.push_back(Card(0,0));

    for(int i=0;i<4;i++)
    {
        Players[i].InRound=true;
        Players[i].Finished=false;
    }

    //START GAME: EVENT(OR SET CODE) = -1
    int event=-1;

    int PlayerLeft=4;
    bool newfirst=false; //END OF ROUND(ALL PLAYERS PASS)
    int countfalse=0;    //COUNT PASSES
    bool huongsoai=false;
    string sth;

    vector<string> ranking; 

    //MASTER LOOP - RUNNING THE GAME
    while(PlayerLeft>1){
        for(int i=first;i<4;i++)
        {
            if(Players[i].InRound==true && Players[i].Finished==false)          //IF NOT PASSED AND NOT COMPLETED -> MOVE
            {
                if(event==-1)
                    cout<<"\n\n! Player \'"<<Players[i].name<<"\' will start the game !\n\n";

                //SHOW TABLE:
                ShowTableThirteen(Table,Players,i);

                cout<<"\nPlayer \'"<<Players[i].name<<"\', type something to continue: ";cin>>sth;
                Players[i].ShowHand();
                event=Players[i].MoveThirteen(Table,event,ranking,PlayerLeft,huongsoai);

                //History update
                if(Players[i].InRound==true)
                    PlayerMoveHistory.push_back(Players[i].name);
                else
                    PlayerMoveHistory.push_back(Players[i].name+" (passed)");
                TableHistory.insert(TableHistory.end(),Table.begin(),Table.end());
                TableHistory.push_back(Card(-1,-1));

                if(PlayerLeft==1) goto gameover;
            }                                                       
            else;                                                               //IF PASSED

            for(int j=0;j<4;j++)                                                //CHECK HOW MANY PLAYERS HAVE PASSED IN THE ROUND
            {
                if(Players[j].InRound==false)
                {
                    countfalse++;
                }
            }

            if(Players[i].Finished==true && countfalse==PlayerLeft)             //SITUATION WHERE A PLAYER PLAY A SET AND FINISH BUT EVERYONE ELSE CANNOT CONTINUE THAT SET
            {
                for(int j=0;j<4;j++)                                            //GIVE PRIORITY TO THE NEXT UNFINISHED PLAYER
                {
                    if(Players[(i+j)%4].Finished==false)
                    {
                        cout<<"\nYou are now prioritize! Play any set.";
                        newfirst=true;
                        first=(i+j)%4;
                        event=0;
                        break;
                    }
                }
                for(int j=0;j<4;j++)                                            //EVERYONE IS NOW IN ROUND AGAIN
                {
                    Players[j].InRound=true;
                }
                break;
            }                                    
            else if(!huongsoai && countfalse==PlayerLeft-1)                     //EVERYONE PASSED(NOT IN ROUND) EXCEPT 1, THAT GUY WILL BE THE PRIORITY(EVENT=0)
            {
                for(int j=0;j<4;j++)                                            //CHECK WHO IS THAT GUY
                {
                    if(Players[j].InRound==true)                                //JUST 1 GUY IS TRUE AT THIS SITUATION
                    {
                        newfirst=true;                                          //END OF ROUND
                        first=j;                                                //MAKE THAT GUY PRIORITY
                        event=0;                                                //UPDATE EVENT=0
                    }           
                }
                for(int j=0;j<4;j++)                                            //EVERYONE IS NOW IN ROUND AGAIN
                {
                    Players[j].InRound=true;
                }
                break;
            }
            countfalse=0;                                                       //RESET COUNTER
        }
        if(newfirst)                                    //IF NEW ROUND:                      
        {
            //
            TableHistory.push_back(Card(0,0));

            newfirst=false;                             
            Table.clear();
            Table.push_back(Card(0,0));
            cout<<"\n\nNew round, play any set!\n";
            countfalse=0;
            huongsoai=false;
        }
        else                                            //IF NOT NEWROUND, SET FIRST BACK TO 0 -> 1 -> 2 -> 3 -> 0...
        {
            first=0;
        }
    }
    gameover:

    //PUT THE LAST PLAYER IN RANKING
    for(int i=0;i<4;i++)                                
    {
        if(Players[i].Finished==false)
        ranking.push_back(Players[i].name);
    }
    cout<<"\n    ! ! LEADERBOARD ! !";
    cout<<"\n============================";
    cout<<"\n| 1st: "<<ranking[0];
    cout<<"\n| 2nd: "<<ranking[1];
    cout<<"\n| 3rd: "<<ranking[2];
    cout<<"\n| 4th: "<<ranking[3];
    cout<<"\n============================";

    cout<<"\n\nType anything to view initial hands: ";cin>>sth;

    //SHOW INITIAL HANDS
    cout<<"\n\nInitial cards:   "<<Players[0].name<<"    "<<Players[1].name<<"    "<<Players[2].name<<"    "<<Players[3].name<<endl;
    for(int i=0;i<13;i++)
    {
        cout<<"              "<<namelength[0];
        InitialHand0[i].SymbolShow();cout<<" "<<namelength[1];
        InitialHand1[i].SymbolShow();cout<<" "<<namelength[2];
        InitialHand2[i].SymbolShow();cout<<" "<<namelength[3];
        InitialHand3[i].SymbolShow();
        cout<<endl;
    }

    cout<<"\n\nType anything to view history: ";cin>>sth;
    cout<<"\n\nHistory: \n";
    int indexCard=0;
    int indexPlayer=0;
    while(true)
    {
        if(TableHistory[indexCard].GetValue()!=0 && TableHistory[indexCard].GetValue()!=-1)
        {
            cout<<PlayerMoveHistory[indexPlayer]<<": ";
            while(TableHistory[indexCard].GetValue()!=0 && TableHistory[indexCard].GetValue()!=-1)
            {
                TableHistory[indexCard].SymbolShow();
                indexCard++;

                if(indexCard>=TableHistory.size())
                    break;
            }
            indexPlayer++;
            cout<<endl;
        }
        else
        {

        }
        cout<<"\n\n";
        indexCard++;

        if(indexCard>=TableHistory.size())
            break;
    }

    return "< GAME OVER >";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ShowTableBlackJack(Player Players[], int N){
    //  2   :   0   15
    //  3   :   0   6   9
    //  4   :   0   4   15  10  
    //  5   :   0   3   6   9   12 
    //  6   :   0   3   5   15  10  12
    //  7   :   0   2   5   7   8   11  13
    //  8   :   0   2   4   6   15  9   11  13
    //  9   :   0   1   3   5   7   8   10  12  14
    //  10  :   0   1   3   5   6   15  9   10  12  14
    //  11  :   0   1   3   5   6   7   8   9   10  12  14
    //  12  :   0   2   3   4   5   6   15  9   10  11  12  13
    //  13  :   0   2   3   4   5   6   7   8   9   10  11  12  13
    //  14  :   0   2   3   4   5   6   7   15  8   9   10  11  12  13
    //  15  :   0   1   2   3   4   5   6   7   8   9   10  11  12  13  14

    Player PlayersSeat[16];  

    int NameLength[16]={};
    int NumberCards[16]={};
    
    for(int i=0;i<16;i++)           //PlayersSeat index
    {
        for(int j=0;j<N;j++)        //Players index
        {
            if(Players[j].Seat==i)
            {
                PlayersSeat[i]=Players[j];
                NameLength[i]=PlayersSeat[i].name.size();
                NumberCards[i]=PlayersSeat[i].Hand.size();
                break;
            }
        }
    }

    for(int i=0;i<16;i++)
    {
        if(PlayersSeat[i].name.size()==0 || PlayersSeat[i].Revealed==0)
        PlayersSeat[i].BlackJackStatus="                    ";  
    } 
    string line[32];

    //LINE1:
    line[1]+="|";
    for(int i=0;i<10;i++)
        line[1]+=" ";
    line[1]+=PlayersSeat[6].name;
    for(int i=0;i<20-NameLength[6];i++)
    {
        if(PlayersSeat[6].name.size()==0)
            line[1]+=" ";                   
        else
            line[1]+=".";                   //
    }                     
    for(int i=0;i<5;i++)
        line[1]+=" ";
    line[1]+=PlayersSeat[7].name;
    for(int i=0;i<20-NameLength[7];i++)
    {
        if(PlayersSeat[7].name.size()==0)
            line[1]+=" ";                   
        else
            line[1]+=".";                   //
    }
    line[1]+=PlayersSeat[15].name;
    for(int i=0;i<20-NameLength[15];i++)
    {
        if(PlayersSeat[15].name.size()==0)
            line[1]+=" ";
        else
            line[1]+=".";                   //
    }
    line[1]+=PlayersSeat[8].name;
    for(int i=0;i<20-NameLength[8];i++)
    {
        if(PlayersSeat[8].name.size()==0)
            line[1]+=" ";                   
        else
            line[1]+=".";                   //
    }
    for(int i=0;i<5;i++)
        line[1]+=" ";
    line[1]+=PlayersSeat[9].name;
    for(int i=0;i<20-NameLength[9];i++)
    {
        if(PlayersSeat[9].name.size()==0)
            line[1]+=" ";                   
        else
            line[1]+=".";                   //
    }
    for(int i=0;i<10;i++)
        line[1]+=" ";
    line[1]+="|";

    //LINE2:
    line[2]+="|";
    for(int i=0;i<10;i++)
        line[2]+=" ";
    for(int i=0;i<PlayersSeat[6].Hand.size();i++)
    {
        if(PlayersSeat[6].Revealed==0)
        line[2]+="[?] ";
        else if(PlayersSeat[6].Revealed>0)
        line[2]+=PlayersSeat[6].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[6];i++)
        line[2]+="    ";
    for(int i=0;i<5;i++)
        line[2]+=" ";
    for(int i=0;i<PlayersSeat[7].Hand.size();i++)
    {
        if(PlayersSeat[7].Revealed==0)
        line[2]+="[?] ";
        else if(PlayersSeat[7].Revealed>0)
        line[2]+=PlayersSeat[7].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[7];i++)
        line[2]+="    ";
    for(int i=0;i<PlayersSeat[15].Hand.size();i++)
    {
        if(PlayersSeat[15].Revealed==0)
        line[2]+="[?] ";
        else if(PlayersSeat[15].Revealed>0)
        line[2]+=PlayersSeat[15].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[15];i++)
        line[2]+="    ";
    for(int i=0;i<PlayersSeat[8].Hand.size();i++)
    {
        if(PlayersSeat[8].Revealed==0)
        line[2]+="[?] ";
        else if(PlayersSeat[8].Revealed>0)
        line[2]+=PlayersSeat[8].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[8];i++)
        line[2]+="    ";
    for(int i=0;i<5;i++)
        line[2]+=" ";
    for(int i=0;i<PlayersSeat[9].Hand.size();i++)
    {
        if(PlayersSeat[9].Revealed==0)
        line[2]+="[?] ";
        else if(PlayersSeat[9].Revealed>0)
        line[2]+=PlayersSeat[9].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[9];i++)
        line[2]+="    ";
    for(int i=0;i<10;i++)
        line[2]+=" ";
    line[2]+="|";

    //LINE3:
    line[3]+="|";
    for(int i=0;i<10;i++)
        line[3]+=" ";
    line[3]+=PlayersSeat[6].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[3]+=" ";
    line[3]+=PlayersSeat[7].BlackJackStatus;
    line[3]+=PlayersSeat[15].BlackJackStatus;
    line[3]+=PlayersSeat[8].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[3]+=" ";
    line[3]+=PlayersSeat[9].BlackJackStatus;
    for(int i=0;i<10;i++)
        line[3]+=" ";
    line[3]+="|";

//LINE4:
line[4]+="|                                                                                                                                  |";

    //LINE5:
    line[5]+="|";
    for(int i=0;i<5;i++)
        line[5]+=" ";
    line[5]+=PlayersSeat[5].BlackJackStatus;
    for(int i=0;i<130-(5+20+20+5);i++)
        line[5]+=" ";
    line[5]+=PlayersSeat[10].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[5]+=" ";
    line[5]+="|";

    //LINE6:
    line[6]+="|";
    for(int i=0;i<5;i++)
        line[6]+=" ";
    line[6]+=PlayersSeat[5].name;
    for(int i=0;i<20-NameLength[5];i++)
    {
        if(PlayersSeat[5].name.size()==0)
            line[6]+=" ";                   
        else
            line[6]+=".";                   //
    }
    for(int i=0;i<130-(5+20+20+5);i++)
        line[6]+=" ";
    for(int i=0;i<20-NameLength[10];i++)
    {
        if(PlayersSeat[10].name.size()==0)
            line[6]+=" ";                   
        else
            line[6]+=".";                   //
    }
    line[6]+=PlayersSeat[10].name;
    for(int i=0;i<5;i++)
        line[6]+=" ";
    line[6]+="|";

    //LINE7:
    line[7]+="|";
    for(int i=0;i<5;i++)
        line[7]+=" ";
    if(PlayersSeat[5].Hand.size()>=1)
    {
        if(PlayersSeat[5].Revealed==0)
        line[7]+="[?] ";
        else if(PlayersSeat[5].Revealed>0)
        line[7]+=PlayersSeat[5].Hand[0].CardShow()+" ";
    }
    else
        line[7]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[7]+=" ";
    if(PlayersSeat[10].Hand.size()>=1)
    {
        if(PlayersSeat[10].Revealed==0)
        line[7]+=" [?]";
        else if(PlayersSeat[10].Revealed>0)
        line[7]+=" "+PlayersSeat[10].Hand[0].CardShow();
    }
    else
        line[7]+="    ";
    for(int i=0;i<5;i++)
        line[7]+=" ";   
    line[7]+="|";

    //LINE8:
    line[8]+="|";
    for(int i=0;i<5;i++)
        line[8]+=" ";
    if(PlayersSeat[5].Hand.size()>=2)
    {
        if(PlayersSeat[5].Revealed==0)
        line[8]+="[?] ";
        else if(PlayersSeat[5].Revealed>0)
        line[8]+=PlayersSeat[5].Hand[1].CardShow()+" ";
    }
    else
        line[8]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[8]+=" ";
    if(PlayersSeat[10].Hand.size()>=2)
    {
        if(PlayersSeat[10].Revealed==0)
        line[8]+=" [?]";
        else if(PlayersSeat[10].Revealed>0)
        line[8]+=" "+PlayersSeat[10].Hand[1].CardShow();
    }
    else
        line[8]+="    ";
    for(int i=0;i<5;i++)
        line[8]+=" ";   
    line[8]+="|"; 

    //LINE9:
    line[9]+="|";
    for(int i=0;i<5;i++)
        line[9]+=" ";
    if(PlayersSeat[5].Hand.size()>=3)
    {
        if(PlayersSeat[5].Revealed==0)
        line[9]+="[?] ";
        else if(PlayersSeat[5].Revealed>0)
        line[9]+=PlayersSeat[5].Hand[2].CardShow()+" ";
    }
    else
        line[9]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[9]+=" ";
    if(PlayersSeat[10].Hand.size()>=3)
    {
        if(PlayersSeat[10].Revealed==0)
        line[9]+=" [?]";
        else if(PlayersSeat[10].Revealed>0)
        line[9]+=" "+PlayersSeat[10].Hand[2].CardShow();
    }
    else
        line[9]+="    ";
    for(int i=0;i<5;i++)
        line[9]+=" ";   
    line[9]+="|";

    //LINE10:
    line[10]+="|";
    for(int i=0;i<5;i++)
        line[10]+=" ";
    if(PlayersSeat[5].Hand.size()>=4)
    {
        if(PlayersSeat[5].Revealed==0)
        line[10]+="[?] ";
        else if(PlayersSeat[5].Revealed>0)
        line[10]+=PlayersSeat[5].Hand[3].CardShow()+" ";
    }
    else
        line[10]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[10]+=" ";
    if(PlayersSeat[10].Hand.size()>=4)
    {
        if(PlayersSeat[10].Revealed==0)
        line[10]+=" [?]";
        else if(PlayersSeat[10].Revealed>0)
        line[10]+=" "+PlayersSeat[10].Hand[3].CardShow();
    }
    else
        line[10]+="    ";
    for(int i=0;i<5;i++)
        line[10]+=" ";   
    line[10]+="|";

    //LINE11:
    line[11]+="|";
    for(int i=0;i<5;i++)
        line[11]+=" ";
    if(PlayersSeat[5].Hand.size()>=5)
    {
        if(PlayersSeat[5].Revealed==0)
        line[11]+="[?] ";
        else if(PlayersSeat[5].Revealed>0)
        line[11]+=PlayersSeat[5].Hand[4].CardShow()+" ";
    }
    else
        line[11]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[11]+=" ";
    if(PlayersSeat[10].Hand.size()>=5)
    {
        if(PlayersSeat[10].Revealed==0)
        line[11]+=" [?]";
        else if(PlayersSeat[10].Revealed>0)
        line[11]+=" "+PlayersSeat[10].Hand[4].CardShow();
    }
    else
        line[11]+="    ";
    for(int i=0;i<5;i++)
        line[11]+=" ";   
    line[11]+="|";

//LINE12:
line[12]+="|                                                                                                                                  |";

    //LINE13:
    line[13]+="|";
    for(int i=0;i<5;i++)
        line[13]+=" ";
    line[13]+=PlayersSeat[4].BlackJackStatus;
    for(int i=0;i<130-(5+20+20+5);i++)
        line[13]+=" ";
    line[13]+=PlayersSeat[11].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[13]+=" ";
    line[13]+="|";

    //LINE14:
    line[14]+="|";
    for(int i=0;i<5;i++)
        line[14]+=" ";
    line[14]+=PlayersSeat[4].name;
    for(int i=0;i<20-NameLength[4];i++)
    {
        if(PlayersSeat[4].name.size()==0)
            line[14]+=" ";                   
        else
            line[14]+=".";                   //
    }
    for(int i=0;i<130-(5+20+20+5);i++)
        line[14]+=" ";
    for(int i=0;i<20-NameLength[11];i++)
    {
        if(PlayersSeat[11].name.size()==0)
            line[14]+=" ";                   
        else
            line[14]+=".";                   //
    }
    line[14]+=PlayersSeat[11].name;
    for(int i=0;i<5;i++)
        line[14]+=" ";
    line[14]+="|";

    //LINE15:
    line[15]+="|";
    for(int i=0;i<5;i++)
        line[15]+=" ";
    if(PlayersSeat[4].Hand.size()>=1)
    {
        if(PlayersSeat[4].Revealed==0)
        line[15]+="[?] ";
        else if(PlayersSeat[4].Revealed>0)
        line[15]+=PlayersSeat[4].Hand[0].CardShow()+" ";
    }
    else
        line[15]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[15]+=" ";
    if(PlayersSeat[11].Hand.size()>=1)
    {
        if(PlayersSeat[11].Revealed==0)
        line[15]+=" [?]";
        else if(PlayersSeat[11].Revealed>0)
        line[15]+=" "+PlayersSeat[11].Hand[0].CardShow();
    }
    else
        line[15]+="    ";
    for(int i=0;i<5;i++)
        line[15]+=" ";   
    line[15]+="|";

    //LINE16:
    line[16]+="|";
    for(int i=0;i<5;i++)
        line[16]+=" ";
    if(PlayersSeat[4].Hand.size()>=2)
    {
        if(PlayersSeat[4].Revealed==0)
        line[16]+="[?] ";
        else if(PlayersSeat[4].Revealed>0)
        line[16]+=PlayersSeat[4].Hand[1].CardShow()+" ";
    }
    else
        line[16]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[16]+=" ";
    if(PlayersSeat[11].Hand.size()>=2)
    {
        if(PlayersSeat[11].Revealed==0)
        line[16]+=" [?]";
        else if(PlayersSeat[11].Revealed>0)
        line[16]+=" "+PlayersSeat[11].Hand[1].CardShow();
    }
    else
        line[16]+="    ";
    for(int i=0;i<5;i++)
        line[16]+=" ";   
    line[16]+="|"; 

    //LINE17:
    line[17]+="|";
    for(int i=0;i<5;i++)
        line[17]+=" ";
    if(PlayersSeat[4].Hand.size()>=3)
    {
        if(PlayersSeat[4].Revealed==0)
        line[17]+="[?] ";
        else if(PlayersSeat[4].Revealed>0)
        line[17]+=PlayersSeat[4].Hand[2].CardShow()+" ";
    }
    else
        line[17]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[17]+=" ";
    if(PlayersSeat[11].Hand.size()>=3)
    {
        if(PlayersSeat[11].Revealed==0)
        line[17]+=" [?]";
        else if(PlayersSeat[11].Revealed>0)
        line[17]+=" "+PlayersSeat[11].Hand[2].CardShow();
    }
    else
        line[17]+="    ";
    for(int i=0;i<5;i++)
        line[17]+=" ";   
    line[17]+="|";

    //LINE18:
    line[18]+="|";
    for(int i=0;i<5;i++)
        line[18]+=" ";
    if(PlayersSeat[4].Hand.size()>=4)
    {
        if(PlayersSeat[4].Revealed==0)
        line[18]+="[?] ";
        else if(PlayersSeat[4].Revealed>0)
        line[18]+=PlayersSeat[4].Hand[3].CardShow()+" ";
    }
    else
        line[18]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[18]+=" ";
    if(PlayersSeat[11].Hand.size()>=4)
    {
        if(PlayersSeat[11].Revealed==0)
        line[18]+=" [?]";
        else if(PlayersSeat[11].Revealed>0)
        line[18]+=" "+PlayersSeat[11].Hand[3].CardShow();
    }
    else
        line[18]+="    ";
    for(int i=0;i<5;i++)
        line[18]+=" ";   
    line[18]+="|";

    //LINE19:
    line[19]+="|";
    for(int i=0;i<5;i++)
        line[19]+=" ";
    if(PlayersSeat[4].Hand.size()>=5)
    {
        if(PlayersSeat[4].Revealed==0)
        line[19]+="[?] ";
        else if(PlayersSeat[4].Revealed>0)
        line[19]+=PlayersSeat[4].Hand[4].CardShow()+" ";
    }
    else
        line[19]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[19]+=" ";
    if(PlayersSeat[11].Hand.size()>=5)
    {
        if(PlayersSeat[11].Revealed==0)
        line[19]+=" [?]";
        else if(PlayersSeat[11].Revealed>0)
        line[19]+=" "+PlayersSeat[11].Hand[4].CardShow();
    }
    else
        line[19]+="    ";
    for(int i=0;i<5;i++)
        line[19]+=" ";   
    line[19]+="|";

//LINE20:
line[20]+="|                                                                                                                                  |";

    //LINE21:
    line[21]+="|";
    for(int i=0;i<5;i++)
        line[21]+=" ";
    line[21]+=PlayersSeat[3].BlackJackStatus;
    for(int i=0;i<130-(5+20+20+5);i++)
        line[21]+=" ";
    line[21]+=PlayersSeat[12].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[21]+=" ";
    line[21]+="|";

    //LINE22:
    line[22]+="|";
    for(int i=0;i<5;i++)
        line[22]+=" ";
    line[22]+=PlayersSeat[3].name;
    for(int i=0;i<20-NameLength[3];i++)
    {
        if(PlayersSeat[3].name.size()==0)
            line[22]+=" ";                   
        else
            line[22]+=".";                   //
    }
    for(int i=0;i<130-(5+20+20+5);i++)
        line[22]+=" ";
    for(int i=0;i<20-NameLength[12];i++)
    {
        if(PlayersSeat[12].name.size()==0)
            line[22]+=" ";                   
        else
            line[22]+=".";                   //
    }
    line[22]+=PlayersSeat[12].name;
    for(int i=0;i<5;i++)
        line[22]+=" ";
    line[22]+="|";

    //LINE23:
    line[23]+="|";
    for(int i=0;i<5;i++)
        line[23]+=" ";
    if(PlayersSeat[3].Hand.size()>=1)
    {
        if(PlayersSeat[3].Revealed==0)
        line[23]+="[?] ";
        else if(PlayersSeat[3].Revealed>0)
        line[23]+=PlayersSeat[3].Hand[0].CardShow()+" ";
    }
    else
        line[23]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[23]+=" ";
    if(PlayersSeat[12].Hand.size()>=1)
    {
        if(PlayersSeat[12].Revealed==0)
        line[23]+=" [?]";
        else if(PlayersSeat[12].Revealed>0)
        line[23]+=" "+PlayersSeat[12].Hand[0].CardShow();
    }
    else
        line[23]+="    ";
    for(int i=0;i<5;i++)
        line[23]+=" ";   
    line[23]+="|";

    //LINE24:
    line[24]+="|";
    for(int i=0;i<5;i++)
        line[24]+=" ";
    if(PlayersSeat[3].Hand.size()>=2)
    {
        if(PlayersSeat[3].Revealed==0)
        line[24]+="[?] ";
        else if(PlayersSeat[3].Revealed>0)
        line[24]+=PlayersSeat[3].Hand[1].CardShow()+" ";
    }
    else
        line[24]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[24]+=" ";
    if(PlayersSeat[12].Hand.size()>=2)
    {
        if(PlayersSeat[12].Revealed==0)
        line[24]+=" [?]";
        else if(PlayersSeat[12].Revealed>0)
        line[24]+=" "+PlayersSeat[12].Hand[1].CardShow();
    }
    else
        line[24]+="    ";
    for(int i=0;i<5;i++)
        line[24]+=" ";   
    line[24]+="|"; 

    //LINE25:
    line[25]+="|";
    for(int i=0;i<5;i++)
        line[25]+=" ";
    if(PlayersSeat[3].Hand.size()>=3)
    {
        if(PlayersSeat[3].Revealed==0)
        line[25]+="[?] ";
        else if(PlayersSeat[3].Revealed>0)
        line[25]+=PlayersSeat[3].Hand[2].CardShow()+" ";
    }
    else
        line[25]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[25]+=" ";
    if(PlayersSeat[12].Hand.size()>=3)
    {
        if(PlayersSeat[12].Revealed==0)
        line[25]+=" [?]";
        else if(PlayersSeat[12].Revealed>0)
        line[25]+=" "+PlayersSeat[12].Hand[2].CardShow();
    }
    else
        line[25]+="    ";
    for(int i=0;i<5;i++)
        line[25]+=" ";   
    line[25]+="|";

    //LINE26:
    line[26]+="|";
    for(int i=0;i<5;i++)
        line[26]+=" ";
    if(PlayersSeat[3].Hand.size()>=4)
    {
        if(PlayersSeat[3].Revealed==0)
        line[26]+="[?] ";
        else if(PlayersSeat[3].Revealed>0)
        line[26]+=PlayersSeat[3].Hand[3].CardShow()+" ";
    }
    else
        line[26]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[26]+=" ";
    if(PlayersSeat[12].Hand.size()>=4)
    {
        if(PlayersSeat[12].Revealed==0)
        line[26]+=" [?]";
        else if(PlayersSeat[12].Revealed>0)
        line[26]+=" "+PlayersSeat[12].Hand[3].CardShow();
    }
    else
        line[26]+="    ";
    for(int i=0;i<5;i++)
        line[26]+=" ";   
    line[26]+="|";

    //LINE27:
    line[27]+="|";
    for(int i=0;i<5;i++)
        line[27]+=" ";
    if(PlayersSeat[3].Hand.size()>=5)
    {
        if(PlayersSeat[3].Revealed==0)
        line[27]+="[?] ";
        else if(PlayersSeat[3].Revealed>0)
        line[27]+=PlayersSeat[3].Hand[4].CardShow()+" ";
    }
    else
        line[27]+="    ";
    for(int i=0;i<130-(5+4+4+5);i++)
        line[27]+=" ";
    if(PlayersSeat[12].Hand.size()>=5)
    {
        if(PlayersSeat[12].Revealed==0)
        line[27]+=" [?]";
        else if(PlayersSeat[12].Revealed>0)
        line[27]+=" "+PlayersSeat[12].Hand[4].CardShow();
    }
    else
        line[27]+="    ";
    for(int i=0;i<5;i++)
        line[27]+=" ";   
    line[27]+="|";

//LINE28:
line[28]+="|                                                                                                                                  |";

    //LINE29:
    line[29]+="|";
    for(int i=0;i<5;i++)
        line[29]+=" ";  
    line[29]+=PlayersSeat[2].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[29]+=" "; 
    line[29]+=PlayersSeat[1].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[29]+=" "; 
    line[29]+=PlayersSeat[0].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[29]+=" "; 
    line[29]+=PlayersSeat[14].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[29]+=" "; 
    line[29]+=PlayersSeat[13].BlackJackStatus;
    for(int i=0;i<5;i++)
        line[29]+=" "; 
    line[29]+="|";
    
    //LINE30:
    line[30]+="|";
    for(int i=0;i<5;i++)
        line[30]+=" ";  
    for(int i=0;i<PlayersSeat[2].Hand.size();i++)
    {
        if(PlayersSeat[2].Revealed==0)
        line[30]+="[?] ";
        else if(PlayersSeat[2].Revealed>0)
        line[30]+=PlayersSeat[2].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[2];i++)
        line[30]+="    ";
    for(int i=0;i<5;i++)
        line[30]+=" ";
    for(int i=0;i<PlayersSeat[1].Hand.size();i++)
    {
        if(PlayersSeat[1].Revealed==0)
        line[30]+="[?] ";
        else if(PlayersSeat[1].Revealed>0)
        line[30]+=PlayersSeat[1].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[1];i++)
        line[30]+="    ";
    for(int i=0;i<5;i++)
        line[30]+=" ";
    for(int i=0;i<PlayersSeat[0].Hand.size();i++)
    {
        if(PlayersSeat[0].Revealed==0)
        line[30]+="[?] ";
        else if(PlayersSeat[0].Revealed>0)
        line[30]+=PlayersSeat[0].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[0];i++)
        line[30]+="    ";
    for(int i=0;i<5;i++)
        line[30]+=" ";
    for(int i=0;i<PlayersSeat[14].Hand.size();i++)
    {
        if(PlayersSeat[14].Revealed==0)
        line[30]+="[?] ";
        else if(PlayersSeat[14].Revealed>0)
        line[30]+=PlayersSeat[14].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[14];i++)
        line[30]+="    ";
    for(int i=0;i<5;i++)
        line[30]+=" ";
    for(int i=0;i<PlayersSeat[13].Hand.size();i++)
    {
        if(PlayersSeat[13].Revealed==0)
        line[30]+="[?] ";
        else if(PlayersSeat[13].Revealed>0)
        line[30]+=PlayersSeat[13].Hand[i].CardShow()+" ";
    }
    for(int i=0;i<5-NumberCards[13];i++)
        line[30]+="    ";
    for(int i=0;i<5;i++)
        line[30]+=" ";
    line[30]+="|";

    //LINE31:
    line[31]+="|";
    for(int i=0;i<5;i++)
        line[31]+=" ";
    line[31]+=PlayersSeat[2].name;
    for(int i=0;i<20-NameLength[2];i++)
    {
        if(PlayersSeat[2].name.size()==0)
            line[31]+=" ";                   
        else
            line[31]+=".";                   //
    }
    for(int i=0;i<5;i++)
        line[31]+=" ";
    line[31]+=PlayersSeat[1].name;
    for(int i=0;i<20-NameLength[1];i++)
    {
        if(PlayersSeat[1].name.size()==0)
            line[31]+=" ";                   
        else
            line[31]+=".";                   //
    }
    for(int i=0;i<5;i++)
        line[31]+=" ";
    line[31]+=PlayersSeat[0].name;
    for(int i=0;i<20-NameLength[0];i++)
        line[31]+=".";                       //
    for(int i=0;i<5;i++)
        line[31]+=" ";
    line[31]+=PlayersSeat[14].name;
    for(int i=0;i<20-NameLength[14];i++)
    {
        if(PlayersSeat[14].name.size()==0)
            line[31]+=" ";                   
        else
            line[31]+=".";                   //
    }
    for(int i=0;i<5;i++)
        line[31]+=" ";
    line[31]+=PlayersSeat[13].name;
    for(int i=0;i<20-NameLength[13];i++)
    {
        if(PlayersSeat[13].name.size()==0)
            line[31]+=" ";                   
        else
            line[31]+=".";                   //
    }
    for(int i=0;i<5;i++)
        line[31]+=" ";
    line[31]+="|";

    cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
    for(int i=1;i<32;i++) cout<<endl<<line[i];
    cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n";

}   

void PlaceSeat(Player Players[], int N){
    Players[0].Seat=0;
    switch(N)
    {
        case 2:
        {
            Players[1].Seat=15;
        } break;
        case 3:
        {
            Players[1].Seat=6;
            Players[2].Seat=9;
        } break;
        case 4:
        {
            Players[1].Seat=5;
            Players[2].Seat=15;
            Players[3].Seat=10;
        } break;
        case 5:
        {
            Players[1].Seat=3;
            Players[2].Seat=6;
            Players[3].Seat=9;
            Players[4].Seat=12;
        } break;
        case 6:
        {
            Players[1].Seat=3;
            Players[2].Seat=5;
            Players[3].Seat=15;
            Players[4].Seat=10;
            Players[5].Seat=12;
        } break;
        case 7:
        {
            Players[1].Seat=2;
            Players[2].Seat=4;
            Players[3].Seat=7;
            Players[4].Seat=8;
            Players[5].Seat=11;
            Players[6].Seat=13;
        } break;
        case 8:
        {
            Players[1].Seat=2;
            Players[2].Seat=4;
            Players[3].Seat=6;
            Players[4].Seat=15;
            Players[5].Seat=9;
            Players[6].Seat=11;
            Players[7].Seat=13;
        } break;
        case 9:
        {
            Players[1].Seat=1;
            Players[2].Seat=3;
            Players[3].Seat=5;
            Players[4].Seat=7;
            Players[5].Seat=8;
            Players[6].Seat=10;
            Players[7].Seat=12;
            Players[8].Seat=14;
        } break;
        case 10:
        {
            Players[1].Seat=1;
            Players[2].Seat=3;
            Players[3].Seat=5;
            Players[4].Seat=6;
            Players[5].Seat=15;
            Players[6].Seat=9;
            Players[7].Seat=10;
            Players[8].Seat=12;
            Players[9].Seat=14;
        } break;
        case 11:
        {
            Players[1].Seat=1;
            Players[2].Seat=3;
            Players[3].Seat=5;
            Players[4].Seat=6;
            Players[5].Seat=7;
            Players[6].Seat=8;
            Players[7].Seat=9;
            Players[8].Seat=10;
            Players[9].Seat=12;
            Players[10].Seat=14;
        } break;
        case 12:
        {
            Players[1].Seat=2;
            Players[2].Seat=3;
            Players[3].Seat=4;
            Players[4].Seat=5;
            Players[5].Seat=6;
            Players[6].Seat=15;
            Players[7].Seat=9;
            Players[8].Seat=10;
            Players[9].Seat=11;
            Players[10].Seat=12;
            Players[11].Seat=13;
        } break;
        case 13:
        {
            Players[1].Seat=2;
            Players[2].Seat=3;
            Players[3].Seat=4;
            Players[4].Seat=5;
            Players[5].Seat=6;
            Players[6].Seat=7;
            Players[7].Seat=8;
            Players[8].Seat=9;
            Players[9].Seat=10;
            Players[10].Seat=11;
            Players[11].Seat=12;
            Players[12].Seat=13;
        } break;
        case 14:
        {
            Players[1].Seat=2;
            Players[2].Seat=3;
            Players[3].Seat=4;
            Players[4].Seat=5;
            Players[5].Seat=6;
            Players[6].Seat=7;
            Players[7].Seat=15;
            Players[8].Seat=8;
            Players[9].Seat=9;
            Players[10].Seat=10;
            Players[11].Seat=11;
            Players[12].Seat=12;
            Players[13].Seat=13;
        } break;
        case 15:
        {
            Players[1].Seat=1;
            Players[2].Seat=2;
            Players[3].Seat=3;
            Players[4].Seat=4;
            Players[5].Seat=5;
            Players[6].Seat=6;
            Players[7].Seat=7;
            Players[8].Seat=8;
            Players[9].Seat=9;
            Players[10].Seat=10;
            Players[11].Seat=11;
            Players[12].Seat=12;
            Players[13].Seat=13;
            Players[14].Seat=14;
        } break;
    }
}

string PlayBlackJack(vector<Card> Deck){
    int N;
    long long MONEY[15];
    long long DealerPay=0;
    string INPUT;
    bool seat15=false;
    bool NoMoreToCheck=false;

    cout<<"\n- Playing BlackJack -\n";
    cout<<"\nHow many players are there include the dealer: ";
    N_again:
    cin>>N;
    if(N<2 || N>15)
    {
        cout<<"\n! Number of players should be in [2:15] ! Please type again: ";
        goto N_again;
    }

    Player Players[N];

    for(int i=0;i<N;i++)
    {
        Players[i].BlackJackStatus="                    ";
        Players[i].Revealed=0;
    }

    cin.ignore();
    cout<<"\nName of the players:\n";
    cout<<"\nDealer's name: ";
    Name0Again:
    getline(cin,INPUT);
    if(INPUT.size()>=14 || INPUT.size()==0)
    {
        cout<<"\nName length cannot longer than 14 or left blank, type another name: ";
        goto Name0Again;
    }
    Players[0].name=INPUT;

    for(int i=1;i<N;i++)
    {
        cout<<"\nPlayer "<<i<<"'s name: ";
        NameiAgain:
        getline(cin,INPUT);
        if(INPUT.size()>=14 || INPUT.size()==0)
        {
            cout<<"\nName length cannot longer than 14 or left blank, type another name: ";
            goto NameiAgain;
        }
        for(int j=0;j<i;j++)
        {
            if(INPUT==Players[j].name)
            {
                cout<<"\nName already taken, try another name: ";
                goto NameiAgain;
            }
        }
        Players[i].name=INPUT;

        cout<<"Money bet: ";
        MONEYiAgain:
        cin>>MONEY[i];
        if(MONEY[i]<=0)
        {
            cout<<"\nPlease input reasonable amount of money: ";
            goto MONEYiAgain;
        }
        cin.ignore();
    }

    cout<<"\n\n";
    cout<<"DEALER: "<<Players[0].name;
    for(int i=1;i<N;i++)
    {
        cout<<"\n"<<Players[i].name<<": "<<MONEY[i];
    }

    cout<<"\n\nType something to continue: ";cin>>INPUT;

    PlaceSeat(Players,N);

    //GIVE CARDS FROM DECK TO PLAYERS
    int j=1;
    bool onecard=false;
    while(true)
    {
        Players[j].Hand.push_back(Deck[0]);         //CARDS FOR PLAYERS
        Deck.erase(Deck.begin());

        j++;
        ShowTableBlackJack(Players,N);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if(j==N)
        {
            Players[0].Hand.push_back(Deck[0]);     //CARDS FOR DEALER
            Deck.erase(Deck.begin());

            ShowTableBlackJack(Players,N);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            if(onecard)
            {
                break;
            }
            onecard=true;
            j=1;
        }
    }

    for(int i=0;i<N;i++)
    {
        RearrangeDefault(Players[i].Hand);
    }

    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Players[j].Seat==i)
            {
                Players[j].CheckBlackJack();
                if(Players[j].Total==1000 || Players[j].Total==10000)
                Players[j].Revealed=2;
            }   
        }
    }

    if(Players[0].Total==1000)
    {
        for(int i=1;i<N;i++)
        {
            if(Players[i].Total==1000)
            {
                Players[i].name+="(DRAW)";
            } 
            if(Players[i].Total==10000)
            {
                Players[i].name+="(WIN)";
            }
            else Players[i].name+="(LOSE)";
        }
        goto FINAL_RESULT;
    }
    else if(Players[0].Total==10000)
    {
        for(int i=1;i<N;i++)
        {
            if(Players[i].Total==10000)
            {
                Players[i].name+="(DRAW)";
            }
            else Players[i].name+="(LOSE)";
        }
        goto FINAL_RESULT;
    }
    else
    {
        for(int i=1;i<N;i++)
        {
            if(Players[i].Total==1000 || Players[i].Total==10000)
            {
                Players[i].name+="(WIN)";
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        if(Players[i].BlackJackStatus!="<B L A C K  J A C K>" && Players[i].BlackJackStatus!="<[A] GLORY ACES [A]>")
            Players[i].BlackJackStatus="                    ";
    }

    for(int i=1;i<=15;i++)  
    {
        if(i==15 && seat15) break;

        for(int j=0;j<N;j++)
        {
            if(Players[j].Seat==i && Players[j].Revealed!=2)
            {
                //TURN START
                for(int k=0;k<N;k++)
                {
                    if(Players[k].Revealed==1)
                    Players[k].Revealed=0;
                }
                ShowTableBlackJack(Players,N);
                cout<<"\nType something to begin your turn, '"<<Players[j].name<<"': ";cin>>INPUT;
                for(int k=0;k<N;k++)
                {
                    if(Players[k].Revealed==1)
                    Players[k].Revealed=0;
                }
                Players[j].Revealed=1;
                ShowTableBlackJack(Players,N);
                //HIT PHASE
                while(Players[j].Total>0 && Players[j].Total<21)
                {
                    cout<<"\nChoose 'hit' or 'stand'? -> ";
                    InputAgain:
                    cin>>INPUT;
                    if(INPUT!="hit" && INPUT!="stand")
                    {
                        cout<<"\n\n! Just type 'hit' or 'stand': ";
                        goto InputAgain;
                    }
                    else if(INPUT=="stand")
                    {
                        Players[j].CheckBlackJack();
                        //CHECK
                        //cout<<Players[j].Total<<" "<<Players[j].TotalA10<<" "<<Players[j].TotalA11<<endl;
                        //cout<<(Players[j].Total<16)<<(Players[j].TotalA10<16)<<(Players[j].TotalA11<16)<<!(Players[j].TotalA10>21)<<!(Players[j].TotalA11>21);
                        if( (Players[j].Total<16 && Players[j].TotalA10<16 && Players[j].TotalA11<16) 
                            || 
                            (Players[j].Total<16 && Players[j].TotalA10>21 && Players[j].TotalA11>21) 
                        )
                        {
                            cout<<"\n! Too young, bitch ! Come on, 'hit' it: ";goto InputAgain;
                        }
                        //SITUATION HAVE [A]
                        if(Players[j].Total<16)
                        {
                            if(Players[j].TotalA11>21) Players[j].Total=Players[j].TotalA10;
                            else Players[j].Total=Players[j].TotalA11;
                        }
                        //END TURN
                        cout<<"\nSTAND";
                        break;
                    }
                    else
                    {
                        //HIT ONE
                        Players[j].Hand.push_back(Deck[0]);
                        RearrangeDefault(Players[j].Hand);
                        Deck.erase(Deck.begin());

                        //CHECK AFTER HIT
                        Players[j].CheckBlackJack();
                        ShowTableBlackJack(Players,N);
                        if(Players[j].Hand.size()==5)
                        {
                            Players[j].Revealed=2;
                            break;
                        }
                    }
                }
                cout<<"\n! END TURN !";
                ShowTableBlackJack(Players,N);
                cout<<"\nType something to end your turn, '"<<Players[j].name<<"': ";cin>>INPUT;
            }   
        }
        if(i==15) {i=7; seat15=true;}
        else if(i==7) i=14;
    }

    //AFTER DONE ALL TURNS
    for(int k=0;k<N;k++)
    {
        if(Players[k].Revealed==1)
        Players[k].Revealed=0;
    }
    ShowTableBlackJack(Players,N);
    Players[0].Revealed=2;
    
    //DEALER'S TURN
    
    cout<<"\nType something to begin dealer's turn: ";cin>>INPUT;

    while(Players[0].Total>0 && Players[0].Total<21)
    {
        ShowTableBlackJack(Players,N);
        if( 
            (Players[0].Total<15 && Players[0].TotalA10<15 && Players[0].TotalA11<15) 
            || 
            (Players[0].Total<15 && Players[0].TotalA10>21 && Players[0].TotalA11>21) 
        )                            //NOT ALLOWED TO CHECK
        {
            cout<<"\nCome on, 'hit' it -> ";
            Input0Again:
            cin>>INPUT;
            if(INPUT!="hit")
            {
                cout<<"\n\n! Just type 'hit': ";
                goto Input0Again;
            }
            else
            {
                //HIT ONE
                Players[0].Hand.push_back(Deck[0]);
                RearrangeDefault(Players[0].Hand);
                Deck.erase(Deck.begin());

                //CHECK AFTER HIT
                Players[0].CheckBlackJack();
                ShowTableBlackJack(Players,N);
            }
        }
        else if(
                (Players[0].Total>=15 && Players[0].Total<21)
                ||
                (Players[0].TotalA10>=15 && Players[0].TotalA10<21)
                ||
                (Players[0].TotalA11>=15 && Players[0].TotalA11<21)
        )      //ALLOWED TO CHECK
        {
            cout<<"\nChoose 'check' or 'hit' -> ";
            Input1Again:
            cin>>INPUT;
            if(INPUT!="hit" && INPUT!="check")
            {
                cout<<"\n\n! Just type 'hit' or 'check': ";
                goto Input1Again;
            }
            else if(INPUT=="check")
            {
                int indexcheck;
                cin.ignore();
                cout<<"\nWhat player you'd like to check? Type their name or 'ALL' to check all: ";
                Input2Again:
                getline(cin,INPUT);
                if(INPUT=="QUIT")
                {
                    cout<<"\n";
                    continue;
                }
                else if(INPUT=="ALL")
                goto CheckAll;

                for(indexcheck=1;indexcheck<N;indexcheck++)
                {
                    if(INPUT==Players[indexcheck].name && Players[indexcheck].Revealed==0)
                    goto Chosen;
                }
                cout<<"\nThere's no one with that name, or their cards have been revealed.\nType again or type 'QUIT' if you change your mind: ";
                goto Input2Again;

                Chosen:
                Players[indexcheck].Revealed=2;
                ShowTableBlackJack(Players,N);
                if(Players[indexcheck].Total>Players[0].Total)
                {
                    Players[indexcheck].name+="(WIN)";
                }
                else if(Players[indexcheck].Total==Players[0].Total)
                {
                    Players[indexcheck].name+="(DRAW)";
                }
                else
                {
                    Players[indexcheck].name+="(LOSE)";
                }
            }
            else
            {
                //HIT ONE
                Players[0].Hand.push_back(Deck[0]);
                RearrangeDefault(Players[0].Hand);
                Deck.erase(Deck.begin());

                //CHECK AFTER HIT
                Players[0].CheckBlackJack();
                ShowTableBlackJack(Players,N);
            }
        }
        else break;

        NoMoreToCheck=true;
        for(int i=1;i<15;i++)
        {
            if(Players[i].Revealed==0)
            NoMoreToCheck=false;
        }
    }
    CheckAll:
    for(int i=1;i<N;i++)
    {
        if(Players[i].Revealed==0)
        {
            Players[i].Revealed=1;
            if(Players[i].Total==Players[0].Total || (Players[i].Total<0 && Players[0].Total<0))
            {
                Players[i].name+="(DRAW)";
            }
            else if(Players[i].Total>Players[0].Total)
            {
                Players[i].name+="(WIN)";
            }
            else
            {
                Players[i].name+="(LOSE)";
            }
        }
        else if(Players[i].Total<0 && Players[0].Total<0 && Players[i].Revealed==2)
        {
            Players[i].name+="(DRAW)";
        }
        else if(Players[i].Hand.size()==5)
        {
            if(Players[i].Total<Players[0].Total)
            Players[i].name+="(LOSE)";
            else if(Players[i].Total==Players[0].Total)
            Players[i].name+="(DRAW)";
            else
            Players[i].name+="(WIN)";
        }

    }

    ShowTableBlackJack(Players,N);
    
    cout<<"\n\nType something to show final result: ";cin>>INPUT;
    FINAL_RESULT:

    //win lose draw
    string W_L_D;
    cout<<"\n\n";
    for(int i=1;i<N;i++)
    {   
        if(Players[i].name[Players[i].name.size()-2]=='N')
        W_L_D="WIN";
        else if(Players[i].name[Players[i].name.size()-2]=='E')
        W_L_D="LOSE";
        else
        W_L_D="DRAW";

        //if checked in check phase, this player won't be charged more when the dealer has 5 cards charlie
        if(Players[i].Revealed==2 && Players[i].Total<1000 && Players[0].Total<1000)
        {   
            if(W_L_D=="WIN")
            ;
            else if(W_L_D=="LOSE")
            MONEY[i]=-MONEY[i];
            else
            MONEY[i]=0;
            goto ShowFinali;
        }

        if(Players[0].Total==1000)
        {
            if(W_L_D=="LOSE")
            MONEY[i]*=-2;
            if(W_L_D=="WIN")
            MONEY[i]*=4;
            else MONEY[i]=0;
        }
        else if(Players[0].Total==10000)
        {
            if(W_L_D=="LOSE")
            MONEY[i]*=-4;
            else MONEY[i]=0;
        }
        else if(Players[0].Hand.size()==5)
        {
            if(W_L_D=="LOSE")
            MONEY[i]*=-2;
            else if(W_L_D=="WIN" && Players[i].Hand.size()==5)
            MONEY[i]*=2;
            else if(W_L_D=="WIN")
            MONEY[i]=MONEY[i];
            else MONEY[i]=0;
        }
        else if(Players[i].Total==1000)
        {
            MONEY[i]*=2;
        }
        else if(Players[i].Total==10000)
        {
            MONEY[i]*=4;
        }
        else if(Players[i].Hand.size()==5 && W_L_D=="WIN")
        {
            MONEY[i]*=2;
        }
        else
        {
            if(W_L_D=="WIN")
            ;
            else if(W_L_D=="LOSE")
            MONEY[i]=-MONEY[i];
            else
            MONEY[i]=0;
        }  

        ShowFinali:
        cout<<"\n"<<setw(20)<<left<<Players[i].name;
        cout<<": "<<setw(5)<<left<<W_L_D<<" ";
        if(W_L_D=="WIN")
        cout<<MONEY[i];
        else if(W_L_D=="LOSE")
        cout<<-MONEY[i];
    }
    for(int i=1;i<N;i++)
    {
        DealerPay+=MONEY[i];
    }
    cout<<"\nDealer: ";
    if(-DealerPay>0)
        cout<<"+"<<-DealerPay;
    else
        cout<<-DealerPay;
    
    cout<<"\n____GAME OVER____";
    return " ";
}