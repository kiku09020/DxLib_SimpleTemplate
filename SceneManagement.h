#pragma once

#include <vector>

class SceneBase
{

public:
	// �V�[�������[�h�����Ƃ��̏���
	virtual void OnSceneLoaded() = 0;

	// �V�[���X�V����
	virtual void OnSceneUpdate() = 0;

	// �V�[���j�������Ƃ��̏���
	virtual void OnSceneDestroied() = 0;
};

//--------------------------------------------------
// �V�[���Ǘ��N���X
class SceneController
{
private:
	static SceneBase* activeScene;

	static std::vector<SceneBase*> sceneList;

	static int sceneCount;		// �V�[���̍��v��

	// �V�[�������X�g�ɒǉ�
	static void AddScene(SceneBase* scene);

	// �V�[�������݂��邩���m�F����
	static bool CheckScene(int sceneIndex);
	static bool CheckScene(SceneBase* scene);

public:
	static void Init();
	static void Update();



	// �V�[���ǂݍ���
	static void LoadScene(int nextSceneIndex, bool doPrevSceneDest);
	static void LoadScene(SceneBase* nextScene, bool doPrevSceneDest);

};