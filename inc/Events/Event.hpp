#pragma once

#include <string>
#include <chrono>

namespace Events {

// enum class EventType {
//     Input = 0,      // Input events eg. keyboard, mouse, controller
//     System,         // Events related to ECS systems eg. dialogue option, combat
//     Engine,         // Events related to the engine core eg. scene change, resource loading
//     Application     // Events related to the application eg. window resize, close
// };

// auto constexpr EventTypeToString(EventType type) -> std::string {
//     switch (type) {
//         case EventType::Input: return "Input";
//         case EventType::System: return "System";
//         case EventType::Engine: return "Engine";
//         case EventType::Application: return "Application";
//     }

//     return "Unknown";
// }

// //  Event ID:
// //      Input:          1__...
// //      System:         01__...
// //      Engine:         001__...
// //      Application:    0001__...
// auto create_id(EventType type) -> uint {
//     static uint id = 0;

//     if (id >= 0b0001'0000'0000'0000) {
//         id = 0;
//     }

//     id += 1;

//     return id & (static_cast<uint>(type) << 12);
// }

// struct Event {
//     Event() {

//     }


// };

} // namespace Events