#include "Schedule.hpp"
#include "Validation.hpp"
#include "Constants.hpp"
#include <stdexcept>

bool has_conflict(const std::vector<Appointment>& appointments, const std::string& doctor, const std::string& date, int hour) {
    for (const auto& appt : appointments) {
        if (appt.date == date && appt.hour == hour && appt.doctor == doctor) {
            return true;
        }
    }
    return false;
}

void add_appointment(std::vector<Appointment>& appointments, const std::string& patient, const std::string& doctor, const std::string& date, int hour, int duration) {
    validate_date_format(date);
    validate_schedule_time(hour, duration);
    if (has_conflict(appointments, doctor, date, hour)) {
        throw std::runtime_error("Horario ocupado");
    }
    appointments.push_back({patient, doctor, date, hour, duration, "MARCADO"});
}

void reschedule_appointment(std::vector<Appointment>& appointments, const std::string& patient, const std::string& current_date, int current_hour, const std::string& new_date, int new_hour) {
    validate_date_format(current_date);
    validate_date_format(new_date);
    if (new_hour < MIN_START_HOUR || new_hour > MAX_START_HOUR) {
        throw std::invalid_argument("Horario invalido: " + std::to_string(new_hour) + " (deve estar entre 08 e 17)");
    }
    for (auto& appt : appointments) {
        if (appt.patient == patient && appt.date == current_date && appt.hour == current_hour) {
            if (has_conflict(appointments, appt.doctor, new_date, new_hour)) {
                throw std::runtime_error("Horario ocupado");
            }
            appt.date = new_date;
            appt.hour = new_hour;
            return;
        }
    }
}
