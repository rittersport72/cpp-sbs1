#ifndef SBS1MESSAGE_H
#define SBS1MESSAGE_H

// STL
#include <string>
#include <iomanip>

namespace SBS1
{
    enum class MessageType
    {
        Undefined,
        SelectionChange,
        NewId,
        NewAircraft,
        StatusAircraft,
        Click,
        /// Indicates a transmission from an aircraft. This type is most common.
        Transmission,
    };

    enum class TransmissionType
    {
        Undefined,
        EsIdentAndCategory,
        EsSurfacePos,
        EsAirbornePos,
        EsAirborneVel,
        SurveillanceAlt,
        SurveillanceId,
        AirToAir,
        AllCallReply,
    };

    /*
     * Class of SBS1 message.
     */
    class Sbs1Message
    {
        // Methodes
    public:
        /*
         * Constructor
         */
        Sbs1Message() : message_type(MessageType::Undefined),
                        transmission_type(TransmissionType::Undefined),
                        session_id(0),
                        aircraft_id(0),
                        ident(""),
                        callsign(""),
                        altitude(0.0),
                        ground_speed(0.0),
                        track(0.0),
                        latitude(0.0),
                        longitude(0.0),
                        vertical_speed(0.0),
                        squawk(0),
                        alert(false),
                        emergency(false),
                        special_position(false),
                        on_ground(false)
        {
            generated = {};
            logged = {};
        };

        // Attributes
    public:
        /// The type of the message
        MessageType message_type;
        /// The type of the transmission message
        TransmissionType transmission_type;
        /// Session
        unsigned int session_id;
        unsigned int aircraft_id;
        /// Aircraft identifier
        std::string ident;
        unsigned int flight_id;
        /// When the message was generated
        std::tm generated;
        /// When the message was logged
        std::tm logged;
        /// The flight number or callsign
        std::string callsign;
        /// The altitude of the aircraft above mean sea level, assuming an altimeter setting of
        /// 1013 millibars (29.92 inches of mercury)
        double altitude;
        /// The ground speed of the aircraft, in some unknown unit
        double ground_speed;
        /// The track of the aircraft, in degrees
        double track;
        /// The aircraft latitude
        double latitude;
        /// The aircraft longitude
        double longitude;
        /// The vertical speed of the aircraft, in some unknown unit (possibly feet per minute)
        double vertical_speed;
        /// The current transponder code
        unsigned short squawk;
        /// Indicates the transponder code has changed
        bool alert;
        /// Indicates an emergency code has been set
        bool emergency;
        /// Indicates the Special Position Indicator has been set
        bool special_position;
        /// Indicates the aircraft is on the ground
        bool on_ground;
    };
}

#endif // SBS1MESSAGE_H