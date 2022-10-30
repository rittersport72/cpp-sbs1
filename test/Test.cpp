#include "Sbs1.h"

// STL
#include <iostream>

int main()
{
    const std::string text = "MSG,3,111,11111,A955D1,111111,2022/09/23,11:27:53.001,2022/09/23,11:27:52.970,,40025,,,48.48807,9.62836,,,,,,0";

    SBS1::Sbs1Message message = SBS1::parse(text);

    std::cout << "transmission type: " << static_cast<std::underlying_type<SBS1::TransmissionType>::type>(message.transmission_type) << std::endl;

    return 0;
}