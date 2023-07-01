#pragma once
#include "DxLib.h"
#include "Window.h"

class Core
{
private:
	const int WAIT_MS = 10;		// ‘Ò‹@ƒ~ƒŠ•b

	Window* window = new Window();

public:
	int Init();
	void Update();
};