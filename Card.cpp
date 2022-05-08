
#ifndef EX2_CARD_CPP
#define EX2_CARD_CPP
#include "Card.h"



//----------------------ApllyEncounter-----------------------
void Card::applyEncounter(Player& player) const{
    if(m_effects == CardType::Battle){
        bool win = true;
        if(player.getAttackStrength()>=m_stats->force){
            printBattleResult(win);
            player.levelUp();
            player.loot(m_stats->loot);
        }
        else{
            player.damage(m_stats->hpLossOnDefeat);
            win = false;
            printBattleResult(win);
            if(player.isKcnockedOut()){
                std::cout << "Player is knocked out";
            }
        }
    }
    if(m_effects == CardType::Buff){
        if(player.pay(m_stats->cost)){
            player.buff(m_stats->buff);
        }
        else{
            std::cout << "Not enough coins";
        }
    }
    if(m_effects == CardType::Heal){
        if(player.pay(m_stats->cost)){
            player.heal(m_stats->heal);
        }
        else{
            std::cout << "Not enough coins";
        }
    }
    if(m_effects == CardType::Treasure){
        player.addCoins(m_stats->loot);
    }
}
//----------------------PrintCardInfo------------------------
    void Card::printInfo() const {
        if (m_effects == CardType::Battle){
            printBattleCardInfo(m_stats);
        }

        if (m_effects == CardType::Buff){
            printBuffCardInfo(m_stats);
        }

        if (m_effects == CardType::Heal){
            printHealCardInfo(m_stats);
        }

        if (m_effects == CardType::Treasure){
            printTreasueCardInfo(m_stats);
        }
    }










#endif