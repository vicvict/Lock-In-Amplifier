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
        LockInAmplifierRanges new_ranges;
        new_ranges.maxPhase = 180;
        new_ranges.minPhase = -180;
        new_ranges.maxHarmonic = 1000;
        new_ranges.minHarmonic = 0;
        new_ranges.maxInternalFrequency = 100;
        new_ranges.minInternalFrequency = 0;


        SetRanges(new_ranges);
    }
protected:

private:

};

#endif // SR865_H
