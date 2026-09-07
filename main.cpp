#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

typedef struct
{
    string titulo;
    string genero;
    int duracaoMin;
    float precoIngresso;
    int ingressosVendidos;

} Filme;

float calcularArrecadacao(Filme f);
float calcularArrecadacao(Filme filmes[], int n);
void selecionaOpcao(char &op);
void cadastrarFilme(Filme &f);
void exibirFilme(const Filme &f);
int indiceMaiorArrecadacao(Filme filmes[], int n);

int main()
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif


    char opcao;
    Filme filmes[10];
    int qtd = 0;

    selecionaOpcao(opcao);

    while (toupper(opcao) != 'X')
    {
        system("cls");

        switch (opcao)
        {
        case '1':
            cout << "----------- CADASTRAR NOVO FILME -----------\n";
            cadastrarFilme(filmes[qtd]);
            qtd++;
            cout << "Filme cadatrado com sucesso!";
            break;

        case '2':
            cout << "----------- LISTA DE FILMES -----------\n";
            if (qtd == 0)
            {
                cout << "Não há filmes cadastrados";
            }
            else
            {
                for (int i = 0; i < qtd; i++)
                    exibirFilme(filmes[i]);
            }
            break;

        case '3':
            cout << "----------- MAIOR ARRECADAÇÃO -----------\n";
            if (qtd == 0)
            {
                cout << "Não há filmes cadastrados";
            }
            else
            {
                cout << "Filme com maior arrecadação: \n";
                exibirFilme(filmes[indiceMaiorArrecadacao(filmes, qtd)]);
                cout << "--------------------------------------" << endl;
            }
            break;

        case '4':
            cout << "----------- ARRECADAÇÃO TOTAL -----------\n";
            if (qtd == 0)
            {
                cout << "Não há filmes cadastrados";
            }
            else
            {
                for (int i = 0; i < qtd; i++)
                    exibirFilme(filmes[i]);
                cout << "Total geral: R$ " << calcularArrecadacao(filmes, qtd) << endl;
            }

            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
            break;
        }

        cout << "\nPressione qualquer tecla para retornar ao [MENU].";
        getch();
        selecionaOpcao(opcao);
    }

    cout << "\nFim do programa.\n";
    getch();
    return 0;
}

void selecionaOpcao(char &op)
{
    system("cls");
    cout << "================ CINEMA MENU ================\n"
         << " [1] Cadastrar novo filme\n"
         << " [2] Listar todos os filmes\n"
         << " [3] Mostrar filme com maior arrecadação\n"
         << " [4] Mostrar arrecadação total (sobrecarga)\n"
         << "---------------------------------------------\n"
         << " [x] Pressione qualquer outra tecla para sair\n"
         << "=============================================\n>";
    op = getch();
    system("cls");
}

void cadastrarFilme(Filme &f)
{

    cout << "Titulo: ";
    getline(cin, f.titulo);
    cout << "Gênero: ";
    getline(cin, f.genero);
    cout << "Duração(min): ";
    cin >> f.duracaoMin;
    cout << "Preço do ingresso: ";
    cin.ignore();
    cin >> f.precoIngresso;
    cout << "Ingressos vendidos: ";
    cin.ignore();
    cin >> f.ingressosVendidos;
    cin.ignore();
}

float calcularArrecadacao(Filme f)
{
    return f.precoIngresso * f.ingressosVendidos;
}

float calcularArrecadacao(Filme filmes[], int n)
{
    float arrecadacaoTotal = 0;
    for (int i = 0; i < n; i++)
        arrecadacaoTotal += calcularArrecadacao(filmes[i]);

    return arrecadacaoTotal;
}

void exibirFilme(const Filme &f)
{
    cout << "--------------------------------------" << endl;
    cout << "Titulo: " << f.titulo << endl;
    cout << "Gênero: " << f.genero << endl;
    cout << "Duração: " << f.duracaoMin << " min" << endl;
    cout << "Preço do ingresso: R$ " << f.precoIngresso << endl;
    cout << "Ingressos vendidos: " << f.ingressosVendidos << endl;
    cout << "Arrecadação: R$ " << calcularArrecadacao(f) << endl;
    cout << "--------------------------------------" << endl;
}
int indiceMaiorArrecadacao(Filme filmes[], int n)
{

    int indiceMaiorArrecadacao = 0;
    int maiorArrecadacao = calcularArrecadacao(filmes[0]);

    for (int i = 1; i < n; i++)
        if (calcularArrecadacao(filmes[i]) > maiorArrecadacao)
            indiceMaiorArrecadacao = i;

    return indiceMaiorArrecadacao;
}
