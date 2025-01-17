


#ifndef EX2_Player_H
#define EX2_Player_H


#include <string>
#include "utilities.h"


class Player {
public:
    /*
     * C'tors of Card class
     *
     * @param name - The name of the player.
     * @param max_hp - The max hp of the player.
     * @param force - The force of the player
     * @return
     *      A new instance of Player.
    */
    Player(char* name, const int max_hp, const int force);
    Player(char* name, const int max_hp);
    Player(char* name);



    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo() const;

    
    /*
     * Levels up the player 1 level:
     *
     * @return
     *      void
    */
    void levelup();
    
    
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
     *      true if hp != 0 and false if hp = 0
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
    char* name;
    int level;
    int force;
    int max_hp;
    int hp;
    int coins;
};


#endif //EX2_Player_H
