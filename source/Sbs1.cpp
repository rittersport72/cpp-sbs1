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
            std::cout << tokens[i] << std::endl;

        // TODO checkme
        if (tokens.size() < 22)
        {
            return Sbs1Message();
        }

        // Create message and assign attributes
        Sbs1Message sbs1Message;
        sbs1Message.message_type = getMessageTypeEnum(tokens[0]);
        sbs1Message.transmission_type = getTransmissionTypeEnum(tokens[1]);
        sbs1Message.session_id = std::stoi(tokens[2]);
        sbs1Message.aircraft_id = std::stoi(tokens[3]);
        sbs1Message.ident = std::stoi(tokens[4]);
        sbs1Message.flight_id = std::stoi(tokens[5]);
        //sbs1Message.generated = tokens[6] tokens[7]
        //sbs1Message.logged = tokens[8] tokens[9]
        sbs1Message.callsign = tokens[10];
        sbs1Message.altitude = std::stod(tokens[11]);  
        sbs1Message.ground_speed = std::stod(tokens[12]);
        sbs1Message.track = std::stod(tokens[13]);
        sbs1Message.latitude = std::stod(tokens[14]);
        sbs1Message.longitude = std::stod(tokens[15]);
        sbs1Message.vertical_speed = std::stod(tokens[16]);
        sbs1Message.squawk = std::stoi(tokens[17]);
        sbs1Message.alert = (bool) std::stoi(tokens[18]);
        sbs1Message.emergency = (bool) std::stoi(tokens[19]);
        sbs1Message.special_position = (bool) std::stoi(tokens[20]);
        sbs1Message.on_ground = (bool) std::stoi(tokens[21]);
    
        return sbs1Message;
    }

    std::map<std::string, MessageType> messageTypeMap =
    {
        { "SEL", MessageType::SelectionChange },
        { "ID",  MessageType::NewId },
        { "AIR", MessageType::NewAircraft },
        { "STA", MessageType::StatusAircraft },
        { "CLK", MessageType::Click },
        { "MSG", MessageType::Transmission },
    };

    MessageType getMessageTypeEnum(const std::string& type)
    {
        try
        {
            const MessageType& value = messageTypeMap.at(type);
            return value;
        }
        catch (const std::out_of_range&) {
            return MessageType::Undefined;
        }
    }

    std::map<std::string, TransmissionType> transmissionTypeMap =
    {
        { "1", TransmissionType::EsIdentAndCategory },
        { "2", TransmissionType::EsSurfacePos },
        { "3", TransmissionType::EsAirbornePos },
        { "4", TransmissionType::EsAirborneVel },
        { "5", TransmissionType::SurveillanceAlt },
        { "6", TransmissionType::SurveillanceId },
        { "7", TransmissionType::AirToAir },
        { "8", TransmissionType::AllCallReply }
    };

    TransmissionType getTransmissionTypeEnum(const std::string& type)
    {
        try
        {
            const TransmissionType& value = transmissionTypeMap.at(type);
            return value;
        }
        catch (const std::out_of_range&) {
            return TransmissionType::Undefined;
        }
    }
}