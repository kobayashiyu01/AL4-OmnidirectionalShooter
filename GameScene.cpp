#include "GameScene.h"

using namespace KamataEngine;

void GameScene::GenerateBlocks() {

	// 要素数
	uint32_t numBlockVertical = mapChipField_->GetNumBlockVirtical();
	uint32_t numBlockHorizontal = mapChipField_->GetNumBlockHrizontal();

	// 要素数を変更する
	worldTransformBlocks_.resize(numBlockVertical);

	// キューブの生成
	for (uint32_t i = 0; i < numBlockVertical; ++i) {
		worldTransformBlocks_[i].resize(numBlockHorizontal);
	}
	for (uint32_t i = 0; i < numBlockVertical; ++i) {
		for (uint32_t j = 0; j < numBlockHorizontal; ++j) {
			if (mapChipField_->GetMapchipTypeByIndex(j, i) == MapChipType::kBlock) {
				WorldTransform* worldTransform = new WorldTransform();
				worldTransform->Initialize();
				worldTransformBlocks_[i][j] = worldTransform;
				worldTransformBlocks_[i][j]->translation_ = mapChipField_->GetMapChipPositionByIndex(j, i);
				worldTransformBlocks_[i][j]->matWorld_ = MakeAffineMatrix(worldTransformBlocks_[i][j]->scale_, worldTransformBlocks_[i][j]->rotation_, worldTransformBlocks_[i][j]->translation_);
				worldTransform->TransferMatrix();
				worldTransformBlocks_[i][j]->TransferMatrix();
			}
		}
	}
}

bool GameScene::IsAABBCollision(const AABB& aabb1, const AABB& aabb2) {
	return (aabb1.min.x <= aabb2.max.x && aabb1.max.x >= aabb2.min.x) && (aabb1.min.y <= aabb2.max.y && aabb1.max.y >= aabb2.min.y) && (aabb1.min.z <= aabb2.max.z && aabb1.max.z >= aabb2.min.z);
}

GameScene::~GameScene() {

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			delete worldTransformBlock;
		}
	}
	worldTransformBlocks_.clear();

	delete playerModel_;
	delete blockModel_;
	delete player_;
	delete mapChipField_;
}


void GameScene::Initialize() {

	worldTransform_.Initialize();
	camera_.Initialize();

	mapChipField_ = new MapChipField;
	mapChipField_->LoadMapChipCsv("Resources/blocks.csv");
	GenerateBlocks();

	player_ = new Player();
	playerModel_ = Model::CreateFromOBJ("player2", true);

	// Model
	Vector3 playerPosition = mapChipField_->GetMapChipPositionByIndex(1, 18);
	player_->Initialize(playerModel_, &camera_, playerPosition);


	blockModel_ = Model::CreateFromOBJ("block");

	cameraController_ = new CameraController();
	cameraController_->Initialize();
	cameraController_->SetTarget(player_);
	cameraController_->Reset();

	player_->SetMapChipField(mapChipField_);


}

void GameScene::Update() {



}

void GameScene::Draw() {




}
