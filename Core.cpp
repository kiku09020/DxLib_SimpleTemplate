#include "Core.h"
#include "SceneManagement.h"
#include "Input.h"

using namespace Input;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Core* core = new Core();

    core->Init();

    while (ProcessMessage() == 0) {
        core->Update();
    }

    return 0;
}



int Core::Init()
{
    Keyboard::Init();
    Mouse::Init();

    SceneController::Init();

    ChangeWindowMode(true);

    return DxLib_Init();
}

void Core::Update()
{
    Keyboard::Update();
    Mouse::Update();

    ClearDrawScreen();

    SetDrawScreen(DX_SCREEN_BACK);

    SceneController::Update();

    ScreenFlip();
    WaitTimer(WAIT_MS);
}