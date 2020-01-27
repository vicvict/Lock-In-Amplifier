#ifndef SR865_H
#define SR865_H


#include "../lockinamplifier.h"

#include <vector>
#include <string>
#include <map>


class SR865: public LockInAmplifier
{
public:
    SR865() : LockInAmplifier() {
        //Они должны быть const!
        LockInAmplifierRanges new_ranges;
        new_ranges.maxPhase = 180;
        new_ranges.minPhase = -180;
        new_ranges.maxHarmonic = 99;
        new_ranges.minHarmonic = 1;
        new_ranges.maxInternalFrequency = 4E6;
        new_ranges.minInternalFrequency = 1E-3;
        new_ranges.minSineAmplitude = 1E-9;
        new_ranges.maxSineAmplitude = 2.0;

        SetRanges(new_ranges);

        std::vector<std::string> newTimeConstant = {"1 us" , "3 us", "10 us", "30 us", "100 us", "300 us",
                                                    "1 ms" , "3 ms", "10 ms", "30 ms", "100 ms", "300 ms",
                                                    "1 s" , "3 s", "10 s", "30 s", "100 s", "300 s",
                                                    "1 Ks" , "3 Ks", "10 Ks", "30 Ks"
                                                    };
        SetTimeConstantList(newTimeConstant);
    }

    int getMinDualHarmonic() const;
    int getMaxDualHarmonic() const;
    bool isValidDualHarmonic(const int &i) const;
    bool setDualHarmonic(const int &i) const;
    std::string getDualHarmonic() const;

    double getMinSineDCLevel() const;
    double getMaxSineDCLevel() const;
    bool isValidSineDCLevel(const double &voltage) const;
    bool setSineDCLevel(const double &voltage) const;
    std::string getSineDCLevel() const;

protected:
    const int minHarmDual = 1;
    const int maxHarmDual = 99;

    const double minSineDCLevel = -5.00;
    const double maxSineDCLevel = +5.00;

    double SineDCLevel;
private:

};

#endif // SR865_H
