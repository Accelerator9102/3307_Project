#include "Timer.h"

/// This constructor initializes all the necessary variables for the timer object.
Timer::Timer(double stop_time, bool start_now) {
    this->stop_time = stop_time;
    pause_duration = std::chrono::seconds::zero();
    current_time = std::chrono::seconds::zero();
    start_time = std::chrono::steady_clock::now();
    last_pause_time = start_time;
    is_paused = !start_now;
}

/// This method retrieves the current running time of the timer.
const double Timer::getCurrentTime() const {
    //if (is_paused) { std::cout << "Paused!" << std::endl; }
    return (double)(current_time - pause_duration).count();
}

/// This method determines if the timer has exceeded its stopping time or not.
const bool Timer::isTimerDone() const {
    return getCurrentTime() >= getStopTime();
}

/// This method retrieves the set stopping time.
const double Timer::getStopTime() const {
    return stop_time;
}

/// This method sets the current stopping time to a new one.
void Timer::setStopTime(const double& stop_time) {
    this->stop_time = stop_time;
}

/// This method forces the timer to update and also takes it out of a paused state.
void Timer::startTimer() {
    update();
    is_paused = false;
}

/// This method puts the timer in a paused state.
void Timer::stopTimer() {
    last_pause_time = std::chrono::steady_clock::now();
    is_paused = true;
}

/// This method makes all the necessary adjustments to the variables to make the timer
/// behave as if it had just been constructed.
void Timer::restartTimer() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    start_time = now;
    last_pause_time = now;
    pause_duration = std::chrono::seconds::zero();
    current_time = std::chrono::seconds::zero();
    is_paused = false;
}

/// This method updates the variables storing the current running time of the timer,
/// as well as the current paused timed if the timer happens to be paused.
void Timer::update() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    current_time = std::chrono::duration_cast<std::chrono::seconds>(now - start_time);
    if (is_paused)
        pause_duration = std::chrono::duration_cast<std::chrono::seconds>(now - last_pause_time);
}

/// Destructor.
Timer::~Timer() {}
