#include "IO.hpp"
#include <iostream>

void list_appointments(const std::vector<Appointment>& appointments, const std::string& date) {
    for (const auto& appt : appointments) {
        if (appt.date == date) {
            std::cout << appt.hour << " " << appt.patient << " " << appt.doctor << " " << appt.status << std::endl;
        }
    }
}
