#include "DxLib.h"
#include "OtherScene.h"


void OtherScene::OtherSceneInitialize()
{

}

void OtherScene::OtherSceneUpdate()
{
	for (int i = 0; i < 256; ++i)
	{
		oldkey[i] = key[i];
	}
	GetHitKeyStateAll(key);

	if (key[KEY_INPUT_A] == 1 && oldkey[KEY_INPUT_A] == 0 && scene == 1 && selectScene > 4)
	{
		selectScene--;
	} else if (key[KEY_INPUT_D] == 1 && oldkey[KEY_INPUT_D] == 0 && scene == 1 && selectScene < 5) {
		selectScene++;
	}

	if (key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0)
	{
		switch (scene)
		{
		case 0: // �^�C�g��->�X�e�[�W�Z���N�g
			scene = 1;
			break;
		case 1: // �X�e�[�W�Z���N�g->�Q�[�����
			scene = selectScene;
			break;
		case 2: // �Q�[���I�[�o�[->�^�C�g��
			scene = 0;
			break;
		case 3: // �Q�[���N���A->�^�C�g��
			scene = 0;
			break;
		}
	}
}

void OtherScene::OtherSceneDraw()
{
	switch (scene)
	{
	case 0: // �^�C�g��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�^�C�g��   SPACE->�X�e�[�W�Z���N�g");
		break;
	case 1: // �X�e�[�W�Z���N�g
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�X�e�[�W�Z���N�g   SPACE->�Q�[�����");
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�`���[�g���A��->4 �Q�[�����->5");
		DrawFormatString(0, 40, GetColor(255, 255, 255), "�L�[A->-  �L�[D->+  (%d)", selectScene);
		break;
	case 2: // �Q�[���I�[�o�[
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[���I�[�o�[   SPACE->�^�C�g��");
		break;
	case 3: // �Q�[���N���A
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[���N���A  SPACE->�^�C�g��");
		break;
	}
}