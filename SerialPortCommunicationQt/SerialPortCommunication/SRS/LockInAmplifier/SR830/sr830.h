#ifndef SR830_H
#define SR830_H


#include "../lockinamplifier.h"

#include <vector>
#include <string>
#include <map>


class SR830: public LockInAmplifier
{
public:
    SR830() : LockInAmplifier() {
        ranges.maxInternalFrequency = 4E6;
        ranges.minSineAmplitude = 1E-9;
        ranges.maxSineAmplitude = 2.0;


        timeConstant = {
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

        sensitivity =   {
                                        "2 nV",     "5 nV",
                            "10 nV",    "20 nV",    "50 nV",
                            "100 nV",   "200 nV",   "500 nV",

                            "1 uV",     "2 uV",     "5 uV",
                            "10 uV",    "20 uV",    "50 uV",
                            "100 uV",   "200 uV",   "500 uV",

                            "1 mV",     "2 mV",     "5 mV",
                            "10 mV",    "20 mV",    "50 mV",
                            "100 mV",   "200 mV",   "500 mV",

                            "1 V"
                        };

        outData =   {
                        "X",                    "Y",        "R",        "Theta",
                        "Aux In1",              "Aux In2",  "Aux In3",  "Aux In4",
                        "Reference Frequency",
                        "CH1 display",          "CH2 display"
                    };
    }


protected:


};

#endif // SR830_H









