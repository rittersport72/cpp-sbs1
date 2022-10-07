#include "Sbs1.h"

// STL
#include <vector>
#include <sstream>
#include <iostream>

namespace SBS1
{
    Sbs1Message parse(const std::string& message_string)
    {   
        // Vector of string to save tokens
        std::vector <std::string> tokens;

        std::stringstream check(message_string);
        std::string intermediate;

        // Tokenizing
        while(getline(check, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        
        // Printing the token vector
        for(int i = 0; i < tokens.size(); i++)
            std::cout << tokens[i] << '\n';

        // TODO checkme
        if (tokens[0].size() < 22)
        {
            return Sbs1Message();
        }

        // Create message and assign attributes
        Sbs1Message sbs1Message;
        sbs1Message.message_type = getMessageTypeEnum(tokens[0]);
        sbs1Message.transmission_type = getTransmissionTypeEnum(tokens[1]);
        // TODO fill all attributes
    
        return sbs1Message;
    }

    MessageType getMessageTypeEnum(std::string type)
    {
        if (type == "SEL")
        {
            return MessageType::SelectionChange;
        }
        else if (type == "ID")
        {
            return MessageType::NewId;
        }
        else if (type == "AIR")
        {
            return MessageType::NewAircraft;
        }
        else if (type == "STA")
        {
            return MessageType::StatusAircraft;
        }
        else if (type == "CLK")
        {
            return MessageType::Click;
        }
        else if (type == "MSG")
        {
            return MessageType::Transmission;
        }
        else
        {
            return MessageType::Undefined;
        }
    }

    TransmissionType getTransmissionTypeEnum(std::string type)
    {
        if (type == "1")
        {
            return TransmissionType::EsIdentAndCategory;
        }
        else if (type == "2")
        {
            return TransmissionType::EsSurfacePos;
        }
        else if (type == "3")
        {
            return TransmissionType::EsAirbornePos;
        }
        else if (type == "4")
        {
            return TransmissionType::EsAirborneVel;
        }
        else if (type == "5")
        {
            return TransmissionType::SurveillanceAlt;
        }
        else if (type == "6")
        {
            return TransmissionType::SurveillanceId;
        }
        else if (type == "7")
        {
            return TransmissionType::AirToAir;
        }
        else if (type == "8")
        {
            return TransmissionType::AllCallReply;
        }
        else
        {
            return TransmissionType::Undefined;
        }
    }
}