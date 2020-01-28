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

        commands.RefSource = "RSRC";
        commands.HarmonicDual = "HARMDUAL";
        commands.SineDCLevel = "SOFF";
        commands.RefTriggerMode = "RTRG";
        commands.InputSignal = "IVMD";
        commands.Sensitivity = "SCAL";

        timeConstant = {
                            "1 us",     "3 us",
                            "10 us",    "30 us",
                            "100 us",   "300 us",

                            "1 ms",     "3 ms",
                            "10 ms",    "30 ms",
                            "100 ms",   "300 ms",

                            "1 s",      "3 s",
                            "10 s",     "30 s",
                            "100 s",    "300 s",

                            "1 ks",     "3 ks",
                            "10 ks",    "30 ks"
                       };


        refSource =    {
                          "INT", "EXT", "DUAL", "CHOP"
                       };

        refTriggerMode =    {
                                "SIN" , "POSTTL", "NEGTTL"
                            };

        refTriggerOutput =  {
                                "50 Ohm", "1 MOhm"
                            };

        inputSignal =       {
                                "VOLTage", "CURRent"
                            };

        inputVoltageMode = {
                                "A", "A-B"
                           };

        inputVoltageCoupling =  {
                                    "AC", "DC"
                                };

        inputVoltageShields =   {
                                    "Float", "Ground"
                                };

        inputVoltageRange =     {
                                    "1 V", "300 mV", "100 mV", "30 mV", "10 mV"
                                };

        inputCurrentGain =      {
                                    "1 uA", "10 nA"
                                };

        sensitivity =   {
                            "1 V",

                            "500 mV",   "200 mV",   "100 mV",
                            "50 mV",    "20 mV",    "10 mV",
                            "5 mV",     "2 mV",     "1 mV",

                            "500 uV",   "200 uV",   "100 uV",
                            "50 uV",    "20 uV",    "10 uV",
                            "5 uV",     "2 uV",     "1 uV",

                            "500 nV",   "200 nV",   "100 nV",
                            "50 nV",    "20 nV",    "10 nV",
                            "5 nV",     "2 nV",     "1 nV",
                        };

        outData =   {
                        "X",        "Y",    "R",    "THETa",
                        "IN1",      "IN2",  "IN3",  "IN4",
                        "OUT1",     "OUT2",
                        "XNOise",   "YNOise",
                        "PHAse",    "SAMp",  "LEVel",
                        "FINT",     "FEXT"
                    };
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
