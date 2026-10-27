# Relatório - AgendaFácil

### Github:

https://github.com/edvaldinhs/agendaFacil

## 1) Etapa 1 - Diagnóstico

### 1.1. Adequação e lógica
| Anomalia encontrada (e onde) | Por que é um problema |
|---|---|
| lst() possui comentário "// lista os atendimentos do mes", mas filtra apenas por data exata passada como parâmetro (if (ag[i].d == d)). (agenda_base.cpp:72-79) | Desinforma quem lê, dificultando manutenção e entendimento. |
| add() verifica conflito apenas por (d, h, pr), mas rem() também precisa considerar o mesmo profissional. (agenda_base.cpp:27-44, 46-70)| Duplicação e possibilidade de regras divergirem ao longo do tempo. |
| rem() percorre e só altera se encontrar o atendimento (p, d, h). Se não encontrar, não informa nada. (agenda_base.cpp:46-70) | usuário não sabe se o atendimento existia ou não. |





### 1.2. Manutenibilidade
| Anomalia encontrada (e onde) | Por que é um problema |
|---|---|
| struct A { string p; string pr; string d; int h; int dur; string st; }. (agenda_base.cpp:19-26) | Baixa legibilidade. |
| vector<A> ag; global. (agenda_base.cpp:27) | Dificulta testes, reutilização e modularização. |
| void add(string p, string pr, string d, int h, int dur), void rem(string p, string d, int h, string nd, int nh)`. (agenda_base.cpp:28, 46) | Cópia de valor na assinatura torna menos eficiente. |






### 1.3. Organização e estética
| Anomalia encontrada (e onde) | Por que é um problema |
|---|---|
| Cabeçalho com histórico de alterações - Linhas 1-6. | histórico deve ficar no controle de versão. |
| Função desmarcar comentada (linhas 72-75) e TODO: rever isso depois (Joao, 2025) (linha 77). | Polui o arquivo. |
| Falta de modularização - Tudo em um único arquivo. | Dificulta organização e reutilização. |






### 1.4. Programação defensiva e segurança
| Anomalia encontrada (e onde) | Por que é um problema |
|---|---|
| try { ... } catch (...) { } em add() (linhas 30-45). | Engole qualquer exceção sem tratar. |
| add() usa múltiplos if aninhados para validar horário. (linhas 31-44) | Difícil de ler/estender. |
| Marcar às 20h simplesmente não faz nada (condições `h >= 8 && h < 18` falham e não há aviso). | Viola "nenhuma operação pode falhar em silêncio". Usuário não sabe o motivo da falha. |




### 1.5. Desempenho e recursos
| Anomalia encontrada (e onde) | Por que é um problema |
|---|---|
|Percorre vetor múltiplas vezes sem função única para a regra de conflito. | Mais difícil garantir a mesma regra em todos os pontos. |






## 2) Decisões de projeto



### 2.1. Modularização e responsabilidades
Decidir separar o código em arquivos com responsabilidade única, distribuidos em include/ e src/. Creio que fica mais organizado do que um único arquivo...



### 2.2. Documentação
Temos Doxygen!!!

Tutorial de Utilização dele no README.md



### 2.3. Uso de IA
Ferramentas de IA foram utilizadas para sumarizar e verificar se não faltava alguma coisa no projeto. Não para gerar código.
