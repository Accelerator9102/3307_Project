/// @class TimeManager
/// @author Daniel Carranza
/// @brief Creates and maintains timer objects.
/// This class is the interface by which other classes can obtain timers.

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "Timer.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class TimeManager {
    public:
        /// @brief Destructor method.
        virtual ~TimeManager();
        
        /// @brief Method to retrieve an instance of TimeManager.
        /// @return A static reference to the TimeManager instance.
        static TimeManager& getInstance();
        
        /// @brief Method to generate a new timer.
        /// @param stop_time The length of time the timer should run for. Defaults to 0.
        /// @param start_now Whether or not the timer should begin counting after construction.
        /// @return The ID of the timer it just added.
        const int addTimer(double stop_time = 0, bool start_now = false);
        
        /// @brief Method to retrieves a particular timer given a key.
        /// @param key The key used to search for a timer object.
        /// @return A reference to the timer object.
        Timer& getTimer(const int key);
        
        /// @brief Method to remove a timer from the stored list.
        /// @param key The key used to search for a timer object.
        void removeTimer(const int key);
        
        /// @brief Method to update all timer objects.
        void update();
    protected:
        /// @brief Default constructor.
        TimeManager();
    private:
        // Prevent copying and assignment
        TimeManager(const TimeManager& other);
        TimeManager& operator=(const TimeManager& other);
        
        static TimeManager* instance; /// @brief An instance of TimeManager.

        std::map<int, Timer> timers; /// @brief A map to store Timer objects and their IDs.
        //std::vector<int> keys;
        int key_count; /// @brief The number of timer objects created.
};

#endif // TIMEMANAGER_H
