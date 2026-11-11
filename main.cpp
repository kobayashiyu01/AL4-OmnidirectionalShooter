#include "GameScene.h"
#include "KamataEngine.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// KamataEngine::←を省略できるようにする
	using namespace KamataEngine;
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	GameScene* gameScene = new GameScene;

	gameScene->Initialize();

	Initialize(L"LE2D_11_コバヤシ_ユウ_AL2");

	while (true) {
		// ↓書いても大丈夫  ////////ただし、ヘッダーファイルにusing namespaceを書いてはいけない//////
		if (KamataEngine::Update()) {
			break;
		}

		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();

		gameScene->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	Finalize();

	delete gameScene;
	gameScene = nullptr;

	return 0;
}
