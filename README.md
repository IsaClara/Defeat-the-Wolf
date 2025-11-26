🐺 Defeat the Wolf - Derrote o Lobo  
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

Um mini-jogo de combate por turnos simples, focado em **probabilidade** e desenvolvido em **C** para fins de aprendizado e prática. Você enfrentará um lobo feroz e sua sobrevivência dependerá tanto de suas escolhas táticas quanto da sua sorte!



## Objetivo

O objetivo principal é **derrotar o lobo** (`hpIn` <= 0) antes que ele o derrote (`hpPlayer` <= 0).

---

## Como Jogar

O jogo é executado diretamente no **Terminal** ou **Console**. O combate ocorre em turnos, onde você escolhe uma ação e, em seguida, o lobo reage.

### Ações do Jogador

Você tem as seguintes opções a cada turno:

| Opção | Ação | Efeito | Chance de Sucesso |
| :---: | :--- | :--- | :--- |
| **[1]** | **Atacar o inimigo** | Causa dano de `atkPlayer` (5 HP) ao lobo. | **50% de chance** de acertar. |
| **[2]** | **Defender** | Anula **completamente** o ataque do lobo no turno atual. | **100%** de defesa (se o lobo atacar). |
| **[3]** | **Usar poção de vida** | Recupera 5 HP (limite máximo de 50 HP). | Você começa com **3 poções**. |
| **[4]** | **Correr** | Encerra o jogo e você perde. | N/A |

### O Combate e a Sorte

* **Ataque do Jogador:** Seu ataque tem **50% de chance** de acertar. Se falhar, você não causa dano.
* **Ataque do Lobo:** Após sua ação (exceto se você correr), o lobo ataca. O ataque dele também tem **50% de chance** de acerto.
    * Se você escolher **Defender** (`[2]`), você **não perde vida** mesmo que o lobo acerte o ataque.
    * Se você **não defender** e o lobo acertar, você perde `atkIn` (10 HP).

---

## Funcionalidades

* **Combate por Turnos Simples:** Estrutura clara de `menu()` para ações do jogador, seguida pela `acaoInimigo()`.
* **Mecânica de Sorte:** Implementação da aleatoriedade (`rand() % 2`) para determinar o sucesso de ataques e defesas.
* **Uso de Cores:** Utiliza códigos ANSI para estilizar a saída no console, tornando a experiência mais visual (depende da compatibilidade do terminal).
* **ASCII Art:** O lobo é representado com arte ASCII.

---

## Tecnologias

* **Linguagem de Programação:** C
* **Bibliotecas Chave:**
    * `<stdio.h>` e `<stdlib.h>`
    * `<time.h>` (para a função de sorte)
    * `<conio.h>` (para `getch()`, comum em ambientes Windows/MS-DOS)

---

## Compilação e Execução

Para compilar e executar este projeto, você precisará de um compilador C (como o **GCC**).

### Passos

1.  **Salve o código** no arquivo `defeat_the_wolf.c`.
2.  **Abra o terminal** no diretório onde o arquivo foi salvo.
3.  **Compile** usando o GCC:

    ```bash
    gcc defeat_the_wolf.c -o defeat_the_wolf
    ```

4.  **Execute** o jogo:

    ```bash
    # Para Linux/macOS
    ./defeat_the_wolf

    # Para Windows
    ./defeat_the_wolf.exe
    ```

---

## Autor

**Criado por: Isa Clara**
