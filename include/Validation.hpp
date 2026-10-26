#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <string>

/**
 * @brief Valida o formato da data no padrao AAAA-MM-DD
 * @param date String com a data
 * @throw std::invalid_argument Caso o formato seja invalido
 */
void validate_date_format(const std::string& date);

/**
 * @brief Valida o expediente e a duracao do atendimento
 * @param hour Hora de inicio
 * @param duration Duracao em minutos
 * @throw std::invalid_argument Caso os valores sejam invalidos
 */
void validate_schedule_time(int hour, int duration);

#endif
