# 🎯 Tarefa: Roteiro de FreeRTOS #1 - EmbarcaTech 2025

👨‍💻 Autor: **Rafael Florentino Barbosa**  
📘 Curso: Residência Tecnológica em Sistemas Embarcados  
🏫 Instituição: EmbarcaTech - HBr  
📍 Local: Brasília - DF  
🗓️ Data: Junho de 2025  

---

## 📂 Descrição do Projeto

Este projeto foi desenvolvido como parte da trilha de aprendizagem da disciplina de sistemas operacionais embarcados com **FreeRTOS**.  
Ele demonstra o uso de tarefas concorrentes controlando periféricos da placa **BitDogLab (Raspberry Pi Pico W)**.

O sistema multitarefa realiza:

- 🌈 **Controle de LED RGB** que alterna entre vermelho, verde e azul a cada 500ms.
- 🔊 **Controle de buzzer** que emite bipes curtos com intervalo de 1 segundo.
- 🕹️ **Leitura de botões físicos**:
  - Botão A: suspende ou retoma a tarefa do LED.
  - Botão B: suspende ou retoma a tarefa do buzzer.

---

## 🔧 Componentes Utilizados

- 🧠 FreeRTOS
- ⚡ Raspberry Pi Pico W (BitDogLab)
- 🔴 LED RGB
- 🔈 Buzzer (ativo)
- 🔘 Botões físicos (A e B)
- 💡 GPIOs via `pico-sdk`

---

## 🧵 Estrutura do Projeto
---

```
├── app/
│ └── main.c # Inicializa o sistema e tarefas
├── hal/
│ ├── buttons.c # Lógica de leitura dos botões
│ ├── buzzers.c # Controle do buzzer
│ └── led.c # Controle do LED RGB
├── include/
│ ├── buttons.h
│ ├── buzzers.h
│ └── led.h
├── FreeRTOS-Kernel/ # Núcleo do FreeRTOS
├── CMakeLists.txt
└── README.md # Este arquivo
```


# 📘 Reflexão e entrega


## 1. O que acontece se todas as tarefas tiverem a mesma prioridade?
Se todas as tarefas tiverem a mesma prioridade, o escalonador do FreeRTOS usa uma política de round-robin:

Ele alterna entre as tarefas com base no tempo de fatia (time slice).

Cada tarefa recebe uma chance de rodar por um curto período, desde que não esteja bloqueada (ex: esperando um vTaskDelay() ou evento).

No seu projeto, isso significa que:

O LED, o buzzer e os botões executariam de forma intercalada, mas a responsividade da tarefa de botões poderia cair um pouco se ela não tivesse prioridade maior, pois poderia ser preemptada por outra tarefa mesmo sendo mais crítica para o controle do sistema.

## 2. Qual tarefa consome mais tempo da CPU?
A tarefa que mais consome tempo da CPU é a button_task, por dois motivos:

Ela executa constantemente a cada 100 ms (polling), sem fazer muito trabalho entre as leituras.

Ao contrário das tarefas de LED e buzzer, que fazem delays de 500 ms e 800 ms, a button_task tem um ciclo muito mais curto, o que significa que ela acorda mais vezes e verifica o estado dos botões com mais frequência.

Entretanto, como ela tem pouco processamento em cada ciclo, o uso total da CPU ainda é baixo, mas a frequência de execução é alta.

## 3. Quais seriam os riscos de usar polling sem prioridades?
Se usar polling (como no seu código) sem configurar prioridades adequadamente, os riscos são:

🔄 Perda de responsividade: Se a tarefa de botões tiver a mesma prioridade que as outras, ela pode demorar mais para executar. Isso causaria atrasos na detecção dos botões, tornando o sistema menos reativo.

🧠 Tarefas críticas preemptadas: Uma tarefa importante como button_task poderia ser interrompida por outra menos crítica (ex: o LED mudando de cor), o que afeta o controle do sistema.

❌ Concorrência mal gerenciada: Sem prioridades, o sistema pode escalar de forma injusta, favorecendo tarefas mais leves ou que bloqueiam menos.

🔁 Uso ineficiente da CPU: Polling sem prioridade (e sem event-driven alternativo) pode levar a uso desnecessário da CPU, especialmente se for feito com vTaskDelay muito baixo ou while(true) sem espera.

---


---

## 🚀 Execução do Projeto

1. Clone o repositório e abra no VS Code.
2. Certifique-se de ter o `pico-sdk` e `FreeRTOS` corretamente configurados.
3. Compile o projeto com CMake/Ninja.
4. Grave o firmware na placa Pico W via UF2 ou `picotool`.

---

## 🧠 Aprendizados

✅ Criação e gerenciamento de múltiplas tarefas com `FreeRTOS`.  
✅ Controle eficiente de GPIOs em tempo real.  
✅ Uso de `vTaskCreate()`, `vTaskSuspend()` e `vTaskResume()`.  
✅ Organização modular de código C com `pico-sdk`.  
✅ Integração de periféricos em ambiente multitarefa embarcado.

---

## 📜 Licença

Distribuído sob a licença [GNU GPL-3.0](https://www.gnu.org/licenses/gpl-3.0.html) ⚖️.

---

## 🙌 Agradecimentos

A todos os mentores e colegas da **EmbarcaTech HBr** por todo apoio técnico e incentivo!

🚀 *#FreeRTOS #BitDogLab #Embarcados #PicoW #ResidênciaTecnológica*