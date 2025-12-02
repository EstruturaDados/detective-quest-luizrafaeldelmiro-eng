#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------
// ESTRUTURA DA ÁRVORE BINÁRIA (MAPA DA MANSÃO)
// ------------------------------------------------------
struct Sala {
    string nome;
    string descricao;
    Sala* esquerda;
    Sala* direita;
};

// Cria uma nova sala
Sala* criarSala(string nome, string descricao) {
    Sala* nova = new Sala;
    nova->nome = nome;
    nova->descricao = descricao;
    nova->esquerda = nullptr;
    nova->direita = nullptr;
    return nova;
}

// Monta o mapa da mansão
Sala* montarMapa() {
    // Sala inicial
    Sala* entrada = criarSala("Entrada principal",
        "Você está na entrada da mansão. Duas portas te aguardam.");

    // Salas à esquerda
    entrada->esquerda = criarSala("Sala de Estar",
        "Uma sala antiga, cheia de quadros e móveis caros.");
    entrada->esquerda->esquerda = criarSala("Cozinha",
        "Cheiro de comida velha. Panelas jogadas pelo chão.");
    entrada->esquerda->direita = criarSala("Biblioteca",
        "Estantes cheias de livros empoeirados.");

    // Salas à direita
    entrada->direita = criarSala("Corredor",
        "Um corredor longo com várias portas trancadas.");
    entrada->direita->esquerda = criarSala("Quarto Antigo",
        "Cama quebrada, janela rangendo com o vento.");
    entrada->direita->direita = criarSala("Porão",
        "Escuro… algo se mexe lá dentro.");

    return entrada;
}

// ------------------------------------------------------
// JOGO
// ------------------------------------------------------
void jogar(Sala* atual) {
    char comando;

    while (true) {
        cout << "\n=== Você está em: " << atual->nome << " ===\n";
        cout << atual->descricao << "\n\n";

        cout << "O que deseja fazer?\n";
        cout << "[E] Ir para a sala à esquerda\n";
        cout << "[D] Ir para a sala à direita\n";
        cout << "[S] Sair do jogo\n";
        cout << "Comando: ";
        cin >> comando;
        comando = tolower(comando);

        if (comando == 's') {
            cout << "\nVocê saiu da mansão!\n";
            break;
        }
        else if (comando == 'e') {
            if (atual->esquerda != nullptr) {
                atual = atual->esquerda;
            } else {
                cout << "\nNão existe sala à esquerda!\n";
            }
        }
        else if (comando == 'd') {
            if (atual->direita != nullptr) {
                atual = atual->direita;
            } else {
                cout << "\nNão existe sala à direita!\n";
            }
        }
        else {
            cout << "Comando inválido!\n";
        }
    }
}

// ------------------------------------------------------
// MAIN
// ------------------------------------------------------
int main() {
    setlocale(LC_ALL, "Portuguese");

    Sala* mapa = montarMapa();
    jogar(mapa);

    return 0;
}
