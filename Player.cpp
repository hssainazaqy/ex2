
#include "utilities.h"
#include <iostream>
#include "Player.h"


#define MAX_LEVEL 10



    void Player::printInfo() const{
        printPlayerInfo(name, level, force, hp, coins);
    }

    
    void Player::levelup(){
        if(level < MAX_LEVEL){
            level++;
        }
    }
    
    
    int Player::getLevel() const{
        return level;
    }

    
    void Player::buff(const int add_force){
        force += add_force;
    }


    void Player::heal(const int add_hp){
        if((hp + add_hp) > (max_hp)){
            hp = max_hp;
        }
        else{
            hp += add_hp;
        }
    }

    
    void Player::damage(const int remove_hp){
        if(hp - remove_hp < 0){
            hp = 0;
        }
        else{
            hp -= remove_hp;
        }
    }

    
    bool Player::isKnockedOut() const{
        return(!hp);
    }


    void Player::addCoins(const int coins_add){
        coins += coins_add;
    }

    
    bool Player::pay(int coins_remove){
        if(coins_remove > coins){
            return false;
        }
        else{
            coins -= coins_remove;
            return true;
        }
    }


    int Player::getAttackStrength() const{
        return(level + force);
    }


    