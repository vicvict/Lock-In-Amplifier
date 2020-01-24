#include "sr844.h"

/*
SR844::SR844()
{
    setStringToBaudRate(SRS844_string_to_baud_rate);
    setStringToDataBits(SRS844_string_to_data_bits);
    setStringToFlowControl(SRS844_string_to_flow_control);
    setStringToParity(SRS844_string_to_parity);
    setStringToStopBits(SRS844_string_to_stop_bits);

    init();
}

bool SR844::setInternalFrequency(const double &new_frequency) const
{
   QString command = "FREQ " + QString::number(new_frequency);
   std::string command_s = to_StdString(command);
   return sendCommand(command_s);
}

double SR844::getFrequency() const
{
    return to_QString(ask("FREQ?")).toDouble();
}

//*/
