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
        ranges.maxInternalFrequency = 4E6;
        ranges.minSineAmplitude = 1E-9;
        ranges.maxSineAmplitude = 2.0;

        std::vector<std::string> newTimeConstant = {"1 us" , "3 us", "10 us", "30 us", "100 us", "300 us",
                                                    "1 ms" , "3 ms", "10 ms", "30 ms", "100 ms", "300 ms",
                                                    "1 s" , "3 s", "10 s", "30 s", "100 s", "300 s",
                                                    "1 ks" , "3 ks", "10 ks", "30 ks"
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

    std::vector<std::string> getRefSourceList() const;
    int refSourceNumberFromString(const std::string  &refSource_string) const;
    std::string refSourceStringFromNumber(const int &refSource_number) const;
    bool setRefSource(const int &refSource) const;
    bool setRefSource(const std::string &refSource) const;
    std::string getRefSource() const;
protected:
    const int minHarmDual = 1;
    const int maxHarmDual = 99;

    const double minSineDCLevel = -5.00;
    const double maxSineDCLevel = +5.00;

    double SineDCLevel;

//ПЕРЕДЕЛАТЬ
    const std::vector <std:: string> refSource =    {
                                                        "INT", "EXT", "DUAL", "CHOP"
                                                    };
private:

};

#endif // SR865_H
