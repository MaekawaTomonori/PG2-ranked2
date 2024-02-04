#include <Novice.h>

#include "src/Scene/SceneManager.h"
#include "src/Util/InputManager.h"
#define inp InputManager::getInstance()
#define sm SceneManager::GetInstance()

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	sm.Init();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		inp.Update();

		///
		/// ↓更新処理ここから
		///

		sm.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::getInstance().isTrigger(DIK_ESCAPE)) {
			break;
		}
	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
