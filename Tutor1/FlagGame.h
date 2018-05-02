#pragma once
#include "Game.h"
#include <vector>
#include <memory>
#include "MainWindow.h"

class FlagGame : public Game
{
public:
	FlagGame(MainWindow& wnd);
	~FlagGame();

private:
	void CycleScenes();
	void ReverseCycleScenes();
	void OutputSceneName() const;
	virtual void ComposeFrame();
	virtual void UpdateModel();

private:
	FrameTimer ft;
	std::vector<std::unique_ptr<Scene>> scenes;
	std::vector<std::unique_ptr<Scene>>::iterator curScene;
};

