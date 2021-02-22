#pragma once
#include <Crynn.h>

namespace SpeedCube
{
	using namespace crynn;

	class Game : protected EventListener
	{
	public:
		static bool IsOver();
		static void Over();

		///Sets the gameover state without invoking OnGameOver, or logging.
		static void SetOverStateNoInvoke(bool state) { over = state; }

		static inline Event<void> OnGameOver;
	private:
		void Update(double deltaTime) override;
		inline static bool over = false;
	};
}