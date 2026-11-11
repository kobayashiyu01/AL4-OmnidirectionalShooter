#pragma once
#include "CameraController.h"
#include "KamataEngine.h"
#include "MapChipField.h"
#include "Player.h"
#include "MathematicalFunction.h"

class GameScene {

public:
	~GameScene();
	// 初期化
	void Initialize();

	void GenerateBlocks();

	void CheckAllCollisions();

	bool IsAABBCollision(const AABB& aabb1, const AABB& aabb2);

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	CameraController* cameraController_ = nullptr;
	Player* player_ = nullptr;
	MapChipField* mapChipField_;

	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;

	KamataEngine::Model* playerModel_ = nullptr;
	KamataEngine::Model* blockModel_ = nullptr;

	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;
};
