#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <ctime>
#include <string>

class Timer {
public:
    explicit Timer();
    ~Timer();

    void start ();
    void finish();

    double nsecElapsedNow     () const;
    double nsecElapsedDuration() const;
    double usecElapsedNow     () const;
    double usecElapsedDuration() const;
    double msecElapsedNow     () const;
    double msecElapsedDuration() const;
    double  secElapsedNow     () const;
    double  secElapsedDuration() const;

    unsigned long long msecSinceEpochNow   () const;
    unsigned long long msecSinceEpochStart () const;
    unsigned long long msecSinceEpochFinish() const;
    unsigned long long  secSinceEpochNow   () const;
    unsigned long long  secSinceEpochStart () const;
    unsigned long long  secSinceEpochFinish() const;

    std::string getCurrentTime    ();
    std::string getCurrentDate    ();
    std::string getCurrentDateTime();

private:
    std::string current_date = "";
    std::string current_time = "";

    std::chrono::high_resolution_clock::time_point time_start ;
    std::chrono::high_resolution_clock::time_point time_finish;

    double nsecElapsed(const std::chrono::high_resolution_clock::time_point &time) const;
    double usecElapsed(const std::chrono::high_resolution_clock::time_point &time) const;
    double msecElapsed(const std::chrono::high_resolution_clock::time_point &time) const;
    double  secElapsed(const std::chrono::high_resolution_clock::time_point &time) const;

    unsigned long long msecSinceEpoch(const std::chrono::high_resolution_clock::time_point &time) const;
    unsigned long long  secSinceEpoch(const std::chrono::high_resolution_clock::time_point &time) const;

    std::string to_string_and_appbegin(const int &value, const size_t &min_length = 0) const;
};

#endif // TIMER_H
