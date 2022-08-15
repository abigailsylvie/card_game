#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include "messages.h"
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

class Game{
     /*
        ------------------- ATTRIBUTES------------------------
             player: keep the human player
             computer: keep the computer player
             deck: collection of all cards
             roundsTail: tracks the last played round
    */
private:
    Player *player;
    Player *computer;
    Deck *deck;
    int roundTail;


    /*
            -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
             Game(): creates a new object of type Game
             ~Game(): destroys object of type Game
    */
public:
    Game(); 
    ~Game();

     /*
        -------------------ACCESSORS-------------------
        
                        GETTERS
             GetPlayer(): returns human player
             GetComputer(): returns the machine player
             GetDeck(): returns the deck
             GetRoundsTail(): returns the roundstail
    */
    Player* GetPlayer();
    Player* GetComputer();
    Deck* GetDeck();
    int GetRoundsTail();

     /*
        ---------------------SETTERS---------------------
         SetPlayer(): updates the human player
         SetComputer(): updates the machine player
         SetDeck(): updates games's deck
         SetRoundsTail(): updates the roundstail
    */

    void SetPlayer(Player*);
    void SetComputer(Player*);
    void SetDeck(Deck*);
    void SetRoundsTail(int);


    /*
        ---------------------METHODS---------------------
         Welcome(): prints welcome message
        InitGame(): Initializes the by generating the Deck
         PrintStatistics(): prints games's statistics
         PlayRound(): Starts a new round
    */

    // void Welcome();
    void StartGame();
    void InitGame();
    void PrintStatistics();
    bool Play();
    void AnnounceWinner(Card[], Card[]);
    void GameOver();
    void AnnounceFinalWinner(int, int);


};