#include "SceneManagement.h"
#include "Scenes.h"

SceneBase* SceneController::activeScene;
std::vector<SceneBase*> SceneController::sceneList;
int SceneController::sceneCount;

void SceneController::Init()
{
	// �����ɃV�[����ǉ�
	AddScene(new Scene1());

	sceneCount = sceneList.size();

	// �����V�[�������[�h
	activeScene = sceneList[0];
	LoadScene(activeScene, false);
}

void SceneController::Update()
{
	activeScene->OnSceneUpdate();
}

//--------------------------------------------------

void SceneController::AddScene(SceneBase* state)
{
	sceneList.push_back(state);
}

//--------------------------------------------------

void SceneController::LoadScene(SceneBase* nextScene, bool doPrevSceneDestroy = false)
{
	// �V�[�������݂��邩�m�F���āA�V�[����؂�ւ���
	if (CheckScene(nextScene)) {
		if (doPrevSceneDestroy) {
			activeScene->OnSceneDestroied();
		}

		activeScene = nextScene;
		activeScene->OnSceneLoaded();
	}
}

void SceneController::LoadScene(int nextSceneIndex, bool doPrevScenedestroy = false)
{
	if (CheckScene(nextSceneIndex)) {
		if (doPrevScenedestroy) {
			activeScene->OnSceneDestroied();
		}
		activeScene = sceneList[nextSceneIndex];
		activeScene->OnSceneLoaded();
	}
}

//--------------------------------------------------

bool SceneController::CheckScene(SceneBase* nextScene)
{
	for (const auto& scene : sceneList) {
		if (scene == nextScene) {
			return true;
		}
	}

	return false;
}

bool SceneController::CheckScene(int nextSceneIndex)
{
	for (const auto& scene : sceneList) {
		if (scene == sceneList[nextSceneIndex]) {
			return true;
		}
	}

	return false;
}