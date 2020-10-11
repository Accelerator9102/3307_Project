#include "TimeManager.h"

TimeManager* TimeManager::instance = NULL;

/// Destructor.
TimeManager::~TimeManager() {};

/// This method returns an instance of the TimeManager object.
/// If an instance doesn't already exist, it creates one.
TimeManager& TimeManager::getInstance() {
    if (instance == NULL) {
        instance = new TimeManager();
    }
    return *instance;
}

/// This method creates a new timer object and increments the number of keys.
const int TimeManager::addTimer(double stop_time, bool start_now) {
    key_count++;
    timers[key_count] = Timer(stop_time, start_now);
    //std::cout << "Registered Timer " << key_count 
    //    << " with time " << getTimer(key_count).getCurrentTime() << "out of" 
    //    << getTimer(key_count).getStopTime() << std::endl;
    return key_count;
}

/// This method returns a specific timer given a key.
Timer& TimeManager::getTimer(const int key) {
    //std::cout << key << std::endl;
    return timers[key];
}

/// This method removes a timer from the stored map given a key.
void TimeManager::removeTimer(const int key) {
    timers.erase(key);
    //keys.erase(std::find(keys.begin(), keys.end(), key));
}

/// This method updates every timer currently stored in the map.
void TimeManager::update() {
    for (auto& timer : timers) {
        //std::cout << "Updating Timer " << timer.first
        //    << std::endl;
        timer.second.update();
    }
}

/// Constructor method. Initializes key count to 0.
TimeManager::TimeManager() {
    key_count = 0;
}

//Stuff to prevent copying and assignment.
TimeManager::TimeManager(const TimeManager& other) { }

TimeManager& TimeManager::operator=(const TimeManager& other) { }
