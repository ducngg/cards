# cards
Play Thirteen(Vietnamese Tien Len) and Blackjack(also Vietnamese rules)

Feb 4 2022
A game played in terminal, playing cards in Tet holiday is one of our tradition, therefore as a Vietnamese, I must learn the rules in order to have the best strategy to beat my friends and family members. That's the reason why this project is made in that time!

# Thirteen
The algorithm is not just if-else, in order to check validation of the playing cards(and compare them), I've come to an idea of using just 2 variables to check them like below.

<img width="493" alt="image" src="https://github.com/ducngg/cards/assets/89516843/84b552ba-3009-462a-b0f1-dd2016076391">

Example: 
straight=1, dup=2 -> Played Double (event 2)
straight=5, dup=1 -> Played Straight 5 (event 5)
straight=3, dup=2 -> Played Straight 3 Duo (event 15) (Ba đôi thông)

Alter the player choose what to play, the program will check if the cards played will return an event (playable) or not (like '3' '3' '4' '5' '5' will not return any valid event).

Then it will check if the event is the same with the previous player has played (there are some special cases that different event is still valid like Quadruple can beat single '2').

Finally it will check if the cards played is larger than the previous ones.

