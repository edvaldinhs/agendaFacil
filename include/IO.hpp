#ifndef IO_HPP
#define IO_HPP

#include "Appointment.hpp"
#include <vector>
#include <string>

/**
 * @brief Lista atendimentos de uma data especifica
 * @param appointments Lista de atendimentos
 * @param date Data a ser filtrada
 */
void list_appointments(const std::vector<Appointment>& appointments, const std::string& date);

#endif
