
#include "utilities.h"
#include <iostream>
#include "Player.h"


#define MAX_LEVEL 10



    void Player::printInfo() const{
        printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);
    }

    void Player::levelUp(){
        if(m_level < MAX_LEVEL){
            m_level++;
        }
    }


    int Player::getLevel() const{
        return m_level;
    }


    void Player::buff(const int add_force){
        m_force += add_force;
    }


    void Player::heal(const int add_hp){
        if((m_hp + add_hp) > (m_max_hp)){
            m_hp = m_max_hp;
        }
        else{
            m_hp += add_hp;
        }
    }


    void Player::damage(const int remove_hp){
        if(m_hp - remove_hp < 0){
            m_hp = 0;
        }
        else{
            m_hp -= remove_hp;
        }
    }


    bool Player::isKnockedOut() const{
        return(!m_hp);
    }


    void Player::addCoins(const int coins_add){
        m_coins += coins_add;
    }


    bool Player::pay(int coins_remove){
        if(coins_remove > m_coins){
            return false;
        }
        else{
            m_coins -= coins_remove;
            return true;
        }
    }


    int Player::getAttackStrength() const{
        return (m_level + m_force);
    }
