


#ifndef EX2_Player_H
#define EX2_Player_H


#include <string>
#include "utilities.h"


class Player {
public:
    /*
     * C'tor of player class
     *
     * @param m_name - The m_name of the player.
     * @param max_hp - The max hp of the player.
     * @param force - The force of the player.
     * @return
     *      A new instance of Player.
    */
    explicit Player(char* _name, int _max_hp = 100, int _force = 5) 
    : m_name(_name), m_max_hp(_max_hp), m_force(_force) , m_level(1), m_hp(_max_hp), m_coins(0){
    }


    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo() const;

    
    /*
     * Levels up the player 1 m_level:
     *
     * @return
     *      void
    */
    void levelUp();
    
    
    /*
     * Gets the player's level:
     *
     * @return
     *      current level of the player
    */
    int getLevel() const;


    
    /*
     * Adds to the force the given parameter:
     * 
     * @param add_force -the force added to the player
     * @return
     *      void
    */
    void buff(const int add_force);

    
    /*
     * Adds hp by parameter until reaches max_hp:
     *
     * @param add_hp -the hp added to the player
     * @return
     *      void
    */
    void heal(const int add_hp);


    
    /*
     * Lowers the hp by parameter until reaches 0:
     *
     * @param remove_hp -the hp removed to the player
     * @return
     *      void
    */
    void damage(const int remove_hp);


    
    /*
     * Checks if hp = 0:
     *
     * @return
     *      false if hp != 0 and true if hp = 0
    */
    bool isKnockedOut() const;


    /*
     * Adds coins to the player:
     *
     * @param coins_add -the coins added to the player
     * @return
     *      void
    */
    void addCoins(const int coins_add);


    
    /*
     * Remove coins from the player:
     *
     * @param coins_remove -the coins removed to the player
     * @return
     *      true if the pay was succesfull and false otherwise
    */
    bool pay(int coins_remove);


    /*
     * Returns the attack strength:
     *
     * @return
     *      current level + current force
    */
    int getAttackStrength() const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;


private:
    char* m_name;
    int m_level;
    int m_force;
    int m_max_hp;
    int m_hp;
    int m_coins;
};


#endif //EX2_Player_H
