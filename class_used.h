

using namespace std;

void InitProgram(){
    string Line1="Initialization--------------------------------------------------";
    string Line2="files:{ main.cpp(main) - cpplibduc.h(standard libs.)";
    string Line3="class_used.h(classes used) - rearrange.h(sort/random cards)";
    string Line4="gamemode.h(gamemodes) }";
    string Line5="ducng || v1_Feb_10_2021";
    string Line6="End initialization";
    
    using namespace std::this_thread;
    using namespace std::chrono;

    std::cout<<endl<<Line1;sleep_for(milliseconds(1000));
    std::cout<<endl<<Line2<<" ";sleep_for(milliseconds(450));for(int i=0;i<64;i++){if(i>Line2.length())std::cout<<".";}
    std::cout<<endl<<Line3<<" ";sleep_for(milliseconds(450));for(int i=0;i<64;i++){if(i>Line3.length())std::cout<<".";}
    std::cout<<endl<<Line4<<" ";sleep_for(milliseconds(750));for(int i=0;i<64;i++){if(i>Line4.length())std::cout<<".";}
    std::cout<<endl<<Line5<<" ";sleep_for(milliseconds(300));for(int i=0;i<64;i++){if(i>Line5.length())std::cout<<".";}
    std::cout<<endl<<Line6<<" ";sleep_for(milliseconds(500));for(int i=0;i<64;i++){if(i>Line6.length())std::cout<<".";}

    std::cout<<"\n\n- Available gamemode -";
    std::cout<<"\n[1] Thirteen.";
    std::cout<<"\n[2] BlackJack."<<"\t\tTerminal size: 134x38";
    std::cout<<"\n[.] ...\n";

    std::cout<<"\n----------------------------------------------------------------";sleep_for(milliseconds(1000));

    std::cout<<"\n\n\n";

    using namespace std;
}

class Card{
    private:
    int value;
    int type;

    public:
    Card(int value, int type){
        this->value=value;
        this->type=type;
    }
    void InValue(int value){
        this->value=value;
    }
    void InType(int type){
        this->type=type;
    }
    int GetValue(){
        return value;
    }
    int GetType(){
        return type;
    }
    void show(){
        cout<<endl<<value<<" "<<type<<endl;
    }
    void SymbolShow(){
        string SymbolValue;
        string SymbolType;
        if(value==1){
            SymbolValue="A";
        }else if(value<=10){
            SymbolValue=to_string(value);
        }else if(value==11){
            SymbolValue="J";
        }else if(value==12){
            SymbolValue="Q";
        }else if(value==13){
            SymbolValue="K";
        }

        if(type==1){
            SymbolType="♠︎";
        } else if(type==2){
            SymbolType="♣︎";
        } else if(type==3){
            SymbolType="♦︎";
        } else if(type==4){
            SymbolType="♥︎";
        }

        cout<<setw(2)<<right<<SymbolValue<<setw(3)<<left<<SymbolType;
    }

    string CardShow(){
        string SymbolValue;
        string SymbolType;
        if(value==1){
            SymbolValue="A";
        }else if(value<=10){
            SymbolValue=to_string(value);
        }else if(value==11){
            SymbolValue="J";
        }else if(value==12){
            SymbolValue="Q";
        }else if(value==13){
            SymbolValue="K";
        }

        if(type==1){
            SymbolType="♠︎";
        } else if(type==2){
            SymbolType="♣︎";
        } else if(type==3){
            SymbolType="♦︎";
        } else if(type==4){
            SymbolType="♥︎";
        }
        if(SymbolValue=="10")
            return SymbolValue+SymbolType;
        else
            return SymbolValue+SymbolType+" ";
    }
};




vector<Card> RearrangeThirteen(vector<Card>& Hand);
string EventToString(int event);



class Player{
    private:

    public:

    string name;
    vector<Card> Hand;

    //Thirteen
    bool InRound;
    bool Finished;

    //BlackJack
    int Total, TotalA10, TotalA11;
    int Seat;
    string BlackJackStatus;
    int Revealed;

    void ShowHand(){
        cout<<"\n\n\n\n"<<name<<"'s hand: ";
        for(int i=0;i<Hand.size();i++)
        {
            Hand[i].SymbolShow();
            cout<<" --";
        }
        cout<<"\b\b";
        cout<<"\n"<<name<<"'s hand:  ";
        for(int i=1;i<=Hand.size();i++)
        {
            if(i>9)
            {
                cout<<"\b";
            }
            cout<<i<<"     ";
        }
    }
    int MoveThirteen(vector<Card>& Table, int& event, vector<string>& ranking, int& PlayerLeft, bool& huongsoai);
    void CheckBlackJack();
};

void Player::CheckBlackJack(){
    //BLACKJACK:
    if(Hand[0].GetValue()==1 && Hand.size()==2)
    {
        if(Hand[1].GetValue()==1)
        {
            BlackJackStatus="<[A] GLORY ACES [A]>";
            Total=10000;
            return;
        }
        else if(Hand[1].GetValue()==10 || Hand[1].GetValue()==11 || Hand[1].GetValue()==12 || Hand[1].GetValue()==13)
        {
            BlackJackStatus="<B L A C K  J A C K>";
            Total=1000;
            return;
        }
    }
    Total=0;
    TotalA10=0;
    TotalA11=0;
    for(int i=0;i<Hand.size();i++)
    {
        Total+=Hand[i].GetValue();
        TotalA10+=Hand[i].GetValue();
        TotalA11+=Hand[i].GetValue();
        if(Hand[i].GetValue()==1)
        {
            TotalA10+=9;
            TotalA11+=10;
        }

        if(Hand[i].GetValue()==13) {Total-=3; TotalA10-=3; TotalA11-=3;}
        if(Hand[i].GetValue()==12) {Total-=2; TotalA10-=2; TotalA11-=2;}
        if(Hand[i].GetValue()==11) {Total-=1; TotalA10-=1; TotalA11-=1;}

        if(Total>21)
        {
            BlackJackStatus="!    B U S T E D   !";
        }
    }

    if(Total<=21 && Hand.size()==5)
    {
            BlackJackStatus="<FIVE CARDS CHARLIE>";
            Total=100-Total;
            return;
    }

    if(Revealed!=0)
    {
        if(BlackJackStatus=="!    B U S T E D   !")
        {
            if(Total==22)
            {
                BlackJackStatus="!   So.. close..   !";
            }
            if(Total>=28)
            {
                BlackJackStatus="! Cannot be bigger !"; 
            }
            Total=0-Total;
            return;
        }
        else if((Total==21 || TotalA10==21 || TotalA11==21) && Hand.size()<5)
        {
            BlackJackStatus="|     NICE HIT     |";     
            return;
        }
        else if(Total<16 && TotalA10<16 && TotalA11<16)
        {
            BlackJackStatus="| Too young, bitch |";
            return;
        }
        else
        {
            if(Hand[0].GetValue()==1 && TotalA11<21)
            BlackJackStatus="|     TOTAL "+to_string(TotalA11)+"     |";
            else if(Hand[0].GetValue()==1 && TotalA10<21)
            BlackJackStatus="|     TOTAL "+to_string(TotalA10)+"     |";
            else
            BlackJackStatus="|     TOTAL "+to_string(Total)+"     |";
        }
    }
    else
        BlackJackStatus="                    "; 
    return;
}



int Player::MoveThirteen(vector<Card>& Table, int& event, vector<string>& ranking, int& PlayerLeft, bool& huongsoai){
        //EVENT: NUMBER THAT THIS FUNCTION WILL RETURN WHEN PLAYING THE CORRESPONDING SET
        //0: pass               0 0
        //1: single             1 1    
        //2: double             1 2
        //3: straight 3         3 1
        //4: straight 4         4 1
        //5: straight 5         5 1
        //6: straight 6         ...
        //7: straight 7
        //8: straight 8         ...
        //9: straight 9
        //10: straight 10       ...
        //11: straight 11      11 1
        //12: straight 12      12 1
        //13: triple            1 3
        //14: quadruple         1 4
        //15: straight 3 duo    3 2
        //16: straight 4 duo    4 2

        //DECOY
        vector<Card> decoyTable=Table;
        int decoyevent=event;
        
        int Pointer;
        bool CardNo[Hand.size()];
        
        //THESE BELOW VARIABLES WILL HELP US TO TELL WHAT IS THE PLAYING SET
        int straight;
        int dup;
        bool check;
        bool straighted;
        bool dupped;
        int straight100dup;
        int CardsPlayed;
        string stringevent;
       
        //CHOOSE 1ST CARD TO PLAY
        cout<<"\nChoose/Unchoose card by type in the number of the card: "; 

        //IF ANY ERROR OCCURS, GO BACK TO THIS 
        //--|--|--
        //--v--v--
        chooseagain:
            for(int i=0;i<Hand.size();i++)
            {
                CardNo[i]=false;
            }
            Table.clear();
            straight=1;
            dup=1;
            check=true;
            straighted=false;
            dupped=false;
            straight100dup=0;
            CardsPlayed=0;

        cin>>Pointer; 
        
        //CHECK IF YOU HAVE PASSED
        if(Pointer==0 && decoyevent!=0)
        {
            cout<<"\nYou have passed.";
            straight=0;
            dup=0;
            goto done;
        }
        else if(Pointer==0 && decoyevent==0)
        {
            cout<<"\n! You are the priority, you cannot pass !";
            cout<<"\nChoose again: ";
            goto chooseagain;
        }
        //INVALID POINTER NUMBER
        else if(Pointer<1 || Pointer>Hand.size())
        {
            cout<<"\n! Invalid number !";
            cout<<"\nChoose again: ";
            goto chooseagain;
        }

        CardNo[Pointer-1]=!CardNo[Pointer-1];
        if(CardNo[Pointer-1])
            Table.push_back(Hand[Pointer-1]);
        else
        {
            for(int i=0;i<Table.size();i++)
            {
                if(Hand[Pointer-1].GetType()==Table[i].GetType() && Hand[Pointer-1].GetValue()==Table[i].GetValue())
                    Table.erase(Table.begin()+i);
            }
        }
        RearrangeThirteen(Table);
        cout<<"You are choosing: ";
        for(int i=0;i<Table.size();i++)
        {
            Table[i].SymbolShow();
            cout<<"   ";
        }

        //CHOOSE NEXT CARDS TO PLAY
        while(true)
        {
            cout<<"\nChoose/Unchoose card by type in the number of the card: "; 
            cin>>Pointer; 

            if(Pointer==0 || (Pointer==-1 && Table.size()>0)) break; //CIN>>0 -> PASS     CIN>>-1 -> DONE CHOOSING 
            else if(Pointer==-1 && Table.size()==0)
            {
                cout<<"\n! You are not playing any cards !";
                continue;
            }

            //INVALID POINTER NUMBER
            if(Pointer>Hand.size() || Pointer<-1)
            {
                cout<<"\n! Invalid number !\n";
                continue;
            }

            CardNo[Pointer-1]=!CardNo[Pointer-1];
            if(CardNo[Pointer-1])
                Table.push_back(Hand[Pointer-1]);
            else
            {
                for(int i=0;i<Table.size();i++)
                {
                    if(Hand[Pointer-1].GetType()==Table[i].GetType() && Hand[Pointer-1].GetValue()==Table[i].GetValue())
                        Table.erase(Table.begin()+i);
                }
            }
            RearrangeThirteen(Table);
            cout<<"You are choosing: ";
            for(int i=0;i<Table.size();i++)
            {
                Table[i].SymbolShow();
                cout<<"   ";
            }
        }

        //CHECK IF YOU HAVE PASSED
        if(Pointer==0 && decoyevent!=0)
        {
            cout<<"\nYou have chosen to passed.\n";
            straight=0;
            dup=0;
            goto done;
        }
        else if(Pointer==0 && decoyevent==0)
        {
            cout<<"\n! You are the prioritize player, you cannot pass !\n";
            cout<<"\nChoose again: ";
            goto chooseagain;
        }
        else
        ;

        cout<<"\nDone choosing:\n";

        //SKIP THE VALID CHECK BECAUSE PLAYING JUST 1 CARD
        if(Table.size()==1)
        {
            goto done;
        }
        
        //CHECK THE SET OF PLAYING CARDS IS VALID
        //UPDATE THE "dup" AND THE "straight"
        for(int i=1;i<Table.size();i++)
        {
            if(check==false)
            {
                cout<<"\n! Invalid set 1 !\nPlease choose again: ";
                goto chooseagain;
            }

            check=false;

            if( 
                (
                    (Table[i].GetValue()==Table[i-1].GetValue()+1)
                    ||
                    (Table[i].GetValue()==1 && Table[i-1].GetValue()==13)
                )
                &&
                !(
                    Table[i].GetValue()==2 && Table[i-1].GetValue()==1
                )
              )  //if straight
            {
                if(dup==2)
                {
                    dup--;
                }
                if(dup>2)
                {
                    cout<<"\n! Invalid set 2 !\nPlease choose again: ";
                    goto chooseagain;
                }
                check=true;
                straight++;
                straighted=true;
            }

            if(Table[i].GetValue()==Table[i-1].GetValue()) //if dup
            {
                check=true;
                dup++;
                dupped=true;
            }
        }
        done:
        
        straight100dup=100*straight+dup;

        //UPDATE EVENT
        switch(straight100dup) 
        {
            case 0:
            {
                event=0; //Pass
                CardsPlayed=0;
                stringevent="Pass - Bỏ";
            } break;
            case 101:
            {
                event=1; //Single
                CardsPlayed=1;
                stringevent="Single - 1 Con";
            } break;
            case 102:
            {
                event=2; //Double
                CardsPlayed=2;
                stringevent="Double - Đôi";
            } break;
            case 301:
            {
                event=3; //Str. 3
                CardsPlayed=3;
                stringevent="Straight 3 - Sảnh 3";
            } break;
            case 401:
            {
                event=4; //Str. 4
                CardsPlayed=4;
                stringevent="Straight 4 - Sảnh 4";
            } break;
            case 501:
            {
                event=5; //Str. 5
                CardsPlayed=5;
                stringevent="Straight 5 - Sảnh 5";
            } break;
            case 601:
            {
                event=6; //Str. 6
                CardsPlayed=6;
                stringevent="Straight 6 - Sảnh 6";
            } break;
            case 701:
            {
                event=7; //Str. 7
                CardsPlayed=7;
                stringevent="Straight 7 - Sảnh 7";
            } break;
            case 801:
            {
                event=8; //Str. 8
                CardsPlayed=8;
                stringevent="Straight 8 - Sảnh 8";
            } break;
            case 901:
            {
                event=9; //Str. 9
                CardsPlayed=9;
                stringevent="Straight 9 - Sảnh 9";
            } break;
            case 1001:
            {
                event=10; //Str. 10
                CardsPlayed=10;
                stringevent="Straight 10 - Sảnh 10";
            } break;
            case 1101:
            {
                event=11; //Str. 11
                CardsPlayed=11;
                stringevent="Straight 11 - Sảnh 11";
            } break;
            case 1201:
            {
                event=12; //Str. 12
                CardsPlayed=12;
                stringevent="Straight 12 - Sảnh 12";
            } break;
            case 103:
            {
                event=13; //Triple
                CardsPlayed=3;
                stringevent="Triple - 3 Con";
            } break;
            case 104:
            {
                event=14; //Quadruple
                CardsPlayed=4;
                stringevent="Quadruple - Tứ Quý";
            } break;
            case 302:
            {
                event=15; //Str. 3 Double
                CardsPlayed=6;
                stringevent="Double Straight 3 - Ba Đôi Thông";
            } break;
            case 402:
            {
                event=16; //Str. 4 Double
                CardsPlayed=8;
                stringevent="Double Straight 4 - Bốn Đôi Thông";
            } break;
        }

        //CHECK IF THE VERY FIRST PLAYER PLAY 3♠︎
        if(decoyevent==-1)
        {
            for(int i=0;i<Table.size();i++)
            {
                if(Table[i].GetType()==1&&Table[i].GetValue()==3)
                {
                    goto have3bich;
                }
            }
            cout<<"\n! Your move must have 3♠︎ !";
            cout<<"\nChoose again: ";
            goto chooseagain;
            have3bich:
            ;
        }

        //CHECK IF THE ALGORITHM IS OKAY
        if(Table.size()!=CardsPlayed && event!=0)
        {
            cout<<"\n! Invalid Set (after switch) !";
            cout<<"\nChoose again: ";
            goto chooseagain;
        }

        //CHECK IF PLAYING SET IS CORRESPOND WITH THE CURRENT TABLE
        if(decoyevent==1 && decoyTable[decoyTable.size()-1].GetValue()==2 && (event==14 || event==15 || event==16))
        {
            goto afterchecksmaller;
        }
        else if(decoyevent==2 && decoyTable[decoyTable.size()-1].GetValue()==2 && (event==14 || event==16))
        {
            goto afterchecksmaller;
        }
        else if(decoyevent==15 && ((event==14 || event==16) || (event==15 && decoyTable[decoyTable.size()-1].GetValue()<Table[Table.size()-1].GetValue())))
        {
            goto afterchecksmaller;
        }
        else if(decoyevent==15 && event==15 && decoyTable[decoyTable.size()-1].GetValue()==Table[Table.size()-1].GetValue() && decoyTable[decoyTable.size()-1].GetType()<Table[Table.size()-1].GetType())
        {
            goto afterchecksmaller;
        }
        else if(decoyevent==14 && (event==16 || (event==14 && decoyTable[decoyTable.size()-1].GetValue()<Table[Table.size()-1].GetValue())))
        {
            goto afterchecksmaller;
        }
        else if(decoyevent==16 && event==16 && decoyTable[decoyTable.size()-1].GetValue()<Table[Table.size()-1].GetValue())
        {
            goto afterchecksmaller;
        }
        else if(event!=decoyevent && decoyevent!=-1 && event!=0 && decoyevent!=0)
        {
            cout<<"\n! Wrong type of Set ! Playing "<<EventToString(decoyevent);
            cout<<"\nChoose again: ";
            goto chooseagain;
        }

        //CHECK SMALLER
        if(decoyevent==-1);
        else if( event!=0
            &&
            (
                Table[Table.size()-1].GetValue()==1
                &&
                (
                    (
                        decoyTable[decoyTable.size()-1].GetValue()==1 
                        &&
                        Table[Table.size()-1].GetType()>decoyTable[decoyTable.size()-1].GetType()
                    )
                    ||
                    decoyTable[decoyTable.size()-1].GetValue()>2 
                )
            )
        );
        else if( event!=0
            &&
            (
                (
                    Table[Table.size()-1].GetValue()==2 
                    && 
                    (
                        (
                            decoyTable[decoyTable.size()-1].GetValue()==2 
                            &&
                            Table[Table.size()-1].GetType()>decoyTable[decoyTable.size()-1].GetType()
                        )
                        ||
                        decoyTable[decoyTable.size()-1].GetValue()!=2 
                    )
                )
                ||
                (
                    Table[Table.size()-1].GetValue()==1 
                    && 
                    (
                        (
                            decoyTable[decoyTable.size()-1].GetValue()==1 
                            &&
                            Table[Table.size()-1].GetType()>decoyTable[decoyTable.size()-1].GetType()
                        )
                        ||
                        (
                            decoyTable[decoyTable.size()-1].GetValue()>2 
                            && 
                            decoyTable[decoyTable.size()-1].GetValue()<14
                        )
                    )
                )
            )
        )
        ;//nothing happen
        else if( event!=0
            &&
            (
                (    
                    Table[Table.size()-1].GetValue()<decoyTable[decoyTable.size()-1].GetValue()
                    ||
                    ( 
                        Table[Table.size()-1].GetValue()==decoyTable[decoyTable.size()-1].GetValue()
                        &&
                        Table[Table.size()-1].GetType()<decoyTable[decoyTable.size()-1].GetType()
                    )
                )
                ||
                (
                    decoyTable[decoyTable.size()-1].GetValue()==1
                    &&
                    (
                        Table[Table.size()-1].GetValue()>2
                    )
                )
                ||
                (
                    decoyTable[decoyTable.size()-1].GetValue()==2
                    &&
                    (
                        Table[Table.size()-1].GetValue()>2 || Table[Table.size()-1].GetValue()==1
                    )
                )
            )
        )   
        {
            cout<<"\n! Set is smaller than the set on table !";
            cout<<"\nChoose again: ";
            goto chooseagain;
        }

        afterchecksmaller:

        //DELETE PLAYED CARDS IN HAND
        if(event!=0)
        {
            cout<<"\n!!!! Played !!!!\n\n";
            huongsoai=false;

            for(int i=0;i<Table.size();i++)
            {
                for(int j=0;j<Hand.size();j++)
                {
                    if(Hand[j].GetType()==Table[i].GetType() && Hand[j].GetValue()==Table[i].GetValue())
                    {
                        Hand.erase(Hand.begin()+j);
                        break;
                    }
                }
            }
        }
        else 
        {
            cout<<"\n!!!! Passed !!!!\n\n\n\n\n";
            Table=decoyTable;
            event=decoyevent;
            InRound=false;
        }

        //CHECK IF FINISHED
        if(Hand.size()==0)
        {
            Finished=true;
            cout<<"\n !__! Player "<<name<<" has finished the game !__!\n";
            huongsoai=true;
            ranking.push_back(name);
            PlayerLeft--;
        }

        /* just for testing
        cout<<"\nHand: ";
        for(int i=0;i<Hand.size();i++)
        {
            Hand[i].SymbolShow();
            cout<<"  ";
        }
        */

        //SHOW CURRENT TABLE 
        /*
        cout<<"\nTable: ";
        for(int i=0;i<Table.size();i++)
        {
            Table[i].SymbolShow();
            cout<<"   ";
        }
        cout<<"\n< "<<stringevent<<" >\n\n\n";
        */

        return event;
        
    }
string EventToString(int event){
        switch(event) 
        {
            case 0:
            {
                return "Pass - Bỏ";
            } break;
            case 1:
            {
                return "Single - 1 Con";
            } break;
            case 2:
            {
                return "Double - Đôi";
            } break;
            case 3:
            {
                return "Straight 3 - Sảnh 3";
            } break;
            case 4:
            {
                return "Straight 4 - Sảnh 4";
            } break;
            case 5:
            {
                return "Straight 5 - Sảnh 5";
            } break;
            case 6:
            {
                return "Straight 6 - Sảnh 6";
            } break;
            case 7:
            {
                return "Straight 7 - Sảnh 7";
            } break;
            case 8:
            {
                return "Straight 8 - Sảnh 8";
            } break;
            case 9:
            {
                return "Straight 9 - Sảnh 9";
            } break;
            case 10:
            {
                return "Straight 10 - Sảnh 10";
            } break;
            case 11:
            {
                return "Straight 11 - Sảnh 11";
            } break;
            case 12:
            {
                return "Straight 12 - Sảnh 12";
            } break;
            case 13:
            {
                return "Triple - 3 Con";
            } break;
            case 14:
            {
                return "Quadruple - Tứ Quý";
            } break;
            case 15:
            {
                return "Double Straight 3 - Ba Đôi Thông";
            } break;
            case 16:
            {
                return "Double Straight 4 - Bốn Đôi Thông";
            } break;
        }
        return "0";
}