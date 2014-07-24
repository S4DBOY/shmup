#include "backgroundManager.h"

#include "stage1background.h"

BackgroundManager backgroundManager;

void BackgroundManager::SetBackground()
{
	background = std::make_unique<Stage1>();
}

void BackgroundManager::Logic()
{
	if (background) background->Logic();
}

void BackgroundManager::Draw() const
{
	if (background) background->Draw();
}
