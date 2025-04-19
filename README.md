# 🌇 Pôr do Sol com SDL2

Este é um projeto educacional e visualmente agradável criado com a biblioteca SDL2, que simula um **pôr do sol animado** usando técnicas simples de renderização em C++. O projeto é dividido em etapas para facilitar o aprendizado e o uso em oficinas ou disciplinas relacionadas à programação de jogos, computação gráfica e desenvolvimento multimídia.

---

## 🎯 Objetivos

- Aprender a inicializar e utilizar a SDL2 em C++
- Criar um fundo com **gradiente colorido**
- Desenhar e animar um **sol** em movimento
- Introduzir conceitos como **cena dinâmica, camadas e loop de renderização**
- (Opcional) Adicionar elementos como nuvens e som ambiente

---

## 📚 Etapas do Projeto

| Etapa | Descrição |
|-------|-----------|
| 1️⃣ | Inicialização da janela e renderizador SDL2 |
| 2️⃣ | Criação de fundo com gradiente simulando o pôr do sol |
| 3️⃣ | Desenho do sol (círculo) com cor personalizada |
| 4️⃣ | Animação do sol no eixo Y (movimento descendente) |
| 5️⃣ | (Opcional) Nuvens desenhadas com formas geométricas simples |
| 6️⃣ | (Opcional) Inclusão de som ambiente relaxante com SDL_mixer |
| 7️⃣ | (Opcional) Polimentos visuais: transições suaves, opacidade, texto etc. |

---

## 🛠️ Requisitos

Antes de compilar o projeto, certifique-se de ter as seguintes bibliotecas instaladas:

- SDL2
- SDL2_ttf (opcional, se desejar adicionar texto)
- SDL2_gfx (opcional, facilita desenho de círculos e primitivas)
- SDL2_mixer (opcional, para som ambiente)

### 💡 No Ubuntu/Debian, use:
```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-ttf-dev libsdl2-gfx-dev libsdl2-mixer-dev g++


### Compilação
g++ -std=c++17 src/main.cpp -o sunset -lSDL2 -lSDL2_ttf -lSDL2_gfx -lSDL2_mixer

## Execução
./sunset
