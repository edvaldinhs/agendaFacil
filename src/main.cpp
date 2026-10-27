#include "Schedule.hpp"
#include "IO.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<Appointment> appointments;
    try {
        add_appointment(appointments, "Ana", "Dr. Silva", "2026-10-05", 9, 30);
        std::cout << "Atendimento marcado para Ana" << std::endl;
    } catch (const std::runtime_error&) {
        std::cout << "Horario ocupado" << std::endl;
    } catch (const std::exception&) {
        // Nao deve ocorrer no caminho feliz
    }
    try {
        add_appointment(appointments, "Bruno", "Dr. Silva", "2026-10-05", 9, 30);
        std::cout << "Atendimento marcado para Bruno" << std::endl;
    } catch (const std::runtime_error&) {
        std::cout << "Horario ocupado" << std::endl;
    } catch (const std::exception&) {
        // Nao deve ocorrer no caminho feliz
    }
    try {
        add_appointment(appointments, "Carla", "Dra. Souza", "2026-10-05", 14, 60);
        std::cout << "Atendimento marcado para Carla" << std::endl;
    } catch (const std::runtime_error&) {
        std::cout << "Horario ocupado" << std::endl;
    } catch (const std::exception&) {
        // Nao deve ocorrer no caminho feliz
    }
    try {
        reschedule_appointment(appointments, "Ana", "2026-10-05", 9, "2026-10-06", 10);
        std::cout << "Remarcado" << std::endl;
    } catch (const std::runtime_error&) {
        std::cout << "Horario ocupado" << std::endl;
    } catch (const std::exception&) {
        // Nao deve ocorrer no caminho feliz
    }
    list_appointments(appointments, "2026-10-05");
    return 0;
}
