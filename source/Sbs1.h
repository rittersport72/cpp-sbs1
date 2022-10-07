#ifndef SBS1_H
#define SBS1_H

#include "Sbs1Message.h"

// STL
#include <string>

namespace SBS1
{
    Sbs1Message parse(const std::string& message_string);

    MessageType getMessageTypeEnum(std::string type);

    TransmissionType getTransmissionTypeEnum(std::string type);
}

#endif // SBS1_H