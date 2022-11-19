#ifndef SBS1_H
#define SBS1_H

#include "Sbs1Message.h"

// STL
#include <string>
#include <vector>
#include <stdexcept>

namespace SBS1
{
    class ParseException : public std::exception
    {
        public:
            ParseException(const std::string& text) : error(text)
            {
            }

            virtual const char* what() const throw()
            {
                return error.c_str();
            }

        private:
            const std::string error;
    };

    Sbs1Message parse(const std::string& message_string);

    Sbs1Message internalExtract(const std::vector <std::string>& tokens);

    MessageType getMessageTypeEnum(const std::string& type);

    TransmissionType getTransmissionTypeEnum(const std::string& type);
}

#endif // SBS1_H