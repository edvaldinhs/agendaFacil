#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include "Appointment.hpp"
#include <vector>
#include <string>

/**
 * @brief Verifica conflito de horario para um profissional
 * @param appointments Lista de atendimentos
 * @param doctor Nome do profissional
 * @param date Data do atendimento
 * @param hour Hora do atendimento
 * @return true se houver conflito, false caso contrario
 */
bool has_conflict(const std::vector<Appointment>& appointments, const std::string& doctor, const std::string& date, int hour);

/**
 * @brief Agenda um novo atendimento
 * @param appointments Lista de atendimentos (por referencia)
 * @param patient Nome do paciente
 * @param doctor Nome do profissional
 * @param date Data do atendimento
 * @param hour Hora de inicio
 * @param duration Duracao em minutos
 * @throw std::invalid_argument Caso haja violacao de pre-condicoes
 * @throw std::runtime_error Caso haja conflito de horario
 */
void add_appointment(std::vector<Appointment>& appointments, const std::string& patient, const std::string& doctor, const std::string& date, int hour, int duration);

/**
 * @brief Remarca um atendimento existente
 * @param appointments Lista de atendimentos (por referencia)
 * @param patient Nome do paciente
 * @param current_date Data atual do atendimento
 * @param current_hour Hora atual do atendimento
 * @param new_date Nova data
 * @param new_hour Nova hora
 * @throw std::invalid_argument Caso haja violacao de pre-condicoes
 * @throw std::runtime_error Caso haja conflito de horario
 */
void reschedule_appointment(std::vector<Appointment>& appointments, const std::string& patient, const std::string& current_date, int current_hour, const std::string& new_date, int new_hour);

#endif
