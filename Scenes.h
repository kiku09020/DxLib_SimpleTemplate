#pragma once
#include "SceneManagement.h"
#include "DxLib.h"

class Scene1:public SceneBase
{
private:


public:
	void OnSceneLoaded() override;
	void OnSceneUpdate() override;
	void OnSceneDestroied() override;
};