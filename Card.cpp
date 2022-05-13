
#ifndef EX2_CARD_CPP
#define EX2_CARD_CPP
#include "Card.h"
#include <iostream>

//-----------------------constructor-------------------------
Card::Card(CardType type, const CardStats& stats){
    m_effect= type;
    m_stats = stats;
}
//----------------------ApllyEncounter-----------------------
void Card::applyEncounter(Player& player) const{
    if(m_effect == CardType::Battle){
        bool win = true;
        if(player.getAttackStrength()>= m_stats.force){
            printBattleResult(win);
            player.levelUp();
            player.addCoins(m_stats.loot);
        }
        else{
            player.damage(m_stats.hpLossOnDefeat);
            win = false;
            printBattleResult(win);
            if(player.isKnockedOut()){
                std::cout << "Player is knocked out";
            }
        }
    }
    if(m_effect == CardType::Buff){
        if(player.pay(m_stats.cost)){
            player.buff(m_stats.buff);
        }
        else{
            std::cout << "Not enough coins";
        }
    }
    if(m_effect == CardType::Heal){
        if(player.pay(m_stats.cost)){
            player.heal(m_stats.heal);
        }
        else{
            std::cout << "Not enough coins";
        }
    }
    if(m_effect == CardType::Treasure){
        player.addCoins(m_stats.loot);
    }
}
//----------------------PrintCardInfo------------------------
    void Card::printInfo() const {
        if (m_effect == CardType::Battle){
            printBattleCardInfo(m_stats);
        }

        if (m_effect == CardType::Buff){
            printBuffCardInfo(m_stats);
        }

        if (m_effect == CardType::Heal){
            printHealCardInfo(m_stats);
        }

        if (m_effect == CardType::Treasure){
            printTreasureCardInfo(m_stats);
        }
    }










#endif