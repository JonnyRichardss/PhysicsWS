#ifndef USE_GAMECLOCK
#define USE_GAMECLOCK
#include <chrono>

using namespace std::chrono_literals;
enum ProfilerPhases { START, INPUT, UPDATE, RENDER };
class GameClock
{
public:
	static GameClock* GetInstance();
	void Tick();
	std::chrono::nanoseconds GetFrametime();
	long long GetFrameCount();
	float GetBudgetPercent();
	std::chrono::high_resolution_clock::time_point GetTimePoint();
	int GetFPS();
private:
	GameClock();
	~GameClock();

	const std::chrono::high_resolution_clock::time_point ENGINE_START_TP;
	std::chrono::high_resolution_clock::time_point last_frame_tp;
	std::chrono::high_resolution_clock::time_point frame_start_tp;
	std::chrono::high_resolution_clock::time_point input_tp;
	std::chrono::high_resolution_clock::time_point update_tp;
	std::chrono::high_resolution_clock::time_point render_tp;

	std::chrono::nanoseconds frametime_ns;
	std::chrono::nanoseconds unused_ns;
	std::chrono::nanoseconds target_ns;

	long long framecounter;

	void SetFPSLimit(int fps);
	std::chrono::nanoseconds GetRemainingBudget();
	void EnforceLimit();
	std::chrono::nanoseconds TimeSinceLastFrame();
	void WaitFor(std::chrono::nanoseconds wait_ns);
};
#endif // !USE_GAMECLOCK
