#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>  // <-- Aqui!
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

// Posição inicial do sol (mais tarde animaremos isso)
int sunY = 100;

// Função para desenhar o fundo em degradê
void drawGradientBackground(SDL_Renderer* renderer) {
    for (int y = 0; y < HEIGHT; ++y) {
        Uint8 r = 255 - (y * 155 / HEIGHT);
        Uint8 g = 69  - (y * 30  / HEIGHT);
        Uint8 b = 0   + (y * 139 / HEIGHT);
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, WIDTH, y);
    }
}

// Função para desenhar o sol
void drawSun(SDL_Renderer* renderer, int x, int y, int radius) {
    filledCircleRGBA(renderer, x, y, radius, 255, 223, 0, 255);  // Amarelo forte
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Erro SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Erro Mixer: " << Mix_GetError() << std::endl;
        return 1;
    }

    Mix_Music* music = Mix_LoadMUS("assets/Music.mp3");
    if (music) {
        Mix_PlayMusic(music, -1);
    } else {
        std::cerr << "Erro ao carregar música: " << Mix_GetError() << std::endl;
    }

    SDL_Window* window = SDL_CreateWindow("Pôr do Sol",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Desenha o céu
        drawGradientBackground(renderer);

        // Desenha o sol
        drawSun(renderer, WIDTH / 2, sunY, 50);

        // Atualiza a tela
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    Mix_FreeMusic(music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
