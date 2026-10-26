#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>

struct Appointment {
    std::string patient;
    std::string doctor;
    std::string date;
    int hour;
    int duration;
    std::string status;
};

#endif
