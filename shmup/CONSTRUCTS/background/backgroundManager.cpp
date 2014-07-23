#include "backgroundManager.h"

#include "stage1background.h"

BackgroundManager backgroundManager;

BackgroundManager::BackgroundManager()
{
    background=nullptr;
}

BackgroundManager::~BackgroundManager()
{
    if(background) delete background;
    background=nullptr;
}

void BackgroundManager::SetBackground()
{
    if(background) delete background;
    background=new Stage1;
}

void BackgroundManager::Logic()
{
    if(background) background->Logic();
}

void BackgroundManager::Draw()
{
    if(background) background->Draw();
}
