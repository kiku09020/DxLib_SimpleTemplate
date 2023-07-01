#pragma once

#include <vector>

class SceneBase
{

public:
	// シーンがロードされるときの処理
	virtual void OnSceneLoaded() = 0;

	// シーン更新処理
	virtual void OnSceneUpdate() = 0;

	// シーン破棄されるときの処理
	virtual void OnSceneDestroied() = 0;
};

//--------------------------------------------------
// シーン管理クラス
class SceneController
{
private:
	static SceneBase* activeScene;

	static std::vector<SceneBase*> sceneList;

	static int sceneCount;		// シーンの合計数

	// シーンをリストに追加
	static void AddScene(SceneBase* scene);

	// シーンが存在するかを確認する
	static bool CheckScene(int sceneIndex);
	static bool CheckScene(SceneBase* scene);

public:
	static void Init();
	static void Update();



	// シーン読み込み
	static void LoadScene(int nextSceneIndex, bool doPrevSceneDest);
	static void LoadScene(SceneBase* nextScene, bool doPrevSceneDest);

};