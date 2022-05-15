#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

#define MAX_LEVEL 10

//--------------------------------------------------------------------------
Mtmchkin::Mtmchkin(const char* playerName, Card* cardsArray, int numOfCards):
m_playerName(playerName) ,m_player(Player(playerName)),m_cardsArray(cardsArray),m_status(GameStatus::MidGame),m_numOfCards(numOfCards)
{}

//--------------------------------------------------------------------------
void Mtmchkin::playNextCard(){

    Card curr_card = *m_cardsArray;
    curr_card.printInfo();
    curr_card.applyEncounter(m_player);
    m_player.printInfo();
    //---------------------------------
    for(int i = 0; i < m_numOfCards - 1; i++){
        m_cardsArray[i] = m_cardsArray[i + 1];
    }
    m_cardsArray[m_numOfCards - 1] = curr_card;
    //---------------------------------
    if(m_player.isKnockedOut()){
        m_status = GameStatus::Loss;
    }
    //---------------------------------
    if(m_player.getLevel() == MAX_LEVEL){
        m_status = GameStatus::Win;
    }
}
//--------------------------------------------------------------------------
bool Mtmchkin::isOver() const{
    if (m_status == GameStatus::Win){
        return true;
    }
    if (m_status == GameStatus::Loss){
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------
    GameStatus Mtmchkin::getGameStatus() const{
       return m_status;
    }
//--------------------------------------------------------------------------
