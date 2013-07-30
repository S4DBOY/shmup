#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

class Player;
class PlayerManager;
extern PlayerManager playerManager;

/**
    \brief A wrapper for the Player type opject
*/
class PlayerManager
{
    public:
        PlayerManager(){};
        ~PlayerManager();
        void Input();
        void Move();
        void Logic();
        void Draw();
        void DrawHitBox();
        void AddPlayer(int type);

        void GetPlayerLocation(double &x, double &y);
    protected:
    private:
        Player *player;
};

#endif
