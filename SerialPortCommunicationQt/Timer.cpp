// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Timer.h"

Timer::Timer() {

}

Timer::~Timer() {

}

void Timer::start() {
    time_start = std::chrono::high_resolution_clock::now();

    return;
}

void Timer::finish() {
    time_finish = std::chrono::high_resolution_clock::now();

    return;
}

double Timer::nsecElapsed(const std::chrono::high_resolution_clock::time_point &time) const {
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds> (time - time_start);

    return elapsed.count();

}

double Timer::usecElapsed(const std::chrono::high_resolution_clock::time_point &time) const {
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds> (time - time_start);

    return elapsed.count();

}

double Timer::msecElapsed(const std::chrono::high_resolution_clock::time_point &time) const {
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds> (time - time_start);

    return elapsed.count();
}

double Timer::secElapsed(const std::chrono::high_resolution_clock::time_point &time) const {
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds> (time - time_start);

    return elapsed.count();
}

double Timer::nsecElapsedNow() const {
    return nsecElapsed(std::chrono::high_resolution_clock::now());
}

double Timer::nsecElapsedDuration() const {
    return nsecElapsed(time_finish);
}

double Timer::usecElapsedNow() const {
    return usecElapsed(std::chrono::high_resolution_clock::now());
}

double Timer::usecElapsedDuration() const {
    return usecElapsed(time_finish);
}

double Timer::msecElapsedNow() const {
    return msecElapsed(std::chrono::high_resolution_clock::now());
}

double Timer::msecElapsedDuration() const {
    return msecElapsed(time_finish);
}

double Timer::secElapsedNow() const {
    return secElapsed(std::chrono::high_resolution_clock::now());
}

double Timer::secElapsedDuration() const {
    return secElapsed(time_finish);
}

unsigned long long Timer::msecSinceEpoch(const std::chrono::high_resolution_clock::time_point &time) const {
    return  1000 * secSinceEpoch(time);
}

unsigned long long Timer::secSinceEpoch(const std::chrono::high_resolution_clock::time_point &time) const {
    return time.time_since_epoch() / std::chrono::seconds(1);
}

unsigned long long Timer::msecSinceEpochNow() const {
    return msecSinceEpoch(std::chrono::high_resolution_clock::now());
}

unsigned long long Timer::msecSinceEpochStart() const {
    return msecSinceEpoch(time_start);
}

unsigned long long Timer::msecSinceEpochFinish() const {
    return msecSinceEpoch(time_finish);
}

unsigned long long Timer::secSinceEpochNow() const {
    return secSinceEpoch(std::chrono::high_resolution_clock::now());
}

unsigned long long Timer::secSinceEpochStart() const {
    return secSinceEpoch(time_start);
}

unsigned long long Timer::secSinceEpochFinish() const {
    return secSinceEpoch(time_finish);
}

std::string Timer::to_string_and_appbegin(const int &value, const size_t &min_length) const {
    std::string result = std::to_string(value);

    while (result.length() < min_length) {
        result = "0" + result;
    }

    return result;
}

std::string Timer::getCurrentTime() {
    getCurrentDateTime();

    return current_time;
}

std::string Timer::getCurrentDate() {
    getCurrentDateTime();

    return current_date;
}

std::string Timer::getCurrentDateTime() {
    std::time_t current_date_time = std::time(nullptr);

    std::tm* now = std::localtime(&current_date_time);

    current_date = to_string_and_appbegin(now->tm_year+1900, 4) + "_" + to_string_and_appbegin(now->tm_mon+1, 2) + "_" + to_string_and_appbegin(now->tm_mday, 2);
    current_time = to_string_and_appbegin(now->tm_hour     , 2) + "_" + to_string_and_appbegin(now->tm_min  , 2) + "_" + to_string_and_appbegin(now->tm_sec , 2);

    return current_date + "_" + current_time;
}
