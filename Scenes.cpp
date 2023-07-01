#include "Scenes.h"
#include "Input.h"

using namespace Input;

void Scene1::OnSceneLoaded()
{

}

void Scene1::OnSceneUpdate()
{
	DrawCircle(960 / 2, 540 / 2, 5, GetColor(255, 255, 255));

	if (Keyboard::GetKeyDown(KEY_INPUT_ESCAPE)) {
		OnSceneDestroied();
	}
}

void Scene1::OnSceneDestroied()
{
	DxLib_End();
}