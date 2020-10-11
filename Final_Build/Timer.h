/// @class Timer
/// @author Daniel Carranza
/// @brief Class to store attributes of timers and update them as needed.
/// This class is responsible for initializing and keeping all needed values
/// needed to keep track of time. It also has the necessary functions to
/// update the timer as well as starting, stopping, and resetting it.

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

class Timer {
    public:
        /// @brief Constructor method.
        /// @param stop_time How long until the timer is done. Defaults to 0.
        /// @param start_now Determines if the timer should start counting on construction. Defaults to false.
        Timer(double stop_time = 0, bool start_now = false);
        
        /// @brief Method to retrieve the current time of the timer.
        /// @return A double representing the current time.
        const double getCurrentTime() const;
        
        /// @brief Method to determine if the timer has finished.
        /// @return True if the timer is done, false otherwise.
        const bool isTimerDone() const;
        
        /// @brief Method to get the set time limit for the timer.
        /// @return A double representing the set time limit for the timer.
        const double getStopTime() const;

        /// @brief Method to set a new time limit for the timer.
        /// @param stop_time The length of time that the timer should go for.
        void setStopTime(const double& stop_time);

        /// @brief Method to tell the timer to count.
        void startTimer();
        
        /// @brief Method to tell the timer to pause.
        void stopTimer();
        
        /// @brief Method to reset the timer to before it began counting.
        void restartTimer();
        
        /// @brief Method to update the time counter.
        void update();

        /// @brief Destructor method.
        ~Timer();
    private:
        double stop_time; /// @brief The time limit for the timer.
        bool is_paused; /// @brief A boolean representing if the timer has been stopped or not.
        std::chrono::steady_clock::time_point start_time; /// @brief The moment in time that the clock started.
        std::chrono::steady_clock::time_point last_pause_time; /// @brief The moment in time that clock was last in a stopped state.
        std::chrono::seconds current_time; /// @brief The time in seconds that the timer has been running for.
        std::chrono::seconds pause_duration; /// @brief The time in seconds that the timer has been paused for.
};

#endif // TIMER_H
