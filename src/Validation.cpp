#include "Validation.hpp"
#include "Constants.hpp"
#include <stdexcept>
#include <cstddef>

void validate_date_format(const std::string& date) {
    if (date.size() != 10) {
        throw std::invalid_argument("Data invalida: '" + date + "' (esperado AAAA-MM-DD)");
    }
    if (date[4] != '-' || date[7] != '-') {
        throw std::invalid_argument("Data invalida: '" + date + "' (esperado AAAA-MM-DD)");
    }
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (date[i] < '0' || date[i] > '9') {
            throw std::invalid_argument("Data invalida: '" + date + "' (esperado AAAA-MM-DD)");
        }
    }
}

void validate_schedule_time(int hour, int duration) {
    if (hour < MIN_START_HOUR || hour > MAX_START_HOUR) {
        throw std::invalid_argument("Horario invalido: " + std::to_string(hour) + " (deve estar entre 08 e 17)");
    }
    if (duration < MIN_DURATION || duration > MAX_DURATION) {
        throw std::invalid_argument("Duracao invalida: " + std::to_string(duration) + " (deve ser entre 15 e 120 minutos)");
    }
    if (duration % DURATION_STEP != 0) {
        throw std::invalid_argument("Duracao invalida: " + std::to_string(duration) + " (deve ser multiplo de 15)");
    }
    if (hour + (duration / 60) > CLOSE_HOUR || (hour == CLOSE_HOUR)) {
        if (duration > 0) {
            if (hour == 17 && duration > 60) {
            }
        }
    }
    if (hour == MAX_START_HOUR && duration > 60) {
        throw std::invalid_argument("Duracao invalida para horario 17:00 (deve terminar ate 18:00)");
    }
    if (hour == MAX_START_HOUR && duration == 60) {
        return;
    }
    if (hour < MAX_START_HOUR) {
        return;
    }
    if (hour == MAX_START_HOUR && duration <= 60) {
        if (duration % DURATION_STEP != 0) {
            throw std::invalid_argument("Duracao invalida: " + std::to_string(duration) + " (deve ser multiplo de 15)");
        }
        return;
    }
    throw std::invalid_argument("Horario invalido: " + std::to_string(hour) + " (deve estar entre 08 e 17)");
}
