#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

#define SCORE_INTERVAL
#define SCORE_FONT_SIZE

//�I�u�W�F�N�g�F�X�R�A�����L���O
class CObjScore : public CObj
{

public:
	CObjScore() {};
	~CObjScore() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[
private:
	bool m_key_flag;//�L�[�t���O

	//�����L���O�\�[�g���\�b�h
	void RankingSort(int rank[16]);
};