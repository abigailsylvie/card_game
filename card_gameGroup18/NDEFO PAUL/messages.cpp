#include "messages.h"
#include<string>
#include<ostream>
#include<sstream>
using namespace std;

/**
 * @brief 
    CONSTEXPR: constexpr is a keyword introduced in C++ 11
    It is somehow like the 'const' keyword but it can also be applied on functions
    The main idea is to help programs to do computations in compilation time rather than run time

    AUTO: The auto keyword specifies that the type of the variable that is 
    being declared will be automatically deducted from its initializer.
 * 
 * @return string 
 */


 /**
 * @brief 
    ------------------------------METHODS----------------------------
        - string Game(): returns the string message 'BLACK MOON'
         - string  Menu(): returns the string message of the game MENU
        - string  Youwin(): returns the string message 'EUREKA! YOU WON...'
         -string  GameOver(): returns the string message 'GAME OVER'
        - string  NoWinner(): returns the string message 'NO WINNER'
        - string  Lost(): returns the string message 'YOU LOST'
        -string  Victory(): returns the string message 'VICTORY'
        - string  Deck(): returns the string message 'DECK'
 * 
 */


    string Messages::Game(){
        constexpr auto blackmoon = R"(
     ___                      ___                                                ___                           
    (   )                    (   )                                              (   )                          
  .-.| |    .--.     .--.     | |   ___      ___ .-. .-.     .---.      .--.     | |_       .--.    ___ .-.    
 /   \ |   /    \   /    \    | |  (   )    (   )   '   \   / .-, \   /  _  \   (   __)    /    \  (   )   \   
|  .-. |  |  .-. ; |  .-. ;   | |  ' /       |  .-.  .-. ; (__) ; |  . .' `. ;   | |      |  .-. ;  | ' .-. ;  
| |  | |  |  | | | |  |(___)  | |,' /        | |  | |  | |   .'`  |  | '   | |   | | ___  |  | | |  |  / (___) 
| |  | |  |  |/  | |  |       | .  '.        | |  | |  | |  / .'| |  _\_`.(___)  | |(   ) |  |/  |  | |        
| |  | |  |  ' _.' |  | ___   | | `. \       | |  | |  | | | /  | | (   ). '.    | | | |  |  ' _.'  | |        
| '  | |  |  .'.-. |  '(   )  | |   \ \      | |  | |  | | ; |  ; |  | |  `\ |   | ' | |  |  .'.-.  | |        
' `-'  /  '  `-' / '  `-' |   | |    \ .     | |  | |  | | ' `-'  |  ; '._,' '   ' `-' ;  '  `-' /  | |        
 `.__,'    `.__.'   `.__,'   (___ ) (___)   (___)(___)(___)`.__.'_.   '.___.'     `.__.    `.__.'  (___)       
                                                                                                                                            

        )";
        std::ostringstream _blackmoon; //declaring a new output stream variable
        _blackmoon << blackmoon; //writing the raw string in the output stream
        system("cls");
        system("cls");
        return _blackmoon.str(); //returning the string content of the output stream
    }


    string Messages::Youwin(){
        constexpr auto youwin = R"(
                
                          YOU WIN     
                                                          
                                                                                      

        )";
         std::ostringstream _youwin;
        _youwin << youwin; 
        return _youwin.str();
    }
    string Messages::YouLose(){
            constexpr auto youlose = R"(    
                                           DEFAITE
            )";

        std::ostringstream _youlose;
        _youlose << youlose; 
        return _youlose.str();
    }

    string Messages::GameOver(){
        constexpr auto gameOver = R"(
            
                                     GAME OVER
                                                                                        
                                                    

        )";
     std::ostringstream _gameOver;
        _gameOver << gameOver; 
        return _gameOver.str();
    }
    

    string Messages::HowToplay(){
        constexpr auto howtoPlay = R"(
            1. The goal in Game cards is to beat the computer's    
                     hand with a hand of greater worth                       
                     (sum of cards in the hand)  

            2. Gallery provides you with deck, color and value of cards 

            3. Pressing C asks for another hand of cards. Pressing other 
            keys holds your total(hand) and end your turn.   

            4. Your name is required before the start of the game.   
              
            5. A lower hand worth means you lose the game       
                                                                                
                _ (Press any key to continue) 
    
        )";

        
        std::ostringstream _howtoPlay;
        _howtoPlay << howtoPlay; 
        return _howtoPlay.str();
    }

    string Messages::NoWinner(){
        constexpr auto noWinner = R"(
            
                                 NO WINNER/PAS DE GAGNANT                                                                    
                                                    

        )";
     std::ostringstream _noWinner;
        _noWinner << noWinner; 
        return _noWinner.str();
    }

    string Messages::Menu(){
        constexpr auto menu = R"(
                    1-Start a new Game           
                    2-How to Play?           
                    3-Gallery             
                    4-Exit                  
        )";
     std::ostringstream _menu;
        _menu << menu; 
        return _menu.str();
    }

    string Messages::Victory(){
        constexpr auto victory = R"(
            VICTORY/VICTOIRE

        )";
     std::ostringstream _victory;
        _victory << victory; 
        return _victory.str();
    }

    string Messages::Lost(){
        constexpr auto lost = R"(
            
                                      YOU LOST /VOUS AVEZ PERDUE

        )";
     std::ostringstream _lost;
        _lost << lost; 
        return _lost.str();
    }

     string Messages::Deck(){
        constexpr auto  deck = R"(
                
                                  
                                  DECK

        )";
     std::ostringstream _deck;
        _deck << deck; 
        return _deck.str();
    }