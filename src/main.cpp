#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

// Largura e altura da janela
const int WIDTH = 800;
const int HEIGHT = 600;

// Função para desenhar um fundo com gradiente vertical
void drawGradientBackground(SDL_Renderer* renderer) {
    for (int y = 0; y < HEIGHT; ++y) {
        // Interpolação entre cores (laranja e roxo escuro)
        Uint8 r = 255 - (y * 155 / HEIGHT);  // de 255 para 100
        Uint8 g = 69  - (y * 30  / HEIGHT);  // de 69  para 39
        Uint8 b = 0   + (y * 139 / HEIGHT);  // de 0   para 139

        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, WIDTH, y);
    }
}

int main() {
    // Inicialização do SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Erro ao inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Inicialização do SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Erro ao inicializar SDL_mixer: " << Mix_GetError() << std::endl;
        return 1;
    }

    // Carregar música
    Mix_Music* music = Mix_LoadMUS("assets/Music.mp3");
    if (!music) {
        std::cerr << "Erro ao carregar música: " << Mix_GetError() << std::endl;
    } else {
        Mix_PlayMusic(music, -1);  // Reproduzir em loop
    }

    // Criar janela
    SDL_Window* window = SDL_CreateWindow("Pôr do Sol",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Erro ao criar janela: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Criar renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erro ao criar renderizador: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Loop principal
    bool running = true;
    SDL_Event event;
    while (running) {
        // Eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Desenhar fundo com gradiente
        drawGradientBackground(renderer);

        // Atualizar a tela
        SDL_RenderPresent(renderer);

        // Aguardar um pequeno tempo
        SDL_Delay(16);
    }

    // Encerrar recursos
    Mix_FreeMusic(music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
