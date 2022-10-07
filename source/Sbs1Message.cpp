#include "Sbs1Message.h"

namespace SBS1
{
    Sbs1Message::Sbs1Message()
    : message_type(MessageType::Undefined)
    , transmission_type(TransmissionType::Undefined) 
    , session_id(0)
    , aircraft_id(0)
    , ident(0)
    , flight_id(0)
    // , generated(0)
    // , logged(0)
    , callsign("")
    , altitude(0.0f)
    , ground_speed(0.0f)
    , track(0.0f)
    , latitude(0.0f)
    , longitude(0.0f)
    , vertical_speed(0.0f)
    , squawk(0)
    , alert(false)
    , emergency(false)
    , special_position(false)
    , on_ground(false)
    {
    }
}