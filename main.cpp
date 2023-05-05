#include"cpplibduc.h"
#include"class_used.h"
#include"rearrange.h"
#include"gamemode.h"

int main(){
    cout<<endl;
    InitProgram();

    int gamemode;
    cout<<"\nChoose gamemode: ";cin>>gamemode;

    vector<Card> OriginalDeck; 
    InitializeDeck(OriginalDeck);

    //Shuffle
    vector<Card> Deck;
    Shuffle(Deck,OriginalDeck);
    
    switch(gamemode)
    {
        case(1):
        {
            PlayThirteen(Deck);
        } break;
        case(2):
        {
            PlayBlackJack(Deck);
        } break;
        default:
        {
            cout<<"\n! Gamemode not available !";
        } break;
    }
    
    return 0;
}
/*
    cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";//0
    cout<<"\n|          ThisIsNameLength2020     ThisIsNameLength2020(ThisIsNameLength20)ThisIsNameLength2020     ThisIsNameLength2020          |";//1
    cout<<"\n|          9♣︎  2♣︎  A♣︎  10♣︎ 3♣︎      [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?]      [?] [?] [?] [?] [?]           |";//2
    cout<<"\n|          !    Black Jack    !                                                                                                    |";//3
    cout<<"\n|                                                                                                                                  |";
    cout<<"\n|                                                                                                                                  |";//5
    cout<<"\n|     ThisIsNameLength2020                                                                                ThisIsNameLength2020     |";//6
    cout<<"\n|     [?]                                                                                                                  9♣︎      |";//7
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";//11
    cout<<"\n|                                                                                                                                  |";
    cout<<"\n|                                                                                                                                  |";//13    
    cout<<"\n|     ThisIsNameLength2020                                                                                ThisIsNameLength2020     |";//14
    cout<<"\n|     [?]                                                                                                                  [?]     |";//15
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";//19
    cout<<"\n|                                                                                                                                  |";
    cout<<"\n|     <B L A C K  J A C K>                                                                                                         |";//21
    cout<<"\n|     ThisIsNameLength2020                                                                                ThisIsNameLength2020     |";//22
    cout<<"\n|     [?]                                                                                                                  [?]     |";//23
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";
    cout<<"\n|     [?]                                                                                                                  [?]     |";//27
    cout<<"\n|                                                                                                                                  |";
    cout<<"\n|     <B L A C K  J A C K>     <FIVE CARDS CHARLIE>                                                                                |";//29
    cout<<"\n|     [?] [?] [?] [?] [?]      [?] [?] [?] [?] [?]      [?] [?] [?] [?] [?]      [?] [?] [?] [?] [?]      [?] [?] [?] [?] [?]      |";//30
    cout<<"\n|     ThisIsNameLength2020     ThisIsNameLength2020     (ThisIsNameLength20)     ThisIsNameLength2020     ThisIsNameLength2020     |";//31
    cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";//32
*/