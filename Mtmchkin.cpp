#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

#define MAX_LEVEL 10

//-------------------------constructors-------------------------------------
Mtmchkin::Mtmchkin(const char* playerName, Card* cardsArray, int numOfCards):
                    m_playerName(playerName) ,m_player(Player(playerName)),m_cardsArray(new Card[numOfCards]),
                    m_status(GameStatus::MidGame),m_numOfCards(numOfCards)
{
    for(int i = 0 ; i < numOfCards; i++){
        m_cardsArray[i] = cardsArray[i];
    }
}
//--------------------------------------------------------------------------
Mtmchkin::~Mtmchkin(){
    delete[] m_cardsArray;
}
//--------------------------------------------------------------------------
Mtmchkin::Mtmchkin(const Mtmchkin& instance):m_playerName(instance.m_playerName) ,m_player(instance.m_player),
                                            m_cardsArray(new Card[instance.m_numOfCards]),
                                            m_status(instance.m_status),m_numOfCards(instance.m_numOfCards){

    for(int i = 0 ; i < numOfCards; i++){
        m_cardsArray[i] = instance.m_cardsArray[i];
    }
}
//--------------------------------------------------------------------------
    Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other){
        if(this == &other){
            return *this;
        }
        m_player = other.m_player;
        m_playerName = other.m_playerName;
        m_numOfCards = other.m_numOfCards;
        delete[] m_cardsArray;
        m_cardsArray = new card[other.m_numOfCards];
        m_status = other.m_status;
        for(int i = 0 ; i < other.m_numOfCards; i++){
        m_cardsArray[i] = other.m_cardsArray[i];
        }
        return *this;
    }
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
