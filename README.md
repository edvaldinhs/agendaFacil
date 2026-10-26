# AgendaFácil

Sistema de agenda de atendimentos para uma clínica pequena.

## Requisitos
- C++17

## Como compilar
```bash
g++ -std=c++17 -Wall -Iinclude src/*.cpp -o agenda
```

## Como executar
```bash
./agenda
```

## Como gerar a documentação com Doxygen
```bash
doxygen Doxyfile
```
A documentação gerada ficará na pasta `docs/`.

## Estrutura do projeto
- `include/` - Arquivos de cabeçalho (.hpp)
- `src/` - Arquivos de implementação (.cpp)
- `docs/` - Documentação gerada pelo Doxygen
- `Doxyfile` - Configuração do Doxygen

## Integrantes
- Edvaldo Henrique dos Santos
