# cpp-sbs1
C++ library for parsing SBS1 base station-formatted ADS-B aircraft data.

SBS1 messages are in simple comma separated format as shown in this example:
```
MSG,5,111,11111,3C56EE,111111,2022/09/23,11:27:17.534,2022/09/23,11:27:17.513,,21900,,,,,,,0,,0,0
MSG,7,111,11111,A955D1,111111,2022/09/23,11:27:17.601,2022/09/23,11:27:17.579,,40025,,,,,,,,,,0
MSG,3,111,11111,A955D1,111111,2022/09/23,11:27:17.619,2022/09/23,11:27:17.580,,40025,,,48.44078,9.71170,,,,,,0
MSG,8,111,11111,A955D1,111111,2022/09/23,11:27:17.624,2022/09/23,11:27:17.580,,,,,,,,,,,,0
MSG,5,111,11111,3C56EE,111111,2022/09/23,11:27:17.625,2022/09/23,11:27:17.580,,21900,,,,,,,0,,0,0
MSG,4,111,11111,A955D1,111111,2022/09/23,11:27:17.627,2022/09/23,11:27:17.580,,,443,311,,,64,,,,,0
MSG,5,111,11111,A955D1,111111,2022/09/23,11:27:17.642,2022/09/23,11:27:17.580,,40025,,,,,,,0,,0,0
MSG,6,111,11111,A955D1,111111,2022/09/23,11:27:17.654,2022/09/23,11:27:17.644,,,,,,,,6655,0,0,0,0
```

Usage of library:

```cpp
// Create SBS1 string
const std::string text = "MSG,3,111,11111,A955D1,111111,2022/09/23,11:27:53.001,2022/09/23,11:27:52.970,,40025,,,48.48807,9.62836,,,,,,0";

try
{
    // Parse SBS1 string into message
    SBS1::Sbs1Message message = SBS1::parse(text);
    
    // Access message attribute
    MessageType message_type = message.message_type;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

## Message attributes
Parsed messages have the following fields:

|Field            |Description                                                         |
|-----------------|--------------------------------------------------------------------|
|message_type     |`enum class` MessageType                                            |
|transmission_type|`enum class` TransmissionType                                       |
|session_id       |`unsigned int` Database session record number.                      |
|aircraft_id      |`unsigned int` Database aircraft record number.                     |
|ident            |`std::string` 24-bit ICACO ID, in hexadecimal.                      |
|flight_id        |`unsigned int` Database flight record number.                       |
|generated        |`std::tm` Date and time the message was generated.                  |
|logged           |`std::tm` Date and time the message was logged.                     |
|callsign         |`std::string` Eight character flight ID or callsign.                |
|altitude         |`double` Mode C altitude relative to 1013 mb (29.92" Hg).           |
|ground_speed     |`double` Speed over ground.                                         |
|track            |`double` Ground track angle, in degree                              |
|latitude         |`double` Latitude, in degree                                        |
|longitude        |`double` Longitude, in degree                                       |
|vertical_speed   |`double` Vertical speed, climb/descend rate                         |
|squawk           |`unsigned short` Assigned mode A squawk code.                       |
|alert            |`bool` Flag to indicate that squawk has changed.                    |
|emergency        |`bool` Flag to indicate emergency code has been set.                |
|special_position |`bool` Flag to indicate Special Position Indicator has been set.    |
|on_ground        |`bool` Flag to indicate ground squat switch is active.              |

## References
Description of SBS1 protocol http://woodair.net/SBS/Article/Barebones42_Socket_Data.htm  
SBS1 parser in Node.js https://github.com/wiseman/node-sbs1  
SBS1 parser in Rust https://github.com/samcrow/rust-sbs1
