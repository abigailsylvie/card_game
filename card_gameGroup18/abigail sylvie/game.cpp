#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include "messages.h"
#include "card.h"
#include "player.h"
#include "deck.h"
#include "game.h"
#include "color.h"

using namespace std;


string nickname = "";


/*
            -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            - Game(): creates a new object of type Game
            - ~Game(): destroys object of type Game
    */
    Game::Game(){
        
        
        if(nickname ==""){
            cout<<endl
            <<"\t " <<"\t"
            <<"Enter your nickname: ";
            cin>>nickname;
        }
       
        this->player = new Player(nickname);
        this->computer = new Player("BlackMoon");
        this->deck = new Deck();
        this->roundTail = 0;
    } 
    Game::~Game(){
        this->player = NULL;
        this->computer = NULL;
        this->deck = NULL;
        this->roundTail = 0;
    }

     /*
        -------------------ACCESSORS-------------------
        
                        GETTERS
            - GetPlayer(): returns human player
            - GetComputer(): returns the machine player
            - GetDeck(): returns the deck
           - GetRoundsTail(): returns the roundstail
    */
    Player* Game::GetPlayer(){
        return this->player;
    }
    Player* Game::GetComputer(){
        return this->computer;
    }
    Deck* Game::GetDeck(){
        return this->deck;
    }
    int Game::GetRoundsTail(){
        return this->roundTail;
    }

     /*
        ---------------------SETTERS---------------------
        - SetPlayer(): updates the human player
        - SetComputer(): updates the machine player
        - SetDeck(): updates games's deck
        - SetRoundsTail(): updates the roundstail
    */

    void Game::SetPlayer(Player* player){
        this->player = player;
    }
    void Game::SetComputer(Player* computer){ 
        this->computer = computer;
    }
    void Game::SetDeck(Deck* deck){
        this->deck = deck;
    }
    void Game::SetRoundsTail(int rounds){
        this->roundTail = rounds;
    }


    /*
        ---------------------METHODS---------------------
        - Welcome(): prints welcome message
        - InitGame(): Initializes the by generating the Deck
        - PrintStatistics(): prints games's statistics
        - PlayRound(): Starts a new round
    */

    // void Game::Welcome(){
    //     UtilsFunctions *utils;
    //     utils->Welcome();
    // }
    void Game::InitGame(){
        std::cout<<"\a";
B:
        Player *player = this->player;
        Player *computer = this->computer;
        UtilsFunctions *utils = new UtilsFunctions();
        char isSatisfied;
        stack<Card> playerHand;
        stack<Card> computerHand;

        Deck *deck = this->deck;

        A:
            playerHand = deck->PickHand();
            player->SetHand(playerHand);
            cout<<"......................................";
            cout<<".................................................\n";
            cout<<"\t "<<"\t "
                <<endl<<"YOUR CARDS: " 
              
                <<endl;
            //printing user hand
            cout<<lightCyan;
            utils->PrintHand(playerHand);
            cout<<lightGreen;
        
        cout<<"Press C to change hand or any other key to continue: ";
        cin>>isSatisfied;
        std::cout<<"\a";

        switch(isSatisfied){
            case 'C':
                    //Putting back the cards
                 while(!playerHand.empty()){
                    deck->PutBackCard(playerHand.top());
                    playerHand.pop();
                    }
                    goto A;
                    break;
            case 'c':
                  //Putting back the cards
                 while(!playerHand.empty()){
                    deck->PutBackCard(playerHand.top());
                    playerHand.pop();
                    }
                    goto A;
                    break;
            default:
                break;

        }

        computerHand = deck->PickHand();
        computer->SetHand(computerHand);

            cout<<"......................................";
            cout<<".................................................\n";
            cout<<"\t "<<"\t "<<endl<<"COMPUTER'S CARDS: "<<endl;
            //printing computer's hand
            cout<<red;
            utils->PrintHand(computerHand);
            cout<<lightGreen;
            system("pause");

        this->Play();

    }




    void Game::PrintStatistics(){
        std::cout<<"\a";
        Player *player = this->player;
        Player *computer = this->player;
        int roundTail = this->GetRoundsTail();
        
        cout<<endl <<"\t " <<"\t "<<"\t ";
        cout<<lightMagenta
            <<"Name: "
            <<bold_on<<player->GetPlayerName()
            <<"\t ";

        cout<<green
            <<"Rounds played: "
            <<this->GetRoundsTail()
            <<"\t ";

        cout<<green
            <<"Wins: "
            <<player->GetWins()
            <<"\t ";

        cout<<red
            <<"Loses: "
            <<player->GetLoses()
            <<"\t "
            <<bold_off
            <<lightGreen;


        cout<<endl;
    }



     void Game::StartGame(){
         int choice;
    
    UtilsFunctions *utils = new UtilsFunctions();
    Messages *messages = new Messages();

    while(true){
        utils->Welcome();
        cout<<messages->Menu();
        cout<<"Press the corresponding key to your choice: ";
         cin>>choice;
         Game *game;
         
        switch(choice){
            case 1:
                
                utils->Welcome();
                game = new Game();
                game->PrintStatistics();
                game->InitGame();
                break;    
            case 2:
                cout<<messages->HowToplay();
                system("pause > 0");
                break;
            case 3:
                utils->Gallery();
                system("pause");
                break;
            case 4:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }
    //Point de repere
     }



   void Game::AnnounceFinalWinner(int playerWins, int playerLoses){
       std::cout<<"\a";
       Messages *messages = new Messages();
       if(playerWins > playerLoses){

        cout<<messages->Victory(); 
        system("pause");
        
       }
       else if (playerWins == playerLoses ) {
           cout <<endl<<"******************DRAW MATCH!******************";
       }
       else {
           cout<<messages->Lost();
           system("pause");   
              
           }
   }


    bool Game::Play(){
        std::cout<<"\a";

            Player *player  = this->player;
            stack<Card> playerHand = player->GetHand();
            Player *computer = this->computer;
            stack<Card> computerHand = computer->GetHand();
            Messages *messages = new Messages();

            int lastRound = this->roundTail;

            Card _computerHand[5];
            Card _playerHand[5];
            int index = 0;
            while(!playerHand.empty()){
                _playerHand[index] = playerHand.top();
                playerHand.pop();
                index++;
                
            }
            index = 0;
            while(!computerHand.empty()){
                _computerHand[index] = computerHand.top();
                computerHand.pop();
                index++;
                
            }
            cout<<"\t \t"
                <<"-------------------------"
                <<"PLAYING ROUND " + std::to_string(roundTail + 1)
                <<"-----------------------"
                <<endl <<endl;
            for(int i =0; i<5; i++){

                cout<<_playerHand[i].GetName()
                    <<" ( " << _playerHand[i].GetWorth() <<" ) "
                    <<"  -------------"
                    <<" VS "
                    <<" -------------- "
                    <<_computerHand[i].GetName()
                    <<" ( " << _computerHand[i].GetWorth() <<" ) ";
                    

                    if(_computerHand[i].GetWorth() > _playerHand[i].GetWorth()){
                        cout<<" ==> "
                            <<_computerHand[i].GetName()
                            <<" WINS!"
                            <<endl
                            <<endl;
                            
                    }
                    else if(_computerHand[i].GetWorth() == _playerHand[i].GetWorth()){
                            cout<<"NO WINNER" <<endl<<endl;
                    }
                    else{
                        cout<<" ==> "
                            <<_playerHand[i].GetName()
                            <<" WINS! (YOU WON)"
                            <<endl
                            <<endl;
                            
                            
                      }
            }

            this->AnnounceWinner(_computerHand, _playerHand);
            this->SetRoundsTail(lastRound + 1);

            cout<<endl<<"\t \t \t YOUR STATISTICS..."<<endl;
            this->PrintStatistics();

            char isGamecontinuing;
            if(this->roundTail <=2){
                cout<<endl<<"Press C to continue or any other letter to exit: ";
                std::cout<<"\a";
                cin>>isGamecontinuing;
                if(isGamecontinuing == 'C' || isGamecontinuing == 'c'){
                    if( (this->roundTail == 2) && (player->GetWins() == 0)  ){
                        cout<<messages->GameOver();
                         cout<<"\t \t YOUR STATISTICS..."<<endl;
                         
                        /* AnnounceFinalWinner(player->GetWins(), player->GetLoses());
                         this->PrintStatistics();
                         system("pause");*/
                         

                    }
                else{
                    
                    this->InitGame();
                    cout<<"\t \t \t-------------- FINAL STATISTICS------------------"<<endl;
                    AnnounceFinalWinner(player->GetWins(), player->GetLoses());
                    this->PrintStatistics();
                   
                
                }
                  
            }
                }
                else{
                    cout<<"\t \t \t-------------- FINAL STATISTICS------------------"<<endl;
                    AnnounceFinalWinner(player->GetWins(), player->GetLoses());
                    this->PrintStatistics();
                    
            }
            }
    //}



    void Game::AnnounceWinner(Card computerHand[], Card playerHand[]){
        std::cout<<"\a";
        int computerHandWorth = 0;
        int playerHandWorth = 0;
        Messages *messages = new Messages();
        for(int i = 0; i<5; i++){
            computerHandWorth += computerHand[i].GetWorth();
            playerHandWorth += playerHand[i].GetWorth();
        }

            cout<<endl<<"\t \t \t" 
                <<"YOU ( " << playerHandWorth<<" POINTS) "
                <<"  ***********"
                <<" VS "
                <<" ************ "
                <<" COMPUTER( " << computerHandWorth<<" POINTS) ";

        if(playerHandWorth > computerHandWorth){
            Player *player = this->player;
            player->SetWins(player->GetWins() + 1);
            
            cout<<green
                <<messages->Youwin();
            cout<<def;
        }
        else if(playerHandWorth == computerHandWorth){
            cout<<messages->NoWinner();
        }
        else{
            cout<<red
                <<messages->YouLose();
            cout<<def;
            player->SetLoses(player->GetLoses() + 1);
            
        }
    }

    void Game::GameOver(){
        std::cout<<"\a";
        Messages *messages = new Messages();
        cout<<messages->GameOver();
        this->PrintStatistics();
        exit(0);
    }