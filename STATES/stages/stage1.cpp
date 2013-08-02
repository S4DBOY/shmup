#include "../../BASIC/globals.h"
#include "stages.h"

#include "../../CONSTRUCTS/managers.h"

GameStage1::GameStage1()
{
    playerManager.AddPlayer(0);
    backgroundManager.SetBackground();
    bulletManager.EraseAllBullets();
    enemyManager.KillAllEnemies();
}

GameStage1::~GameStage1()
{

}

void GameStage1::StageLogic()
{
    int frame=stateFrameCounter;
    if(frame==0) enemyManager.AddEnemy(E_ENEMY1, SCREEN_WIDTH/2, 200, 0, 0);
}
