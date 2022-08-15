#include "utils.h"
#include "card.h"
#include "color.h"
#include "messages.h"
#include "deck.h"
#include<string>
#include<iostream>
using namespace std;





string UtilsFunctions::getCardName(string suite, int worth){
    switch(worth){
        case 1:
            return ("ACE_OF_" + suite);
            break;
        case 11:
            return ("JACK_OF_" + suite);
            break;
        case 12:
            return ("QUEEN_OF_" + suite);
            break;
        case 13:
            return ("KING_OF_" + suite);
            break;
        default:
            return (std::to_string(worth) + "_OF_" + suite);
    }
}




/**
 * @brief 
    The function printHand take the Hand of the player as paramter and
        display it to the user
 * 
 * @param stack<Card> cards 
 */
void UtilsFunctions::PrintHand(stack<Card> cards){
    Messages *messages = new Messages(); //creates a new object of type Messages

            /*
                Transform the player's hand from stack<Card> to an array in
                order to manipulate it easily

            */

    Card hand[5];
    int index = 0;
    while(!cards.empty()){
        hand[index] = cards.top();
        index++;
        cards.pop();
        
    }



    /*  Printing the the names of the card */
    std::cout<<"\n";
    for(int i = 0; i<5; i++){
        cout<<hand[i].GetName()<<"\t";
    }


    /* 
        ----------PRINTING THE CARD-------------
         ♦ It prints the cards line by line
         ♦ Each suite has a unique design
    
    */
        std::cout<<"\n";
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                Card card = hand[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }



        //Determining the design of the card according to its suite
                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }



                /* -----Printing the cards line by line------*/

                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        std::cout<<"\n";
    }
    for(int i=0; i<5; i++){
     cout<<"Worth:"<<hand[i].GetWorth();
        
                string suite = hand[i].GetSuite();
                cout<<"("<<hand[i].GetColor(suite)<<")\t";}

}




    /**
     * @brief Welcome(): prints the name of the game
     * 
     */

    void UtilsFunctions::Welcome(){
        Messages *messages = new Messages();
        string _welcome = messages->Game();
        cout<<blue<<_welcome;
    }



    /**
     * @brief 
     -------DISPLAY THE GAME MENU TO THE USER------

     * 
     * @return true (If the user wants to starts a new game)
     * @return false  (If the user choses another option)
     */
    bool UtilsFunctions::Menu(){
        int choice;
        Messages *msg = new Messages();
        constexpr auto menu = R"(
            1-Start a new Game
            2-How to Play?
            3-Settings
            4-Gallery
            5-Exit
            (Press the keep corresponding to you choice)  
        )";

        switch(choice){
            case 1:
                cout<<"\a";
                return true;
                break;
            case 2:
                cout<<"\a";
                cout<<msg->HowToplay();
                return false;
                break;
            case 3:
                cout<<"\a";
                cout<<msg->HowToplay();
                return false;
                break;
            case 4:
                cout<<"\a";
                exit(0);
                return false;
                break;
        }
    }

    void UtilsFunctions::Settings(){
        int choice;
        string settings[3]={
            "1- Change Game Theme",
            "2- Use Joystick",
            "3- Return to main menu"
        };
        for(int i = 1; i<= 3; i++){
            cout<<settings[i];
        }
        switch(choice){
            case 1:
                system("cls");
                this->Welcome();
                 system("color 0A");
        }
        
    }

    
    /**
    * @brief 
     Gallery(): 
                ♦ Prints the Deck of 52 cards 
                ♦ It prints each card with its name, color and value
    * 
    */

    void UtilsFunctions::Gallery(){
        Deck *deck = new Deck();
        Messages *messages = new Messages();
        vector<Card> cards = deck->GetCards();
        cout<<messages->Deck();         

        for(int i = 0; i<10; i++){
        cout<<cards[i].GetName()<<"\t";
    }
    std::cout<<"\n";
           
        for(int i = 0; i< 6; i++){
            for(int j = 0; j<10; j++){
                Card card = cards[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string color = card.GetColor(suite);
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }


                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }
                
                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        
        std::cout<<"\n";
    }
     for(int i = 0; i<10; i++){
          cout<<"Worth:"<<cards[i].GetWorth();
         Card card = cards[i];
                string suite = card.GetSuite();
                cout<<"("<<cards[i].GetColor(suite)<<")\t";
    }
    std::cout<<"\n\n";
    for(int i = 20; i<30; i++){
        cout<<cards[i].GetName()<<"\t";
    }
        std::cout<<"\n";
        for(int i = 0; i< 6; i++){
            for(int j = 20; j<30; j++){
                Card card = cards[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }


                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }
                
                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        std::cout<<"\n";
    }
for(int i = 10; i<20; i++){
        cout<<"Worth:"<<cards[i].GetWorth();
         Card card = cards[i];
                string suite = card.GetSuite();
                cout<<" ("<<cards[i].GetColor(suite)<<")\t";
    }
    std::cout<<"\n\n";
    for(int i = 0; i<10; i++){
        cout<<cards[i].GetName()<<"\t";
    }
        std::cout<<"\n";
        for(int i = 0; i< 6; i++){
            for(int j = 0; j<10; j++){
                Card card = cards[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }


                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }
                
                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        std::cout<<"\n";
    }
for(int i = 20; i<30; i++){
       cout<<"Worth:"<<cards[i].GetWorth();
         Card card = cards[i];
                string suite = card.GetSuite();
                cout<<"("<<cards[i].GetColor(suite)<<")\t";
    }
    std::cout<<"\n\n";
    for(int i = 30; i<40; i++){
        cout<<cards[i].GetName()<<"\t";
    }
        std::cout<<"\n";
        for(int i = 0; i< 6; i++){
            for(int j = 30; j<40; j++){
                Card card = cards[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }


                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }
                
                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        std::cout<<"\n";
    }
for(int i = 30; i<40; i++){
         cout<<"Worth:"<<cards[i].GetWorth();
         Card card = cards[i];
                string suite = card.GetSuite();
                cout<<"("<<cards[i].GetColor(suite)<<")\t";
    }

    std::cout<<"\n\n";
    for(int i = 40; i<50; i++){
        cout<<cards[i].GetName()<<"\t";
    }
        
        std::cout<<"\n";
        for(int i = 0; i< 6; i++){
            for(int j = 40; j<50; j++){
                Card card = cards[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }


                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }
                
                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        std::cout<<"\n";
    }



    
for(int i = 40; i<50; i++){
        cout<<"Worth:"<<cards[i].GetWorth();
         Card card = cards[i];
                string suite = card.GetSuite();
                cout<<"("<<cards[i].GetColor(suite)<<")\t";
    }
    std::cout<<"\n\n";
    for(int i = 50; i<52; i++){
        cout<<cards[i].GetName()<<"\t";
    }
        
        std::cout<<"\n";
        for(int i = 0; i< 6; i++){
            for(int j = 50; j<52; j++){
                Card card = cards[j];
                string suite = card.GetSuite();
                int worth = card.GetWorth();
                string name = card.GetName();
                string design;
                string cardWorth;


                 switch(worth){
                     case 1:
                        cardWorth = "A"; break;
                    case 10:
                        cardWorth = "X"; break;
                    case 11:
                        cardWorth = "J"; break;
                    case 12:
                        cardWorth = "Q"; break;
                    case 13:
                        cardWorth = "K"; break;
                    default:
                        cardWorth = std::to_string(worth);
                }


                if(suite == "CLUB"){
                    design = "| :(): |" ;
                }
                else if(suite == "HEART"){
                    design = "| (\\/) |";
                }
                else if(suite == "DIAMOND"){
                    design = "|  //  |";
                }
                else{
                    design = "| :/\\: |";
                }
                
                switch(i){
                case 0: std::cout<<".------.\t"; break;
                case 1: std::cout<<"|"<<cardWorth<<".--. |\t"; break;
                case 2: std::cout<<design <<"\t"; break;
                case 3: std::cout<<design <<"\t"; break;
                case 4: std::cout<<"| '--'"<<cardWorth<<"|\t"; break;
                case 5: 
                std::cout<<"`------'\t";
            }
           
        }
        std::cout<<"\n";
    }
                        
for(int i = 50; i<52; i++){
        cout<<"Worth:"<<cards[i].GetWorth();
         Card card = cards[i];
                string suite = card.GetSuite();
                cout<<"("<<cards[i].GetColor(suite)<<")\t";
    }
    }